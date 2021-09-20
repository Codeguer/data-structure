#include"Sort.h"

// 插入排序
void InsertSort(int* a, int n) {
	for (int i = 0; i < n - 1; i++) {
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0) {
			if (tmp < a[end]) {
				a[end + 1] = a[end];
				end--;
			}
			else
				break;
		}
		a[end + 1] = tmp;
	}

}

void __InsertSort(int* a, int n, int gap) {
	for (int i = 0; i < n - gap; i++) {
		int end = i;
		int tmp = a[end + gap];
		while (end >= 0) {
			if (tmp < a[end]) {
				a[end + gap] = a[end];
				end -= gap;
			}
			else
				break;
		}
		a[end + gap] = tmp;
	}
}
// 希尔排序
void ShellSort(int* a, int n) {
	int gap = n;
	while (gap > 1) {
		gap = gap / 3 + 1;
		__InsertSort(a, n, gap);
	}
}

void swap(int* pa, int pos1, int pos2) {
	int tmp = pa[pos1];
	pa[pos1] = pa[pos2];
	pa[pos2] = tmp;
}

// 选择排序
void SelectSort(int* a, int n) {
	int begin = 0;
	int end = n - 1;
	while (begin < end) {
		int min = begin, max = begin;
		for (int i = begin + 1; i <= end; i++) {
			if (a[i] < a[min])min = i;
			if (a[i] > a[max])max = i;
		}
		swap(a, begin, min);
		if (max == begin) {
			max = min;
		}
		swap(a, end, max);
		begin++;
		end--;
	}
}

// 堆排序
void AdjustDwon(int* a, int n, int root) {
	int parent = root;
	while (parent * 2 + 1 < n) {
		int child = parent * 2 + 1;
		if (child + 1 < n && a[child] < a[child + 1]) {
			child++;
		}
		if (a[parent] < a[child])
			swap(a, parent, child);
		else
			break;
		parent = child;
	}
}
void HeapSort(int* a, int n) {
	int parent = (n - 1 - 1) / 2;
	while (parent >= 0) {
		AdjustDwon(a, n, parent);
		parent--;
	}
	int end = n - 1;
	while (end > 0) {
		swap(a, 0, end);
		AdjustDwon(a, --end, 0);
	}
}

//冒泡排序
void BubbleSort(int* a, int n) {
	int end = n - 1;
	while (end > 0) {
		int cur = 0;
		int flag = 0;
		while (cur < end) {
			if (a[cur] > a[cur + 1]) {
				//swap(a, cur, cur + 1);//调用函数有堆栈的时间消耗
				int tmp = a[cur];
				a[cur] = a[cur + 1];
				a[cur + 1] = tmp;
				flag = -1;
			}
			cur++;
		}
		if (!flag)break;
		end--;
	}
}

// 快速排序递归实现
// 快速排序hoare版本

int GetMiddle(int* a, int begin, int end) {
	int middle = (begin + end) / 2;
	if (a[begin] >= a[end]) {
		if (a[middle] >= a[begin])return begin;
		if (a[middle] <= a[end])return end;
		if (a[middle] <= a[begin] && a[middle] >= a[end])return middle;
	}
	else {//a[begin] < a[end]
		if (a[middle] <= a[begin])return begin;
		if (a[middle] >= a[end])return end;
		if (a[middle] >= a[begin] && a[middle] <= a[end])return middle;
	}
	
}

int PartSort1(int* a, int begin, int end) {
	int middle = GetMiddle(a, begin, end);
	if (middle != begin)
		swap(a, middle, begin);
	int key = a[begin];
	int left = begin;
	int right = end;
	while (left < right) {
		while (left < right && a[right] >= key) {
			right--;
		}
		while (left < right && a[left] <= key) {
			left++;
		}if (left < right)
			swap(a, left, right);
	}
	swap(a, begin, left);
	return left;
}
// 快速排序挖坑法
int PartSort2(int* a, int begin, int end) {
	int middle = GetMiddle(a, begin, end);
	if (middle != begin)
		swap(a, middle, begin);
	int key = a[begin];
	int left = begin;
	int right = end;
	while (left < right) {
		while (left < right && a[right] >= key) {
			right--;
		}
		a[left] = a[right];
		while (left < right && a[left] <= key) {
			left++;
		}
		a[right] = a[left];
	}
	a[left] = key;
	return left;
}
// 快速排序前后指针法
int PartSort3(int* a, int begin, int end) {
	int middle = GetMiddle(a, begin, end);
	if(middle!=begin)
		swap(a, middle, begin);
	int key = a[begin];
	int prev = begin;
	int cur = prev + 1;
	while (cur <= end) {
		while (cur <= end&&a[cur] >= key) {
			cur++;
		}
		if (cur <= end) {
			if (++prev != cur)swap(a, prev, cur);
		}
		cur++;
	}
	swap(a, begin, prev);
	return prev;
}

void QuickSort(int* a, int begin, int end) {
	if (begin >= end)
		return;
	if (end - begin >= 20) {
		//int meeti = PartSort1(a, begin, end);
	//int meeti = PartSort2(a, begin, end);
		int meeti = PartSort3(a, begin, end);
		QuickSort(a, begin, meeti - 1);
		QuickSort(a, meeti + 1, end);
	}
	else
		ShellSort(a, end - begin + 1);
}
// 快速排序 非递归实现
void QuickSortNonR(int* a, int begin, int end) {
	Stack st;
	StackInit(&st);
	StackPush(&st, begin);
	StackPush(&st, end);
	while (!StackEmpty(&st)) {
		int right = StackTop(&st);
		StackPop(&st);
		int left = StackTop(&st);
		StackPop(&st);

		int meeti = PartSort1(a, left, right);
		if (left < meeti-1) {
			StackPush(&st, left);
			StackPush(&st, meeti - 1);
		}

		if (right > meeti+1) {
			StackPush(&st, meeti+1);
			StackPush(&st, right);
		}
	}
	StackDestroy(&st);
}

// 归并排序递归实现
void _MergeSort(int* a, int left, int right, int* tmp) {
	if (left >= right)return;
	int mid = (left + right) >> 1;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;
	int tmp_i = left;
	while (begin1 <= end1 && begin2 <= end2) {
		if (a[begin1] > a[begin2]) {
			tmp[tmp_i++] = a[begin2++];
		}
		else {
			tmp[tmp_i++] = a[begin1++];
		}
	}

	while (begin1 <= end1) {
		tmp[tmp_i++] = a[begin1++];
	}

	while (begin2 <= end2) {
		tmp[tmp_i++] = a[begin2++];
	}

	for (int j = left; j <= right; j++) {
		a[j] = tmp[j];
	}
}


void MergeSort(int* a, int n) {
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL) {
		printf("MergeSort->malloc:error\n");
		exit(-1);
	}
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}
// 归并排序非递归实现
void MergeSortNonR(int* a, int n);

// 计数排序
void CountSort(int* a, int n) {
	int min = a[0], max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] < min)min = a[i];
		if (a[i] > max)max = a[i];
	}
	int tmp_legth = max - min + 1;
	int* tmp = (int*)calloc( tmp_legth, sizeof(int));
	assert(tmp);

	for (int i = 0; i < n; i++) {
			tmp[a[i] - min]++;
	}

	for (int i = 0,j=0; i < tmp_legth; i++) {
		while (tmp[i]) {
			a[j++] = i + min;
			tmp[i]--;
		}
	}
}
