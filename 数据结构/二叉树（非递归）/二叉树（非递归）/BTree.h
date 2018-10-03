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
���������������ȣ�
*/
void LevelOrder(BTreeNode *root)
{
	Queue queue;
	QueueInit(&queue);
	BTreeNode *front;

	if (root == NULL){
		return;
	}

	QueuePush(&queue, root);    //�ŵ��ǽ�㣬���ǽ��� data
	while (!QueueEmpty(&queue)){
		front = QueueFront(&queue);
		QueuePop(&queue);

		//front���������սڵ㲻Ҫ
		//�����㣬���ҽ��
		if (front->left != NULL){
			QueuePush(&queue, front->left);
		}

		if (front->right != NULL){
			QueuePush(&queue, front->right);
		}

		//������� front �ڵ�
		printf("%d  ", front->data);
	}

	QueueDestroy(&queue);
}

/*
�ж�һ�����ǲ�����ȫ������
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

		//�Ͳ������������front �п���Ϊ NULL
		if (front == NULL){
			//�������ȫ��������ʣ�µĽ��ȫ�� NULL
			break;
		}
		QueuePush(&queue, front->left);
		QueuePush(&queue, front->right);
	}

	//����ʣ�����Ƿ��� NULL
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
�ǵݹ����
*/

//�ǵݹ�ǰ�����
//ջ�ﱣ����� ������û�б����Ľ��
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
		//top �������� �� ���Ѿ���������
		top = StackTop(&stack);  //ȡԪ��
		StackPop(&stack);

		//
		cur = top->right;
	}
}

//�ǵݹ��������
//ջ�ﱣ����� ������ �� �� û�б����Ľ��
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
		//top ���������Ѿ���������
		top = StackTop(&stack);  //ȡԪ��
		StackPop(&stack);
		printf("%d  ", top->data);

		//�����������˼��ȥ����������
		cur = top->right;
	}
}

//�ǵݹ�������
void PostOrderLoop(BTreeNode *root)
{
	Stack stack;
	StackInit(&stack);
	//last��һ���������Ľ��
	BTreeNode *cur, *top;
	BTreeNode *last = NULL;
	cur = root;

	while (cur != NULL || !StackEmpty(&stack)){
		//����������
		while (cur != NULL){
			StackPush(&stack, cur);
			cur = cur->left;
		}

		//top ���������Ѿ���������
		top = StackTop(&stack);  //ȡԪ��

		if (top->right == NULL || top->right == last){
			//�������������������
			StackPop(&stack);
			printf("%d  ", top->data);

			//��¼������������Ľ��
			last = top;
		}
		else{
			//���������û�б�����
			cur = top->right;
		}
	}
}

/*
����
*/
//�ݹ�
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

//�ǵݹ�
void Mirror2(BTreeNode *root)
{
	Stack	stack;
	StackInit(&stack);
	// last ��һ���������Ľ��
	BTreeNode *cur, *top, *last = NULL;
	cur = root;

	while (cur != NULL || !StackEmpty(&stack)) {
		// ����������
		while (cur != NULL) {
			StackPush(&stack, cur);
			cur = cur->left;
		}
		// top �� ������ �Ѿ���������
		top = StackTop(&stack);

		if (top->right == NULL || top->right == last) {
			// �������������������
			StackPop(&stack);

			// �滻��ԭ���Ĵ�ӡ
			BTreeNode *t = top->left;
			top->left = top->right;
			top->right = t;

			// ��¼����������Ľ��
			last = top;
		}
		else {
			// ���������û�б�������
			cur = top->right;
		}
	}
}
