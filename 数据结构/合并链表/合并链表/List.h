#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;

typedef struct ListNode {
	DataType data;
	struct ListNode *next;
}	ListNode;

void ListPush(ListNode **ppFirst, DataType data)
{
	ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
	assert(newNode);
	newNode->data = data;
	newNode->next = NULL;

	if (*ppFirst == NULL) {
		*ppFirst = newNode;
		return;
	}
	ListNode *cur = *ppFirst;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	cur->next = newNode;
}

/*
*�ϲ���������������ʹ�ϳɵ���������
*/

ListNode *MergeOrderdList(ListNode *list1, ListNode *list2)
{
	ListNode *cur1 = list1;
	ListNode *cur2 = list2;
	ListNode *result = NULL; //�������
	ListNode *tail = NULL;   //��������е����һ����㣬����β��
	ListNode *next;          //��������������е���һ�����

	while (cur1 != NULL && cur1 != NULL){
		if (cur1->data <= cur2->data){
			//Ӧ��ȡ���� 1 �Ľڵ�
			if (result != NULL){
				tail->next = cur1;

			}
		}
	}

}

ListNode* UnionList(ListNode *list1, ListNode *list2)
{
	assert(list1);
	assert(list2);

	ListNode *p1 = list1;
	ListNode *p2 = list2;
	ListNode *result = NULL;

	while (p1 != NULL && p2 != NULL)
	{
		if (p1->data < p2->data){
			ListPush(&result, p1->data);
			p1 = p1->next;
		}
		else{
			ListPush(&result, p2->data);
			p2 = p2->next;
		}
	}

	// һ������Ϊ����
	if (p1 == NULL) {
		while (p2 != NULL){
			ListPush(&result, p2->data);
			p2 = p2->next;
		}
	}

	if (p2 == NULL) {
		while (p1 != NULL){
			ListPush(&result, p1->data);
			p1 = p1->next;
		}
	}

	return result;
}

void PrintResult(ListNode* result)
{
	ListNode *cur;

	for (cur = result; cur != NULL; cur = cur->next)
	{
		printf("%d  ", cur->data);
	}
}