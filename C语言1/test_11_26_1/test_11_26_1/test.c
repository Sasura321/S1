//假设二叉树采用二叉链存储结构存储，设计一个算法，计算一棵给定二叉树的所有叶子结点个数

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20

typedef struct node
{
	int data;
	struct node *lchild,*rchild;
}Bitree;

BTNode *Q[MAXSIZE];
*Creatree()
{
	char ch;
	int front = 1;
	int rear = 0;
	Bitree *T = NULL,*s;
	printf("请输入树的结点：（‘@’表示虚结点，‘#’表示结束）\n");
	ch = getchar();
	while(ch != '#')
	{
		s = NULL;
		if(ch != '@')
		{
			s = (Bitree*)malloc(sizeof(Bitree));
			s->data = ch;
			s->lchild = s->rchild = NULL;
		}
		rear++;
		Q[rear] = s;
		if(rear == 1)
			T = s;
		else
		{
			if(s != NULL && Q[front] != NULL)
			{
				if(rear%2 == 0)
					Q[front]->lchild = s;
				else
					Q[front]->rchild = s;
			}
			if(rear%2 == 1)
				front++;
		}
		ch = getchar();
	}
	return T;
}

int countleft(Bitree *T)
{
	if(T == NULL)
		return 0;
	else if((T->lchild == NULL) && (T->rchild == NULL))
		return 1;
	else
		return countleft(b->lchild)+countleft(b->rchild);
}

void main()
{
	Bitree *T;
	int count = 0;
	T = Creatree();
	count = countleft(b);
	printf("此二叉树的所有结点个数为：%d\n",count);
}