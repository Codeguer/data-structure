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
//��ӡ���
void BinaryTreePrint(BTNode* Node)
{
	assert(Node);
	printf("%d ", Node->_data);
}
// ������ǰ�����
void BinaryTreePrevOrder(BTNode* Proot)
{
	if (Proot == NULL)
		return;
	BinaryTreePrint(Proot);
	BinaryTreePrevOrder(Proot->_pLeft);
	BinaryTreePrevOrder(Proot->_pRight);
}
// �������������
void BinaryTreeInOrder(BTNode* Proot)
{
	if (Proot == NULL)
		return;
	BinaryTreeInOrder(Proot->_pLeft);
	BinaryTreePrint(Proot);
	BinaryTreeInOrder(Proot->_pRight);
}
// �������������
void BinaryTreePostOrder(BTNode* Proot)
{
	if (Proot == NULL)
		return;
	BinaryTreePostOrder(Proot->_pLeft);
	BinaryTreePostOrder(Proot->_pRight);
	BinaryTreePrint(Proot);
}

// �������ڵ����
int BinaryTreeSize(BTNode* Proot)
{
	return Proot == NULL ? 0 : BinaryTreeSize(Proot->_pLeft) + BinaryTreeSize(Proot->_pRight)+1;
}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* Proot)
{
	if (Proot == NULL)
		return 0;
	if (Proot->_pLeft == NULL && Proot->_pRight == NULL)
		return 1;
	return BinaryTreeLeafSize(Proot->_pLeft) + BinaryTreeLeafSize(Proot->_pRight);
}
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* Proot, int k)
{
	if (Proot == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(Proot->_pLeft, k - 1)+ 
		   BinaryTreeLevelKSize(Proot->_pRight, k - 1);
	
}
// ����������ֵΪx�Ľڵ�
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

// �������
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

// �ж϶������Ƿ�����ȫ������
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
// ����������
void BinaryTreeDestory(BTNode** PProot)
{
	if (*PProot == NULL)
		return;
	BinaryTreeDestory(&(*PProot)->_pLeft);
	BinaryTreeDestory(&(*PProot)->_pRight);
	free(*PProot);
	*PProot = NULL;
}