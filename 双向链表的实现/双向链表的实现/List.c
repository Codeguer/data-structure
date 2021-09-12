#include"List.h"

// 创建返回链表的头结点.
ListNode* ListCreate()
{
	ListNode*head = (ListNode*)malloc(sizeof(ListNode));
	head->_next = head;
	head->_prev = head;
	return head;
}
// 双向链表销毁
void ListDestory(ListNode* plist)
{
	assert(plist);
	ListNode* cur = plist->_next;
	while (cur != plist)//带头双向循环链表cur不可能为空
	{
		plist->_next = cur->_next;
		free(cur);
		cur = plist->_next;
	}
	free(plist);
	plist = NULL;
}
// 双向链表打印
void ListPrint(ListNode* plist)
{
	assert(plist);
	ListNode* cur = plist->_next;
	while (cur != plist)//带头双向循环链表cur不可能为空
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
// 双向链表尾插
void ListPushBack(ListNode* plist, LTDataType x)
{
	/*assert(plist);
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->_data = x;
	newnode->_prev = plist->_prev;
	newnode->_next = plist;
	plist->_prev = newnode;
	newnode->_prev->_next = newnode;*/
	ListInsert(plist, x);
}
// 双向链表尾删
void ListPopBack(ListNode* plist)
{
	/*assert(plist);
	if (plist->_prev == plist)
		return;
	plist->_prev = plist->_prev->_prev;
	free(plist->_prev->_next);
	plist->_prev->_next = plist;*/
	ListErase(plist->_prev);
}
// 双向链表头插
void ListPushFront(ListNode* plist, LTDataType x)
{
	/*assert(plist);
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->_data = x;
	plist->_next->_prev = newnode;
	newnode->_next = plist->_next;
	newnode->_prev = plist;
	plist->_next = newnode;*/
	ListInsert(plist->_next, x);
}
// 双向链表头删
void ListPopFront(ListNode* plist)
{
	/*assert(plist);
	if (plist->_next == plist)
		return;
	plist->_next = plist->_next->_next;
	free(plist->_next->_prev);
	plist->_next->_prev = plist;*/
	ListErase(plist->_next);
}
// 双向链表查找
ListNode* ListFind(ListNode* plist, LTDataType x)
{
	assert(plist);
	ListNode*cur = plist->_next;
	while (cur != plist)
	{
		if (cur->_data == x)
			return cur;
		cur = cur->_next;
	}
	return NULL;
}
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode*newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->_data = x;
	newnode->_prev = pos->_prev;
	newnode->_next = pos;
	pos->_prev = newnode;
	newnode->_prev->_next = newnode;
}
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);
}