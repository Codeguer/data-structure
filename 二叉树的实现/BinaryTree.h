#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
typedef int BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* _pLeft; // ָ��ǰ�ڵ�����
	struct BinaryTreeNode* _pRight; // ָ��ǰ�ڵ��Һ���
	BTDataType _data; // ��ǰ�ڵ�ֵ��
}BTNode;

BTNode* BinaryTreeNodeCreat(BTDataType data);//�½����
//��ӡ���
void BinaryTreePrint(BTNode* Node);
// ������ǰ�����
void BinaryTreePrevOrder(BTNode* Proot);
// �������������
void BinaryTreeInOrder(BTNode* Proot);
// �������������
void BinaryTreePostOrder(BTNode* Proot);

// �������ڵ����
int BinaryTreeSize(BTNode* Proot);
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* Proot);
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* Proot, int k);
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* Proot, BTDataType x);

// �������
void BinaryTreeLevelOrder(BTNode* Proot);

// �ж϶������Ƿ�����ȫ������
bool BinaryTreeComplete(BTNode* Proot);
// ����������
void BinaryTreeDestory(BTNode** PProot);