/**
 * program to sort the array using recursive selection sort
 * compilation: gcc recursive_sort.c
 * Execution: Data-Structures-And-Algorithms/coding/recursive_sort.c
 * @Abhishek (1910991168) 
 * 03/08/2021
 * Assignemnt: 5
*/

#include<stdio.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int recur_for_min_ele(int *arr, int idx, int n) {
	
	if(idx == n - 1)  {
		return idx;
	}
	
	//keep rucurring in range i + 1 to n to find minimum element index
	int min_ele_idx = recur_for_min_ele(arr, idx + 1, n);
	
	// comparing the result of range i + 1 to n with current element and returning the corresponding result
	
	if(arr[idx] <= arr[min_ele_idx]) {
		return idx;
	}
	
	else {
		return min_ele_idx;
	}	
		
}

//function to sort the passed array using selection sort
// Time  : O(N*N)
// Space : O(1)  if we don't consider recursion call stack otherwise O(N)
void selection_sort_using_recursion(int *arr, int n) {
	
	for(int i = 0; i < n - 1; i++) {
		
		//finding minimum element in range i to n
		int min_ele_idx = recur_for_min_ele(arr, i, n);
//		placing the current minimum to its exact position
		swap(&arr[i], &arr[min_ele_idx]);
	}
	
}
int main() {
	int n;
	printf("Enter the number of terms: ");
	scanf("%d", &n);
	int a[n];
	printf("Enter the elements: ");
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	printf("array before sorting is : ");
	for(int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	selection_sort_using_recursion(a, n);
	printf("array after sorting is : ");
	for(int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	
}
