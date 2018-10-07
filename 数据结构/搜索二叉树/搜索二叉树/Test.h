#pragma once

#include "BSTree.h"

void test()
{
	int r;
	BSTreeNode *root = NULL;
	r = BSTreeInsert(&root, 5); printf("插入 %s\n", r ? "成功" : "失败");
	r = BSTreeInsert(&root, 3); printf("插入 %s\n", r ? "成功" : "失败");
	r = BSTreeInsert(&root, 7); printf("插入 %s\n", r ? "成功" : "失败");
	r = BSTreeInsert(&root, 1); printf("插入 %s\n", r ? "成功" : "失败");
	r = BSTreeInsert(&root, 4); printf("插入 %s\n", r ? "成功" : "失败");
	r = BSTreeInsert(&root, 6); printf("插入 %s\n", r ? "成功" : "失败");
	r = BSTreeInsert(&root, 8); printf("插入 %s\n", r ? "成功" : "失败");
	r = BSTreeInsert(&root, 0); printf("插入 %s\n", r ? "成功" : "失败");
	r = BSTreeInsert(&root, 2); printf("插入 %s\n", r ? "成功" : "失败");
	r = BSTreeInsert(&root, 9); printf("插入 %s\n", r ? "成功" : "失败");
	r = BSTreeInsert(&root, 10); printf("插入 %s\n", r ? "成功" : "失败");

	InOrder(root); printf("\n");

	r = BSTreeFind(root, 9); printf("查找 9 %s\n", r ? "成功" : "失败");
	r = BSTreeFind2(root, 10); printf("查找 10 %s\n", r ? "成功" : "失败");

	BSTreeNodeRemove(&root, 8); 
	BSTreeNodeRemove(&root, 2);
	BSTreeNodeRemove(&root, 5); 
}