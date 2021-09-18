#include"BinaryTree.h"

void test()
{
	BTNode* A = BinaryTreeNodeCreat(1);
	BTNode* B = BinaryTreeNodeCreat(2);
	BTNode* C = BinaryTreeNodeCreat(3);
	BTNode* D = BinaryTreeNodeCreat(4);
	BTNode* E = BinaryTreeNodeCreat(5);
	BTNode* F = BinaryTreeNodeCreat(6);
	BTNode* G = BinaryTreeNodeCreat(7);
	BTNode* H = BinaryTreeNodeCreat(8);
	BTNode* J = BinaryTreeNodeCreat(9);
	BTNode* K = BinaryTreeNodeCreat(10);
	BTNode* L = BinaryTreeNodeCreat(11);

	A->_pLeft = B;
	A->_pRight = C;
	B->_pLeft = D;
	B->_pRight = E;
	C->_pLeft = F;
	C->_pRight = G;
	D->_pLeft = H;
	D->_pRight = J;
	E->_pLeft = K;
	E->_pRight = L;

	//BinaryTreePrint(A);
	BinaryTreePrevOrder(A);printf("前序遍历\n");
	BinaryTreeInOrder(A); printf("中序遍历\n");
	BinaryTreePostOrder(A); printf("后序遍历\n");
	BinaryTreeLevelOrder(A); printf("层序遍历\n");

	printf("%d\n", BinaryTreeSize(A));
	printf("%d\n", BinaryTreeLeafSize(A));
	printf("%d\n", BinaryTreeLevelKSize(A, 4));
	BTNode* find_node = BinaryTreeFind(A, 51);
	printf("%d\n", BinaryTreeComplete(A));

	BinaryTreeDestory(&A);
}


int main()
{
	test();
	return 0;
}