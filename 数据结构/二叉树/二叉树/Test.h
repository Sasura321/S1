#pragma once
#include"Btree.h"

void test()
{
	int preOrder[] = { 1, 2, 3, -1, 4, 5, -1, -1, -1, 6, -1, -1, 7, 8, -1, -1, 9, -1, 0 };
	int size = sizeof (preOrder) / sizeof(int);
	int pUsedSize;
	BTreeNode *root = CreateTree(preOrder, size, &pUsedSize);

	printf("前序遍历：> ");
	PreOrder(root);
	printf("\n中序遍历：> ");
	InOrder(root);
	printf("\n后序遍历：> ");
	PostOrder(root);
	printf("\n");

	printf("节点个数(方法一)：> %d\n", GetSize1(root));
	printf("节点个数(方法二)：> ");
	GetSize2(root);
	printf("%d\n",count);

	printf("叶子节点个数(方法一)：> %d\n", GetLeafSize(root));
	printf("叶子节点个数(方法二)：> ");
	GetLeafSize2(root);
	printf("%d\n", num);

	printf("第k层节点个数：> %d\n", GetLeafKSize(root, 4));
	printf("高度：> %d\n", GetHight(root));
	
	if (Find(root, 5) != NULL){
		printf("查找成功\n");
	}
	else{
		printf("查找失败\n");
	}

}
