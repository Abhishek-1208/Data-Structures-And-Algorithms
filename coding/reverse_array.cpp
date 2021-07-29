#include <stdio.h>
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
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
	
	reverse(a,n);
	
	printf("Array after reverseal: ");
	for(int i = 0; i < n; i++) {
		printf("%d ",a[i]);
	}
	printf("\n");

}
