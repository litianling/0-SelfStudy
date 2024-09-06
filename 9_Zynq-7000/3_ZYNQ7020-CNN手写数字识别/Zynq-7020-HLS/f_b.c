#include <math.h>
#include <string.h>

static float conv_kernel_1[3][3];
static float max_poo_locate_1[14][14];
static float conv_kernel_2[3][3];
static float max_poo_locate_2[6][6];
static float fc_hidden_layer1[36][20];
static float fc_hidden_layer2[20][10];

static float mnist_data[30][30];
static float conv_out_1[28][28];
static float max_poo_out_1[14][14];
static float conv_out_2[12][12];
static float max_poo_out_2[6][6];
static float fc_in_1[1][36];
static float fc_out_1[1][20];
static float fc_in_2_relu1[1][20];
static float fc_out_2[1][10];
static float probability_result[10];

float max(float a, float b) {
	return (a > b)? a : b;
}
/**********************************************************************************/

void Conv2d(int w,int h,int k,float *input_matrix,float *kernel,float *out_matrix){
    for(int i=0;i<w-k+1;i++)
        for(int j=0;j<h-k+1;j++){
            out_matrix[i*(h-k+1)+j]=0;
            Conv2d_label0:for(int col=i;col<i+3;col++)
                for(int row=j;row<j+3;row++)
                    out_matrix[i*(h-k+1)+j]+=input_matrix[col*h+row]*kernel[(col-i)*k+(row-j)];
        }
}

void MaxPool2d(int w,int h,int k,float *input_matrix,float *output_matrix,float *locate_matrix){
    for(int i=0;i<w/k;i++)
        for(int j=0;j<h/k;j++){
            int max_num=-999;
            for(int col=i*k;col<(i+1)*k;col++)
                for(int row=j*k;row<(j+1)*k;row++)
                    if(input_matrix[col*h+row]>max_num){
                        max_num=input_matrix[col*h+row];
                        locate_matrix[i*(h/k)+j]=col*h+row;
                    }
            output_matrix[i*(h/k)+j]=max_num;
        }
}

void MatrixExtensionImproved(int w,int h,float *input_matrix1,float *output_matrix){
    MatrixExtensionImproved_label1:for(int i=0;i<w;i++)
        for(int j=0;j<h;j++)
            output_matrix[i*h+j]=input_matrix1[i*h+j];
}

void MatrixMultiply(int h,int h_out,float *input_matrix,float *para_layer,float*output_matrix){
    for(int j=0;j<h_out;j++){
        output_matrix[j]=0;
        for(int i=0;i<h;i++)
            output_matrix[j]+=input_matrix[i]*para_layer[i*h_out+j];
    }
}

void Relu(int h,float *input_matrix,float *output_matrix){
    for(int j=0;j<h;j++)
        output_matrix[j]=max(input_matrix[j],input_matrix[j]*0.05);
}

/**********************************************************************************/

void MatrixBackPropagationMultiply(int w,int h,float *input_matrix,float *grad,float *rgrad){
    for(int i=0;i<w;i++)
        for(int j=0;j<h;j++)
            rgrad[i*h+j]=input_matrix[i]*grad[j];
}

void CalculateMatrixGrad(int w,int h,float *input_matrix,float *grad,float *output_matrix){
    for(int i=0;i<w;i++){
        output_matrix[i]=0;
        for(int j=0;j<h;j++)
            output_matrix[i]+=input_matrix[i*h+j]*grad[j];
    }
}

void ReluBackPropagation(int w,float *input_matrix,float *grad,float *output_matrix){
    for(int i=0;i<w;i++)
        if(input_matrix[i]>0)
            output_matrix[i]=1*grad[i];
        else
            output_matrix[i]=0.05*grad[i];
}

void MaxPooBackPropagation(int w,int h,int k,float *input_matrix,float *output_matrix,float *locate_matrix){
    for(int col=0;col<w;col++)
        for(int low=0;low<h;low++)
            output_matrix[col*h+low]=0;
    int current_locate;
    for(int i=0;i<w/k;i++)
        for(int j=0;j<h/k;j++){
            current_locate = locate_matrix[i*(h/k)+j];
            output_matrix[current_locate]=input_matrix[i*(h/k)+j];
        }
}

void OverturnKernel(int k,float *input_matrix,float *output_matrix){
    for(int i=0;i<k;i++)
        for(int j=0;j<k;j++)
            output_matrix[(k-1-i)*k+(k-1-j)]=input_matrix[i*k+j];
}

void Padding(int w,int stride,float *input_matrix,float *output_matrix){
    Padding_label3:for(int i=0;i<w+2*stride;i++)
        for(int j=0;j<w+2*stride;j++){
            if((i>=stride)&&(j>=stride)&&(i<stride+w)&&(j<stride+w))
                output_matrix[i*(w+2*stride)+j]=input_matrix[(i-stride)*w+(j-stride)];
            else
                output_matrix[i*(w+2*stride)+j]=0;
        }
}

void MatrixBackPropagation(int w,int h,float *input_matrix,float *output_matrix,float lr){
    for(int i=0;i<w;i++)
        for(int j=0;j<h;j++)
            output_matrix[i*h+j]-=lr*input_matrix[i*h+j];
}


/**********************************************************************************/

void forward(){
    Conv2d(30,30,3,mnist_data,conv_kernel_1,conv_out_1);
    MaxPool2d(28,28,2,conv_out_1,max_poo_out_1,max_poo_locate_1);
    Conv2d(14,14,3,max_poo_out_1,conv_kernel_2,conv_out_2);
    MaxPool2d(12,12,2,conv_out_2,max_poo_out_2,max_poo_locate_2);

    MatrixExtensionImproved(6,6,max_poo_out_2,fc_in_1);
    MatrixMultiply(36,20,fc_in_1,fc_hidden_layer1,fc_out_1);
    Relu(20,fc_out_1,fc_in_2_relu1);
    MatrixMultiply(20,10,fc_in_2_relu1,fc_hidden_layer2,fc_out_2);

    float probability_sum=0;	// here£¡£¡£¡
    for(int i=0;i<10;i++)
        probability_sum+=exp(fc_out_2[0][i]);
    for(int j=0;j<10;j++){
        probability_result[j]=exp(fc_out_2[0][j])/probability_sum;
    }
    return ;
}


void backward(int label,float* lr_in){
    float grad_2[10];
    for(int i=0;i<10;i++){
        if(i==label) grad_2[i]=probability_result[i]-1;
        else grad_2[i]=probability_result[i]-0;
    }
    float wgrad_2[300];
    MatrixBackPropagationMultiply(20,10,fc_in_2_relu1,grad_2,wgrad_2);

    float rgrad_1[20];
    CalculateMatrixGrad(20,10,fc_hidden_layer2,grad_2,rgrad_1);
    float grad_1[20];
    ReluBackPropagation(20,fc_out_1,rgrad_1,grad_1);
    float wgrad_1[720];
    MatrixBackPropagationMultiply(36,20,fc_in_1,grad_1,wgrad_1);
    float grad_0[36];
    CalculateMatrixGrad(36,20,fc_hidden_layer1,grad_1,grad_0);


    float *pool_grad_2=grad_0;
    float conv_grad_2[144];
    MaxPooBackPropagation(12,12,2,pool_grad_2,conv_grad_2,max_poo_locate_2);

    float kernel_grad_2[9];
    Conv2d(14,14,12,max_poo_out_1,conv_grad_2,kernel_grad_2);
    float conv_grad_2_padding[256];
    Padding(12,2,conv_grad_2,conv_grad_2_padding);
    float kernel_grad_2_overturn[9];
    OverturnKernel(3,conv_kernel_2,kernel_grad_2_overturn);
    float pool_grad_1[196];
    Conv2d(16,16,3,conv_grad_2_padding,kernel_grad_2_overturn,pool_grad_1);

    float conv_grad_1[784];
    MaxPooBackPropagation(28,28,2,pool_grad_1,conv_grad_1,max_poo_locate_1);
    float kernel_grad_1[9];
    Conv2d(30,30,28,mnist_data,conv_grad_1,kernel_grad_1);


    MatrixBackPropagation(3,3,kernel_grad_1,conv_kernel_1,(*lr_in));
    MatrixBackPropagation(3,3,kernel_grad_2,conv_kernel_2,(*lr_in));
    MatrixBackPropagation(36,20,wgrad_1,fc_hidden_layer1,(*lr_in));
    MatrixBackPropagation(20,10,wgrad_2,fc_hidden_layer2,(*lr_in));
    return;
}

void forw_back(int flag, float *in, float *conv1, float *conv2, float *fc1, float *fc2, float *out, int label, float* lr) {

#pragma HLS INTERFACE s_axilite port=flag bundle=ctrl
#pragma HLS INTERFACE s_axilite port=label bundle=ctrl
#pragma HLS INTERFACE s_axilite port=in bundle=ctrl
#pragma HLS INTERFACE s_axilite port=conv1 bundle=ctrl
#pragma HLS INTERFACE s_axilite port=conv2 bundle=ctrl
#pragma HLS INTERFACE s_axilite port=out bundle=ctrl
#pragma HLS INTERFACE s_axilite port=fc1 bundle=ctrl
#pragma HLS INTERFACE s_axilite port=fc2 bundle=ctrl
#pragma HLS INTERFACE m_axi depth=32 port=in bundle=data
#pragma HLS INTERFACE m_axi depth=32 port=conv1 bundle=data
#pragma HLS INTERFACE m_axi depth=32 port=conv2 bundle=data
#pragma HLS INTERFACE m_axi depth=32 port=out bundle=data
#pragma HLS INTERFACE m_axi depth=32 port=fc1 bundle=data
#pragma HLS INTERFACE m_axi depth=32 port=fc2 bundle=data
#pragma HLS INTERFACE s_axilite port=return bundle=ctrl

	if(flag == 0){
		memcpy(conv_kernel_1, conv1, sizeof(float) * 9);
		memcpy(conv_kernel_2, conv2, sizeof(float) * 9);
		memcpy(fc_hidden_layer1, fc1, sizeof(float) * 36 * 20);
		memcpy(fc_hidden_layer2, fc2, sizeof(float) * 20 * 10);
	}
	else if(flag == 1){
		memcpy(mnist_data, in, sizeof(float) * 30 * 30);
	}
	else if(flag == 2){
		forward();
	}
	else if(flag == 3){
		forward();
		backward(label, lr);
	}
	else if(flag == 4){
		memcpy(out, probability_result, sizeof(float) * 10);
	}
    else {
        memcpy(conv1, conv_kernel_1, sizeof(float) * 9);
        memcpy(conv2, conv_kernel_2, sizeof(float) * 9);
        memcpy(fc1, fc_hidden_layer1, sizeof(float) * 36 * 20);
        memcpy(fc2, fc_hidden_layer2, sizeof(float) * 20 * 10);
    }
}
