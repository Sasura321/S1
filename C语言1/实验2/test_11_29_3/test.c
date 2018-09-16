//���һ�ø����Ķ�������Ҷ�ӽ��

#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode      //������������
{
    char data;                      
    struct BiTNode *lchild,*rchild; 
} BiTNode,*BiTree;

int CreateBiTree(BiTree *T) //����������
{
    char data;
    scanf("%c",&data);
	//�������������������н���ֵ���ַ�������#����ʾ����
    if (data == '#') 
	{
        *T = NULL;
    } 
	else 
	{
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T)->data = data;          //���ɸ����
        CreateBiTree(&(*T)->lchild);//����������
        CreateBiTree(&(*T)->rchild);//����������
    }
    return 0;
}

void Visit(BiTree T) //���
{
    if (T->lchild == NULL && T->rchild == NULL) 
	{
        printf("%c ",T->data);
    }
}

void PreOrder(BiTree T) //�������
{
    if (T != NULL) 
	{
        Visit(T);               //���ʸ��ڵ�
        PreOrder(T->lchild);    //�������ӽ��
        PreOrder(T->rchild);    //�������ӽ��
    }
}

void InOrder(BiTree T) //�������
{
    if (T != NULL) 
	{
        InOrder(T->lchild);     //�������ӽ��
        Visit(T);               //���ʸ��ڵ�
        InOrder(T->rchild);     //�������ӽ��
    }
}

void PostOrder(BiTree T) //�������
{
    if (T != NULL) 
	{
        PostOrder(T->lchild);   //�������ӽ��
        PostOrder(T->rchild);   //�������ӽ��
        Visit(T);               //���ʸ��ڵ�
    }
}

int main()
{
    BiTree T;
	int t = 0;
	printf("������������н���ֵ���ַ�������#����ʾ������");
    CreateBiTree(&T);
	printf("��ѡ��һ�ֶ������ı�����ʽ\n");
	printf("���롮1��������������롮2��������������롮3���������:");
	scanf("%d",&t);
	switch(t)
	{
	case 1:
		printf("ѡ����������������");
	    PreOrder  (T);
	    printf("\n");
		break;
	case 2:
		printf("��������������");
	    InOrder   (T);
	    printf("\n");
		break;
	case 3:
		printf("��������������");
	    PostOrder (T);
	    printf("\n");
		break;
	default:
		printf("���벻�淶");
		break;
	}
    return 0;
}

//##CD#EABF##G###