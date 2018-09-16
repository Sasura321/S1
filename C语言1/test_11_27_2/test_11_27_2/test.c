#include<stdio.h>
#include<stdlib.h>
 
typedef struct node
{
    char data;
    struct node *lchild;
    struct node *rchild;
}BTnode;
 
BTnode* CreateBiTree(BTnode *&T)
{
    char ch;
	printf("请输入树的结点：")
    ch = getchar();
    if (ch == '#')    //空格改成#
        return  NULL;
    else
    {
        T = (BTnode*)malloc(sizeof(BTnode));
        T->data = ch;
        T->lchild=CreateBiTree(T->lchild);
        T->rchild=CreateBiTree(T->rchild);
        return T;
    }
}
 
void PreOrder(BTnode *b)
{
    if (b != NULL)
    {
        b->data = getchar();;
        PreOrder(b->lchild);
        PreOrder(b->rchild);
    }
}
int main()
{
    BTnode *B = (BTnode*)malloc(sizeof(BTnode));
    B=CreateBiTree(B);
    PreOrder(B);
    return 0;
}