#pragma once
#include"Stack.h"
#include"Queue.h"

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int TDataType;

typedef struct BTreeNode{
	TDataType data;
	struct BTreeNode *left;
	struct BTreeNode *right;
}	BTreeNode;

/*
创建一棵二叉树
*/
BTreeNode *CreateNode(int data)
{
	BTreeNode *node = (BTreeNode*)malloc(sizeof(BTreeNode));
	node->data = data;
	node->left = node->right = NULL;

	return node;
}

BTreeNode *CreateTree(int preOrder[], int size, int *pUsedSize)
{
	//考虑特殊情况，空
	if (size == 0){
		*pUsedSize = 0;
		return NULL;
	}

	//正常情况
	int leftUsed, rightUsed;
	int rootValue = preOrder[0];
	if (rootValue == -1){
		*pUsedSize = 1;
		return NULL;
	}
	BTreeNode *root = CreateNode(rootValue);

	root->left = CreateTree(preOrder + 1, size - 1, &leftUsed);
	root->right = CreateTree(preOrder + 1 + leftUsed, size - 1 - leftUsed, &rightUsed);
	*pUsedSize = leftUsed + rightUsed + 1;

	return root;
}


/*
层序遍历（广度优先）
*/
void LevelOrder(BTreeNode *root)
{
	Queue queue;
	QueueInit(&queue);
	BTreeNode *front;

	if (root == NULL){
		return;
	}

	QueuePush(&queue, root);    //放的是结点，不是结点的 data
	while (!QueueEmpty(&queue)){
		front = QueueFront(&queue);
		QueuePop(&queue);

		//front向下拉，空节点不要
		//先左结点，后右结点
		if (front->left != NULL){
			QueuePush(&queue, front->left);
		}

		if (front->right != NULL){
			QueuePush(&queue, front->right);
		}

		//层序遍历 front 节点
		printf("%d  ", front->data);
	}

	QueueDestroy(&queue);
}

/*
判断一棵树是不是完全二叉树
*/
int IsComplete(BTreeNode *root)
{
	Queue queue;
	QueueInit(&queue);
	BTreeNode *front;

	if (root == NULL){
		return 1;
	}

	QueuePush(&queue, root);
	while (!QueueEmpty(&queue)){
		front = QueueFront(&queue);
		QueuePop(&queue);

		//和层序遍历的区别：front 有可能为 NULL
		if (front == NULL){
			//如果是完全二叉树，剩下的结点全是 NULL
			break;
		}
		QueuePush(&queue, front->left);
		QueuePush(&queue, front->right);
	}

	//队列剩余结点是否都是 NULL
	while (!QueueEmpty(&queue)){
		front = QueueFront(&queue);
		QueuePop(&queue);
		if (front != NULL){
			QueueDestroy(&queue);
			return 0;
		}
	}

	QueueDestroy(&queue);
	return 1;
}

/*
非递归遍历
*/

//非递归前序遍历
//栈里保存的是 右子树没有遍历的结点
void PreOrderLoop(BTreeNode *root)
{
	Stack stack;
	StackInit(&stack);
	BTreeNode *cur, *top;
	cur = root;

	while (cur != NULL || !StackEmpty(&stack)){
		while (cur != NULL){
			printf("%d  ", cur->data);
			StackPush(&stack, cur);
			cur = cur->left;
		}
		//top 的左子树 和 根已经遍历过了
		top = StackTop(&stack);  //取元素
		StackPop(&stack);

		//
		cur = top->right;
	}
}

//非递归中序遍历
//栈里保存的是 右子树 和 根 没有遍历的结点
void InOrderLoop(BTreeNode *root)
{
	Stack stack;
	StackInit(&stack);
	BTreeNode *cur, *top;
	cur = root;

	while (cur != NULL || !StackEmpty(&stack)){
		while (cur != NULL){
			StackPush(&stack, cur);
			cur = cur->left;
		}
		//top 的左子树已经遍历过了
		top = StackTop(&stack);  //取元素
		StackPop(&stack);
		printf("%d  ", top->data);

		//利用子问题的思想去遍历右子树
		cur = top->right;
	}
}

//非递归后序遍历
void PostOrderLoop(BTreeNode *root)
{
	Stack stack;
	StackInit(&stack);
	//last上一个被遍历的结点
	BTreeNode *cur, *top;
	BTreeNode *last = NULL;
	cur = root;

	while (cur != NULL || !StackEmpty(&stack)){
		//遍历左子树
		while (cur != NULL){
			StackPush(&stack, cur);
			cur = cur->left;
		}

		//top 的左子树已经遍历过了
		top = StackTop(&stack);  //取元素

		if (top->right == NULL || top->right == last){
			//如果右子树被遍历过了
			StackPop(&stack);
			printf("%d  ", top->data);

			//记录这个被遍历过的结点
			last = top;
		}
		else{
			//如果右子树没有被遍历
			cur = top->right;
		}
	}
}

/*
求镜像
*/
//递归
void Mirror1(BTreeNode *root)
{
	if (root == NULL){
		return;
	}

	Mirror1(root->left);
	Mirror1(root->right);
	BTreeNode *temp = root->left;
	root->left = root->right;
	root->right = temp;
}

//非递归
void Mirror2(BTreeNode *root)
{
	Stack	stack;
	StackInit(&stack);
	// last 上一个被遍历的结点
	BTreeNode *cur, *top, *last = NULL;
	cur = root;

	while (cur != NULL || !StackEmpty(&stack)) {
		// 遍历左子树
		while (cur != NULL) {
			StackPush(&stack, cur);
			cur = cur->left;
		}
		// top 的 左子树 已经遍历过了
		top = StackTop(&stack);

		if (top->right == NULL || top->right == last) {
			// 如果右子树被遍历过了
			StackPop(&stack);

			// 替换掉原来的打印
			BTreeNode *t = top->left;
			top->left = top->right;
			top->right = t;

			// 记录这个被遍历的结点
			last = top;
		}
		else {
			// 如果右子树没有被遍历过
			cur = top->right;
		}
	}
}
