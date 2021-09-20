/**
 * program to analyze different sorting algorithms speed on various inputs
 * compilation: gcc analyzing_different_sorting_algorithms_speed.c
 * Execution: Data-Structures-And-Algorithms/coding/analyzing_different_sorting_algorithms_speed.c
 * @Abhishek (1910991168) 
 * 29/07/2021
Assignemnt: 3

**** ---> link of google sheet showing chart and anlysis of all algorithms on different input:  "https://bit.ly/3kVj0B2"   <----- *****

*/


#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>
#include <stdlib.h>

//function to swap value of 2 variables
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//function to generate random input for testing
void random_input_generator(int *arr, int n) {
	for(int i = 0; i < n; i++) {
		arr[i] = rand();
	}
}

//function to generate increasing input for testing
void increasing_input_generator(int *arr, int n) {
	for(int i = 0; i < n; i++) {
		arr[i] = i;
	}
}

//function to generate decreasing input for testing
void decreasing_input_generator(int *arr, int n) {
	for(int i = 0; i < n; i++) {
		arr[i] = n-i;
	}
}

//function to perform bubble_sort algo on passed array
void bubble_sort(int *arr, int n) {
	
	for(int i = 0; i < n - 1; i++) {
		int is_swap_performed = 0;
		for(int j = 0; j < n - i - 1; j++) {
			if(arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				is_swap_performed = 1;
			}
		}
		// in case no element is swapped in last iteration , it means array is sorted now and we can safely exit
		if(is_swap_performed == 0) {
			break;
		}
	}
}


//function to perform selection sort algo on passed array
void selection_sort(int *arr, int n) {
	for (int i = 0; i < n-1; i++){
		int min_idx = i;
		//finding the minimum element in the range A[i...n] 
        	for (int j = i+1; j < n; j++) {
	        	if (arr[j] < arr[min_idx]) {
	            		min_idx = j;
			}
		}
		//placing current minimum to its correct position by swapping     
	    	swap(&arr[min_idx], &arr[i]);
	}
}


//function to perform insertion sort algo on passed array
void insertion_sort(int *arr, int n) {
	
	for(int i = 1; i < n; i++) {
		int curr_element = arr[i];
		int j = i;
		//finding correct position for the current element in the already sorted array [0... i-1]
		while(j > 0 && arr[j - 1] > curr_element) {
			arr[j] = arr[j - 1];
			j--; 
		} 
		arr[j] = curr_element;
	}
}


//time calculator to analyze performance of specified algo on various type of inputs
long long time_calculator(int *arr, int n, int algo_no) {
	struct timeval start;	
	struct timeval end;	
	long long time_taken;	


	//performing the algo specified by the user and marking the time taken by it
	switch (algo_no) {
		case 1: {
			gettimeofday(&start, 0);	// mark the start time 
			insertion_sort(arr, n);			
			gettimeofday(&end, 0);		// mark the end time 
			
			break;
		}
		case 2: {
			gettimeofday(&start, 0);	// mark the start time 
			selection_sort(arr, n);			
			gettimeofday(&end, 0);		// mark the end time 
			break;
		}
		case 3: {
			gettimeofday(&start, 0);	// mark the start time 
			bubble_sort(arr, n);			
			gettimeofday(&end, 0);		// mark the end time 
			break;
		}
	}

	//formula to convert seconds to microseconds
	time_taken = ((end.tv_sec * 1000000) + end.tv_usec) - ((start.tv_sec * 1000000) + start.tv_usec);
	return time_taken;
}


//driver function
int main() {
	
	printf("1. Insertion Sort\n");
	printf("2. Selection Sort\n");
	printf("3. Bubble Sort\n");
	printf("Enter the Algorithm Number you want to perform: ");
	int algo_no;
	scanf("%d", &algo_no);
	
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
		time_taken = time_calculator(arr, n, algo_no);
		printf("Time taken by specified algorithm for random input of size %d is %lld \n", n, time_taken);
		
		increasing_input_generator(arr, n);
		time_taken = time_calculator(arr, n, algo_no);
		printf("Time taken by specified algorithm for increasing input of size %d is %lld \n", n, time_taken);
		
		decreasing_input_generator(arr, n);
		time_taken = time_calculator(arr, n, algo_no);
		printf("Time taken by specified algorithm for decreasing input of size %d is %lld \n\n", n, time_taken);
		
	}
	
}
