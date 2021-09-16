#include"Stack.h"	

void test()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	StackPush(&st, 6);

	StackPop(&st);
	printf("top:%d\n", StackTop(&st));
	StackDestroy(&st);
}

int main()
{
	test();
	return 0;
}