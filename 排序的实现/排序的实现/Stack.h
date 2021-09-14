#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdbool.h>//������ͷ�ļ�
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>


//�ñ�����û�нϺõ�֧��C99��׼����˲�������û�У�OJ�ϵ�֧��
//�������ú궨�嶨�岼������
//typedef int BOOL;
//#define TRUE 1
//#define FALSE 0

typedef int STDataType;
struct Stack
{
	STDataType*a;
	int top;		//ջ��
	int capacity;//������������
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