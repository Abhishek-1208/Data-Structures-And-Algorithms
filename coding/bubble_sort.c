#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>
#include <stdlib.h>
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void random_input_generator(int *arr, int n) {
	for(int i = 0; i < n; i++) {
		arr[i] = rand();
	}
}
void increasing_input_generator(int *arr, int n) {
	for(int i = 0; i < n; i++) {
		arr[i] = i;
	}
}
void decreasing_input_generator(int *arr, int n) {
	for(int i = 0; i < n; i++) {
		arr[i] = n-i;
	}
}


void bubble_sort(int *arr, int n) {
	
	for(int i = 0; i < n - 1; i++) {
		int is_swap_performed = 0;
		for(int j = 0; j < n - i - 1; j++) {
			if(arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				is_swap_performed = 1;
			}
		}
		if(is_swap_performed == 0) {
			break;
		}
	}
}

long long time_calculator(int *arr, int n) {
	struct timeval start;	
	struct timeval end;	
	long long time_taken;	

	gettimeofday(&start, 0);	// mark the start time 
	bubble_sort(arr, n);
	gettimeofday(&end, 0);		// mark the end time 

	time_taken = ((end.tv_sec * 1000000) + end.tv_usec) - ((start.tv_sec * 1000000) + start.tv_usec);
	return time_taken;
}


int main() {
	
	int test_cases;
	printf("Enter The number of TestCases: ");
	scanf("%d", &test_cases);
	while(test_cases--) {
		int n;
		printf("Enter The size of array: ");
		scanf("%d", &n);
		int arr[n + 1]; // + 1 is done so as to handle the base case if user entered the size as 0 
		long long time_taken;
		random_input_generator(arr, n);
		time_taken = time_calculator(arr, n);
		printf("Time taken by Bubble Sort for random input of size %d is %lld \n", n, time_taken);
		
		increasing_input_generator(arr, n);
		time_taken = time_calculator(arr, n);
		printf("Time taken by Bubble Sort for increasing input of size %d is %lld \n", n, time_taken);
		
		decreasing_input_generator(arr, n);
		time_taken = time_calculator(arr, n);
		printf("Time taken by Bubble Sort for decreasing input of size %d is %lld \n\n", n, time_taken);
		
	}
	
}
