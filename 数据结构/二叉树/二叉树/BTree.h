#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int TDataType;

typedef struct BTreeNode{
	TDataType data;
	struct BTreeNode *left;
	struct BTreeNode *right;
}	BTreeNode;

BTreeNode *CreateNode(int data)
{
	BTreeNode *node = (BTreeNode*)malloc(sizeof(BTreeNode));
	node->data = data;
	node->left = node->right = NULL;

	return node;
}

/*
����һ�ö�����
*/
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
����������
*/

//ǰ�����
void PreOrder(BTreeNode *root)
{
	//���ǿ���
	if (root == NULL){
		return;
	}

	printf(" %d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}

//�������
void InOrder(BTreeNode *root)
{
	if (root == NULL){
		return;
	}

	InOrder(root->left);
	printf(" %d ", root->data);
	InOrder(root->right);
}

//�������
void PostOrder(BTreeNode *root)
{
	if (root == NULL){
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf(" %d ", root->data);
}

/*
�������ܽڵ����
*/
//����һ
int GetSize1(BTreeNode *root)
{
	if (root == NULL){
		return 0;
	}

	int left = GetSize1(root->left);
	int right = GetSize1(root->right);

	return left + right + 1;
}

//������
int count = 0;
void GetSize2(BTreeNode *root)
{
	if (root == NULL){
		return;
	}

	GetSize2(root->left);
	GetSize2(root->right);
	count++;
}

/*
��Ҷ�ӽڵ����
*/
int GetLeafSize(BTreeNode *root)
{
	if (root == NULL){
		return 0;
	}

	if (root->left == NULL && root->right == NULL){
		return 1;
	}

	return GetLeafSize(root->left) + GetLeafSize(root->right);
}

//������
int num = 0;
void GetLeafSize2(BTreeNode *root)
{
	if (root == NULL){
		return 0;
	}

	if (root->left == NULL && root->right == NULL){
		num++;
	}

	GetLeafSize2(root->left);
	GetLeafSize2(root->right);
}

/*
���k��Ľڵ����
*/
int GetLeafKSize(BTreeNode *root,int k)
{
	if (root == NULL){
		//����������㶼��0
		return 0;
	}

	if (k == 1){
		// ��һ��ֻ�и��ڵ�һ��
		return 1;
	}

	int left = GetLeafKSize(root->left, k - 1);
	int right = GetLeafKSize(root->right, k - 1);

	return left + right;
}

/*
��߶�/���
*/ 
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

	result = Find(root->right,data);
	if (result != NULL){
		//�������ҵ���
		return result;
	}
	else{
		//û���ҵ�
		return NULL;
	}
}