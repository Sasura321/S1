#include "List.h"

void TestReverseList()
{
	ListNode *list1 = NULL;
	ListPush(&list1, 1);
	ListPush(&list1, 2);
	ListPush(&list1, 3);
	ListPush(&list1, 5);
	ListPush(&list1, 7);

	ListNode *list2 = NULL;
	ListPush(&list2, 4);
	ListPush(&list2, 6);
	ListPush(&list2, 8);
	ListPush(&list2, 9);

	ListNode* result = UnionList(list1, list2);
	PrintResult(result);
	printf("\n");
}


int main()
{
	TestReverseList();
	return 0;
}