#include"List.h"

// �������������ͷ���.
ListNode* ListCreate()
{
	ListNode*head = (ListNode*)malloc(sizeof(ListNode));
	head->_next = head;
	head->_prev = head;
	return head;
}
// ˫����������
void ListDestory(ListNode* plist)
{
	assert(plist);
	ListNode* cur = plist->_next;
	while (cur != plist)//��ͷ˫��ѭ������cur������Ϊ��
	{
		plist->_next = cur->_next;
		free(cur);
		cur = plist->_next;
	}
	free(plist);
	plist = NULL;
}
// ˫�������ӡ
void ListPrint(ListNode* plist)
{
	assert(plist);
	ListNode* cur = plist->_next;
	while (cur != plist)//��ͷ˫��ѭ������cur������Ϊ��
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
// ˫������β��
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
// ˫������βɾ
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
// ˫������ͷ��
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
// ˫������ͷɾ
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
// ˫���������
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
// ˫��������pos��ǰ����в���
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
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	assert(pos);
	pos->_prev->_next = pos->_next;
	pos->_next->_prev = pos->_prev;
	free(pos);
}