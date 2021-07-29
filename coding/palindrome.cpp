//program to check whether given string is palindrome or not ignoring white spaces and lowercase and uppercase conditions
#include <stdio.h>

//return length of entered string as return value after taking input from user
int input_string(char *str)  {
	char temp;
	int len = 0;
	while(temp = getchar()) {
		if(temp =='\n') {
			str[len] ='\0';
			break;
		}
		else
			str[len++] = temp; 
	}
	return len;
}

//auxillary function to check whether x and y are equal or not regardless of uppercase or lowercase condition
int are_equal(char x, char y) {
	if(x >= 'a' &&  x <= 'z') {
		return (x == y) || ((x - 32) == y);
	}
	if(x >= 'A' && x <= 'Z') {	
		return (x == y) || ((x + 32) == y);
	}
	return x == y;
}
//function to check whether the given string is palinrome or not after ignoring white spaces and uppercase and lowercase
int is_palindrome(char *str, int len) {
	int l = 0, r = len - 1;
	while(l < r) {
		//ignore in case of white space
		if(str[l] == ' ') {
			l++;
		}
		else if(str[r] == ' ') {
			r--;
		}
		//check if the given 2 character are equal or not
		else {
			//if not equal return 0;
			if(are_equal(str[l], str[r]) == 0) {
				return 0;
			}
			else {
				l++;
				r--;
			}
		}
		
	}
	//reaching here means all character are in required form ..so we return true 
	return 1;
}
int main() {
	char str[50], temp;
	printf("Enter the string: ");
	int len = input_string(str);
	//if is_palindrome returns true ..print true otherwise false
	if(is_palindrome(str, len)) {
		printf("true\n");
	}
	else {
		printf("false\n");
	}
}
