#include "Sort.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

// 插入排序
void InsertSort(int* a, int n)
{
	// 多趟排序
	for (int i = 0; i < n - 1; ++i)
	{
		// 把tmp插入到数组的[0,end]有序区间中
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

// 希尔排序（就是减小最里层的循环的次数）
// 尝试算一下他的时间复杂度是多少？
// 平均 O(N^1.3)
// 最坏：O(log3(N) * N) 这里log3(N)是以3为底N的对数
void ShellSort(int* a, int n)
{
	// gap > 1的时候，预排序
	// gap == 1的时候，直接插入排序  O(N)
	int gap = n;
	while (gap > 1) // n/3/3/3.../3 == 1  -》 3^x = n  x就是这个while循环跑的次数
	{
		//gap = (gap / 3 + 1);
		if (gap == 0)
			gap = 1;
		// 最坏的情况：逆序，gap很大的时侯-》O(N)
		// ...
		// 
		// 这里有一个for循环与while循环嵌套
		//gap很小时本来应该是O(N*N),但是经过前面的预排序，数组已经很接近有序的
		//因此while循环没开始多久就跳出来了根本无法循环到N的量级去，所以这里还是O(N)
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

//选择排序
// N N-2 N-4...
// O(N^2)
void SelectSort(int* a, int n)
{
	int left = 0, right = n - 1;
	while (left < right)
	{
		// 选出最大的值和最小的值
		int minIndex = left, maxIndex = left;
		for (int i = left; i <= right; ++i)
		{
			if (a[i] < a[minIndex])
				minIndex = i;

			if (a[i] > a[maxIndex])
				maxIndex = i;
		}

		Swap(&a[left], &a[minIndex]);
		// 如果max和left位置重叠，max被换走了，要修正一下max的位置
		if (left == maxIndex)
		{
			maxIndex = minIndex;
		}

		Swap(&a[right], &a[maxIndex]);
		++left;
		--right;
	}
}

// 堆排序之向下调整
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
//堆排序
//O(N*log(N))
void HeapSort(int* a, int n)
{
	// 升序  建大堆
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

//冒泡排序
// 最坏：O（N^2）
// 最好：O(N)
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


//快速排序(一开始可以看这个进行理解）
//一开始写的版本，后面对其进行封装与优化
//int QuickSort(int* a, int begin, int end)
//{
//	if (begin >= end)//[begin,end]区间为0或者区间不存在则返回
//		return;
//	int left = begin, right = end;
//	int keyi = left;
//	while (left < right)//当相遇时弹出
//	{
//		// 找小
//		while (left < right && a[right] >= a[keyi])//left < right防止right越界
//			--right;
//
//		// 找大
//		while (left < right && a[left] <= a[keyi])// a[right] >= a[keyi])与a[left] <= a[keyi]
//			//的等号不能省不然可能会出现死循环
//			++left;
//
//		Swap(&a[left], &a[right]);
//	}
//	int meeti = left;//记录相遇点
//	Swap(&a[keyi], &a[meeti]);//将相遇点的值与keyi交换
//	QuickSort(a, begin, meeti - 1);//递归
//	QuickSort(a, meeti + 1, end);//递归
//}

//从早期快排中独立出来的单趟排序
//partsort为单趟排序的意思
// hoare版本 -- 左右指针法--发明快排的人想的
//int PartSort1(int* a, int left, int right)//排序一趟就返回相遇点
//{
//	
//	int keyi = left;
//	while (left < right)
//	{
//		// 找小
//		while (left < right && a[right] >= a[keyi])
//			--right;
//
//		// 找大
//		while (left < right && a[left] <= a[keyi])
//			++left;
//
//		Swap(&a[left], &a[right]);
//	}
//	Swap(&a[keyi], &a[left]);
//
//	return left;//返回相遇的位置
//}


//快排，时间复杂度，最好的情况O(N*log2(N)),最坏O（N^2)
//优化方法1：三数取中，避免快排出现最坏的情况
int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) >> 1;//移位的效率比除以2的效率要高一点
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





//左右指针法
int PartSort1(int* a, int left, int right)//排序一趟就返回相遇点
{
	int midIndex = GetMidIndex(a, left, right);//使用三数取中
	Swap(&a[left], &a[midIndex]);//将三数取中后的结果与最左边的值进行交换

	int keyi = left;
	while (left < right)
	{
		// 找小
		while (left < right && a[right] >= a[keyi])
			--right;

		// 找大
		while (left < right && a[left] <= a[keyi])
			++left;

		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[left]);

	return left;//返回相遇的位置，也就是keyi
}



// 挖坑法
int PartSort2(int* a, int left, int right)
{
	int midIndex = GetMidIndex(a, left, right);//使用三数取中
	Swap(&a[left], &a[midIndex]);//将三数取中后的结果与最左边的值进行交换
	int key = a[left];//将最左边的值给key,然后将最左边的视为坑（没有数据的意思）
	while (left < right)
	{
		// 找小
		while (left < right && a[right] >= key)
		{
			--right;
		}

		// 放到左边的坑位中,右边就形成新的坑
		a[left] = a[right];

		// 找大
		while (left < right && a[left] <= key)
		{
			++left;
		}

		// 放到右边的坑位中，左边就形成新的坑
		a[right] = a[left];
	}

	a[left] = key;//最后相遇点一定是坑，将key放到坑中

	return left;//返回相遇点，也就是key值所在的位置
}


// 前后指针法[begin,end]
int PartSort3(int* a, int left, int right)
{
	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midIndex]);

	int keyi = left;
	int prev = left, cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)//cur找比keyi小的数
		{
			Swap(&a[cur], &a[prev]);
		}
		++cur;
	}
	Swap(&a[keyi], &a[prev]);
	return prev;//最后返回prev的位置，也就是keyi，这里的keyi表示的是下标
}



//快速排序
// 初闻不知曲中意，再闻已是曲中人
void QuickSort(int* a, int begin, int end)//（用的是左右指针法）
{
	if (begin >= end)//[begin,end]区间为0或者区间不存在则返回
		return;

	// 1、如果这个子区间是数据较多，继续选key单趟，分割子区间分治递归
	// 2、如果这个子区间是数据较小，再去分治递归不太划算
	//此时越往后递归，子区间就越多，每个子区间的数据就越少，每个子区间都要递归就不划算，
	//可以在后面进行插入排序，因为此时每个子区间是接近有序的，接近于希尔排序了

	if (end - begin > 0)//小区间优化的效果没那么明显，如果对相应数据量级进行针对性的调
		//往往数据量越大，比如将20换成1000效果就明显了，20是官方给的，官方不敢给大了
	{
		int keyi = PartSort1(a, begin, end);
		//int keyi = PartSort2(a, begin, end);
		//int keyi = PartSort3(a, begin, end);


		// [begin, keyi-1] keyi [keyi+1, end]
		QuickSort(a, begin, keyi - 1);//递归
		QuickSort(a, keyi + 1, end);//递归
	}
	else
	{
		InsertSort(a + begin, end - begin + 1);
		//HeapSort(a + begin, end - begin + 1);也可以换成其如堆排，希尔排序效果会更好
	}
}

// 递归现代编译器优化很好，性能已经不是大问题
// 最大的问题->递归深度太深，程序本身没问题，但是栈空间不够，导致栈溢出
// 只能改成非递归，改成非递归有两种方式：
// 1、直接改循环-》斐波那契数列求解
// 2、树遍历非递归和快排非递归等等，只能用Stack存储数据模拟递归过程
// [begin, end]

// 非递归

#include"Stack.h"
//用Stack存储数据模拟递归过程
void QuickSortNonR(int* a, int begin, int end)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, begin);
	StackPush(&st, end);

	while (!StackEmpty(&st))
	{
		int left, right;
		right = StackTop(&st);//把end给right
		StackPop(&st);

		left = StackTop(&st);//把begin给left
		StackPop(&st);

		int keyi = PartSort1(a, left, right);//单趟排序返回分治点的下标
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

//归并排序
// 时间复杂度：O(N*logN)
// 空间复杂度：O(N)
//归并是最接近二分的，因此有时候效率会比快排高，但是快排可以进行针对性优化
//归并的空间复杂度是0(N),这是一个缺点，当数据量足够大时，没那么多的空间给它分配
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;

	int mid = (left + right) >> 1;
	// [left, mid][mid+1,right]
	_MergeSort(a, left, mid, tmp);//先递归进行分治
	_MergeSort(a, mid + 1, right, tmp);

	// 两段有序子区间归并tmp,并拷贝回去
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

	// 归并完成以后，拷贝回到原数组
	for (int j = left; j <= right; ++j)
		a[j] = tmp[j];
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);//创建临时数组
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
}




