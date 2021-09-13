#include"BinaryTree.h"

void Test()
{
	BTree*A = BinaryTreeNodeCreat('A');
	BTree*B = BinaryTreeNodeCreat('B');
	BTree*C = BinaryTreeNodeCreat('C');
	BTree*D = BinaryTreeNodeCreat('D');
	BTree*E = BinaryTreeNodeCreat('E');
	BTree*F = BinaryTreeNodeCreat('F');
	BTree*H = BinaryTreeNodeCreat('H');
	BTree*J = BinaryTreeNodeCreat('J');
	BTree*K = BinaryTreeNodeCreat('K');

	A->_leftchild = B;
	A->_rightchild = C;
	B->_leftchild = D;
	D->_rightchild = E;
	E->_leftchild = F;
	C->_leftchild = H;
	C->_rightchild = J;
	H->_leftchild = K;

	BinaryTreePrint(A);

	
	BinaryTreePrevOrder(A);//ǰ�����
	printf("ǰ�����\n");
	BinaryTreeInOrder(A);//�������
	printf("�������\n");
	BinaryTreePostOrder(A);//�������
	printf("�������\n");
	printf("\n");

	printf("һ����%d���ڵ�\n", BinaryTreeSize(A));
	printf("һ����%d��Ҷ�ӽڵ�\n", BinaryTreeLeafSize(A));
	int k = 1;
	while (k<6)
	{
		printf("��%d��һ����%d���ڵ�\n", k, BinaryTreeLevelKSize(A, k));
		k++;
	}
	
	printf("����ֵΪH�Ľڵ㣺");
	BinaryTreePrint(BinaryTreeFind(A, 'H'));
	printf("����ֵΪU�Ľڵ㣺");
	BinaryTreePrint(BinaryTreeFind(A, 'U'));
	
	BinaryTreeLevelOrder(A);//��α���
	printf("��α���\n");

	printf("�ж��Ƿ�Ϊ��ȫ������: %d", BinaryTreeComplete(A));

	BinaryTreeDestory(&A);
	
}

int main()
{
	Test();
	return 0;
}