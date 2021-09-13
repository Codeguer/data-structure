#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include"Queue.h"
#include<stack>
#include<vector>
#include<iostream>
using namespace std;
typedef char BinaryTreeDataType;
typedef struct BinaryTree//�����Һ���ָ�뽨���������Ľṹ
{
	BinaryTreeDataType _data;//������
	struct BinaryTree *_leftchild;//��ָ����
	struct BinaryTree *_rightchild;//��ָ����
}BTree;




BTree* BinaryTreeNodeCreat(BinaryTreeDataType data);//�½����
//��ӡ���
void BinaryTreePrint(BTree* Node);
// ������ǰ�����
void BinaryTreePrevOrder(BTree* Proot);
// �������������
void BinaryTreeInOrder(BTree* Proot);
// �������������
void BinaryTreePostOrder(BTree* Proot);

// �������ڵ����
int BinaryTreeSize(BTree* Proot);
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTree* Proot);
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTree* Proot, int k);
// ����������ֵΪx�Ľڵ�
BTree* BinaryTreeFind(BTree* Proot, BinaryTreeDataType x);

// �������
void BinaryTreeLevelOrder(BTree* Proot);

// �ж϶������Ƿ�����ȫ������
bool BinaryTreeComplete(BTree* Proot);
// ����������
void BinaryTreeDestory(BTree** PProot);

