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

//查找（递归）
//找到返回1，没找到返回0
int BSTreeFind(const BSTreeNode *root, DataType key)
{
	//空树
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

//非递归
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

// 插入（非递归）
int BSTreeInsert(BSTreeNode **root, DataType key)
{
	BSTreeNode *cur = *root;
	BSTreeNode *parent = NULL;

	while (cur != NULL){
		//重复了，插入失败
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
		//空树中插入
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

//插入（递归）
int BSTreeInsert2(BSTreeNode **root, DataType key)
{
	//空树，直接插入
	if (root == NULL){
		BSTreeNode *node = (BSTreeNode *)malloc(sizeof(BSTreeNode));
		node->key = key;
		node->left = node->right = NULL;
		*root == node;
		return 1;
	}

	if (key == (*root)->key){
		//重复了，插入失败
		return 0;
	}
	else if (key > (*root)->key){
		// 这个是不对的，更改的只是栈上临时变量的值
		// BSTreeNode *child = (*root)->right;
		// return BSTreeInsert2(&child, key);
		return BSTreeInsert2(&(*root)->right, key);
	}
	else{
		return BSTreeInsert2(&(*root)->left, key);
	}
}

//中序遍历
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
删除(非递归)
*/
// 找到就删除，返回成功 1
// 没找到删除失败，返回 0
/*
1.叶子结点 ， 直接删除
2.只有一个孩子（子树），继承大统
3.替换法删除
	不是删除这个结点，仅替换左子树最大 or 右子树最小
	左子树的最大值   沿着左孩子，一路向右，直到->right == NULL
	右子树的最小值   相反
*/

//删除左为空的情况
static void RemoveLeftNULL(DataType key, BSTreeNode *parent, BSTreeNode **root, BSTreeNode * cur)
{
	if (parent == NULL){
		//要删除的就是根结点
		*root = cur->right;
	}
	else{
		if (key < parent->key){
			// cur 是 parent 的 left
			parent->left = cur->right;
		}
		else{
			// cur 是 parent 的 right
			parent->right = cur->right;
		}
	}

	free(cur);
}

//删除右为空的情况
static void RemoveRightNULL(DataType key, BSTreeNode *parent, BSTreeNode **root, BSTreeNode * cur)
{
	if (parent == NULL){
		//要删除的就是根结点
		*root = cur->left;
	}
	else{
		if (key < parent->key){
			// cur 是 parent 的 left
			parent->left = cur->left;
		}
		else{
			// cur 是 parent 的 right
			parent->right = cur->left;
		}
	}

	free(cur);
}

// 左右孩子都不为空
static void RemoveHasLeftAndRight(BSTreeNode *cur)
{
	//找左子树中最大的
	BSTreeNode *del = cur->left;
	BSTreeNode *delParent = NULL;
	while (del->right != NULL){
		delParent = del;
		del = del->right;
	}
	// del 就是左子树中最大的

	cur->key = del->key;
	//删除 del 结点
	if (delParent == NULL){
		// 左孩子中最大的就是 cur 的左孩子
		cur->left = del->left;
	}
	else{
		delParent->right = del->left;
	}

	free(del);
}

int BSTreeNodeRemove(BSTreeNode **root, DataType key)
{
	//先查找，后删除
	BSTreeNode *cur = *root;
	BSTreeNode *parent = NULL;

	while (cur != NULL){
		if (key == cur->key){
			//这里找到了，这里是删除的地方
			if (cur->left == NULL){
				// cur 没有左孩子
				RemoveLeftNULL(key, parent, root, cur);
			}
			else if (cur->right == NULL){
				// cur 没有右孩子
				RemoveRightNULL(key, parent, root, cur);
			}
			else{
				// 左右孩子都不为空
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

//删除（递归）
int BSTreeNodeRemove2(BSTreeNode **root, DataType key)
{
	if (*root == NULL){
		return 0;
	}

	if (key == (*root)->key){
		BSTreeNode *del = *root;
		if ((*root)->left == NULL){
			// 1. 要删除的是不是根
			// 2. 判断要删除的结点是根的左还是右
			*root = (*root)->right;
			free(del);
		}
		else if ((*root)->right == NULL){
			*root = (*root)->left;
			free(del);
		}
		else{
			//左右都不为空
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