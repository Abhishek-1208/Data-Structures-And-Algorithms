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
int is_present_in_2nd_string(char *str, int len, char x) {
	for(int i = 0; i < len; i++) {
		if(str[i] == x) {
			return 1;
		}
	}
	return 0;
}
int any(char *str1, int len1, char *str2, int len2) {
	
	
	for(int i = 0; i < len1; i++) {
		if(is_present_in_2nd_string(str2, len2, str1[i]) ) {
			return i;
		}
	}
	
	return -1;
	
}
int main() {
	char str1[50], str2[50];
	printf("Enter the 1st string: ");
	int len1 = input_string(str1);
	printf("Enter the 2nd string: ");
	int len2 = input_string(str2);
	
	int index = any(str1, len1, str2, len2);
	if(index == -1) {
		printf("There is no occurence of any character of string2 in string\n");
	}
	else {
		printf("%d is the index where first occurence of any character of string2 is find in string1\n", index);
	}
	
}
