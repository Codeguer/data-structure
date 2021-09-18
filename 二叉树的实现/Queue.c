#include"Queue.h"

// ��ʼ������
void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_front = NULL;
	q->nums = 0;
}
// ��β�����
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode *tmp=(QNode*)malloc(sizeof(QNode));
	tmp->_data = data;
	tmp->_pNext = NULL;
	if (q->_front == NULL)
		q->_front=tmp;
	else if (q->_rear)
		q->_rear->_pNext = tmp;
	q->_rear = tmp;
	q->nums++;
}
// ��ͷ������
void QueuePop(Queue* q)
{
	assert(q);
	if (q->_front == NULL||q->nums==0)
		return;
	q->_front = q->_front->_pNext;
	q->nums--;
}
// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->_front != NULL||q->nums!=0);
	return q->_front->_data;
}
// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->_rear||q->nums);
	return q->_rear->_data;
}
// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* q)
{
	assert(q);
	return q->nums;
}
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
int QueueEmpty(Queue* q)
{
	assert(q);
	if (q->nums == 0)
		return 1;
	else
		return 0;
}
// ���ٶ���
void QueueDestroy(Queue* q)
{
	assert(q);
	while (q->nums)
	{
		QNode* next = q->_front->_pNext;
		free(q->_front);
		q->_front = next;
		q->nums--;
	}
	q->_rear = NULL;
}