#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode //���������
{
    char data;                      //����
    struct BiTNode *lchild,*rchild; //���Һ���ָ��
} BiTNode,*BiTree;

int CreateBiTree(BiTree &T) //���������д���������
{
    char data;
    scanf("%c",&data);//�������������������н���ֵ��һ���ַ�������#����ʾ����
    if (data == '#') 
	{
        T = NULL;
    } 
	else 
	{
        T = (BiTree)malloc(sizeof(BiTNode));
        T->data = data;         //���ɸ����
        CreateBiTree(T->lchild);//����������
        CreateBiTree(T->rchild);//����������
    }
    return 0;
}
void Visit(BiTree T)//���
{
    if (T->data != '#') 
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

int main() 
{
    BiTree T;
    CreateBiTree(T);
    printf("������� ��");
	PreOrder  (T);
	printf("\n");
    return 0;
}
//ABC##DE#G##F###
//�������        ��A B C D E G F

///       A
///      /
///     B
///    / \
///   C   D
///      / \
///     E   F
///      \
///       G
