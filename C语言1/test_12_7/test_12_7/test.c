//编写一个程序实现快速排序算法
//用相关数据进行测试并输出各次划分之后的结果

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 10    //待排序数据个数 
typedef struct 
{
    int r[MAXSIZE+1];
    int length;
}SqList;

//交换函数
void swap(SqList *L,int i,int j)
{
    int temp=L->r[i];
    L->r[i]=L->r[j];
    L->r[j]=temp;
}

int Partition(SqList *L,int low,int high)
{
    int pivot;

    int m=low+(high-low)/2;
    if(L->r[low] > L->r[high])
        swap(L,low,high);
    if(L->r[m] > L->r[high])
        swap(L,high,m);
    if(L->r[m] > L->r[low])
        swap(L,low,m);      //这一段意思是，选左端、中间、右端三个数，然后三数取中作为枢轴
                            //避免了直接去左端作为枢轴时，左端恰好是很小或很大的情况

    pivot=L->r[low];     //将第一个元素作为枢轴pivotkey

    L->r[0]=pivot;       //将枢轴关键字存入L->r【0】

    while(low<high)     //从表的两端交替向中间扫描
    {
        while(low<high && L->r[high]>=pivot)     //从右边起，将比pivotkey小的换到左边
            high--;

        L->r[low]=L->r[high];       //采用替换而不是交换的方式，避免了多余的交换操作

        while(low<high && L->r[low]<=pivot)      //从左边起，将比pivotkey大的换到右边
            low++;

        L->r[high]=L->r[low];       //采用替换而不是交换的方式，避免了多余的交换操作

    }
    L->r[low]=L->r[0];      //将枢轴值替换回L->r【low】

    return low;     //low与high相等时，即为枢轴位置
}

//递归函数
void QSort(SqList *L,int low,int high)
{
    int pivot;
        while(low<high)     //用while替换if
                            //一次循环后，low没用了，将pivot替换low，再循环一次，就去排序高子表了
                            //这是用迭代替换了部分递归
        {
            pivot=Partition(L,low,high);        //将表一分为二

            QSort(L,low,pivot-1);       //低子表继续递归
            low=pivot+1;
        }
        QSort(L,pivot+1,high);
}

//插入函数
void Insert(SqList *L)
{
	int data;
    L->length++;
    L->r[L->length]=data;
} 

//输出函数
void Printf(SqList *L)
{
    int i;
    for(i=1;i<=L->length;i++)
    {
        printf("%d ",L->r[i]);
    }
}

//主函数
void main()
{
    SqList *L;
    int i;
    int a[]={1,2,3,4,5,6,7,8,9,10};
    for(i=0;i<10;i++)
    {
        Insert(&L);
    }
    QSort(L,1,L->length);

    Insert(&L);
    Printf(L);
}
