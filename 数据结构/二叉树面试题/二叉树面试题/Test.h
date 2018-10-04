#pragma once
#include "BTree.h"

void test()
{
	int preOrder[] = { 1, 2, 3, -1, 4, 5, -1, -1, -1, 6, -1, -1, 7, 8, -1, -1, 9, -1, 0 };
	//int preOrder[] = { 1,2,-1,-1,3};
	int size = sizeof (preOrder) / sizeof(int);
	int pUsedSize;
	BTreeNode *root = CreateTree(preOrder, size, &pUsedSize);

	BTreeNode *t = GetAncestor(root, root->left, root->right);
	printf("����������Ƚ��:> %d\n", *t);

	//int dif = IsBalance(root);
	//if (dif == 1){
	//	printf("ƽ����\n");
	//}
	//else{
	//	printf("����ƽ����\n");
	//}
	printf("%d ƽ����\n", IsBalance(root));
	int *pHight;
	printf("%d ƽ����\n", IsBalanceAd(root,&pHight));
	printf("��Զ���������֮��ľ���:> %d \n", GetLongDistance(root));
}

void TestPreInTree()
{
	int preOrder[] = { 1, 2, 3, 4, 5, 6, 7 };
	int inOrder[] = { 2, 1, 4, 6, 7, 5, 3 };
	int size = sizeof(preOrder) / sizeof(int);

	BTreeNode *root = CreatePreInTree(preOrder, inOrder, size);


	printf("success\n");
}