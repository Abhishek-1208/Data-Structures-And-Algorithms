#include <stdio.h> 
#include <stdlib.h>
int ** multiply_matrices(int **a, int n1, int m1, int **b, int n2, int m2, int *res_row, int *res_col) {
	
	if(m2 != n1) {
		return nullptr;
	}
	
	*res_row = n1;
	*res_col = m2;
	int ** res = (int**)malloc(*res_row * sizeof(int));
	for(int i = 0; i < *res_row; i++) {
		res[i] = (int *)malloc(*res_col * sizeof(int));
		for(int j = 0; j < *res_col; j++) {
			res[i][j] = 0;
            for (int k = 0; k < m1; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
		}
	}
	
	
	
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
	if(res_row == -1) {
		printf("Matrix multiplication is not possible for the given matrices\n");
		
	}
	else {
		printf("resultant matrix after multiplication is given below:\n");
		for(int i = 0; i < res_row; i++) {
			for(int j = 0; j < res_col; j++) {
				printf("%d ", res[i][j]);	
			}
			printf("\n");
		}
	}
	
	
}
