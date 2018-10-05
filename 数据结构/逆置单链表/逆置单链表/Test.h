#include "List.h"

void PrintReverseList(ListNode *result)
{
	ListNode *cur = result;
	for (cur = result; cur != NULL; cur = cur->next){
		printf("%d -> ", cur->data);
	}
}

void TestReverseList()
{
	ListNode *first = NULL;
	ListPushBack(&first, 1);
	ListPushBack(&first, 2);
	ListPushBack(&first, 3);
	ListPushBack(&first, 4);
	ListPushBack(&first, 5);

	ListNode *result = NULL;
	result = ReverseList(first);
	PrintReverseList(result);
	printf("\n");
}