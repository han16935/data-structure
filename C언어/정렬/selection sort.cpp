#include <stdio.h>
#include <limits.h>
#define size 5

void swap(int * num1, int * num2){
	int tmp = *num2;
	*num2 = *num1;
	*num1 = tmp;
}

void selectionSort(int * arr){
	// 선택 정렬은 배열의 최솟값을 찾은 뒤, 그 최솟값을 정렬되지 않은 부분의 첫 번째 값과 swap하면서 정렬 
	// i는 한 번 돌수록 점차 증가 
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
