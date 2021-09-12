#include"List.h"

int main()
{
	ListNode*head = ListCreate();
	ListPushBack(head, 1);
	ListPushBack(head, 2);
	ListPushBack(head, 3);
	ListPushBack(head, 4);
	ListPushBack(head, 5);
	ListPushBack(head, 6);
	ListPushBack(head, 7);
	ListPushBack(head, 8);
	ListPopBack(head);
	ListPushFront(head, 0);
	ListPopFront(head);
	ListPrint(head);
	return 0;
}