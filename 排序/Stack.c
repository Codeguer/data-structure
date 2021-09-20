#include"Stack.h"

// ��ʼ��ջ
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = (STDataType*)malloc(sizeof(STDataType) * 10);
	ps->_top = 0;
	ps->_capacity = 10;
}

static void IsFull(Stack* ps)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		STDataType*tmp= (STDataType*)realloc(ps->_a, sizeof(STDataType)*ps->_capacity*2 );
		if (tmp == NULL)
		{
			printf("IsFull->realloc:error\n	");
			exit(-1);
		}
		ps->_a = tmp;
		ps->_capacity *= 2;
	}
}
// ��ջ
void StackPush(Stack* ps, STDataType data)
{
	IsFull(ps);
	ps->_a[ps->_top] = data;
	ps->_top++;
}
// ��ջ
void StackPop(Stack* ps)
{
	assert(ps);
	if (StackEmpty(ps))
		return;
	ps->_top--;
}
// ��ȡջ��Ԫ��
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(StackEmpty(ps) == 0);
	return ps->_a[ps->_top - 1];
}
// ��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0
int StackEmpty(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
		return 1;
	else
		return 0;
}
// ����ջ
void StackDestroy(Stack* ps)
{
	assert(ps);
	assert(ps->_a);
	ps->_top = 0;
	ps->_capacity = 0;
	free(ps->_a);
	ps->_a = NULL;
}
