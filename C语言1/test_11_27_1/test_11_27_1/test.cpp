#include<iostream>
#include<malloc.h>
using namespace std;
 
typedef struct node
{
    char data;
    struct node *lchild;
    struct node *rchild;
}BTnode;
 
BTnode* CreateBiTree(BTnode *&T)
{
    char ch;
    cin >>ch;
    if (ch == '#')    //¿Õ¸ñ¸Ä³É#
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
        cout << b->data;
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