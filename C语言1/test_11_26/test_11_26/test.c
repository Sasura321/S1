//假设二叉树采用二叉链存储结构存储，设计一个算法，计算一棵给定二叉树的所有节点个数

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *lchild,*rchild;
}BTNode;

BTNode *creatree()
{
	char ch;
	node *b = NULL;
	node *s = NULL;
	printf("请输入树的结点：（‘@’表示虚结点，‘#’表示结束）\n");
	ch = getchar();
	while(ch != '#')
	{
		if(ch != '@')
		{
			s = (node*)malloc(sizeof(node));
			s->data = ch;
		}
	}
}

int countnode(BTNode *b)
{
	if(b == NULL)
		return 0;
	else
		return countnode(b->lchild)+countnode(b->rchild)+1;
}

void main()
{
	BTNode *b;
	int count = 0;
	b = creatree();
	count = countnode(b);
	printf("此二叉树的所有结点个数为：%d",count);
}