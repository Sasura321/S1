//��������������
//����8.30-----ʱ��2:06

#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
�ж�һ�������Ƿ�ƴд��ȷ
*/

typedef struct Word{
	char   word[20];
	struct Word *left;
	struct Word *right;
}	Word;

//����
int WordFind(const Word *root, char word[])
{
	const Word *cur = root;
	int r;

	while (cur != NULL){
		r = strncmp(word, cur->word, 20); //�Ƚ������ַ�
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

//���루�ݹ飩
int WordInsert(Word **root, char word[])
{
	//������ֱ�Ӳ���
	if (root == NULL){
		Word *node = (Word *)malloc(sizeof(Word));
		strncpy(node->key, key, 20);
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