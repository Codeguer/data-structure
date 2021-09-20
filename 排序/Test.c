#include"Sort.h"

void test() {
	int* arr1 = (int*)malloc(sizeof(int) * N);
	int* arr2 = (int*)malloc(sizeof(int) * N);
	int* arr3 = (int*)malloc(sizeof(int) * N);
	int* arr4 = (int*)malloc(sizeof(int) * N);
	int* arr5 = (int*)malloc(sizeof(int) * N);
	int* arr6 = (int*)malloc(sizeof(int) * N);
	int* arr7 = (int*)malloc(sizeof(int) * N);
	int* arr8 = (int*)malloc(sizeof(int) * N);
	int* arr9 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		int tmp = rand();
		arr1[i] = tmp;
		arr2[i] = tmp;
		arr3[i] = tmp;
		arr4[i] = tmp;
		arr5[i] = tmp;
		arr6[i] = tmp;
		arr7[i] = tmp;
		arr8[i] = tmp;
		arr9[i] = tmp;
	}
	int begin1 = clock();
	InsertSort(arr1, N);
	int end1 = clock();
	int a1[] = { 5,8,2,8,34,9,4,8,3,9,2,7,34,2,6,7 };
	int sz1 = sizeof(a1) / sizeof(a1[0]);
	InsertSort(a1, sz1);
	printf("InsertSort:");
	for (int i = 0; i < sz1; i++) {
		printf("%d ", a1[i]);
	}
	printf("\n");


	int begin2 = clock();
	ShellSort(arr2, N);
	int end2 = clock();
	int a2[] = { 5,8,2,8,34,9,4,8,3,9,2,7,34,2,6,7 };
	int sz2 = sizeof(a2) / sizeof(a2[0]);
	ShellSort(a2, sz2);
	printf("ShellSort: ");
	for (int i = 0; i < sz2; i++) {
		printf("%d ", a2[i]);
	}
	printf("\n");

	int begin3 = clock();
	SelectSort(arr3, N);
	int end3 = clock();
	int a3[] = { 5,8,2,8,34,9,4,8,3,9,2,7,34,2,6,7 };
	int sz3 = sizeof(a3) / sizeof(a3[0]);
	SelectSort(a3, sz3);
	printf("SelectSort:");
	for (int i = 0; i < sz3; i++) {
		printf("%d ", a3[i]);
	}
	printf("\n");

	int begin4 = clock();
	HeapSort(arr4, N);
	int end4 = clock();
	int a4[] = { 5,8,2,8,34,9,4,8,3,9,2,7,34,2,6,7 };
	int sz4 = sizeof(a4) / sizeof(a4[0]);
	HeapSort(a4, sz4);
	printf("HeapSort:  ");
	for (int i = 0; i < sz4; i++) {
		printf("%d ", a4[i]);
	}
	printf("\n");

	int begin5 = clock();
	BubbleSort(arr5, N);
	int end5 = clock();
	int a5[] = { 5,8,2,8,34,9,4,8,3,9,2,7,34,2,6,7 };
	int sz5 = sizeof(a5) / sizeof(a5[0]);
	BubbleSort(a5, sz5);
	printf("BubbleSort:");
	for (int i = 0; i < sz5; i++) {
		printf("%d ", a5[i]);
	}
	printf("\n");

	int begin6 = clock();
	QuickSort(arr6,0, N-1);
	int end6 = clock();
	int a6[] = { 5,8,2,8,34,9,4,8,3,9,2,7,34,2,6,7 };
	int sz6 = sizeof(a6) / sizeof(a6[0]);
	QuickSort(a6,0, sz6-1);
	printf("QuickSort: ");
	for (int i = 0; i < sz6; i++) {
		printf("%d ", a6[i]);
	}
	printf("\n");

	int begin7 = clock();
	QuickSortNonR(arr7, 0, N - 1);
	int end7= clock();
	int a7[] = { 5,8,2,8,34,9,4,8,3,9,2,7,34,2,6,7 };
	int sz7 = sizeof(a7) / sizeof(a7[0]);
	QuickSortNonR(a7, 0, sz7 - 1);
	printf("QuickSortNonR: ");
	for (int i = 0; i < sz7; i++) {
		printf("%d ", a7[i]);
	}
	printf("\n");

	int begin8 = clock();
	MergeSort(arr8, N);
	int end8 = clock();
	int a8[] = { 5,8,2,8,34,9,4,8,3,9,2,7,34,2,6,7 };
	int sz8 = sizeof(a8) / sizeof(a8[0]);
	MergeSort(a8, sz8);
	printf("MergeSort: ");
	for (int i = 0; i < sz8; i++) {
		printf("%d ", a8[i]);
	}
	printf("\n");

	int begin9 = clock();
	CountSort(arr9, N);
	int end9 = clock();
	int a9[] = { 5,8,2,8,34,9,4,8,3,9,2,7,34,2,6,7 };
	int sz9 = sizeof(a9) / sizeof(a9[0]);
	CountSort(a9, sz9);
	printf("CountSort: ");
	for (int i = 0; i < sz9; i++) {
		printf("%d ", a9[i]);
	}
	printf("\n");

	printf("InsertSort():%d\n", end1 - begin1);
	printf("ShellSort():%d\n", end2 - begin2);
	printf("SelectSort():%d\n", end3 - begin3);
	printf("HeapSort():%d\n", end4 - begin4);
	printf("BubbleSort():%d\n", end5 - begin5);
	printf("QuickSort():%d\n", end6 - begin6);
	printf("QuickSortNonR():%d\n", end7 - begin7);
	printf("MergeSort():%d\n", end8 - begin8);
	printf("CountSort():%d\n", end9 - begin9);

	free(arr1);
	free(arr2);
	free(arr3);
	free(arr4);
	free(arr5);
	free(arr6);
	free(arr7);
}
int main() {
	srand((size_t)time(NULL));
	test();
	return 0;
}