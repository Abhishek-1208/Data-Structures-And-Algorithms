/**
 * program to reverse the given string 
 * compilation: gcc string_reversal.c
  Execution: Data-Structures-And-Algorithms/coding/string_reversal.c
 * @Abhishek (1910991168) 
 * 29/07/2021
 * Assignemnt: 3
*/
#include <stdio.h>

//return length of entered string as return value
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

//function to help us swap the passed 2 characters
void swap(char *x, char *y) {
	char temp = *x;
	*x = *y;
	*y = temp;
}
//functiont to reverse the passed array
void reverse(char *str) {
	int len = 0;
	//calculating the length of given string first
	while(str[len] != '\0') {
		len++;
	}
	
	int l = 0, r = len - 1;
	while(l < r) {
		//swapping the ith and (n-i-1)th character to reverse the string 
		swap(&str[l++], &str[r--]);
	}
}


int main() {
	char str[50], temp;
	printf("Enter the string: ");
	int len = input_string(str);
	printf("string before reversal is %s\n", str);
	reverse(str);
	printf("string after reversal is %s\n", str);
}
