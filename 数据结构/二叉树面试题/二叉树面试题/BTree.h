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
����һ�ö�����
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
	//���������������
	if (size == 0){
		*pUsedSize = 0;
		return NULL;
	}

	//�������
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
����ĳһ�ڵ��Ƿ��ڸ��������ظ��ڵ�Ķ�������
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
		//�������ҵ���
		return result;
	}

	result = Find(root->right, data);
	if (result != NULL){
		//�������ҵ���
		return result;
	}
	else{
		//û���ҵ�
		return NULL;
	}
}

/*
*���������������������������Ƚ��
*/
//(ǰ�� node1 �� node2 һ���� root ����)
BTreeNode *GetAncestor(BTreeNode *root,BTreeNode *node1, BTreeNode *node2)
{
	BTreeNode *node1InLeft = Find(root->left, node1->data);
	BTreeNode *node2InLeft = Find(root->left, node2->data);
	BTreeNode *node1InRight = Find(root->right, node1->data);
	BTreeNode *node2InRight = Find(root->right, node2->data);

	//��������ڲ�ͬ������
	if ((node1InLeft && node2InRight) || (node1InRight && node2InLeft)){
		return root;
	}

	//���������ͬһ������
	if (node1InLeft){
		return GetAncestor(root->left, node1, node2);
	}
	if (node2InRight){
		return GetAncestor(root->right, node1, node2);
	}
}

/*
�ж�һ�����Ƿ���ƽ����
*/

// ��߶� / ���
#define MAX(a,b)  ( (a)>(b) ? (a):(b) )

int GetHight(BTreeNode *root)
{
	//��Ϊ��
	if (root == NULL){
		return 0;
	}

	//�ж�ֻ��һ���ڵ�ʱ
	//��дҲ�ɲ�д��д�Ļ��ɽ�ʡ���κ�������
	if (root == 1){
		return 1;
	}

	return MAX(GetHight(root->left), GetHight(root->right)) + 1;
}

//1.����������Ҫ��ƽ����
//2.���������ĸ߶Ȳ����1
//3.������ƽ�⣬һ�ý����Ҳ��ƽ��
int IsBalance(BTreeNode *root)
{
	if (root == NULL){
		return 1;
	}

	//�ж��������Ƿ�ƽ��
	int leftBalance = IsBalance(root->left);
	if (!leftBalance){
		return 0;
	}

	//�ж��������Ƿ�ƽ��
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

//�Ż�
int IsBalanceAd(BTreeNode *root, int *pHight)
{
	if (root == NULL){
		return 1;
	}

	//�ж��������Ƿ�ƽ��
	int leftHight;
	int leftBalance = IsBalanceAd(root->left,&leftHight);
	if (!leftBalance){
		*pHight = -1;   //��ƽ���������߶�û���ã�����ֵ������
		return 0;
	}

	//�ж��������Ƿ�ƽ��
	int rightHight;
	int rightBalance = IsBalanceAd(root->right,&rightHight);
	if (!rightBalance){
		*pHight = -1;
		return 0;
	}

	*pHight = MAX(leftHight, rightHight) + 1;

	//�߶Ȳ����1
	int dif = leftHight - rightHight;
	if (dif <= 1 && dif >= -1){
		return 1;
	}
	else{
		return 0;
	}
}

/*
�����������Զ���������֮��ľ���
*/

//1.��������Զ����   2.����������Զ����
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

//����������Զ���� = �������߶� + �������߶�
//��ֹ������������ֻ��һ�����  return 0;
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
��ǰ���������������ؽ���������ǰ����������1,2,3,4,5,6 �� ������������4,2,5,1,6,3��
*/
//������ǰ�� [1,1+rootIn)   size:rootIn     ����[0,rootIn)
//������ǰ�� [1+rootIn,size) size-1-rootIn  ����[root+1,size)

// ֵ���ظ�
BTreeNode *CreatePreInTree(int preOrder[], int inOrder[], int size)
{
	if (size <= 0){
		return NULL;
	}

	//��ǰ���ҵ��±�
	int rootValue = preOrder[0];

	//���������ҵ������±�
	int rootInOrder = -1;
	for (int i = 0; i < size; i++){
		if (inOrder[i] == rootValue){
			rootInOrder = i;
		}
	}
	assert(rootInOrder != -1);
	// rootInOrder ���Ǹ��������е��±꣬Ҳ�����������ĸ���

	BTreeNode *root = CreateNode(rootValue);
	root->left = CreatePreInTree(preOrder + 1, inOrder, rootInOrder);
	root->right = CreatePreInTree(preOrder + 1 + rootInOrder, inOrder + 1 + rootInOrder, size - 1 - rootInOrder);

	return root;
}