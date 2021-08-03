/**
 * program to find every 3rd fibonacci number upto n values
 * compilation: gcc every3rd_term_of_fibonacci.c
 * Execution: Data-Structures-And-Algorithms/coding/every3rd_term_of_fibonacci.c
 * @Abhishek (1910991168) 
 * 03/08/2021
 * Assignemnt: 5
*/

#include <stdio.h>

//function to find every 3rd fibonacci number upto n terms
// Time : O(N)
// Space: O(1)
void fibo(int n, int *dp) {
	
	if( n <= 1) {
		dp[n] = (n == 1);
		return;
	}

	//if answer of n is not known already , then recur for it
	if(dp[n] == -1) {
		fibo(n - 1, dp);
		fibo(n - 2, dp);
		//adding the answer of previous 2 values to get answer for current value
		dp[n] = dp[n - 1] + dp[n - 2];
	}
	
}
int main() {
	int n;
	printf("Enter the number of Terms: ");
	scanf("%d", &n);
	int dp[3 * n + 1];
	
	for(int i = 0; i <= 3 * n; i++) {
		dp[i] = -1;
	}
	
	fibo(3 * n, dp);
	for(int i = 1, j = 3; i <= n; i++, j += 3) {
		printf("%d ", dp[j]);
	}
	
	printf("\n");

}
