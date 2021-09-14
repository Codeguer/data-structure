#include"Stack.h"

void StackInit(Stack*pst)
{
	assert(pst);

	//pst->a = NULL;
	//pst->top = 0;
	//pst->capacity = 0;

	pst->a = (Stack*)malloc(sizeof(Stack)*2);
	pst->top = 0;
	pst->capacity = 4;
}


void StackDestroy(Stack *pst)
{
	assert(pst);
	free(pst->a);
	pst -> a = NULL;
	pst->capacity = pst->top=0;
}

void StackPush(Stack *pst,STDataType x)
{
	assert(pst);
	if (pst->top == pst->capacity)
	{
		STDataType*tmp = (STDataType*)realloc(pst->a,sizeof(STDataType)*pst->capacity * 2);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);//结束掉整个程序
		}
		pst->a = tmp;
		pst->capacity *= 2;
	}
	pst->a[pst->top] = x;
	pst->top ++;
}
void StackPop(Stack *pst)
{
	assert(pst);
	assert(!StackEmpty(pst));
	pst->top--;
}

STDataType StackTop(Stack*pst)//访问栈顶的数据
{
	assert(pst);
	assert(!StackEmpty(pst));
	return pst->a[pst->top - 1];
}


bool StackEmpty(Stack*pst)
{
	assert(pst);
	return pst->top == 0;
}
int StackSize(Stack *pst)
{
	return pst->top;
}
