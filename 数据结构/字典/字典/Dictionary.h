//（搜索二叉树）
//日期8.30-----时间2:06

#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
判断一个单词是否拼写正确
*/

typedef struct Word{
	char   word[20];
	struct Word *left;
	struct Word *right;
}	Word;

//查找
int WordFind(const Word *root, char word[])
{
	const Word *cur = root;
	int r;

	while (cur != NULL){
		r = strncmp(word, cur->word, 20); //比较两个字符
		if (r == 0){
			return 1;
		}
		else if (r < 0){
			return cur->left;
		}
		else{
			return cur->right;
		}
	}

	return 0;
}

//插入（递归）
int WordInsert(Word **root, char word[])
{
	//空树，直接插入
	if (root == NULL){
		Word *node = (Word *)malloc(sizeof(Word));
		strncpy(node->key, key, 20);
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