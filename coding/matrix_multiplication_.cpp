/**
 * program to multiply given 2 matrices
 * compilation: gcc program to multiply given 2 matrices.c
  Execution: Data-Structures-And-Algorithms/coding/program to multiply given 2 matrices.c
 * @Abhishek (1910991168) 
 * 29/07/2021
 * Assignemnt: 3
*/
#include <stdio.h> 
#include <stdlib.h>

//helping function to find the matrix multiplication of given 2 matrices
int ** multiply_matrices(int **a, int n1, int m1, int **b, int n2, int m2, int *res_row, int *res_col) {
	
	//condition to check whether matrix multiplication is possible or not for the given 2 matrices
	if(m2 != n1) {
		return nullptr;
	}
	
	*res_row = n1;
	*res_col = m2;
	//dynamically creating the resultant matrix
	int ** res = (int**)malloc(*res_row * sizeof(int));
	
	for(int i = 0; i < *res_row; i++) {
		
		//providing the required number of columms in current row
		res[i] = (int *)malloc(*res_col * sizeof(int));
		
		for(int j = 0; j < *res_col; j++) {
			res[i][j] = 0;
			//calculating value of current cell using by multiplying ith row of first matrix with jth column of second matrix
			for (int k = 0; k < m1; k++) {
				res[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	//returning the final matrix
	return res;
}

int main() {
	
	int n1, m1;
	printf("Enter the dimension of 1st matrix: ");
	scanf("%d %d", &n1, &m1);
	
	int *a[n1];
	printf("Enter the elements of the 1st matrix:\n");
	for(int i = 0; i < n1; i++) {
		a[i] = (int *)malloc(m1 * sizeof(int));
		for(int j = 0; j < m1; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	int n2, m2;
	printf("Enter the dimension of 2nd matrix: ");
	scanf("%d %d", &n2, &m2);
	
	int *b[n2];
	printf("Enter the elements of the 2nd matrix:\n");
	for(int i = 0; i < n2; i++) {
		b[i] = (int *)malloc(m2 * sizeof(int));
		for(int j = 0; j < m2; j++) {
			scanf("%d", &b[i][j]);
		}
	}
	
	int res_row = -1, res_col = -1;
	int **res = multiply_matrices(a, n1, m1, b, n2, m2, &res_row, &res_col);
	//res_row = -1 means that multiplication is not possible
	if(res_row == -1) {
		printf("Matrix multiplication is not possible for the given matrices\n");
	}
	else {
		//printing the content in case multiplication of the given matrices is possible
		printf("resultant matrix after multiplication is given below:\n");
		for(int i = 0; i < res_row; i++) {
			for(int j = 0; j < res_col; j++) {
				printf("%d ", res[i][j]);	
			}
			printf("\n");
		}
	}
	
	
}
