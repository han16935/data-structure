#include <stdio.h>
#define size 10

void swap(int * arr, int * num1, int * num2){
	int tmp = *num2;
	*num2 = *num1;
	*num1 = tmp;
}

void insertionSort(int * arr){
	int i;
	int j;
	for(i=1;i<size;i++){
		for(j=i;j>0;j--){
		   if(arr[j-1] > arr[j]){
		   	 swap(arr, &arr[j-1], &arr[j]);
		   }
		   else break;	
		}
	}
}

int main(void){
	int arr[size] = {10,9,8,7,6,5,4,3,2,1};
	insertionSort(arr);
	for(int i=0;i<size;i++){
		printf("%d ", arr[i]);
	}
}
