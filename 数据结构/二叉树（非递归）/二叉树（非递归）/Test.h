#pragma once
#include"Btree.h"


void test()
{
	int preOrder[] = { 1, 2, 3, -1, 4, 5, -1, -1, -1, 6, -1, -1, 7, 8, -1, -1, 9, -1, 0 };
	//int preOrder[] = { 1,2,-1,-1,3};
	int size = sizeof (preOrder) / sizeof(int);
	int pUsedSize;
	BTreeNode *root = CreateTree(preOrder, size, &pUsedSize);

	printf("层序遍历：> ");
	LevelOrder(root);
	printf("\n");

	printf("非递归前序遍历：> ");
	PreOrderLoop(root); printf("\n");
	printf("非递归中序遍历：> ");
	InOrderLoop(root); printf("\n");
	printf("非递归后序遍历：> ");
	PostOrderLoop(root); printf("\n");

	int ret = IsComplete(root);
	if (ret == 1){
		printf("是完全二叉树\n");
	}
	else{
		printf("不是完全二叉树\n");
	}

	Mirror1(root);
	//Mirror2(root);
	PreOrderLoop(root);
	printf("\n");

}
