#include"Queue.h"

// 初始化队列
void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_front = NULL;
	q->nums = 0;
}
// 队尾入队列
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
// 队头出队列
void QueuePop(Queue* q)
{
	assert(q);
	if (q->_front == NULL||q->nums==0)
		return;
	q->_front = q->_front->_pNext;
	q->nums--;
}
// 获取队列头部元素
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->_front != NULL||q->nums!=0);
	return q->_front->_data;
}
// 获取队列队尾元素
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->_rear||q->nums);
	return q->_rear->_data;
}
// 获取队列中有效元素个数
int QueueSize(Queue* q)
{
	assert(q);
	return q->nums;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
int QueueEmpty(Queue* q)
{
	assert(q);
	if (q->nums == 0)
		return 1;
	else
		return 0;
}
// 销毁队列
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