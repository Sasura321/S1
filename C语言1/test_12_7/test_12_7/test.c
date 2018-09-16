//��дһ������ʵ�ֿ��������㷨
//��������ݽ��в��Բ�������λ���֮��Ľ��

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 10    //���������ݸ��� 
typedef struct 
{
    int r[MAXSIZE+1];
    int length;
}SqList;

//��������
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
        swap(L,low,m);      //��һ����˼�ǣ�ѡ��ˡ��м䡢�Ҷ���������Ȼ������ȡ����Ϊ����
                            //������ֱ��ȥ�����Ϊ����ʱ�����ǡ���Ǻ�С��ܴ�����

    pivot=L->r[low];     //����һ��Ԫ����Ϊ����pivotkey

    L->r[0]=pivot;       //������ؼ��ִ���L->r��0��

    while(low<high)     //�ӱ�����˽������м�ɨ��
    {
        while(low<high && L->r[high]>=pivot)     //���ұ��𣬽���pivotkeyС�Ļ������
            high--;

        L->r[low]=L->r[high];       //�����滻�����ǽ����ķ�ʽ�������˶���Ľ�������

        while(low<high && L->r[low]<=pivot)      //������𣬽���pivotkey��Ļ����ұ�
            low++;

        L->r[high]=L->r[low];       //�����滻�����ǽ����ķ�ʽ�������˶���Ľ�������

    }
    L->r[low]=L->r[0];      //������ֵ�滻��L->r��low��

    return low;     //low��high���ʱ����Ϊ����λ��
}

//�ݹ麯��
void QSort(SqList *L,int low,int high)
{
    int pivot;
        while(low<high)     //��while�滻if
                            //һ��ѭ����lowû���ˣ���pivot�滻low����ѭ��һ�Σ���ȥ������ӱ���
                            //�����õ����滻�˲��ֵݹ�
        {
            pivot=Partition(L,low,high);        //����һ��Ϊ��

            QSort(L,low,pivot-1);       //���ӱ�����ݹ�
            low=pivot+1;
        }
        QSort(L,pivot+1,high);
}

//���뺯��
void Insert(SqList *L)
{
	int data;
    L->length++;
    L->r[L->length]=data;
} 

//�������
void Printf(SqList *L)
{
    int i;
    for(i=1;i<=L->length;i++)
    {
        printf("%d ",L->r[i]);
    }
}

//������
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
