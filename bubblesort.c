#include <stdio.h>

/*------------------------------------------------
+ Function pointers point to data in text segment
+ Pointers are always the same length
+ Global variables exist for length of program
------------------------------------------------*/

int arr[] = {34, 23, 12, 22, 11, 64, 90};//exists in DATA segment
const int N = sizeof(arr)/sizeof(arr[0]);//exists in DATA segment

void swap/*TEXT segment*/(int *xp, int *yp){
	int temp/*STACK segment*/ = *xp; //malloc(sizeof(int)) - this would exist in heap
	*xp = *yp; //exists in STACK, only lasts for length of function
	*yp = temp; //&temp - returns adress from HEAP, not STACK
}
void bubbleSort/*TEXT segment*/(int arr[], int n){
	for (int i = 0; i < n-1; i++){
		for (int j = 0; j < n-i-1; j++){
			if (arr[j] > arr[j+1]){
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}
void printArray/*TEXT segment*/(int arr[], int size){
	for (int i=0; i < size; i++){
		printf("%d", arr[i]);
	}
	printf("\n");
}

int main/*TEXT segment*/() {
	bubbleSort(arr, N);
	printf("Sorted array: \n");
	printArray(arr, N);
	return 0;
}
