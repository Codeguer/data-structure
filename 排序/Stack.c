#include"Stack.h"

// 初始化栈
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
// 入栈
void StackPush(Stack* ps, STDataType data)
{
	IsFull(ps);
	ps->_a[ps->_top] = data;
	ps->_top++;
}
// 出栈
void StackPop(Stack* ps)
{
	assert(ps);
	if (StackEmpty(ps))
		return;
	ps->_top--;
}
// 获取栈顶元素
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(StackEmpty(ps) == 0);
	return ps->_a[ps->_top - 1];
}
// 获取栈中有效元素个数
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
int StackEmpty(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
		return 1;
	else
		return 0;
}
// 销毁栈
void StackDestroy(Stack* ps)
{
	assert(ps);
	assert(ps->_a);
	ps->_top = 0;
	ps->_capacity = 0;
	free(ps->_a);
	ps->_a = NULL;
}
