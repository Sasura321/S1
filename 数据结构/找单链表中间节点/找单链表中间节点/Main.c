#include"List.h"

int main()
{
	ListNode *first = NULL;
	ListPushBack(&first, 1);
	ListPushBack(&first, 2);
	ListPushBack(&first, 3);
	ListPushBack(&first, 4);
	ListPushBack(&first, 5);

	FindMid(first);
	return 0;
}