#include <stdio.h>
int are_equal(char x, char y) {
	if(x >= 'a' &&  x <= 'z') {
		return (x == y) || ((x - 32) == y);
	}
	if(x >= 'A' && x <= 'Z') {	
		return (x == y) || ((x + 32) == y);
	}
	return x == y;
}
int is_palindrome(char *str, int len) {
	int l = 0, r = len - 1;
	while(l < r) {
		if(str[l] == ' ') {
			l++;
		}
		else if(str[r] == ' ') {
			r--;
		}
		else {
			if(are_equal(str[l], str[r]) == 0) {
				return 0;
			}
			else {
				l++;
				r--;
			}
		}
		
	}
	return 1;
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
	if(is_palindrome(str, len)) {
		printf("true\n");
	}
	else {
		printf("false\n");
	}
}
