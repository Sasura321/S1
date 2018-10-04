#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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
查找某一节点是否在给定的无重复节点的二叉树里
*/
BTreeNode *Find(BTreeNode *root, TDataType data)
{
	if (root == NULL){
		return NULL;
	}

	if (root->data == data){
		return root;
	}

	BTreeNode *result = Find(root->left, data);
	if (result != NULL){
		//左子树找到了
		return result;
	}

	result = Find(root->right, data);
	if (result != NULL){
		//右子树找到了
		return result;
	}
	else{
		//没有找到
		return NULL;
	}
}

/*
*求二叉树中两个结点的最近公共祖先结点
*/
//(前提 node1 和 node2 一定在 root 树中)
BTreeNode *GetAncestor(BTreeNode *root,BTreeNode *node1, BTreeNode *node2)
{
	BTreeNode *node1InLeft = Find(root->left, node1->data);
	BTreeNode *node2InLeft = Find(root->left, node2->data);
	BTreeNode *node1InRight = Find(root->right, node1->data);
	BTreeNode *node2InRight = Find(root->right, node2->data);

	//两个结点在不同子树上
	if ((node1InLeft && node2InRight) || (node1InRight && node2InLeft)){
		return root;
	}

	//两个结点在同一子树上
	if (node1InLeft){
		return GetAncestor(root->left, node1, node2);
	}
	if (node2InRight){
		return GetAncestor(root->right, node1, node2);
	}
}

/*
判断一棵树是否是平衡树
*/

// 求高度 / 深度
#define MAX(a,b)  ( (a)>(b) ? (a):(b) )

int GetHight(BTreeNode *root)
{
	//树为空
	if (root == NULL){
		return 0;
	}

	//判断只有一个节点时
	//可写也可不写，写的画可节省两次函数调用
	if (root == 1){
		return 1;
	}

	return MAX(GetHight(root->left), GetHight(root->right)) + 1;
}

//1.左右子树需要是平衡树
//2.左右子树的高度差不超过1
//3.空树是平衡，一棵结点树也是平衡
int IsBalance(BTreeNode *root)
{
	if (root == NULL){
		return 1;
	}

	//判断左子树是否平衡
	int leftBalance = IsBalance(root->left);
	if (!leftBalance){
		return 0;
	}

	//判断右子树是否平衡
	int rightBalance = IsBalance(root->right);
	if (!rightBalance){
		return 0;
	}

	int leftHight = GetHight(root->left);
	int rightHight = GetHight(root->right);

	int dif = leftHight - rightHight;
	if (dif <= 1 && dif >= -1){
		return 1;
	}
	else{
		return 0;
	}
}

//优化
int IsBalanceAd(BTreeNode *root, int *pHight)
{
	if (root == NULL){
		return 1;
	}

	//判断左子树是否平衡
	int leftHight;
	int leftBalance = IsBalanceAd(root->left,&leftHight);
	if (!leftBalance){
		*pHight = -1;   //不平衡的情况，高度没有用，给的值无意义
		return 0;
	}

	//判断右子树是否平衡
	int rightHight;
	int rightBalance = IsBalanceAd(root->right,&rightHight);
	if (!rightBalance){
		*pHight = -1;
		return 0;
	}

	*pHight = MAX(leftHight, rightHight) + 1;

	//高度差不超过1
	int dif = leftHight - rightHight;
	if (dif <= 1 && dif >= -1){
		return 1;
	}
	else{
		return 0;
	}
}

/*
求二叉树中最远的两个结点之间的距离
*/

//1.左子树最远距离   2.右子树在最远距离
int MAX_THREE(int a, int b, int c)
{
	if (a >= b && a >= c){
		return a;
	}

	if (b >= a && b >= c){
		return b;
	}

	return c;
}

//经过根的最远距离 = 左子树高度 + 右子树高度
//终止条件：空树；只有一个结点  return 0;
int GetLongDistance(BTreeNode *root)
{
	if (root == NULL){
		return 0;
	}

	int leftLD = GetLongDistance(root->left);
	int rightLD = GetLongDistance(root->right);
	int leftHeight = GetHight(root->left);
	int rightHeight = GetHight(root->right);
	int rootLD = leftHeight + rightHeight;

	return MAX_THREE(leftLD, rightLD, rootLD);
}

/*
有前序遍历和中序遍历重建二叉树（前序遍历结果：1,2,3,4,5,6 ； 中序遍历结果：4,2,5,1,6,3）
*/
//左子树前序 [1,1+rootIn)   size:rootIn     中序：[0,rootIn)
//右子树前序 [1+rootIn,size) size-1-rootIn  中序：[root+1,size)

// 值不重复
BTreeNode *CreatePreInTree(int preOrder[], int inOrder[], int size)
{
	if (size <= 0){
		return NULL;
	}

	//从前序找到下标
	int rootValue = preOrder[0];

	//从中序中找到根的下标
	int rootInOrder = -1;
	for (int i = 0; i < size; i++){
		if (inOrder[i] == rootValue){
			rootInOrder = i;
		}
	}
	assert(rootInOrder != -1);
	// rootInOrder 既是根在中序中的下标，也是左子树结点的个数

	BTreeNode *root = CreateNode(rootValue);
	root->left = CreatePreInTree(preOrder + 1, inOrder, rootInOrder);
	root->right = CreatePreInTree(preOrder + 1 + rootInOrder, inOrder + 1 + rootInOrder, size - 1 - rootInOrder);

	return root;
}