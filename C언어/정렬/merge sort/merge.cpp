#include <stdio.h>
#include <math.h>
#define SIZE 10

void merge(int arr[], int left, int mid, int right){
	int tmp[SIZE]= {0, };
	int tmpIdx = left;
	int l = left;
	int m = mid+1;
	int r = right;
	while(l<mid+1 && m<=r){
		if(arr[l]>arr[m]){
			tmp[tmpIdx] = arr[m];
			m++;
			tmpIdx++;
		}
		
		else if(arr[l]<arr[m]){
			tmp[tmpIdx] = arr[l];
		    l++;
		    tmpIdx++;
		}
	}
	
	if(l<mid+1){
		for(int i=l;i<mid+1;i++){
			tmp[tmpIdx++] = arr[i];
		}
	}
	
	else if(m<=r){
		for(int j=m;j<=r;j++){
			tmp[tmpIdx++] = arr[j];
		}
	}
	
	for(int k=l;k<=r;k++){
		arr[k] = tmp[k];
	}
}

void mergeSort(int arr[], int left, int right){
	if(left<right){
		int m = (left+right)/2;
		mergeSort(arr, left, m);
		mergeSort(arr, m+1, right);
		merge(arr, left, m, right);
	}
}

int main(void){
	int arr[SIZE] = {5,4,3,2,1};
	mergeSort(arr, 0, SIZE-1);
	for(int i=0;i<SIZE;i++){
		printf("%d", arr[i]);
	}
	return 0;
}



//int tmpArr[SIZE];

//void swap(int * arr, int left, int right){
//	int tmp = arr[left];
//	arr[left] = arr[right];
//	arr[right] = tmp;
//}
//
//void merge(int * arr, int left, int mid, int right){
//	int tmpArrIndex = left;
//	int low = left;
//	int high = mid+1;
//	while(low<=mid && high<=right){
//		if(arr[low]<=arr[high]){
//			tmpArr[tmpArrIndex++] = arr[low++];
//		}
//		
//		else if(arr[low]>arr[high]){
//			tmpArr[tmpArrIndex++] = arr[high++];
//		}
//	}
//	
//    for(int k=left;k<=right;k++){
//    	arr[k] = tmpArr[k];
//	}
//}
//
//
//void mergeSort(int * arr, int left, int right){
//	if(left<right){
//		int mid = (left+right)/2;
//	    mergeSort(arr, left, mid);
//		mergeSort(arr, mid+1, right);
//		merge(arr, left, mid, right);
//	}
//}
//
//
//int main(void){
//	int arr[SIZE] = {4,5,3,6,1};
//	
//    for(int i=0;i<SIZE;i++){
//    	printf("%d ", arr[i]);
//	}
//	return 0;
//}








//int * merge(int * result, int * arr1, int * arr2){
//	int h1 = 0;
//	int h2 = 0;
//	int resultHead = 0;
//	
//	while(h1<size && h2<size){
//		if(arr1[h1]<=arr2[h2]) result[resultHead++] = arr1[h1++];
//		else result[resultHead++] = arr2[h2++];
//	}
//	
//	printf("%d %d\n", h1, h2);
//	return result;
//}
//
//int main(void){
//	int arr1[size] = {1,3,5,7,9};
//	int arr2[size] = {2,4,6};
//	int result[resultSize];
//	merge(result, arr1, arr2);
//	for(int i=0;i<resultSize;i++){
//		printf("%d ", result[i]);
//	}
//}
