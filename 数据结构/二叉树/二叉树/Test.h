#pragma once
#include"Btree.h"

void test()
{
	int preOrder[] = { 1, 2, 3, -1, 4, 5, -1, -1, -1, 6, -1, -1, 7, 8, -1, -1, 9, -1, 0 };
	int size = sizeof (preOrder) / sizeof(int);
	int pUsedSize;
	BTreeNode *root = CreateTree(preOrder, size, &pUsedSize);

	printf("ǰ�������> ");
	PreOrder(root);
	printf("\n���������> ");
	InOrder(root);
	printf("\n���������> ");
	PostOrder(root);
	printf("\n");

	printf("�ڵ����(����һ)��> %d\n", GetSize1(root));
	printf("�ڵ����(������)��> ");
	GetSize2(root);
	printf("%d\n",count);

	printf("Ҷ�ӽڵ����(����һ)��> %d\n", GetLeafSize(root));
	printf("Ҷ�ӽڵ����(������)��> ");
	GetLeafSize2(root);
	printf("%d\n", num);

	printf("��k��ڵ������> %d\n", GetLeafKSize(root, 4));
	printf("�߶ȣ�> %d\n", GetHight(root));
	
	if (Find(root, 5) != NULL){
		printf("���ҳɹ�\n");
	}
	else{
		printf("����ʧ��\n");
	}

}
