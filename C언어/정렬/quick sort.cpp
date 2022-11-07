#include <stdio.h>
#define SIZE 8

void swap(int arr[], int num1, int num2){
	int tmp = arr[num1];
	arr[num1] = arr[num2];
	arr[num2] = tmp;
}

int partition(int * arr, int left, int right){
	int pivot = left;
	int swapIdx = left;
	for(int i = left+1;i<=right;i++){
		if(arr[pivot]>arr[i]){
			swapIdx++;
			swap(arr, swapIdx, i);
		}
	}
    swap(arr, pivot, swapIdx);
    return swapIdx;
}

void quickSort(int * arr, int left, int right){
	if(left<right){
		int pivot = partition(arr, left, right);
		quickSort(arr, left, pivot-1);
		quickSort(arr, pivot+1, right);
	}
}

int main(void){
	int arr[SIZE] = {8,7,6,5,4,3,2,1};
	quickSort(arr, 0, SIZE-1);
	for(int i=0;i<SIZE;i++){
		printf("%d ", arr[i]);
	}
}
