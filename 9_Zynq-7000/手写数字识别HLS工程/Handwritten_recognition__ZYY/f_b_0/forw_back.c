#include <math.h>
//para
static float conv_kernel1[3][3] = {0};
//static float conv_kernel12[3][3] = {0};
static float conv_kernel2[3][3] = {0};
//static float conv_kernel22[3][3] = {0};
static float conv_kernel3[3][3] = {0};
//static float conv_kernel32[3][3] = {0};
static float fc_hidden_layer1[576][180] = {0}; //103680
static float fc_hidden_layer2[180][45] = {0}; //8100
static float fc_hidden_layer3[45][10] = {0}; //450

//data
static float mnist_data[30][30] = {0};
static float first_conv1[28][28] = {0};
static float sencond_conv1[26][26] = {0};
static float third_conv1[24][24] = {0};
static float flatten_conv[1][576] = {0};
static float first_fc[1][180] = {0};
static float first_relu[1][180] = {0};
static float second_fc[1][45] = {0};
static float second_relu[1][45] = {0};
static float outmlp[1][10] = {0};
static float result[10] = {0};
static float out_grad[10] = {0};

float max(float a, float b) {
	return (a > b)? a : b;
}

void Conv2d1(,float *input_matrix,float *kernel,float *out_matrix){
    for(int i=0;i<28;i++)
        for(int j=0;j<28;j++){
            out_matrix[i*28+j]=0;
            Conv2d1_label0:for(int row=i;row<i+3;row++)
                for(int col=j;col<j+3;col++)
                    out_matrix[i*28+j]+=input_matrix[row*30+col]*kernel[(row-i)*3+(col-j)];
        }
}

void Conv2d2(float *input_matrix,float *kernel,float *out_matrix){
    for(int i=0;i<28-3+1;i++)
        for(int j=0;j<28-3+1;j++){
            out_matrix[i*(28-3+1)+j]=0;
            Conv2d2_label1:for(int row=i;row<i+3;row++)
                for(int col=j;col<j+3;col++)
                    out_matrix[i*(28-3+1)+j]+=input_matrix[row*28+col]*kernel[(row-i)*3+(col-j)];
        }
}

void Conv2d3(float *input_matrix,float *kernel,float *out_matrix){
    for(int i=0;i<26-3+1;i++)
        for(int j=0;j<26-3+1;j++){
            out_matrix[i*(26-3+1)+j]=0;
            Conv2d3_label2:for(int row=i;row<i+3;row++)
                for(int col=j;col<j+3;col++)
                    out_matrix[i*(26-3+1)+j]+=input_matrix[row*26+col]*kernel[(row-i)*3+(col-j)];
        }
}

void Relu1(float *input_matrix,float *output_matrix){
    Relu1_label0:for(int j=0;j<180;j++)
        output_matrix[j]=max(input_matrix[j],input_matrix[j]*0.05);
}

void Relu2(float *input_matrix,float *output_matrix){
    Relu2_label1:for(int j=0;j<45;j++)
        output_matrix[j]=max(input_matrix[j],input_matrix[j]*0.05);
}

void MatrixExtensionImproved(float *input_matrix1,float *output_matrix){
    for(int i=0;i<24;i++)
        for(int j=0;j<24;j++) {
            output_matrix[i*24+j]=input_matrix1[i*24+j];
        }
}

void MatrixMultiply1(float *input_matrix,float *para_layer,float*output_matrix){
    for(int j=0;j<180;j++){
        output_matrix[j]=0;
        for(int k=0;k<576;k++)
            output_matrix[j]+=input_matrix[k]*para_layer[k*180+j];
    }
}

void MatrixMultiply2(float *input_matrix,float *para_layer,float*output_matrix){
    for(int j=0;j<45;j++){
        output_matrix[j]=0;
        for(int k=0;k<180;k++)
            output_matrix[j]+=input_matrix[k]*para_layer[k*45+j];
    }
}

void MatrixMultiply3(float *input_matrix,float *para_layer,float*output_matrix){
    for(int j=0;j<10;j++){
        output_matrix[j]=0;
        for(int k=0;k<45;k++)
            output_matrix[j]+=input_matrix[k]*para_layer[k*10+j];
    }
}
void Conv2d_b1(float *input_matrix,float *kernel,float *out_matrix){
    for(int i=0;i<26-24+1;i++)
        for(int j=0;j<26-24+1;j++){
            out_matrix[i*(26-24+1)+j]=0;
            Conv2d_b1_label4:for(int row=i;row<i+3;row++)
                for(int col=j;col<j+3;col++)
                    out_matrix[i*(26-24+1)+j]+=input_matrix[row*26+col]*kernel[(row-i)*24+(col-j)];
        }
}
void Conv2d_b2(float *input_matrix,float *kernel,float *out_matrix){
    for(int i=0;i<28-3+1;i++)
        for(int j=0;j<28-3+1;j++){
            out_matrix[i*(28-3+1)+j]=0;
            Conv2d_b2_label5:for(int row=i;row<i+3;row++)
                for(int col=j;col<j+3;col++)
                    out_matrix[i*(28-3+1)+j]+=input_matrix[row*28+col]*kernel[(row-i)*3+(col-j)];
        }
}
void Conv2d_b3(float *input_matrix,float *kernel,float *out_matrix){
    for(int i=0;i<28-26+1;i++)
        for(int j=0;j<28-26+1;j++){
            out_matrix[i*(28-26+1)+j]=0;
            Conv2d_b3_label6:for(int row=i;row<i+3;row++)
                for(int col=j;col<j+3;col++)
                    out_matrix[i*(28-26+1)+j]+=input_matrix[row*28+col]*kernel[(row-i)*26+(col-j)];
        }
}
void Conv2d_b4(float *input_matrix,float *kernel,float *out_matrix){
    for(int i=0;i<30-3+1;i++)
        for(int j=0;j<30-3+1;j++){
            out_matrix[i*(30-3+1)+j]=0;
            Conv2d_b4_label7:for(int row=i;row<i+3;row++)
                for(int col=j;col<j+3;col++)
                    out_matrix[i*(30-3+1)+j]+=input_matrix[row*30+col]*kernel[(row-i)*3+(col-j)];
        }
}
void Conv2d_b5(float *input_matrix,float *kernel,float *out_matrix){
    for(int i=0;i<30-28+1;i++)
        for(int j=0;j<30-28+1;j++){
            out_matrix[i*(30-28+1)+j]=0;
            Conv2d_b5_label8:for(int row=i;row<i+3;row++)
                for(int col=j;col<j+3;col++)
                    out_matrix[i*(30-28+1)+j]+=input_matrix[row*30+col]*kernel[(row-i)*28+(col-j)];
        }
}

void MatrixBackPropagationMultiply1(float *para,float *grad,float *rgrad){
    for(int i=0;i<45;i++)
        for(int j=0;j<10;j++)
            rgrad[i*10+j]=para[i]*grad[j];

}

void MatrixBackPropagationMultiply2(float *para,float *grad,float *rgrad){
    for(int i=0;i<180;i++)
        for(int j=0;j<45;j++)
            rgrad[i*45+j]=para[i]*grad[j];

}

void MatrixBackPropagationMultiply3(float *para,float *grad,float *rgrad){
    for(int i=0;i<576;i++)
        for(int j=0;j<180;j++)
            rgrad[i*180+j]=para[i]*grad[j];
}


void CalculateMatrixGrad1(float *input_matrix,float *grad,float *output_matrix){
    for(int i=0;i<45;i++){
        output_matrix[i]=0;
        for(int j=0;j<10;j++){
            output_matrix[i]+=input_matrix[i*10+j]*grad[j];
        }
    }
}
void CalculateMatrixGrad2(float *input_matrix,float *grad,float *output_matrix){
    for(int i=0;i<180;i++){
        output_matrix[i]=0;
        for(int j=0;j<45;j++){
            output_matrix[i]+=input_matrix[i*45+j]*grad[j];
        }
    }
}
void CalculateMatrixGrad3(float *input_matrix,float *grad,float *output_matrix){
    for(int i=0;i<576;i++){
        output_matrix[i]=0;
        for(int j=0;j<180;j++){
            output_matrix[i]+=input_matrix[i*180+j]*grad[j];
        }
    }
}

void ReluBackPropagation1(float *input_matrix,float *grad,float *output_matrix){
    for(int i=0;i<45;i++){
        if(input_matrix[i]>0) output_matrix[i]=1*grad[i];
        else output_matrix[i]=0.05*grad[i];
    }
}
void ReluBackPropagation2(float *input_matrix,float *grad,float *output_matrix){
    for(int i=0;i<180;i++){
        if(input_matrix[i]>0) output_matrix[i]=1*grad[i];
        else output_matrix[i]=0.05*grad[i];
    }
}

void Padding1(float *input_matrix,float *output_matrix){
    for(int i=0;i<26+2;i++)
        for(int j=0;j<26+2;j++)
            output_matrix[i*(26+2)+j]=0;
}
void Padding2(float *input_matrix,float *output_matrix){
    for(int i=0;i<24+2;i++)
        for(int j=0;j<24+2;j++)
            output_matrix[i*(24+2)+j]=0;
}

void OverturnKernel(float *input_matrix,float *output_matrix){
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            output_matrix[(3-1-i)*3+(3-1-j)]=input_matrix[i*3+j];
}

void MatrixSplit(float *input_matrix,float *splited_matrix1){
    for(int idx=0;idx<576;idx++){
        splited_matrix1[idx]=input_matrix[idx];
    }
}

void backward(int label, float *conv1, float *conv2, float *conv3, float *fc1, float *fc2, float *fc3, float* lr_in){
    for(int i=0;i<10;i++) {
        if(i==label) out_grad[i]=result[i]-1;
        else out_grad[i]=result[i]-0;
    }

    float out_wgrad[450];
    MatrixBackPropagationMultiply1(second_relu,out_grad,out_wgrad);

    float second_rgrad[45];
    CalculateMatrixGrad1(fc_hidden_layer3,out_grad,second_rgrad);
    float second_grad[180];
    ReluBackPropagation1(second_fc,second_rgrad,second_grad);
    float second_wgrad[8100];
    MatrixBackPropagationMultiply2(first_relu,second_grad,second_wgrad);

    
    float first_rgrad[180];
    CalculateMatrixGrad2(fc_hidden_layer2,second_grad,first_rgrad);
    float first_grad[180];
    ReluBackPropagation2(first_fc,first_rgrad,first_grad);
    float first_wgrad[103680];
    MatrixBackPropagationMultiply3(flatten_conv,first_grad,first_wgrad);
    float third_conv_grad1[576];
    CalculateMatrixGrad3(fc_hidden_layer1,first_grad,third_conv_grad1);

    float third_kernel_grad[9];
    Conv2d_b1(sencond_conv1,third_conv_grad1,third_kernel_grad);
    float second_conv_grad1[676];
    float third_kernel_overturn[9];
    OverturnKernel(conv_kernel3,third_kernel_overturn);
    float third_conv_grad_padding1[784];
    Padding1(third_conv_grad1,third_conv_grad_padding1);
    Conv2d_b2(third_conv_grad_padding1,third_kernel_overturn,second_conv_grad1);
    float second_kernel_grad[9];
    Conv2d_b3(first_conv1,second_conv_grad1,second_kernel_grad);
    float first_conv_grad[784];
    float second_kernel_overturn[9];
    OverturnKernel(conv_kernel2,second_kernel_overturn);
    float second_conv_grad_padding1[900];
    Padding2(second_conv_grad1,second_conv_grad_padding1);
    Conv2d_b4(second_conv_grad_padding1,second_kernel_overturn,first_conv_grad);
    float first_kernel_grad[9];
    Conv2d_b5(mnist_data,first_conv_grad,first_kernel_grad);

    float lr[1];
    memcpy(lr, lr_in, sizeof(float));
    int m = 0;
    int n = 0;
    for(m = 0; m < 3; m++) {
    	for(n = 0; n < 3; n++) {
    		conv_kernel1[m][n] -= lr[0] * first_kernel_grad[m * 3 + n];
    		conv_kernel2[m][n] -= lr[0] * second_kernel_grad[m * 3 + n];
    		conv_kernel3[m][n] -= lr[0] * third_kernel_grad[m * 3 + n];
    	}
    }
    for(m = 0; m < 576; m++) {
    	for(n = 0; n < 180; n++) {
    		fc_hidden_layer1[m][n] -= lr[0] * first_wgrad[m * 576 + n];
    	}
    }
    for(m = 0; m < 180; m++) {
		for(n = 0; n < 45; n++) {
			fc_hidden_layer2[m][n] -= lr[0] * second_wgrad[m * 180 + n];
		}
	}
    for(m = 0; m < 45; m++) {
		for(n = 0; n < 10; n++) {
			fc_hidden_layer3[m][n] -= lr[0] * out_wgrad[m * 45 + n];
		}
	}
    memcpy(conv1, conv_kernel1, sizeof(float) * 9);
    memcpy(conv2, conv_kernel2, sizeof(float) * 9);
    memcpy(conv3, conv_kernel3, sizeof(float) * 9);
    memcpy(fc1, fc_hidden_layer1, sizeof(float) * 103680);
    memcpy(fc2, fc_hidden_layer2, sizeof(float) * 8100);
    memcpy(fc3, fc_hidden_layer3, sizeof(float) * 450);
}

void forward(float *input_matrix, float *conv1, float *conv2, float *conv3, float *fc1, float *fc2, float *fc3){
	memcpy(mnist_data, input_matrix, sizeof(float) * 30 * 30);
    memcpy(conv_kernel1, conv1, sizeof(float) * 9);
    memcpy(conv_kernel2, conv2, sizeof(float) * 9);
    memcpy(conv_kernel3, conv3, sizeof(float) * 9);
    data1:{
		Conv2d1(mnist_data,conv_kernel1,first_conv1);
		Conv2d2(first_conv1,conv_kernel2,sencond_conv1);
		Conv2d3(sencond_conv1,conv_kernel3,third_conv1);
    }

    memcpy(fc_hidden_layer1, fc1, sizeof(float) * 576 * 180);
    memcpy(fc_hidden_layer2, fc2, sizeof(float) * 180 * 45);
    memcpy(fc_hidden_layer3, fc3, sizeof(float) * 45 * 10);
    MatrixExtensionImproved(third_conv1,flatten_conv);
    data2:{
    	MatrixMultiply1(flatten_conv,fc_hidden_layer1,first_fc);
		Relu1(first_fc,first_relu);
		MatrixMultiply2(first_relu,fc_hidden_layer2,second_fc);
		Relu2(second_fc,second_relu);
		MatrixMultiply3(second_relu,fc_hidden_layer3,outmlp);
    }
}

void forw_back(int flag, float *in, float *conv1, float *conv2, float *conv3, float *fc1, float *fc2, float *fc3, float *out, int label, float* lr) {

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
        forward(in, conv1, conv2, conv3, fc1, fc2, fc3);
        memcpy(out, outmlp, sizeof(float) * 10);
    }
    else {
    	forward(in, conv1, conv2, conv3, fc1, fc2, fc3);
    	float probability = 0;
    	for(int j = 0; j < 10; j++) {
    		probability += exp(outmlp[0][j]);
    	}
    	for(int i=0;i<10;i++){
			result[i]=exp(outmlp[0][i])/probability;
		}
    	memcpy(out, result, sizeof(float) * 10);
        backward(label, conv1, conv2, conv3, fc1, fc2, fc3, lr);
    }
}
