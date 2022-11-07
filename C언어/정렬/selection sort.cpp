#include <stdio.h>
#include <limits.h>
#define size 5

void swap(int * num1, int * num2){
	int tmp = *num2;
	*num2 = *num1;
	*num1 = tmp;
}

void selectionSort(int * arr){
	// ���� ������ �迭�� �ּڰ��� ã�� ��, �� �ּڰ��� ���ĵ��� ���� �κ��� ù ��° ���� swap�ϸ鼭 ���� 
	// i�� �� �� ������ ���� ���� 
	for(int i=0;i<size-1;i++){ 
	    int min = arr[i];
	    int minIndex = i;
		for(int j=i;j<size;j++){
		    if(arr[j]<min){
		    	swap(&arr[j], &arr[i]);
			}
		}
	}
}

int main(void){
	int arr[size] = {5,4,3,2,1};
	selectionSort(arr);
	for(int i=0;i<size;i++){
		printf("%d ", arr[i]);
	}
}
