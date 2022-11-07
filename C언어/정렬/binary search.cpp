#include <stdio.h>
#define size 10

int binary_search(int * arr, int value){
	int left = 0;
	int right = size-1;
	int pivot;
	while(left<=right){
		pivot = (left+right)/2;
		
		if(arr[left]==value){
			return left;
		}
		
		if(arr[right]==value){
			return right;
		}
		
		if(arr[pivot]>value){
			right = pivot;
		}
		
		else if(arr[pivot]<value){
			left = pivot;
		}
		
		else{
			return pivot;
		}
	}
}

int main(void){
	int arr[size] = {1,2,3,4,5,6,7,8,9,10};
	printf("%d", binary_search(arr, 7));
}
