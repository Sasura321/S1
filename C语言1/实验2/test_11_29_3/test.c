//输出一棵给定的二叉树的叶子结点

#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode      //定义二叉树结点
{
    char data;                      
    struct BiTNode *lchild,*rchild; 
} BiTNode,*BiTree;

int CreateBiTree(BiTree *T) //创建二叉树
{
    char data;
    scanf("%c",&data);
	//按先序次序输入二叉树中结点的值（字符），‘#’表示空树
    if (data == '#') 
	{
        *T = NULL;
    } 
	else 
	{
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T)->data = data;          //生成根结点
        CreateBiTree(&(*T)->lchild);//构造左子树
        CreateBiTree(&(*T)->rchild);//构造右子树
    }
    return 0;
}

void Visit(BiTree T) //输出
{
    if (T->lchild == NULL && T->rchild == NULL) 
	{
        printf("%c ",T->data);
    }
}

void PreOrder(BiTree T) //先序遍历
{
    if (T != NULL) 
	{
        Visit(T);               //访问根节点
        PreOrder(T->lchild);    //访问左子结点
        PreOrder(T->rchild);    //访问右子结点
    }
}

void InOrder(BiTree T) //中序遍历
{
    if (T != NULL) 
	{
        InOrder(T->lchild);     //访问左子结点
        Visit(T);               //访问根节点
        InOrder(T->rchild);     //访问右子结点
    }
}

void PostOrder(BiTree T) //后序遍历
{
    if (T != NULL) 
	{
        PostOrder(T->lchild);   //访问左子结点
        PostOrder(T->rchild);   //访问右子结点
        Visit(T);               //访问根节点
    }
}

int main()
{
    BiTree T;
	int t = 0;
	printf("请输入二叉树中结点的值（字符），‘#’表示空树：");
    CreateBiTree(&T);
	printf("请选择一种二叉树的遍历方式\n");
	printf("输入‘1’先序遍历；输入‘2’中序遍历；输入‘3’后序遍历:");
	scanf("%d",&t);
	switch(t)
	{
	case 1:
		printf("选择先序遍历，结果：");
	    PreOrder  (T);
	    printf("\n");
		break;
	case 2:
		printf("中序遍历，结果：");
	    InOrder   (T);
	    printf("\n");
		break;
	case 3:
		printf("后序遍历，结果：");
	    PostOrder (T);
	    printf("\n");
		break;
	default:
		printf("输入不规范");
		break;
	}
    return 0;
}

//##CD#EABF##G###