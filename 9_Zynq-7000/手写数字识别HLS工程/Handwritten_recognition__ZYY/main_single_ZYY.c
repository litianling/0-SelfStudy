#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#define max(a,b)(((a)>(b))?(a):(b))
#define SAMPLE_NUM 30//宏定义的样本数量
float lr;
float result[10];//最后通过softmax输出的结果

struct parameter{
    float conv_kernel11[3][3];
    float conv_kernel21[3][3];
    float conv_kernel31[3][3];
    float fc_hidden_layer1[576][180];
    float fc_hidden_layer2[180][45];
    float fc_hidden_layer3[45][10];
};

//网络中每一层的尺寸
struct result{
    float mnist_data[30][30];
    //通道一
    float first_conv1[28][28];
    float sencond_conv1[26][26];
    float third_conv1[24][24];
    //全连接
    float flatten_conv[1][576];//合并两个通道
    float first_fc[1][180];//第一层全连接输出
    float first_relu[1][180];//第一层激活函数输出
    float second_fc[1][45];//第二层全连接输出
    float second_relu[1][45];//第二层激活函数输出
    float outmlp[1][10];//全连接的输出
    float result[10];//Softmax的输出
};

//训练集结构体，训练样本30*30
struct input{
    float a[10][SAMPLE_NUM][30][30];//[标签][样本数量][w][h]
};

//保存每一张图片的结构体
struct sample{
    float a[30][30];//data
    int number;//label
}Sample[SAMPLE_NUM*10];

//卷积操作,卷积核大小为k*k
void Conv2d(int w,int h,int k,float *input_matrix,float *kernel,float *out_matrix){
    for(int i=0;i<w-k+1;i++)
        for(int j=0;j<h-k+1;j++){
            out_matrix[i*(w-k+1)+j]=0;
            for(int row=i;row<i+3;row++)
                for(int col=j;col<j+3;col++)
                    out_matrix[i*(w-k+1)+j]+=input_matrix[row*w+col]*kernel[(row-i)*k+(col-j)];
        }
}

//最大池化操作，池化核大小为k*k
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

//用LeakyRelu代替Relu，避免梯度弥散
void Relu(int w,int h,float *input_matrix,float *output_matrix){
    for(int i=0;i<w;i++)
        for(int j=0;j<h;j++)
            output_matrix[i*w+j]=max(input_matrix[i*w+j],input_matrix[i*w+j]*0.05);
}

//特征图扁平化后concat
void MatrixExtensionImproved(int w,int h,float *input_matrix1,float *output_matrix){
    for(int i=0;i<w;i++)
        for(int j=0;j<h;j++)
            output_matrix[i*w+j]=input_matrix1[i*w+j];//将通道一的特征图输出加入到output_matrix
}

//全连接的矩阵乘法
void MatrixMultiply(int w,int h,int out_deminsion,float *input_matrix,float *para_layer,float*output_matrix){
    for(int i=0;i<w;i++)
        for(int j=0;j<out_deminsion;j++){
            output_matrix[i*w+j]=0;
            for(int k=0;k<h;k++)
                output_matrix[i*w+j]+=input_matrix[i*w+k]*para_layer[k*out_deminsion+j];
        }
}

//将全连接反向传播过来的梯度拆成两部分输入到两个channel中
// void MatrixSplit(float *input_matrix,float *splited_matrix1,float *splited_matrix2){
//     for(int idx=0;idx<1152;idx++)
//         if(idx<576)
//             splited_matrix1[idx]=input_matrix[idx];
//         else
//             splited_matrix2[idx-576]=input_matrix[idx];
// }

//将全连接反向传播过来的梯度拆成两部分输入到两个channel中
void MatrixSplit(float *input_matrix,float *splited_matrix1){
    for(int idx=0;idx<576;idx++){
        splited_matrix1[idx]=input_matrix[idx];
        //splited_matrix2[idx]=input_matrix[idx+576];
    }
}

//更新网络参数
void MatrixBackPropagation(int w,int h,float *input_matrix,float *output_matrix){
    for(int i=0;i<w;i++)
        for(int j=0;j<h;j++)
            output_matrix[i*h+j]-=lr*input_matrix[i*h+j];
}

//反向传播时的矩阵乘法
void MatrixBackPropagationMultiply(int w,int h,float *para,float *grad,float *rgrad){
    for(int i=0;i<w;i++)
        for(int j=0;j<h;j++)
            rgrad[i*h+j]=para[i]*grad[j];

}

//计算当前层的参数矩阵的梯度,利用前一层神经元梯度行矩阵乘本层神经元梯度列矩阵,得到本层参数梯度
void CalculateMatrixGrad(int w,int h,float *input_matrix,float *grad,float *output_matrix){
    for(int i=0;i<w;i++){
        output_matrix[i]=0;//梯度清空，方便累加
        for(int j=0;j<h;j++){
            output_matrix[i]+=input_matrix[i*h+j]*grad[j];
        }
    }
}

//激活函数的反向传播
void ReluBackPropagation(int w,float *input_matrix,float *grad,float *output_matrix){
    for(int i=0;i<w;i++)
        if(input_matrix[i]>0) output_matrix[i]=1*grad[i];
        else output_matrix[i]=0.05*grad[i];
}

//反向传播时对梯度进行填充，由w*h变为(w+2*stride)*(h+2*stride)
void Padding(int w,int stride,float *input_matrix,float *output_matrix){
    for(int i=0;i<w+2*stride;i++)
        for(int j=0;j<w+2*stride;j++)
            output_matrix[i*(w+2*stride)+j]=0;//输出矩阵初始化
//    for(int i=0;i<w;i++)
//        for(int j=0;j<w;j++)
//            output_matrix[(i+stride)*(w+2*stride)+(j+stride)]=input_matrix[i*w+j];
}

//由于卷积核翻转180°后恰好是导数形式，故进行翻转后与后向传播过来的梯度相乘
void OverturnKernel(int k,float *input_matrix,float *output_matrix){
    for(int i=0;i<k;i++)
        for(int j=0;j<k;j++)
            output_matrix[(k-1-i)*k+(k-1-j)]=input_matrix[i*k+j];
}

//释放内存
void MemoryFree(float *x){
    free(x);
    x=NULL;
}

//使用随机数初始化网络参数
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

//前向传播，包括三层卷积，三层全连接
void forward(float *input_matrix,struct parameter* para,struct result* data){
    Conv2d(30,30,3,input_matrix,&para->conv_kernel11[0][0],&data->first_conv1[0][0]);
    Conv2d(28,28,3,&data->first_conv1[0][0],&para->conv_kernel21[0][0],&data->sencond_conv1[0][0]);
    Conv2d(26,26,3,&data->sencond_conv1[0][0],&para->conv_kernel31[0][0],&data->third_conv1[0][0]);//第一个通道得到24*24的特征图

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

//反向传播，更新梯度
void backward(int label,struct parameter* para,struct result* data){
    /****************************************************************************************
     * grad结尾的变量代表每一层的梯度
     * wgrad结尾的变量代表每一层的参数的梯度
     * rgrad结尾的代表激活函数的梯度
     * 本网络结构是两个通道的卷积加三层全连接，每个通道有三层卷积层，无池化层，层数使用序数词标明
    ****************************************************************************************/
    int float_len=sizeof(float);
    float *out_grad;
    out_grad=(float*)malloc(10*float_len);//网络的输出是10个float类型
    //交叉熵损失函数求导结果为y_hat_i-y_i
    for(int i=0;i<10;i++)
        if(i==label) out_grad[i]=data->result[i]-1;
        else out_grad[i]=data->result[i]-0;
    //三层全连接层的反向传播
    
    //第三层全连接反向传播 out_wgrad
    float *out_wgrad;
    out_wgrad=(float*)malloc(450*float_len);
    MatrixBackPropagationMultiply(45,10,&data->second_relu[0][0],out_grad,out_wgrad);//与第二层输出

    //第二层全连接反向传播
    float *second_rgrad;
    second_rgrad=(float*)malloc(45*float_len);
    CalculateMatrixGrad(45,10,&para->fc_hidden_layer3[0][0],out_grad,second_rgrad);//与参数相乘，求loss和
    MemoryFree(out_grad);
    float *second_grad;
    second_grad=(float*)malloc(180*float_len);
    ReluBackPropagation(45,&data->second_fc[0][0],second_rgrad,second_grad);//与第二层中间结果再求loss
    MemoryFree(second_rgrad);
    float *second_wgrad;
    second_wgrad=(float*)malloc(8100*float_len);
    MatrixBackPropagationMultiply(180,45,&data->first_relu[0][0],second_grad,second_wgrad);//与第一层输出结果求loss

    //第一层全连接反向传播
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
    //通道一
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

    //通道一更新参数
    MatrixBackPropagation(3,3,first_kernel_grad,&para->conv_kernel11[0][0]);
    MatrixBackPropagation(3,3,second_kernel_grad,&para->conv_kernel21[0][0]);
    MatrixBackPropagation(3,3,third_kernel_grad,&para->conv_kernel31[0][0]);
    //printf("%f\n", first_conv_grad[0]);
    //全连接层更新参数
    MatrixBackPropagation(576,180,first_wgrad,&para->fc_hidden_layer1[0][0]);
    MatrixBackPropagation(180,45,second_wgrad,&para->fc_hidden_layer2[0][0]);
    MatrixBackPropagation(45,10,out_wgrad,&para->fc_hidden_layer3[0][0]);
    //清空内存
    MemoryFree(first_kernel_grad);
    MemoryFree(second_kernel_grad);
    MemoryFree(third_kernel_grad);
    MemoryFree(first_wgrad);
    MemoryFree(second_wgrad);
    MemoryFree(out_wgrad);
    return;
}

//从图片中提取数据
int DataLoader(){
    for(int num=0;num<10;num++){
        for(int i=0;i<SAMPLE_NUM;i++){
            //利用char型数据提取图片内容，后转化为int型
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
            sprintf(file_name1,"%d%s",i+1,".bmp");//通过i++循环批量读取文件
		    strcat(route_name2,file_name1);
		    fp=fopen(route_name2,"rb");

            if(fp==NULL){
                printf("训练集打开失败，请检查Training_set文件夹是否存在以及训练图片是否完整！\n");
			    return 1;
            }
            fseek(fp,62,SEEK_SET);//bmp单色位图像素数据从62个字节处开始
            fread(e,sizeof(char),120,fp);//把所有数据以char型的格式读到e数组中
            fclose(fp);

            int y=0;
            for(int r=0;r<120;r++){
                for(int u=1;u<9;u++){
                    l[y]=(int)(((e[r])) >> (8-u) & 0x01);//把每一个char型数据拆开成01数据存放到数组l中
                    y++;
                    if(y>960)
                        break;
                }
            }
            int g=0;
            for(int u=0;u<30;u++){
                y=0;
                for(int j=0;j<32;j++){
                    if((j!=30)&&(j!=31)){Sample[num*SAMPLE_NUM+i].a[u][y]=l[g];y++;};//去掉windows自动补0的数据，把真正的数据存放的样本结构体中
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
            Sample[num*SAMPLE_NUM+i].number=num;//给样本打标签
            free(e);
            e=NULL;
            free(l);
            l=NULL;
        }
    }
    return 0;
}

//训练前读取网络参数
int read_file(struct parameter* parameter4){
    FILE*fp;
    fp=fopen("Training_set//Network_parameter.bin","rb");
    if(fp==NULL)
    {
        printf("文件打开失败，请检查网络参数文件是否在训练集文件夹内！\n");
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

//训练结束后保存网络参数
void printf_file(struct parameter* parameter4){
    FILE*fp;
    fp=fopen("Training_set//Network_parameter.bin","wb");//采用二进制格式保存参数，便于读取
    struct parameter* parameter1;
    parameter1=(struct parameter*)malloc(sizeof(struct parameter));
    (*parameter1)=(*parameter4);
    fwrite(parameter1,sizeof(struct parameter),1,fp);//打印网络结构体
    fclose(fp);
    free(parameter1);
    parameter1=NULL;
    return;
}

//训练过程中的最优参数打印函数
void printf_file2(struct parameter* parameter4){
    FILE*fp;
    fp=fopen("NetworkParameters.bin","wb");
    struct parameter* parameter1;
    parameter1=(struct parameter*)malloc(sizeof(struct parameter));
    (*parameter1)=(*parameter4);
    fwrite(parameter1,sizeof(struct parameter),1,fp);//结果指针、大小、数量、文件指针
    fclose(fp);
    free(parameter1);
    parameter1=NULL;
    return;
};

//交叉熵损失函数
float Cross_entropy(float *a,int m){
    float u=0;
    u=(-log10(a[m]));
    return u;
}

//网络训练部分，读取到图像数据进行前向传播的训练
void train(int epochs,struct parameter *para,struct result *data){
    printf("进入train函数：\n");
    float corss_loss=2;//保存每次训练的最大交叉熵
    for(int epoch=0;epoch<epochs;epoch++){
        //printf("hhhh");
        lr=pow((corss_loss/10),1.7);
        if(lr>0.01) lr=0.01;
        if((epoch+1)%10==0){
            printf("训练进度: %lf",100*((float)(epoch+1)/(float)epochs));
            printf("%%  交叉熵损失: %f  学习率:%.10f\n",corss_loss,lr);
            if(lr<0.0000000001)printf_file2(para);//如果找到局部最优则打印网络参数
        }

        int a,b;
        srand(time(NULL));
        for(int q=0;q<300;q++){
            a=(int)((rand()/(RAND_MAX+1.0))*300);//确定本轮随机交换的变量下标
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
        for(int i=0;i<SAMPLE_NUM*10;i++) {//训练已经打乱的所有样本
            corss_loss=0;
            struct sample* sample3;
            sample3=(struct sample *)malloc(sizeof(struct sample));
            (*sample3)=Sample[i];
            int y=sample3->number;
            forward(&sample3->a[0][0],para,data);//正向传播
            backward(y,para,data);
            free(sample3);
            sample3=NULL;
            float g=Cross_entropy(&data->result[0],y);//计算本轮最大交叉熵损失，用于指导调整学习率
            if(g>corss_loss)corss_loss=g;
        }
    }
    printf("\n");
    return;
}

//用测试集中的样本测试网络，一共有十个测试样本
void test_network(struct parameter* parameter2,struct result *data2){
    char e[120];
    int l[960];
    float data[30][30];
    for(int i=0;i<10;i++){
        FILE *fp;
        char s[30];
        sprintf(s,"%s%d%s","Training_set//Test_set//",i+1,".bmp");
        printf("\n打开的文件名:%s\n",s);
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
        forward(&data[0][0],parameter2,data2);//把获取的样本数据正向传播一次
        float sum=0;
        int k=0;
        for(int j=0;j<10;j++)
            {
                if(result[j]>sum)
                {
                    sum=result[j];
                    k=j;//获取分类结果
                }
                else continue;
            }
        printf("\n");
        for(int i=0;i<10;i++)//打印分类结果
        {
            printf("预测值是%d的概率：%lf\n",i,result[i]);
        }
        printf("最终预测值:%d\n",k);
}
return ;
}

int main(){

    int h=DataLoader();
    if(h==0)printf("训练数据读取成功\n");
    else if(h==1){
        printf("训练集读取失败！程序自动退出\n");
        system("pause");
        return 0;
    }
    struct parameter *storage;//定义存放网络参数的结构体
    (storage) = (struct parameter*)malloc(sizeof(struct parameter));//动态分配空间
    struct result *data;
    (data) = (struct result*)malloc(sizeof(struct result));

    first:
    printf("请问您是否希望从已训练的网络参数文件中读取网络参数？是请按y，否请按n。\n");
    setbuf(stdin,NULL);//清空键盘缓冲区
    char g;
    g=getch();
    if(g=='y'){
        int h=read_file(storage);
        if(h==1){
            printf("参数包不存在！开始自动随机初始化网络参数\n");
            init(storage);
            printf_file(storage);
            printf("网络参数初始化完毕！\n");
        }
        if(h==0)
            printf("参数读取成功!\n");
    }
    else if (g=='n'){
        init(storage);
        printf_file(storage);
        printf("参数初始化完毕！\n");
    }
    else goto first;

    second:
    printf("请输入预训练的次数：\n");
    int epoch;
    scanf("%d",&epoch);
    printf("开始训练\n");
    train(epoch,storage,data);
    test_network(storage,data);
    printf_file(storage);

    third:
    printf("继续训练请按1，退出请按2\n");
    setbuf(stdin,NULL);
    char v;
    v=getch();
    if(v=='1')goto second;
    else if(v=='2'){printf_file(storage);return 0;}//退出则在退出之前保存网络参数
    else goto third;

    return 0;
}
