#include <math.h>
#include <string.h>

static float conv_out_1[28][28];
static float conv_out_2[26][26];
static float conv_out_3[24][24];

static float fc_in_1[1][576];
static float fc_out_1[1][180];
static float fc_in_2_relu1[1][180];
static float fc_out_2[1][45];
static float fc_in_3_relu2[1][45];
static float fc_out_3[1][10];

float max(float a, float b) {
	return (a > b)? a : b;
}

void Conv2d(int w,int h,int k,float *input_matrix,float *kernel,float *out_matrix){
    for(int i=0;i<w-k+1;i++)
        for(int j=0;j<h-k+1;j++){
            out_matrix[i*(h-k+1)+j]=0;
            Conv2d_label0:for(int col=i;col<i+3;col++)
                for(int row=j;row<j+3;row++)
                    out_matrix[i*(h-k+1)+j]+=input_matrix[col*h+row]*kernel[(col-i)*k+(row-j)];
        }
}

void MatrixExtensionImproved(int w,int h,float *input_matrix1,float *output_matrix){
    for(int i=0;i<w;i++)
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

void OverturnKernel(int k,float *input_matrix,float *output_matrix){
    for(int i=0;i<k;i++)
        for(int j=0;j<k;j++)
            output_matrix[(k-1-i)*k+(k-1-j)]=input_matrix[i*k+j];
}

void Padding(int w,int stride,float *input_matrix,float *output_matrix){
    for(int i=0;i<w+2*stride;i++)
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

void forward(float *mnist_data,float *conv_kernel_1,float *conv_kernel_2,float *conv_kernel_3,float *fc_hidden_layer1,float *fc_hidden_layer2,float *fc_hidden_layer3,float *probability_result){
    Conv2d(30,30,3,mnist_data,conv_kernel_1,conv_out_1);
    Conv2d(28,28,3,conv_out_1,conv_kernel_2,conv_out_2);
    Conv2d(26,26,3,conv_out_2,conv_kernel_3,conv_out_3);

    MatrixExtensionImproved(24,24,conv_out_3,fc_in_1);
    MatrixMultiply(576,180,fc_in_1,fc_hidden_layer1,fc_out_1);
    Relu(180,fc_out_1,fc_in_2_relu1);
    MatrixMultiply(180,45,fc_in_2_relu1,fc_hidden_layer2,fc_out_2);
    Relu(45,fc_out_2,fc_in_3_relu2);
    MatrixMultiply(45,10,fc_in_3_relu2,fc_hidden_layer3,fc_out_3);

    float probability_sum=0;
    for(int i=0;i<10;i++){
        probability_sum+=exp(fc_out_3[0][i]);
    }
    for(int j=0;j<10;j++){
        probability_result[j]=exp(fc_out_3[0][j])/probability_sum;
    }
    return;
}

void backward(float *mnist_data,float *conv_kernel_1,float *conv_kernel_2,float *conv_kernel_3,float *fc_hidden_layer1,float *fc_hidden_layer2,float *fc_hidden_layer3,float *probability_result,int label,float* lr_in){
    float grad_3[10];
    for(int i=0;i<10;i++)
        if(i==label) grad_3[i]=probability_result[i]-1;
        else grad_3[i]=probability_result[i]-0;

    float wgrad_3[450];
    MatrixBackPropagationMultiply(45,10,fc_in_3_relu2,grad_3,wgrad_3);

    float rgrad_2[45];
    CalculateMatrixGrad(45,10,fc_hidden_layer3,grad_3,rgrad_2);
    float grad_2[180];
    ReluBackPropagation(45,fc_out_2,rgrad_2,grad_2);
    float wgrad_2[8100];
    MatrixBackPropagationMultiply(180,45,fc_in_2_relu1,grad_2,wgrad_2);

    float rgrad_1[180];
    CalculateMatrixGrad(180,45,fc_hidden_layer2,grad_2,rgrad_1);
    float grad_1[180];
    ReluBackPropagation(180,fc_out_1,rgrad_1,grad_1);
    float wgrad_1[103680];
    MatrixBackPropagationMultiply(576,180,fc_in_1,grad_1,wgrad_1);

    float grad_0[576];
    CalculateMatrixGrad(576,180,fc_hidden_layer1,grad_1,grad_0);

    float *conv_grad_3=grad_0;
    float kernel_grad_3[9];
    Conv2d(26,26,24,conv_out_2,conv_grad_3,kernel_grad_3);
    float conv_grad_2[676];
    float kernel_grad_3_overturn[9];
    OverturnKernel(3,conv_kernel_3,kernel_grad_3_overturn);
    float conv_grad_3_padding[784];
    Padding(24,2,conv_grad_3,conv_grad_3_padding);
    Conv2d(28,28,3,conv_grad_3_padding,kernel_grad_3_overturn,conv_grad_2);

    float kernel_grad_2[9];
    Conv2d(28,28,26,conv_out_1,conv_grad_2,kernel_grad_2);
    float conv_grad_1[784];
    float kernel_grad_2_overturn[9];
    OverturnKernel(3,conv_kernel_2,kernel_grad_2_overturn);
    float conv_grad_2_padding[900];
    Padding(26,2,conv_grad_2,conv_grad_2_padding);
    Conv2d(30,30,3,conv_grad_2_padding,kernel_grad_2_overturn,conv_grad_1);

    float kernel_grad_1[9];
    Conv2d(30,30,28,mnist_data,conv_grad_1,kernel_grad_1);

    MatrixBackPropagation(3,3,kernel_grad_1,conv_kernel_1,(*lr_in));
    MatrixBackPropagation(3,3,kernel_grad_2,conv_kernel_2,(*lr_in));
    MatrixBackPropagation(3,3,kernel_grad_3,conv_kernel_3,(*lr_in));

    MatrixBackPropagation(576,180,wgrad_1,fc_hidden_layer1,(*lr_in));
    MatrixBackPropagation(180,45,wgrad_2,fc_hidden_layer2,(*lr_in));
    MatrixBackPropagation(45,10,wgrad_3,fc_hidden_layer3,(*lr_in));
    return;
}

void forw_back_LTL(int flag, float *in, float *conv1, float *conv2, float *conv3, float *fc1, float *fc2, float *fc3, float *out, int label, float* lr) {

#pragma HLS INTERFACE s_axilite port=flag bundle=ctrl
#pragma HLS INTERFACE s_axilite port=label bundle=ctrl
#pragma HLS INTERFACE s_axilite port=in bundle=ctrl
#pragma HLS INTERFACE s_axilite port=conv1 bundle=ctrl
#pragma HLS INTERFACE s_axilite port=conv2 bundle=ctrl
#pragma HLS INTERFACE s_axilite port=conv3 bundle=ctrl
#pragma HLS INTERFACE s_axilite port=out bundle=ctrl
#pragma HLS INTERFACE s_axilite port=fc1 bundle=ctrl
#pragma HLS INTERFACE s_axilite port=fc2 bundle=ctrl
#pragma HLS INTERFACE s_axilite port=fc3 bundle=ctrl
#pragma HLS INTERFACE m_axi depth=32 port=in bundle=data
#pragma HLS INTERFACE m_axi depth=32 port=conv1 bundle=data
#pragma HLS INTERFACE m_axi depth=32 port=conv2 bundle=data
#pragma HLS INTERFACE m_axi depth=32 port=conv3 bundle=data
#pragma HLS INTERFACE m_axi depth=32 port=out bundle=data
#pragma HLS INTERFACE m_axi depth=32 port=fc1 bundle=data
#pragma HLS INTERFACE m_axi depth=32 port=fc2 bundle=data
#pragma HLS INTERFACE m_axi depth=32 port=fc3 bundle=data
#pragma HLS INTERFACE s_axilite port=return bundle=ctrl

	if(flag == 0) {
        forward(in,conv1,conv2,conv3,fc1,fc2,fc3,out);
    }
    else {
    	forward(in,conv1,conv2,conv3,fc1,fc2,fc3,out);
        backward(in,conv1,conv2,conv3,fc1,fc2,fc3,out,label,lr);
    }
}
