#pragma once 

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;

typedef struct BSTreeNode{
	DataType key;
	struct BSTreeNode *left;
	struct BSTreeNode *right;
}	BSTreeNode;

//���ң��ݹ飩
//�ҵ�����1��û�ҵ�����0
int BSTreeFind(const BSTreeNode *root, DataType key)
{
	//����
	if (root == NULL){
		return 0;
	}

	if (key == root->key){
		return 1;
	}

	else if (key > root->key){
		return BSTreeFind(root->right, key);
	}
	else{
		return BSTreeFind(root->left, key);
	}
}

//�ǵݹ�
int BSTreeFind2(const BSTreeNode *root, DataType key)
{
	BSTreeNode *cur = (BSTreeNode*)root;

	while (cur != NULL){
		if (key == cur->key){
			return 1;
		}
		else if (key > cur->key){
			cur = cur->right;
		}
		else{
			cur = cur->left;
		}
	}

	return 0;
}

// ���루�ǵݹ飩
int BSTreeInsert(BSTreeNode **root, DataType key)
{
	BSTreeNode *cur = *root;
	BSTreeNode *parent = NULL;

	while (cur != NULL){
		//�ظ��ˣ�����ʧ��
		if (key == cur->key){
			return 0;
		}
		else if (key > cur->key){
			cur = cur->right;
		}
		else{
			cur = cur->left;
		}
	}
	free(cur);

	BSTreeNode *node = (BSTreeNode *)malloc(sizeof(BSTreeNode));
	node->key = key;
	node->left = node->right = NULL;

	if (parent == NULL){
		//�����в���
		*root = node;
		return 1;
	}
	else if(key > parent->key){
		parent->right = node;
	}
	else{
		parent->left = node;
	}

	return 1;
}

//���루�ݹ飩
int BSTreeInsert2(BSTreeNode **root, DataType key)
{
	//������ֱ�Ӳ���
	if (root == NULL){
		BSTreeNode *node = (BSTreeNode *)malloc(sizeof(BSTreeNode));
		node->key = key;
		node->left = node->right = NULL;
		*root == node;
		return 1;
	}

	if (key == (*root)->key){
		//�ظ��ˣ�����ʧ��
		return 0;
	}
	else if (key > (*root)->key){
		// ����ǲ��Եģ����ĵ�ֻ��ջ����ʱ������ֵ
		// BSTreeNode *child = (*root)->right;
		// return BSTreeInsert2(&child, key);
		return BSTreeInsert2(&(*root)->right, key);
	}
	else{
		return BSTreeInsert2(&(*root)->left, key);
	}
}

//�������
void InOrder(BSTreeNode *root)
{
	if (root == NULL){
		return;
	}
	InOrder(root->left);
	printf("%d  ", root->left);
	InOrder(root->right);
}

/*
ɾ��(�ǵݹ�)
*/
// �ҵ���ɾ�������سɹ� 1
// û�ҵ�ɾ��ʧ�ܣ����� 0
/*
1.Ҷ�ӽ�� �� ֱ��ɾ��
2.ֻ��һ�����ӣ����������̳д�ͳ
3.�滻��ɾ��
	����ɾ�������㣬���滻��������� or ��������С
	�����������ֵ   �������ӣ�һ·���ң�ֱ��->right == NULL
	����������Сֵ   �෴
*/

//ɾ����Ϊ�յ����
static void RemoveLeftNULL(DataType key, BSTreeNode *parent, BSTreeNode **root, BSTreeNode * cur)
{
	if (parent == NULL){
		//Ҫɾ���ľ��Ǹ����
		*root = cur->right;
	}
	else{
		if (key < parent->key){
			// cur �� parent �� left
			parent->left = cur->right;
		}
		else{
			// cur �� parent �� right
			parent->right = cur->right;
		}
	}

	free(cur);
}

//ɾ����Ϊ�յ����
static void RemoveRightNULL(DataType key, BSTreeNode *parent, BSTreeNode **root, BSTreeNode * cur)
{
	if (parent == NULL){
		//Ҫɾ���ľ��Ǹ����
		*root = cur->left;
	}
	else{
		if (key < parent->key){
			// cur �� parent �� left
			parent->left = cur->left;
		}
		else{
			// cur �� parent �� right
			parent->right = cur->left;
		}
	}

	free(cur);
}

// ���Һ��Ӷ���Ϊ��
static void RemoveHasLeftAndRight(BSTreeNode *cur)
{
	//��������������
	BSTreeNode *del = cur->left;
	BSTreeNode *delParent = NULL;
	while (del->right != NULL){
		delParent = del;
		del = del->right;
	}
	// del ����������������

	cur->key = del->key;
	//ɾ�� del ���
	if (delParent == NULL){
		// ���������ľ��� cur ������
		cur->left = del->left;
	}
	else{
		delParent->right = del->left;
	}

	free(del);
}

int BSTreeNodeRemove(BSTreeNode **root, DataType key)
{
	//�Ȳ��ң���ɾ��
	BSTreeNode *cur = *root;
	BSTreeNode *parent = NULL;

	while (cur != NULL){
		if (key == cur->key){
			//�����ҵ��ˣ�������ɾ���ĵط�
			if (cur->left == NULL){
				// cur û������
				RemoveLeftNULL(key, parent, root, cur);
			}
			else if (cur->right == NULL){
				// cur û���Һ���
				RemoveRightNULL(key, parent, root, cur);
			}
			else{
				// ���Һ��Ӷ���Ϊ��
				RemoveHasLeftAndRight(cur);
			}

			return 1;
		}

		parent = cur;
		if (key < cur->key){
			cur = cur->left;
		}
		else{
			cur = cur->right;
		}
	}

	return 0;
}

//ɾ�����ݹ飩
int BSTreeNodeRemove2(BSTreeNode **root, DataType key)
{
	if (*root == NULL){
		return 0;
	}

	if (key == (*root)->key){
		BSTreeNode *del = *root;
		if ((*root)->left == NULL){
			// 1. Ҫɾ�����ǲ��Ǹ�
			// 2. �ж�Ҫɾ���Ľ���Ǹ���������
			*root = (*root)->right;
			free(del);
		}
		else if ((*root)->right == NULL){
			*root = (*root)->left;
			free(del);
		}
		else{
			//���Ҷ���Ϊ��
			RemoveHasLeftAndRight(*root);
		}

		return 1;
	}

	if (key < (*root)->key){
		return BSTreeNodeRemove2(&(*root)->left, key);
	}
	else{
		return BSTreeNodeRemove2(&(*root)->right, key);
	}
}