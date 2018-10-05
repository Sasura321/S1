#include"链表面试题.h"

//测试
void TestPrintReverse()
{
	ListNode *first = NULL;
	ListPushBack(&first, 1);
	ListPushBack(&first, 2);
	ListPushBack(&first, 3);
	ListPushBack(&first, 4);
	ListPushBack(&first, 5);

	printf("倒序打印：");
	PrintReverse(first);
	printf("递归：");
	PrintReverseRecursion(first);
	printf("\n");

	ListNode *result = ReverseList(first);
	printf("逆置打印：");
	PrintResult(result);

	ListNode *sur = JosephCycle(first, 4);
	printf("约瑟夫环：%d \n", sur->data);

	ListNode *list1 = NULL;
	ListPushBack(&list1, 1);
	ListPushBack(&list1, 2);
	ListPushBack(&list1, 3);
	ListPushBack(&list1, 5);
	ListPushBack(&list1, 7);

	ListNode *list2 = NULL;
	ListPushBack(&list2, 4);
	ListPushBack(&list2, 6);
	ListPushBack(&list2, 8);
	ListPushBack(&list2, 9);

	printf("合并链表：");
	PrintResult(MergeOrderedList(list1, list2));

	printf("找相同数据：");
	ListNode *list3 = NULL, *list4 = NULL;
	ListPushBack(&list3, 1);
	ListPushBack(&list3, 3);
	ListPushBack(&list3, 4);
	ListPushBack(&list3, 5);

	ListPushBack(&list4, 1);
	ListPushBack(&list4, 2);
	ListPushBack(&list4, 4);

	Unionset(list3, list4);
	UnionsetDup(list3, list4);

	printf("找中间结点：");
	FindMid(first);

	printf("倒数第k个结点：");
	FindTailK(list1, 3);

}

int main()
{
	TestPrintReverse();
	return 0;
}

