#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#define max(a,b)(((a)>(b))?(a):(b))
#define SAMPLE_NUM 30//�궨�����������
float lr;
float result[10];//���ͨ��softmax����Ľ��

struct parameter{
    float conv_kernel11[3][3];
    float conv_kernel21[3][3];
    float conv_kernel31[3][3];
    float fc_hidden_layer1[576][180];
    float fc_hidden_layer2[180][45];
    float fc_hidden_layer3[45][10];
};

//������ÿһ��ĳߴ�
struct result{
    float mnist_data[30][30];
    //ͨ��һ
    float first_conv1[28][28];
    float sencond_conv1[26][26];
    float third_conv1[24][24];
    //ȫ����
    float flatten_conv[1][576];//�ϲ�����ͨ��
    float first_fc[1][180];//��һ��ȫ�������
    float first_relu[1][180];//��һ�㼤������
    float second_fc[1][45];//�ڶ���ȫ�������
    float second_relu[1][45];//�ڶ��㼤������
    float outmlp[1][10];//ȫ���ӵ����
    float result[10];//Softmax�����
};

//ѵ�����ṹ�壬ѵ������30*30
struct input{
    float a[10][SAMPLE_NUM][30][30];//[��ǩ][��������][w][h]
};

//����ÿһ��ͼƬ�Ľṹ��
struct sample{
    float a[30][30];//data
    int number;//label
}Sample[SAMPLE_NUM*10];

//�������,����˴�СΪk*k
void Conv2d(int w,int h,int k,float *input_matrix,float *kernel,float *out_matrix){
    for(int i=0;i<w-k+1;i++)
        for(int j=0;j<h-k+1;j++){
            out_matrix[i*(w-k+1)+j]=0;
            for(int row=i;row<i+3;row++)
                for(int col=j;col<j+3;col++)
                    out_matrix[i*(w-k+1)+j]+=input_matrix[row*w+col]*kernel[(row-i)*k+(col-j)];
        }
}

//���ػ��������ػ��˴�СΪk*k
void MaxPool2d(int w,int h,int k,float *input_matrix,float *output_matrix){
    for(int i=0;i<w/k;i++)
        for(int j=0;j<h/k;j++){
            int max_num=-999;
            for(int row=k*i;row<k*i+k;row++)
                for(int col=k*j;col<k*j+k;col++)
                    if(input_matrix[row*w+col]>max_num)
                        max_num=input_matrix[row*w+col];
            output_matrix[i*(w/2)+j]=max_num;
        }
}

//��LeakyRelu����Relu�������ݶ���ɢ
void Relu(int w,int h,float *input_matrix,float *output_matrix){
    for(int i=0;i<w;i++)
        for(int j=0;j<h;j++)
            output_matrix[i*w+j]=max(input_matrix[i*w+j],input_matrix[i*w+j]*0.05);
}

//����ͼ��ƽ����concat
void MatrixExtensionImproved(int w,int h,float *input_matrix1,float *output_matrix){
    for(int i=0;i<w;i++)
        for(int j=0;j<h;j++)
            output_matrix[i*w+j]=input_matrix1[i*w+j];//��ͨ��һ������ͼ������뵽output_matrix
}

//ȫ���ӵľ���˷�
void MatrixMultiply(int w,int h,int out_deminsion,float *input_matrix,float *para_layer,float*output_matrix){
    for(int i=0;i<w;i++)
        for(int j=0;j<out_deminsion;j++){
            output_matrix[i*w+j]=0;
            for(int k=0;k<h;k++)
                output_matrix[i*w+j]+=input_matrix[i*w+k]*para_layer[k*out_deminsion+j];
        }
}

//��ȫ���ӷ��򴫲��������ݶȲ�����������뵽����channel��
// void MatrixSplit(float *input_matrix,float *splited_matrix1,float *splited_matrix2){
//     for(int idx=0;idx<1152;idx++)
//         if(idx<576)
//             splited_matrix1[idx]=input_matrix[idx];
//         else
//             splited_matrix2[idx-576]=input_matrix[idx];
// }

//��ȫ���ӷ��򴫲��������ݶȲ�����������뵽����channel��
void MatrixSplit(float *input_matrix,float *splited_matrix1){
    for(int idx=0;idx<576;idx++){
        splited_matrix1[idx]=input_matrix[idx];
        //splited_matrix2[idx]=input_matrix[idx+576];
    }
}

//�����������
void MatrixBackPropagation(int w,int h,float *input_matrix,float *output_matrix){
    for(int i=0;i<w;i++)
        for(int j=0;j<h;j++)
            output_matrix[i*h+j]-=lr*input_matrix[i*h+j];
}

//���򴫲�ʱ�ľ���˷�
void MatrixBackPropagationMultiply(int w,int h,float *para,float *grad,float *rgrad){
    for(int i=0;i<w;i++)
        for(int j=0;j<h;j++)
            rgrad[i*h+j]=para[i]*grad[j];

}

//���㵱ǰ��Ĳ���������ݶ�,����ǰһ����Ԫ�ݶ��о���˱�����Ԫ�ݶ��о���,�õ���������ݶ�
void CalculateMatrixGrad(int w,int h,float *input_matrix,float *grad,float *output_matrix){
    for(int i=0;i<w;i++){
        output_matrix[i]=0;//�ݶ���գ������ۼ�
        for(int j=0;j<h;j++){
            output_matrix[i]+=input_matrix[i*h+j]*grad[j];
        }
    }
}

//������ķ��򴫲�
void ReluBackPropagation(int w,float *input_matrix,float *grad,float *output_matrix){
    for(int i=0;i<w;i++)
        if(input_matrix[i]>0) output_matrix[i]=1*grad[i];
        else output_matrix[i]=0.05*grad[i];
}

//���򴫲�ʱ���ݶȽ�����䣬��w*h��Ϊ(w+2*stride)*(h+2*stride)
void Padding(int w,int stride,float *input_matrix,float *output_matrix){
    for(int i=0;i<w+2*stride;i++)
        for(int j=0;j<w+2*stride;j++)
            output_matrix[i*(w+2*stride)+j]=0;//��������ʼ��
//    for(int i=0;i<w;i++)
//        for(int j=0;j<w;j++)
//            output_matrix[(i+stride)*(w+2*stride)+(j+stride)]=input_matrix[i*w+j];
}

//���ھ���˷�ת180���ǡ���ǵ�����ʽ���ʽ��з�ת������򴫲��������ݶ����
void OverturnKernel(int k,float *input_matrix,float *output_matrix){
    for(int i=0;i<k;i++)
        for(int j=0;j<k;j++)
            output_matrix[(k-1-i)*k+(k-1-j)]=input_matrix[i*k+j];
}

//�ͷ��ڴ�
void MemoryFree(float *x){
    free(x);
    x=NULL;
}

//ʹ���������ʼ���������
void init(struct parameter *para){
    srand(time(NULL));
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            para->conv_kernel11[i][j]=(rand()/(RAND_MAX+1.0));
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            para->conv_kernel21[i][j]=(rand()/(RAND_MAX+1.0))/5;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            para->conv_kernel31[i][j]=(rand()/(RAND_MAX+1.0))/5;
    for(int i=0;i<576;i++)
        for(int j=0;j<180;j++)
            para->fc_hidden_layer1[i][j]=(rand()/(RAND_MAX+1.0))/1000;
    for(int i=0;i<180;i++)
        for(int j=0;j<45;j++)
            para->fc_hidden_layer2[i][j]=(rand()/(RAND_MAX+1.0))/100;
    for(int i=0;i<45;i++)
        for(int j=0;j<10;j++)
            para->fc_hidden_layer3[i][j]=(rand()/(RAND_MAX+1.0))/10;
}

//ǰ�򴫲�������������������ȫ����
void forward(float *input_matrix,struct parameter* para,struct result* data){
    Conv2d(30,30,3,input_matrix,&para->conv_kernel11[0][0],&data->first_conv1[0][0]);
    Conv2d(28,28,3,&data->first_conv1[0][0],&para->conv_kernel21[0][0],&data->sencond_conv1[0][0]);
    Conv2d(26,26,3,&data->sencond_conv1[0][0],&para->conv_kernel31[0][0],&data->third_conv1[0][0]);//��һ��ͨ���õ�24*24������ͼ

    MatrixExtensionImproved(24,24,&data->third_conv1[0][0],&data->flatten_conv[0][0]);
    MatrixMultiply(1,576,180,&data->flatten_conv[0][0],&para->fc_hidden_layer1[0][0],&data->first_fc[0][0]);
    Relu(1,180,&data->first_fc[0][0],&data->first_relu[0][0]);
    MatrixMultiply(1,180,45,&data->first_relu[0][0],&para->fc_hidden_layer2[0][0],&data->second_fc[0][0]);
    Relu(1,45,&data->second_fc[0][0],&data->second_relu[0][0]);
    MatrixMultiply(1,45,10,&data->second_relu[0][0],&para->fc_hidden_layer3[0][0],&data->outmlp[0][0]);

    float probability;
    for(int i=0;i<10;i++)
        probability+=exp(data->outmlp[0][i]);
    for(int i=0;i<10;i++){
        data->result[i]=exp(data->outmlp[0][i])/probability;
        result[i]=data->result[i];
    }
    return;
}

//���򴫲��������ݶ�
void backward(int label,struct parameter* para,struct result* data){
    /****************************************************************************************
     * grad��β�ı�������ÿһ����ݶ�
     * wgrad��β�ı�������ÿһ��Ĳ������ݶ�
     * rgrad��β�Ĵ���������ݶ�
     * ������ṹ������ͨ���ľ��������ȫ���ӣ�ÿ��ͨ�����������㣬�޳ػ��㣬����ʹ�������ʱ���
    ****************************************************************************************/
    int float_len=sizeof(float);
    float *out_grad;
    out_grad=(float*)malloc(10*float_len);//����������10��float����
    //��������ʧ�����󵼽��Ϊy_hat_i-y_i
    for(int i=0;i<10;i++)
        if(i==label) out_grad[i]=data->result[i]-1;
        else out_grad[i]=data->result[i]-0;
    //����ȫ���Ӳ�ķ��򴫲�
    
    //������ȫ���ӷ��򴫲� out_wgrad
    float *out_wgrad;
    out_wgrad=(float*)malloc(450*float_len);
    MatrixBackPropagationMultiply(45,10,&data->second_relu[0][0],out_grad,out_wgrad);//��ڶ������

    //�ڶ���ȫ���ӷ��򴫲�
    float *second_rgrad;
    second_rgrad=(float*)malloc(45*float_len);
    CalculateMatrixGrad(45,10,&para->fc_hidden_layer3[0][0],out_grad,second_rgrad);//�������ˣ���loss��
    MemoryFree(out_grad);
    float *second_grad;
    second_grad=(float*)malloc(180*float_len);
    ReluBackPropagation(45,&data->second_fc[0][0],second_rgrad,second_grad);//��ڶ����м�������loss
    MemoryFree(second_rgrad);
    float *second_wgrad;
    second_wgrad=(float*)malloc(8100*float_len);
    MatrixBackPropagationMultiply(180,45,&data->first_relu[0][0],second_grad,second_wgrad);//���һ����������loss

    //��һ��ȫ���ӷ��򴫲�
    float *first_rgrad;
    first_rgrad=(float*)malloc(180*float_len);
    CalculateMatrixGrad(180,45,&para->fc_hidden_layer2[0][0],second_grad,first_rgrad);
    MemoryFree(second_grad);
    float *first_grad;
    first_grad=(float*)malloc(180*float_len);
    ReluBackPropagation(180,&data->first_fc[0][0],first_rgrad,first_grad);
    MemoryFree(first_rgrad);
    float *first_wgrad;
    first_wgrad=(float*)malloc(103680*float_len);
    MatrixBackPropagationMultiply(576,180,&data->flatten_conv[0][0],first_grad,first_wgrad);
    float *all_conv_grad;
    all_conv_grad=(float*)malloc(576*float_len);
    CalculateMatrixGrad(576,180,&para->fc_hidden_layer1[0][0],first_grad,all_conv_grad);
    MemoryFree(first_grad);
    //ͨ��һ
    float *third_conv_grad1;
    third_conv_grad1=(float*)malloc(576*float_len);
    float *third_conv_grad2;
    third_conv_grad2=(float*)malloc(576*float_len);
    MatrixSplit(all_conv_grad,third_conv_grad1);
    MemoryFree(all_conv_grad);
    float *third_kernel_grad;
    third_kernel_grad=(float*)malloc(9*float_len);
    Conv2d(26,26,24,&data->sencond_conv1[0][0],third_conv_grad1,third_kernel_grad);
    float *second_conv_grad1;
    second_conv_grad1=(float*)malloc(676*float_len);
    float *third_kernel_overturn;
    third_kernel_overturn=(float*)malloc(9*float_len);
    OverturnKernel(3,&para->conv_kernel31[0][0],third_kernel_overturn);
    float *third_conv_grad_padding1;
    third_conv_grad_padding1=(float*)malloc(784*float_len);
    Padding(26,1,third_conv_grad1,third_conv_grad_padding1);
    MemoryFree(third_conv_grad1);
    Conv2d(28,28,3,third_conv_grad_padding1,third_kernel_overturn,second_conv_grad1);
    MemoryFree(third_kernel_overturn);
    MemoryFree(third_conv_grad_padding1);
    float *second_kernel_grad;
    second_kernel_grad=(float*)malloc(9*float_len);
    Conv2d(28,28,26,&data->first_conv1[0][0],second_conv_grad1,second_kernel_grad);
    float *first_conv_grad;
    first_conv_grad=(float*)malloc(784*float_len);
    float *second_kernel_overturn;
    second_kernel_overturn=(float*)malloc(9*float_len);
    OverturnKernel(3,&para->conv_kernel21[0][0],second_kernel_overturn);
    float *second_conv_grad_padding1;
    second_conv_grad_padding1=(float*)malloc(900*float_len);
    Padding(28,1,second_conv_grad1,second_conv_grad_padding1);
    MemoryFree(second_conv_grad1);
    Conv2d(30,30,3,second_conv_grad_padding1,second_kernel_overturn,first_conv_grad);
    MemoryFree(second_kernel_overturn);
    MemoryFree(second_conv_grad_padding1);
    float *first_kernel_grad;
    first_kernel_grad=(float*)malloc(9*float_len);
    Conv2d(30,30,28,&data->mnist_data[0][0],first_conv_grad,first_kernel_grad);
    MemoryFree(first_conv_grad);

    //ͨ��һ���²���
    MatrixBackPropagation(3,3,first_kernel_grad,&para->conv_kernel11[0][0]);
    MatrixBackPropagation(3,3,second_kernel_grad,&para->conv_kernel21[0][0]);
    MatrixBackPropagation(3,3,third_kernel_grad,&para->conv_kernel31[0][0]);
    //printf("%f\n", first_conv_grad[0]);
    //ȫ���Ӳ���²���
    MatrixBackPropagation(576,180,first_wgrad,&para->fc_hidden_layer1[0][0]);
    MatrixBackPropagation(180,45,second_wgrad,&para->fc_hidden_layer2[0][0]);
    MatrixBackPropagation(45,10,out_wgrad,&para->fc_hidden_layer3[0][0]);
    //����ڴ�
    MemoryFree(first_kernel_grad);
    MemoryFree(second_kernel_grad);
    MemoryFree(third_kernel_grad);
    MemoryFree(first_wgrad);
    MemoryFree(second_wgrad);
    MemoryFree(out_wgrad);
    return;
}

//��ͼƬ����ȡ����
int DataLoader(){
    for(int num=0;num<10;num++){
        for(int i=0;i<SAMPLE_NUM;i++){
            //����char��������ȡͼƬ���ݣ���ת��Ϊint��
            char(*e);
            int(*l);
            e=(char*)malloc(sizeof(char)*120);
            l=(int*)malloc(sizeof(int)*960);

            char route_name1[5];
            char route_name2[30]="Training_set\\";
            sprintf(route_name1,"%d%s",num,"\\");
            strcat(route_name2,route_name1);

            FILE *fp;
            char file_name1[10];
            sprintf(file_name1,"%d%s",i+1,".bmp");//ͨ��i++ѭ��������ȡ�ļ�
		    strcat(route_name2,file_name1);
		    fp=fopen(route_name2,"rb");

            if(fp==NULL){
                printf("ѵ������ʧ�ܣ�����Training_set�ļ����Ƿ�����Լ�ѵ��ͼƬ�Ƿ�������\n");
			    return 1;
            }
            fseek(fp,62,SEEK_SET);//bmp��ɫλͼ�������ݴ�62���ֽڴ���ʼ
            fread(e,sizeof(char),120,fp);//������������char�͵ĸ�ʽ����e������
            fclose(fp);

            int y=0;
            for(int r=0;r<120;r++){
                for(int u=1;u<9;u++){
                    l[y]=(int)(((e[r])) >> (8-u) & 0x01);//��ÿһ��char�����ݲ𿪳�01���ݴ�ŵ�����l��
                    y++;
                    if(y>960)
                        break;
                }
            }
            int g=0;
            for(int u=0;u<30;u++){
                y=0;
                for(int j=0;j<32;j++){
                    if((j!=30)&&(j!=31)){Sample[num*SAMPLE_NUM+i].a[u][y]=l[g];y++;};//ȥ��windows�Զ���0�����ݣ������������ݴ�ŵ������ṹ����
				    g++;
                }
            }
            int q=Sample[num*SAMPLE_NUM+i].a[0][0];
		    if(q==1){
                int n=0;
                int z=0;
                for(int b=0;b<30;b++){
                    n=0;
                    for(;;){
                        if(n>=30)break;
                        if(Sample[num*SAMPLE_NUM+i].a[z][n]==0)Sample[num*SAMPLE_NUM+i].a[z][n]=1;
                        else if(Sample[num*SAMPLE_NUM+i].a[z][n]==1)Sample[num*SAMPLE_NUM+i].a[z][n]=0;
                        n++;
                    }
                    z++;
                }
            }
            Sample[num*SAMPLE_NUM+i].number=num;//���������ǩ
            free(e);
            e=NULL;
            free(l);
            l=NULL;
        }
    }
    return 0;
}

//ѵ��ǰ��ȡ�������
int read_file(struct parameter* parameter4){
    FILE*fp;
    fp=fopen("Training_set//Network_parameter.bin","rb");
    if(fp==NULL)
    {
        printf("�ļ���ʧ�ܣ�������������ļ��Ƿ���ѵ�����ļ����ڣ�\n");
        return 1;
    }
    struct parameter* parameter1;
    parameter1=(struct parameter*)malloc(sizeof(struct parameter));
    fread(parameter1,sizeof(struct parameter),1,fp);
    (*parameter4)=(*parameter1);
    fclose(fp);
    free(parameter1);
    parameter1=NULL;
    return 0;
}

//ѵ�������󱣴��������
void printf_file(struct parameter* parameter4){
    FILE*fp;
    fp=fopen("Training_set//Network_parameter.bin","wb");//���ö����Ƹ�ʽ������������ڶ�ȡ
    struct parameter* parameter1;
    parameter1=(struct parameter*)malloc(sizeof(struct parameter));
    (*parameter1)=(*parameter4);
    fwrite(parameter1,sizeof(struct parameter),1,fp);//��ӡ����ṹ��
    fclose(fp);
    free(parameter1);
    parameter1=NULL;
    return;
}

//ѵ�������е����Ų�����ӡ����
void printf_file2(struct parameter* parameter4){
    FILE*fp;
    fp=fopen("NetworkParameters.bin","wb");
    struct parameter* parameter1;
    parameter1=(struct parameter*)malloc(sizeof(struct parameter));
    (*parameter1)=(*parameter4);
    fwrite(parameter1,sizeof(struct parameter),1,fp);//���ָ�롢��С���������ļ�ָ��
    fclose(fp);
    free(parameter1);
    parameter1=NULL;
    return;
};

//��������ʧ����
float Cross_entropy(float *a,int m){
    float u=0;
    u=(-log10(a[m]));
    return u;
}

//����ѵ�����֣���ȡ��ͼ�����ݽ���ǰ�򴫲���ѵ��
void train(int epochs,struct parameter *para,struct result *data){
    printf("����train������\n");
    float corss_loss=2;//����ÿ��ѵ������󽻲���
    for(int epoch=0;epoch<epochs;epoch++){
        //printf("hhhh");
        lr=pow((corss_loss/10),1.7);
        if(lr>0.01) lr=0.01;
        if((epoch+1)%10==0){
            printf("ѵ������: %lf",100*((float)(epoch+1)/(float)epochs));
            printf("%%  ��������ʧ: %f  ѧϰ��:%.10f\n",corss_loss,lr);
            if(lr<0.0000000001)printf_file2(para);//����ҵ��ֲ��������ӡ�������
        }

        int a,b;
        srand(time(NULL));
        for(int q=0;q<300;q++){
            a=(int)((rand()/(RAND_MAX+1.0))*300);//ȷ��������������ı����±�
            b=(int)((rand()/(RAND_MAX+1.0))*300);
            if(a>=0&&a<300&&(a!=b)&&b>=0&&b<300){
                struct sample* sample5;
                sample5=(struct sample *)malloc(sizeof(struct sample));
                (*sample5)=Sample[a];
                Sample[a]=Sample[b];
                Sample[b]=(*sample5);
                free(sample5);
                sample5=NULL;
            }
            else continue;
        }
        for(int i=0;i<SAMPLE_NUM*10;i++) {//ѵ���Ѿ����ҵ���������
            corss_loss=0;
            struct sample* sample3;
            sample3=(struct sample *)malloc(sizeof(struct sample));
            (*sample3)=Sample[i];
            int y=sample3->number;
            forward(&sample3->a[0][0],para,data);//���򴫲�
            backward(y,para,data);
            free(sample3);
            sample3=NULL;
            float g=Cross_entropy(&data->result[0],y);//���㱾����󽻲�����ʧ������ָ������ѧϰ��
            if(g>corss_loss)corss_loss=g;
        }
    }
    printf("\n");
    return;
}

//�ò��Լ��е������������磬һ����ʮ����������
void test_network(struct parameter* parameter2,struct result *data2){
    char e[120];
    int l[960];
    float data[30][30];
    for(int i=0;i<10;i++){
        FILE *fp;
        char s[30];
        sprintf(s,"%s%d%s","Training_set//Test_set//",i+1,".bmp");
        printf("\n�򿪵��ļ���:%s\n",s);
        fp = fopen(s, "rb");
        if(fp == NULL){
            printf("Cann't open the file!\n");
            system("pause");
            return;
        }
        fseek(fp, 62, SEEK_SET);
        fread(e,sizeof(char),120,fp);
        fclose(fp);
        int y=0;
        for(int r=0;r<120;r++){
          for (int u=1;u<9;u++){
            l[y]=(int)((e[r]) >> (8-u) & 0x01);
            y++;
            if(y>960)break;
          };
        };
        y=0;
        int g=0;
        for(int u=0;u<30;u++)
        {
            y=0;
            for(int j=0;j<32;j++)
            {
                if((j!=30)&&(j!=31)){data[u][y]=l[g];y++;};
                g++;
            }
        }
        int q=data[0][0];
        if(q==1){
            int n=0;
            int z=0;
            for(int b=0;b<30;b++)
            {
                n=0;
                for(;;)
                {
                    if(n>=30)break;
                    if(data[z][n]==0)data[z][n]=1;
                    else if(data[z][n]==1)data[z][n]=0;
                    n++;
                }
                z++;
            }
        }
        forward(&data[0][0],parameter2,data2);//�ѻ�ȡ�������������򴫲�һ��
        float sum=0;
        int k=0;
        for(int j=0;j<10;j++)
            {
                if(result[j]>sum)
                {
                    sum=result[j];
                    k=j;//��ȡ������
                }
                else continue;
            }
        printf("\n");
        for(int i=0;i<10;i++)//��ӡ������
        {
            printf("Ԥ��ֵ��%d�ĸ��ʣ�%lf\n",i,result[i]);
        }
        printf("����Ԥ��ֵ:%d\n",k);
}
return ;
}

int main(){

    int h=DataLoader();
    if(h==0)printf("ѵ�����ݶ�ȡ�ɹ�\n");
    else if(h==1){
        printf("ѵ������ȡʧ�ܣ������Զ��˳�\n");
        system("pause");
        return 0;
    }
    struct parameter *storage;//��������������Ľṹ��
    (storage) = (struct parameter*)malloc(sizeof(struct parameter));//��̬����ռ�
    struct result *data;
    (data) = (struct result*)malloc(sizeof(struct result));

    first:
    printf("�������Ƿ�ϣ������ѵ������������ļ��ж�ȡ������������밴y�����밴n��\n");
    setbuf(stdin,NULL);//��ռ��̻�����
    char g;
    g=getch();
    if(g=='y'){
        int h=read_file(storage);
        if(h==1){
            printf("�����������ڣ���ʼ�Զ������ʼ���������\n");
            init(storage);
            printf_file(storage);
            printf("���������ʼ����ϣ�\n");
        }
        if(h==0)
            printf("������ȡ�ɹ�!\n");
    }
    else if (g=='n'){
        init(storage);
        printf_file(storage);
        printf("������ʼ����ϣ�\n");
    }
    else goto first;

    second:
    printf("������Ԥѵ���Ĵ�����\n");
    int epoch;
    scanf("%d",&epoch);
    printf("��ʼѵ��\n");
    train(epoch,storage,data);
    test_network(storage,data);
    printf_file(storage);

    third:
    printf("����ѵ���밴1���˳��밴2\n");
    setbuf(stdin,NULL);
    char v;
    v=getch();
    if(v=='1')goto second;
    else if(v=='2'){printf_file(storage);return 0;}//�˳������˳�֮ǰ�����������
    else goto third;

    return 0;
}
