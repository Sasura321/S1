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
	printf("最近公共祖先结点:> %d\n", *t);

	//int dif = IsBalance(root);
	//if (dif == 1){
	//	printf("平衡树\n");
	//}
	//else{
	//	printf("不是平衡树\n");
	//}
	printf("%d 平衡树\n", IsBalance(root));
	int *pHight;
	printf("%d 平衡树\n", IsBalanceAd(root,&pHight));
	printf("最远的两个结点之间的距离:> %d \n", GetLongDistance(root));
}

void TestPreInTree()
{
	int preOrder[] = { 1, 2, 3, 4, 5, 6, 7 };
	int inOrder[] = { 2, 1, 4, 6, 7, 5, 3 };
	int size = sizeof(preOrder) / sizeof(int);

	BTreeNode *root = CreatePreInTree(preOrder, inOrder, size);


	printf("success\n");
}