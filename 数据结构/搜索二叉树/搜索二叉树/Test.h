#pragma once

#include "BSTree.h"

void test()
{
	int r;
	BSTreeNode *root = NULL;
	r = BSTreeInsert(&root, 5); printf("���� %s\n", r ? "�ɹ�" : "ʧ��");
	r = BSTreeInsert(&root, 3); printf("���� %s\n", r ? "�ɹ�" : "ʧ��");
	r = BSTreeInsert(&root, 7); printf("���� %s\n", r ? "�ɹ�" : "ʧ��");
	r = BSTreeInsert(&root, 1); printf("���� %s\n", r ? "�ɹ�" : "ʧ��");
	r = BSTreeInsert(&root, 4); printf("���� %s\n", r ? "�ɹ�" : "ʧ��");
	r = BSTreeInsert(&root, 6); printf("���� %s\n", r ? "�ɹ�" : "ʧ��");
	r = BSTreeInsert(&root, 8); printf("���� %s\n", r ? "�ɹ�" : "ʧ��");
	r = BSTreeInsert(&root, 0); printf("���� %s\n", r ? "�ɹ�" : "ʧ��");
	r = BSTreeInsert(&root, 2); printf("���� %s\n", r ? "�ɹ�" : "ʧ��");
	r = BSTreeInsert(&root, 9); printf("���� %s\n", r ? "�ɹ�" : "ʧ��");
	r = BSTreeInsert(&root, 10); printf("���� %s\n", r ? "�ɹ�" : "ʧ��");

	InOrder(root); printf("\n");

	r = BSTreeFind(root, 9); printf("���� 9 %s\n", r ? "�ɹ�" : "ʧ��");
	r = BSTreeFind2(root, 10); printf("���� 10 %s\n", r ? "�ɹ�" : "ʧ��");

	BSTreeNodeRemove(&root, 8); 
	BSTreeNodeRemove(&root, 2);
	BSTreeNodeRemove(&root, 5); 
}