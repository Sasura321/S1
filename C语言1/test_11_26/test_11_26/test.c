//������������ö������洢�ṹ�洢�����һ���㷨������һ�ø��������������нڵ����

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
	printf("���������Ľ�㣺����@����ʾ���㣬��#����ʾ������\n");
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
	printf("�˶����������н�����Ϊ��%d",count);
}