#pragma once
#include"Btree.h"


void test()
{
	int preOrder[] = { 1, 2, 3, -1, 4, 5, -1, -1, -1, 6, -1, -1, 7, 8, -1, -1, 9, -1, 0 };
	//int preOrder[] = { 1,2,-1,-1,3};
	int size = sizeof (preOrder) / sizeof(int);
	int pUsedSize;
	BTreeNode *root = CreateTree(preOrder, size, &pUsedSize);

	printf("���������> ");
	LevelOrder(root);
	printf("\n");

	printf("�ǵݹ�ǰ�������> ");
	PreOrderLoop(root); printf("\n");
	printf("�ǵݹ����������> ");
	InOrderLoop(root); printf("\n");
	printf("�ǵݹ���������> ");
	PostOrderLoop(root); printf("\n");

	int ret = IsComplete(root);
	if (ret == 1){
		printf("����ȫ������\n");
	}
	else{
		printf("������ȫ������\n");
	}

	Mirror1(root);
	//Mirror2(root);
	PreOrderLoop(root);
	printf("\n");

}
