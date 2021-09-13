#include"BinaryTree.h"


BTree* BinaryTreeNodeCreat(BinaryTreeDataType data)
{
	BTree*Node = (BTree*)malloc(sizeof(BTree));
	Node->_data = data;
	Node->_leftchild = NULL;
	Node->_rightchild = NULL;
	return Node;
}
void BinaryTreePrint(BTree* Node)
{
	if (Node == NULL)
		printf("%d\n", -1);
	else
	{
		printf("%c\n", Node->_data);

	}
}
// ������ǰ�����
//void BinaryTreePrevOrder(BTree* Proot)
//{
//	if (Proot == NULL)
//	{
//		printf("NULL ");
//		return;
//	}
//		
//	printf("%c ", Proot->_data);
//	BinaryTreePrevOrder(Proot->_leftchild);
//	BinaryTreePrevOrder(Proot->_rightchild);
//}

//�������ķǵݹ����֮ǰ�����
void BinaryTreePrevOrder(BTree* Proot)
{
	vector<char>ret;
	stack<BTree*>st;
	BTree*cur = Proot;
	while (cur || !st.empty())
	{
		while (cur)
		{
			ret.push_back(cur->_data);
			st.push(cur);
			cur = cur->_leftchild;
		}

		//st����һ���ض���Ϊ��
		cur = st.top()->_rightchild;
		st.pop();
	}

	for (auto e : ret)
	{
		cout << e << " ";
	}
}





// �������������
//void BinaryTreeInOrder(BTree* Proot)
//{
//	if (Proot == NULL)
//	{
//		printf("NULL ");
//		return;
//	}
//
//	BinaryTreeInOrder(Proot->_leftchild);
//	printf("%c ", Proot->_data);
//	BinaryTreeInOrder(Proot->_rightchild);
//}
//�������ǵݹ����֮�������
void BinaryTreeInOrder(BTree* Proot)
{
	vector<char>ret;
	stack<BTree*>st;
	BTree*cur = Proot;
	while (cur || !st.empty())
	{
		while (cur)
		{
			st.push(cur);
			cur = cur->_leftchild;
		}

		//st����һ���ض���Ϊ��
		ret.push_back(st.top()->_data);
		cur = st.top()->_rightchild;
		st.pop();

	}

	for (auto e : ret)
	{
		cout << e << " ";
	}
}
//// �������������
//void BinaryTreePostOrder(BTree* Proot)
//{
//	if (Proot == nullptr)
//	{
//		//cout << "NULL ";
//		return;
//	}
//
//	BinaryTreePostOrder(Proot->_leftchild);
//	BinaryTreePostOrder(Proot->_rightchild);
//	printf("%c ", Proot->_data);
//}

// �������ǵݹ�֮���������ʹ��ǰ��ָ�룩
void BinaryTreePostOrder(BTree* Proot)
{
	vector<char>ret;
	stack<BTree*>st;
	BTree*cur = Proot;
	BTree*lastNode = nullptr;//������ʵĽ��
	while (cur || !st.empty())
	{
		while (cur)
		{
			//ret.push_back(cur->_data);
			st.push(cur);
			cur = cur->_leftchild;
		}
		//lastNode NULL
		if (st.top()->_rightchild == nullptr || lastNode == st.top()->_rightchild)
		{
			ret.push_back(st.top()->_data);
			lastNode = st.top();
			st.pop();
		}
		else
		{
			cur = st.top()->_rightchild;
		}


	}

	for (auto e : ret)
	{
		cout << e << " ";
	}
}

// �������ڵ����
int BinaryTreeSize(BTree* Proot)
{
	return Proot == NULL ? 0 : (BinaryTreeSize(Proot->_leftchild) + BinaryTreeSize(Proot->_rightchild) + 1);
}

// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTree* Proot)
{
	if (Proot == NULL)
	{
		return 0;
	}

	if (Proot->_leftchild == NULL && Proot->_rightchild == NULL)
		return 1;

	return BinaryTreeLeafSize(Proot->_leftchild) + BinaryTreeLeafSize(Proot->_rightchild);


}
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTree* Proot, int k)
{
	if (Proot == NULL)
		return 0;
	if (1 == k)
		return 1;
	return BinaryTreeLevelKSize(Proot->_leftchild, k - 1)
		+ BinaryTreeLevelKSize(Proot->_rightchild, k - 1);
}


// ����������ֵΪx�Ľڵ�
BTree* BinaryTreeFind(BTree* Proot, BinaryTreeDataType x)
{
	if (Proot == NULL)
		return NULL;
	if (Proot->_data == x)
		return Proot;
	BTree* LeftTmp = BinaryTreeFind(Proot->_leftchild, x);
	if (LeftTmp)
		return LeftTmp;
	BTree* RightTmp = BinaryTreeFind(Proot->_rightchild, x);
	if (RightTmp)
		return RightTmp;
	if (LeftTmp == NULL && RightTmp == NULL)
	{
		return NULL;
	}
}

// �������
void BinaryTreeLevelOrder(BTree* Proot)
{
	if (Proot == NULL)
	{
		printf("NULL ");
		return;
	}
	Queue Q;
	QueueInit(&Q);
	QueuePush(&Q, Proot);
	while (!QueueEmpty(&Q))
	{
		QDataType front = QueueFront(&Q);
		if (front == NULL)
			printf("NULL ");
		else
		{
			printf("%c ", front->_data);
			QueuePush(&Q, front->_leftchild);
			QueuePush(&Q, front->_rightchild);
		}
		QueuePop(&Q);
	}
	QueueDestroy(&Q);
}
// �ж϶������Ƿ�����ȫ������
bool BinaryTreeComplete(BTree* Proot)
{
	if (Proot == NULL)
	{
		return false;
	}
	Queue Q;
	QueueInit(&Q);
	QueuePush(&Q, Proot);
	while (!QueueEmpty(&Q))
	{
		QDataType front = QueueFront(&Q);
		QueuePop(&Q);
		if (front == NULL)
		{
			break;
		}
		QueuePush(&Q, front->_leftchild);
		QueuePush(&Q, front->_rightchild);
	}
	while (!QueueEmpty(&Q))
	{
		QDataType front = QueueFront(&Q);
		QueuePop(&Q);
		if (front != NULL)
			return false;
	}
	return true;
}
// ����������
void BinaryTreeDestory(BTree** PProot)
{
	if (*PProot == NULL)
		return;

	BinaryTreeDestory(&((*PProot)->_leftchild));
	BinaryTreeDestory(&((*PProot)->_rightchild));
	free(*PProot);
	*PProot = NULL;
}
