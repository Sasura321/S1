#pragma once

#include"List.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

/*
*��βͷ����ӡ������
*/
void PrintReverse(ListNode *first)
{
	ListNode *end = NULL;
	while (end != first)
	{
		ListNode *cur = first;
		
		//�ҵ�Ҫ��ӡ�Ľ��
		while (cur->next != end)
		{
			cur = cur->next;
		}
		printf("%d  ", cur->data);
		end = cur;
	}
	printf("\n");
}

//�ݹ�
void PrintReverseRecursion(ListNode *first)
{
	if (first->next == NULL){
		printf("%d  ", first->data);
	}
	else{
		PrintReverseRecursion(first->next);
		//�����г��� first ֮������н�㶼�����ӡ��
		printf("%d  ", first->data);
	}
}

/*
*��ת/��ת������
*/  

/*����������������
�������ú������ĵ�һ������ַ��ԭ������Ч
1-->2-->3-->4-->5
5-->4-->3-->2-->1 */ 
ListNode *ReverseList(ListNode *first)
{
	ListNode *cur = first;
	ListNode *node;
	ListNode *result = NULL;

	while (cur != NULL)
	{
		//��ԭ��������ͷɾ����ժ������û������ɾ����
		node = cur;
		cur = cur->next;

		//node ���Ǳ�ժ�����Ľ��
		node->next = result;
		result = node;
	}
	return result;
}

//������
//1-->2-->3-->4-->5-->NULL
//NULL<--1<--2<--3<--4<--5
ListNode *ReverseList2(ListNode *first)
{
	ListNode *p1 = NULL;
	ListNode *p2 = first;
	ListNode *p3 = first->next;

	while (p2 != NULL)
	{
		p2->next = p1;

		p1 = p2;
		p2 = p3;
		if (p3 != NULL)
		{
			p3 = p3->next;
		}
	}

	return p1;
}


//ɾ��һ����ͷ������ķ�β�ڵ㣨���ܱ�������
void RemoveNoFirst(ListNode *pos)
{
	pos->data = pos->next->data;
	ListNode *del = pos->next;
	pos->next = pos->next->next;

	free(del);
}

//����ͷ�������һ���ڵ�ǰ����һ���ڵ㣨���ܱ�������
void InsertNoFirst(ListNode *pos, DataType data)
{
	ListNode *cur = pos;
	cur->next = pos->next;
	pos->next = cur;

	pos->data = data;
}

/*
*Լɪ��
*/
ListNode *JosephCycle(ListNode *first, int k)
{
	//��һ���������ɻ�
	ListNode *tail = first;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	//tail�������һ���ڵ�
	tail->next = first;

	//�ڶ���
	ListNode *cur = first;
	//����������������ֻ��һ�����
	while (cur->next == NULL){
		ListNode *prev = NULL;
		for (int i = 0; i < k - 1; i++){
			prev = cur;
			cur = cur->next;
		}

		//cur��������Ҫɾ���Ľ��
		prev->next = cur->next;
		free(cur);

		//��ѭ������
		cur = prev->next;
	}

	cur->next = NULL;
	return cur;

}

/*
* �ϲ��������������ϲ�����Ȼ��������
*/
ListNode* MergeOrderedList(ListNode *list1, ListNode *list2)
{
	assert(list1);
	assert(list2);

	ListNode *p1 = list1;
	ListNode *p2 = list2;
	ListNode *result = NULL;

	while (p1 != NULL && p2 != NULL)
	{
		if (p1->data < p2->data){
			ListPushBack(&result, p1->data);
			p1 = p1->next;
		}
		else{
			ListPushBack(&result, p2->data);
			p2 = p2->next;
		}
	}

	// һ������Ϊ����
	if (p1 == NULL) {
		while (p2 != NULL){
			ListPushBack(&result, p2->data);
			p2 = p2->next;
		}
	}

	if (p2 == NULL) {
		while (p1 != NULL){
			ListPushBack(&result, p1->data);
			p1 = p1->next;
		}
	}

	return result;
}

// �Ż�
ListNode * MergeOrderedListAd(ListNode *list1, ListNode *list2)
{
	ListNode *cur1 = list1;
	ListNode *cur2 = list2;
	ListNode *result = NULL;  //�������
	ListNode *tail = NULL;    //�����������һ����㣬����β��
	ListNode *next;           //����������̵���һ�����
	ListNode *node;

	while (cur1 != NULL && cur2 != NULL)
	{
		if (cur1->data <= cur2->data)
		{
			node = cur1;
		}
		else
		{
			node = cur2;
		}
		next = node->next;
		if (result != NULL)
		{
			//����Ϊ�գ�����β�崦��
			tail->next = node;
		}
		else
		{
			//�����������һ����㣬��ѭ������
			result = node;
		}

		node->next = NULL;
		//�����µ����һ�����
		tail = node;

		if (node == cur1)
		{
			cur1 = next;
		}
		else
		{
			cur2 = next;
		}

		//һ���������
		if (cur1 == NULL)
		{
			tail->next = cur2;
		}
		if (cur2 == NULL)
		{
			tail->next = cur1;
		}

		return result;
	}
}

/*
**��������������������ͬ�����ݡ�void Unionset(Node *list1,Node *list2)
*/

void Unionset(ListNode *list1, ListNode *list2)
{
	ListNode *cur1 = list1;
	ListNode *cur2 = list2;

	while (cur1 != NULL && cur2 != NULL)
	{
		if (cur1->data < cur2->data)
		{
			cur1 = cur1->next;
		}
		else if (cur1->data > cur2->data)
		{
			cur2 = cur2->next;
		}
		else
		{
			printf("%d  ", cur1->data);
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
	}

	printf("\n");
}

void UnionsetDup(ListNode *list1, ListNode *list2)
{
	ListNode *cur1 = list1;
	ListNode *cur2 = list2;
	DataType data;

	while (cur1 != NULL && cur2 != NULL)
	{
		if (cur1->data < cur2->data)
		{
			cur1 = cur1->next;
		}
		else if (cur1->data > cur2->data)
		{
			cur2 = cur2->next;
		}
		else
		{
			printf("%d  ", cur1->data);
			data = cur1->data;

			while (cur1 != NULL && cur1->data == data)
			{
				cur1 = cur1->next;
			}
			while (cur2 != NULL && cur2->data == data)
			{
				cur2 = cur2->next;
			}
		}
	}

	printf("\n");
}

/*
**��ѯ��������м��㣬Ҫ��ֻ����һ��
*/
void FindMid(ListNode *first)
{
	ListNode *fast = first;
	ListNode *slow = first;

	while (1)
	{
		fast = fast->next;
		if (fast == NULL)
		{
			break;
		}
		fast = fast->next;
		if (fast == NULL)
		{
			break;
		}
		slow = slow->next;
	}
	printf("%d\n", slow->data);
}

/*
**���ҵ�����ĵ�����k����㣬Ҫ��ֻ����һ������
*/
//ǰ��ָ��
void FindTailK(ListNode *first, int k)
{
	ListNode *forward = first;
	ListNode *backward = first;

	while (k--)
	{
		forward = forward->next;
	}

	while (forward != NULL)
	{
		forward = forward->next;
		backward = backward->next;
	}

	printf("%d\n", backward->data);
}

//��ӡ����
void PrintResult(ListNode* result)
{
	ListNode *cur;

	for (cur = result; cur != NULL; cur = cur->next)
	{
		printf("%d->", cur->data);
	}
	printf("NULL\n");
}



