#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdbool.h>//布尔的头文件
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>


//该编译器没有较好的支持C99标准，因此布尔类型没有，OJ上的支持
//还可以用宏定义定义布尔出来
//typedef int BOOL;
//#define TRUE 1
//#define FALSE 0

typedef int STDataType;
struct Stack
{
	STDataType*a;
	int top;		//栈顶
	int capacity;//容量方便扩容
};

typedef struct Stack ST;
typedef struct Stack Stack;

void StackInit(Stack *pst);
void StackDestroy(Stack *pst);

void StackPush(Stack *pst, STDataType x);
void StackPop(Stack *pst);

STDataType StackTop(Stack*pst);


bool StackEmpty(Stack*pst);
int StackSize(Stack *pst);