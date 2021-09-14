#include "Sort.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

// ��������
void InsertSort(int* a, int n)
{
	// ��������
	for (int i = 0; i < n - 1; ++i)
	{
		// ��tmp���뵽�����[0,end]����������
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

// ϣ�����򣨾��Ǽ�С������ѭ���Ĵ�����
// ������һ������ʱ�临�Ӷ��Ƕ��٣�
// ƽ�� O(N^1.3)
// ���O(log3(N) * N) ����log3(N)����3Ϊ��N�Ķ���
void ShellSort(int* a, int n)
{
	// gap > 1��ʱ��Ԥ����
	// gap == 1��ʱ��ֱ�Ӳ�������  O(N)
	int gap = n;
	while (gap > 1) // n/3/3/3.../3 == 1  -�� 3^x = n  x�������whileѭ���ܵĴ���
	{
		//gap = (gap / 3 + 1);
		if (gap == 0)
			gap = 1;
		// ������������gap�ܴ��ʱ��-��O(N)
		// ...
		// 
		// ������һ��forѭ����whileѭ��Ƕ��
		//gap��Сʱ����Ӧ����O(N*N),���Ǿ���ǰ���Ԥ���������Ѿ��ܽӽ������
		//���whileѭ��û��ʼ��þ��������˸����޷�ѭ����N������ȥ���������ﻹ��O(N)
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else {
					break;
				}
			}

			a[end + gap] = tmp;
		}
		//printf("gap:%d->", gap);
		//PrintArray(a, n);
	}
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//ѡ������
// N N-2 N-4...
// O(N^2)
void SelectSort(int* a, int n)
{
	int left = 0, right = n - 1;
	while (left < right)
	{
		// ѡ������ֵ����С��ֵ
		int minIndex = left, maxIndex = left;
		for (int i = left; i <= right; ++i)
		{
			if (a[i] < a[minIndex])
				minIndex = i;

			if (a[i] > a[maxIndex])
				maxIndex = i;
		}

		Swap(&a[left], &a[minIndex]);
		// ���max��leftλ���ص���max�������ˣ�Ҫ����һ��max��λ��
		if (left == maxIndex)
		{
			maxIndex = minIndex;
		}

		Swap(&a[right], &a[maxIndex]);
		++left;
		--right;
	}
}

// ������֮���µ���
void AdjustDwon(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}

		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
//������
//O(N*log(N))
void HeapSort(int* a, int n)
{
	// ����  �����
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDwon(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		--end;
	}
}

//ð������
// ���O��N^2��
// ��ã�O(N)
void BubbleSort(int* a, int n)
{
	//for (int j = 0; j < n; ++j)
	//{
	//	for (int i = 1; i < n-j; ++i)
	//	{
	//		if (a[i - 1] > a[i])
	//		{
	//			Swap(&a[i - 1], &a[i]);
	//		}
	//	}
	//}

	for (int end = n; end > 0; --end)
	{
		int exchange = 0;
		for (int i = 1; i < end; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}

		if (exchange == 0)
		{
			break;
		}
	}
}


//��������(һ��ʼ���Կ����������⣩
//һ��ʼд�İ汾�����������з�װ���Ż�
//int QuickSort(int* a, int begin, int end)
//{
//	if (begin >= end)//[begin,end]����Ϊ0�������䲻�����򷵻�
//		return;
//	int left = begin, right = end;
//	int keyi = left;
//	while (left < right)//������ʱ����
//	{
//		// ��С
//		while (left < right && a[right] >= a[keyi])//left < right��ֹrightԽ��
//			--right;
//
//		// �Ҵ�
//		while (left < right && a[left] <= a[keyi])// a[right] >= a[keyi])��a[left] <= a[keyi]
//			//�ĵȺŲ���ʡ��Ȼ���ܻ������ѭ��
//			++left;
//
//		Swap(&a[left], &a[right]);
//	}
//	int meeti = left;//��¼������
//	Swap(&a[keyi], &a[meeti]);//���������ֵ��keyi����
//	QuickSort(a, begin, meeti - 1);//�ݹ�
//	QuickSort(a, meeti + 1, end);//�ݹ�
//}

//�����ڿ����ж��������ĵ�������
//partsortΪ�����������˼
// hoare�汾 -- ����ָ�뷨--�������ŵ������
//int PartSort1(int* a, int left, int right)//����һ�˾ͷ���������
//{
//	
//	int keyi = left;
//	while (left < right)
//	{
//		// ��С
//		while (left < right && a[right] >= a[keyi])
//			--right;
//
//		// �Ҵ�
//		while (left < right && a[left] <= a[keyi])
//			++left;
//
//		Swap(&a[left], &a[right]);
//	}
//	Swap(&a[keyi], &a[left]);
//
//	return left;//����������λ��
//}


//���ţ�ʱ�临�Ӷȣ���õ����O(N*log2(N)),�O��N^2)
//�Ż�����1������ȡ�У�������ų���������
int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) >> 1;//��λ��Ч�ʱȳ���2��Ч��Ҫ��һ��
	// left  mid  right
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else // a[left] >= a[mid]
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}





//����ָ�뷨
int PartSort1(int* a, int left, int right)//����һ�˾ͷ���������
{
	int midIndex = GetMidIndex(a, left, right);//ʹ������ȡ��
	Swap(&a[left], &a[midIndex]);//������ȡ�к�Ľ��������ߵ�ֵ���н���

	int keyi = left;
	while (left < right)
	{
		// ��С
		while (left < right && a[right] >= a[keyi])
			--right;

		// �Ҵ�
		while (left < right && a[left] <= a[keyi])
			++left;

		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[left]);

	return left;//����������λ�ã�Ҳ����keyi
}



// �ڿӷ�
int PartSort2(int* a, int left, int right)
{
	int midIndex = GetMidIndex(a, left, right);//ʹ������ȡ��
	Swap(&a[left], &a[midIndex]);//������ȡ�к�Ľ��������ߵ�ֵ���н���
	int key = a[left];//������ߵ�ֵ��key,Ȼ������ߵ���Ϊ�ӣ�û�����ݵ���˼��
	while (left < right)
	{
		// ��С
		while (left < right && a[right] >= key)
		{
			--right;
		}

		// �ŵ���ߵĿ�λ��,�ұ߾��γ��µĿ�
		a[left] = a[right];

		// �Ҵ�
		while (left < right && a[left] <= key)
		{
			++left;
		}

		// �ŵ��ұߵĿ�λ�У���߾��γ��µĿ�
		a[right] = a[left];
	}

	a[left] = key;//���������һ���ǿӣ���key�ŵ�����

	return left;//���������㣬Ҳ����keyֵ���ڵ�λ��
}


// ǰ��ָ�뷨[begin,end]
int PartSort3(int* a, int left, int right)
{
	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midIndex]);

	int keyi = left;
	int prev = left, cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)//cur�ұ�keyiС����
		{
			Swap(&a[cur], &a[prev]);
		}
		++cur;
	}
	Swap(&a[keyi], &a[prev]);
	return prev;//��󷵻�prev��λ�ã�Ҳ����keyi�������keyi��ʾ�����±�
}



//��������
// ���Ų�֪�����⣬��������������
void QuickSort(int* a, int begin, int end)//���õ�������ָ�뷨��
{
	if (begin >= end)//[begin,end]����Ϊ0�������䲻�����򷵻�
		return;

	// 1�������������������ݽ϶࣬����ѡkey���ˣ��ָ���������εݹ�
	// 2�������������������ݽ�С����ȥ���εݹ鲻̫����
	//��ʱԽ����ݹ飬�������Խ�࣬ÿ������������ݾ�Խ�٣�ÿ�������䶼Ҫ�ݹ�Ͳ����㣬
	//�����ں�����в���������Ϊ��ʱÿ���������ǽӽ�����ģ��ӽ���ϣ��������

	if (end - begin > 0)//С�����Ż���Ч��û��ô���ԣ��������Ӧ����������������Եĵ�
		//����������Խ�󣬱��罫20����1000Ч���������ˣ�20�ǹٷ����ģ��ٷ����Ҹ�����
	{
		int keyi = PartSort1(a, begin, end);
		//int keyi = PartSort2(a, begin, end);
		//int keyi = PartSort3(a, begin, end);


		// [begin, keyi-1] keyi [keyi+1, end]
		QuickSort(a, begin, keyi - 1);//�ݹ�
		QuickSort(a, keyi + 1, end);//�ݹ�
	}
	else
	{
		InsertSort(a + begin, end - begin + 1);
		//HeapSort(a + begin, end - begin + 1);Ҳ���Ի���������ţ�ϣ������Ч�������
	}
}

// �ݹ��ִ��������Ż��ܺã������Ѿ����Ǵ�����
// ��������->�ݹ����̫�������û���⣬����ջ�ռ䲻��������ջ���
// ֻ�ܸĳɷǵݹ飬�ĳɷǵݹ������ַ�ʽ��
// 1��ֱ�Ӹ�ѭ��-��쳲������������
// 2���������ǵݹ�Ϳ��ŷǵݹ�ȵȣ�ֻ����Stack�洢����ģ��ݹ����
// [begin, end]

// �ǵݹ�

#include"Stack.h"
//��Stack�洢����ģ��ݹ����
void QuickSortNonR(int* a, int begin, int end)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, begin);
	StackPush(&st, end);

	while (!StackEmpty(&st))
	{
		int left, right;
		right = StackTop(&st);//��end��right
		StackPop(&st);

		left = StackTop(&st);//��begin��left
		StackPop(&st);

		int keyi = PartSort1(a, left, right);//�������򷵻ط��ε���±�
		if (left < keyi - 1)
		{
			StackPush(&st, left);
			StackPush(&st, keyi - 1);
		}

		if (keyi + 1 < right)
		{
			StackPush(&st, keyi + 1);
			StackPush(&st, right);
		}
	}

	StackDestroy(&st);
}

//�鲢����
// ʱ�临�Ӷȣ�O(N*logN)
// �ռ临�Ӷȣ�O(N)
//�鲢����ӽ����ֵģ������ʱ��Ч�ʻ�ȿ��Ÿߣ����ǿ��ſ��Խ���������Ż�
//�鲢�Ŀռ临�Ӷ���0(N),����һ��ȱ�㣬���������㹻��ʱ��û��ô��Ŀռ��������
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;

	int mid = (left + right) >> 1;
	// [left, mid][mid+1,right]
	_MergeSort(a, left, mid, tmp);//�ȵݹ���з���
	_MergeSort(a, mid + 1, right, tmp);

	// ��������������鲢tmp,��������ȥ
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[i++] = a[begin1++];
		else
			tmp[i++] = a[begin2++];
	}

	while (begin1 <= end1)
		tmp[i++] = a[begin1++];

	while (begin2 <= end2)
		tmp[i++] = a[begin2++];

	// �鲢����Ժ󣬿����ص�ԭ����
	for (int j = left; j <= right; ++j)
		a[j] = tmp[j];
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);//������ʱ����
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
}




