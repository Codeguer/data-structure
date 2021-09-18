#include"BinaryTree.h"
#include"Queue.h"
BTNode* BinaryTreeNodeCreat(BTDataType data)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	assert(newnode);
	newnode->_data = data;
	newnode->_pLeft = NULL;
	newnode->_pRight = NULL;
	return newnode;
}
//打印结点
void BinaryTreePrint(BTNode* Node)
{
	assert(Node);
	printf("%d ", Node->_data);
}
// 二叉树前序遍历
void BinaryTreePrevOrder(BTNode* Proot)
{
	if (Proot == NULL)
		return;
	BinaryTreePrint(Proot);
	BinaryTreePrevOrder(Proot->_pLeft);
	BinaryTreePrevOrder(Proot->_pRight);
}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* Proot)
{
	if (Proot == NULL)
		return;
	BinaryTreeInOrder(Proot->_pLeft);
	BinaryTreePrint(Proot);
	BinaryTreeInOrder(Proot->_pRight);
}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* Proot)
{
	if (Proot == NULL)
		return;
	BinaryTreePostOrder(Proot->_pLeft);
	BinaryTreePostOrder(Proot->_pRight);
	BinaryTreePrint(Proot);
}

// 二叉树节点个数
int BinaryTreeSize(BTNode* Proot)
{
	return Proot == NULL ? 0 : BinaryTreeSize(Proot->_pLeft) + BinaryTreeSize(Proot->_pRight)+1;
}
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* Proot)
{
	if (Proot == NULL)
		return 0;
	if (Proot->_pLeft == NULL && Proot->_pRight == NULL)
		return 1;
	return BinaryTreeLeafSize(Proot->_pLeft) + BinaryTreeLeafSize(Proot->_pRight);
}
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* Proot, int k)
{
	if (Proot == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(Proot->_pLeft, k - 1)+ 
		   BinaryTreeLevelKSize(Proot->_pRight, k - 1);
	
}
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* Proot, BTDataType x)
{
	if (Proot == NULL)
		return NULL;
	if (Proot->_data == x)
		return Proot;
	BTNode* tmp_pleft = BinaryTreeFind(Proot->_pLeft, x);
	if (tmp_pleft != NULL)
		return tmp_pleft;
	BTNode* tmp_pright = BinaryTreeFind(Proot->_pRight, x);
	if (tmp_pright != NULL)
		return tmp_pright;
	if (tmp_pleft == NULL && tmp_pright == NULL)
		return NULL;
}

// 层序遍历
void BinaryTreeLevelOrder(BTNode* Proot)
{
	if (Proot == NULL)
		return;
	Queue q;
	QueueInit(&q);
	QueuePush(&q,Proot);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		if (front != NULL)
		{
			printf("%d ", front->_data);
			QueuePush(&q, front->_pLeft);
			QueuePush(&q, front->_pRight);
		}
		QueuePop(&q);
	}
	QueueDestroy(&q);
}

// 判断二叉树是否是完全二叉树
bool BinaryTreeComplete(BTNode* Proot)
{
	if (Proot == NULL)
		return;
	Queue q;
	QueueInit(&q);
	QueuePush(&q, Proot);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		if (front != NULL)
		{
			QueuePush(&q, front->_pLeft);
			QueuePush(&q, front->_pRight);
		}
		else if (front == NULL)
		{
			while (!QueueEmpty(&q))
			{
				if (QueueFront(&q) != NULL)
					return false;
				QueuePop(&q);
			}
			QueueDestroy(&q);
			return true;
		}
		QueuePop(&q);
	}
	QueueDestroy(&q);
}
// 二叉树销毁
void BinaryTreeDestory(BTNode** PProot)
{
	if (*PProot == NULL)
		return;
	BinaryTreeDestory(&(*PProot)->_pLeft);
	BinaryTreeDestory(&(*PProot)->_pRight);
	free(*PProot);
	*PProot = NULL;
}