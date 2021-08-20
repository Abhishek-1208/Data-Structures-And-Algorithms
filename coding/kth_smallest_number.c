/**
 * program to find kth smallest element in an array
 * compilation: gcc kth_smallest_number.c
 * Execution: ./a.out
 * @Abhishek (1910991168) 
 * 20/08/2021
 * Assignemnt: 8
*/

// I have used the lomuto partition scheme for partitioning the array which does more swaps compared to hoare partition scheme.
// Also lomuto partition takes a little more time compared to hoare partitions because of the more number of swaps

// Best Case T.C    : O(N)
// Average Case T.C : O(N)
// Worst Case T.C   : O(N ^ 2) ...this will occur if the array is sorted and our random function always pick first element as pivot ..although chances of it are very less.

// Space : O(1)

#include <stdio.h>

// to swap passed 2 variables
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


//partition function which partition the array around a particular element
int partition(int *arr, int n, int start, int end) {
    
    int len = end - start + 1;
    //using rand() function for random pivot element
    int pivot = start + rand() % len;
    swap(&arr[pivot], &arr[end]);

    int idx = start;

    for(int i = start; i <= end; i++) {
        if(arr[i] <= arr[end]) {
            swap(&arr[i], &arr[idx]++);
        }
    }
    //correct index of pivot if array is sorted
    return idx - 1;

}

int kth_smallest_element(int *arr, int n, int k) {

    int l = 0, r = n - 1;

    while(l <= r) {

        int pos = partition(arr, n, l, r);

        //if the correct position pivot has its index equals k - 1 ..it means we are done with the search and it is the required index
        if(pos == k - 1) {
            return arr[pos];
        }

        //it means that kth element must be smaller so reducing the range to the left
        else if(pos >= k) {
            r = pos - 1;            
        }

        //it means that kth element must be greater than current element so reducing the range to the right
        else {
            l = pos + 1;   
        }

    }
    
    //reaching this point means that we did'nt found the element which means k is out of the array range
    printf("entered position is out of range\n");
    return -1;    
    
}

int main() {

    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter the elements of array: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    int k;
    printf("Enter the position: ");
    scanf("%d", &k);

    printf("Required element is %d\n" , kth_smallest_element(a, n, k));
    
    
}