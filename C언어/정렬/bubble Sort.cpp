#include <stdio.h>
#define size 5

int * bubbleSort(int * arr){
	int tmp;
	int i;
	int j;
	
	for(i=size;i>1;i--){
		for(j=0;j<i-1;j++){
			if(arr[j]>arr[j+1]){
				tmp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	return arr;
}

int main(void){
	int arr[size] = {5,4,3,2,1};
    bubbleSort(arr);
    for(int i=0;i<size;i++){
    	printf("%d ", arr[i]);
	}
	return 0;
}
