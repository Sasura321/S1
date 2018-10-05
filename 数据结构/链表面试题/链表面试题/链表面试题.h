#pragma once

#include"List.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

/*
*从尾头到打印单链表
*/
void PrintReverse(ListNode *first)
{
	ListNode *end = NULL;
	while (end != first)
	{
		ListNode *cur = first;
		
		//找到要打印的结点
		while (cur->next != end)
		{
			cur = cur->next;
		}
		printf("%d  ", cur->data);
		end = cur;
	}
	printf("\n");
}

//递归
void PrintReverseRecursion(ListNode *first)
{
	if (first->next == NULL){
		printf("%d  ", first->data);
	}
	else{
		PrintReverseRecursion(first->next);
		//链表中除了 first 之外的所有结点都逆序打印了
		printf("%d  ", first->data);
	}
}

/*
*逆转/反转单链表
*/  

/*传入链表，进行逆置
返回逆置后的链表的第一个结点地址，原链表将无效
1-->2-->3-->4-->5
5-->4-->3-->2-->1 */ 
ListNode *ReverseList(ListNode *first)
{
	ListNode *cur = first;
	ListNode *node;
	ListNode *result = NULL;

	while (cur != NULL)
	{
		//从原来链表中头删（光摘下来，没有真正删除）
		node = cur;
		cur = cur->next;

		//node 就是被摘下来的结点
		node->next = result;
		result = node;
	}
	return result;
}

//方法二
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


//删除一个无头单链表的非尾节点（不能遍历链表）
void RemoveNoFirst(ListNode *pos)
{
	pos->data = pos->next->data;
	ListNode *del = pos->next;
	pos->next = pos->next->next;

	free(del);
}

//在无头单链表的一个节点前插入一个节点（不能遍历链表）
void InsertNoFirst(ListNode *pos, DataType data)
{
	ListNode *cur = pos;
	cur->next = pos->next;
	pos->next = cur;

	pos->data = data;
}

/*
*约瑟夫环
*/
ListNode *JosephCycle(ListNode *first, int k)
{
	//第一步，链表构成环
	ListNode *tail = first;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	//tail就是最后一个节点
	tail->next = first;

	//第二步
	ListNode *cur = first;
	//结束条件是链表中只有一个结点
	while (cur->next == NULL){
		ListNode *prev = NULL;
		for (int i = 0; i < k - 1; i++){
			prev = cur;
			cur = cur->next;
		}

		//cur就是我们要删除的结点
		prev->next = cur->next;
		free(cur);

		//让循环继续
		cur = prev->next;
	}

	cur->next = NULL;
	return cur;

}

/*
* 合并两个有序链表，合并后依然有序（升序）
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

	// 一个链表为空了
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

// 优化
ListNode * MergeOrderedListAd(ListNode *list1, ListNode *list2)
{
	ListNode *cur1 = list1;
	ListNode *cur2 = list2;
	ListNode *result = NULL;  //结果链表
	ListNode *tail = NULL;    //结果链表的最后一个结点，方便尾插
	ListNode *next;           //保存遍历过程的下一个结点
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
			//链表不为空，则做尾插处理
			tail->next = node;
		}
		else
		{
			//保存链表的下一个结点，让循环继续
			result = node;
		}

		node->next = NULL;
		//保存新的最后一个结点
		tail = node;

		if (node == cur1)
		{
			cur1 = next;
		}
		else
		{
			cur2 = next;
		}

		//一个链表空了
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
**求两个已排序单链表中相同的数据。void Unionset(Node *list1,Node *list2)
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
**查询单链表的中间结点，要求只遍历一遍
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
**查找单链表的倒数第k个结点，要求只遍历一次链表
*/
//前后指针
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

//打印链表
void PrintResult(ListNode* result)
{
	ListNode *cur;

	for (cur = result; cur != NULL; cur = cur->next)
	{
		printf("%d->", cur->data);
	}
	printf("NULL\n");
}



