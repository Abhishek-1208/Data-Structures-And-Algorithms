#include <stdio.h>

void swap(char *x, char *y) {
	char temp = *x;
	*x = *y;
	*y = temp;
}
void reverse(char *str) {
	int len = 0;
	while(str[len] != '\0') {
		len++;
	}
	int l = 0, r = len - 1;
	while(l < r) {
		swap(&str[l++], &str[r--]);
	}
}


int main() {
	char str[50], temp;
	printf("Enter the string: ");
	int len = 0;
	while(temp = getchar()) {
		if(temp =='\n') {
			str[len] ='\0';
			break;
		}
		else
			str[len++] = temp; 
	}
	printf("string before reversal is %s\n", str);
	reverse(str);
	printf("string after reversal is %s\n", str);
}
