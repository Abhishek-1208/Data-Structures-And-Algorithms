/**
 * program to reverse given array
 * compilation: gcc reverse.c
  Execution: Data-Structures-And-Algorithms/coding/reverse.c
 * @Abhishek (1910991168) 
 * 29/07/2021
 * Assignemnt: 3
*/
#include <stdio.h>

//function to swap given 2 values
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//helping function to reverse the passed array using 2 pointer approach
void reverse(int *a, int n) {
	int l = 0, r = n - 1;
	while(l < r) {
		swap(&a[l++], &a[r--]);
	}
}

int main() {
	int n;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	
	int a[n];
	printf("Enter the elements: ");
	for(int i = 0; i < n; i++) {
		scanf("%d",&a[i]);
	}
	
	printf("Array before reverseal: ");
	for(int i = 0; i < n; i++) {
		printf("%d ",a[i]);
	}
	printf("\n");
	//calling the function to reverse the array
	reverse(a,n);
	
	printf("Array after reverseal: ");
	for(int i = 0; i < n; i++) {
		printf("%d ",a[i]);
	}
	printf("\n");

}
