#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
typedef int BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* _pLeft; // 指向当前节点左孩子
	struct BinaryTreeNode* _pRight; // 指向当前节点右孩子
	BTDataType _data; // 当前节点值域
}BTNode;

BTNode* BinaryTreeNodeCreat(BTDataType data);//新建结点
//打印结点
void BinaryTreePrint(BTNode* Node);
// 二叉树前序遍历
void BinaryTreePrevOrder(BTNode* Proot);
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* Proot);
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* Proot);

// 二叉树节点个数
int BinaryTreeSize(BTNode* Proot);
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* Proot);
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* Proot, int k);
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* Proot, BTDataType x);

// 层序遍历
void BinaryTreeLevelOrder(BTNode* Proot);

// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BTNode* Proot);
// 二叉树销毁
void BinaryTreeDestory(BTNode** PProot);