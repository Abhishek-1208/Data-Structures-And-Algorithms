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
int squeeze(char *str1, int len1, char *str2, int len2) {
	
	int new_len = 0;
	for(int i = 0; i < len1; i++) {
		if(is_present_in_2nd_string(str2, len2, str1[i]) == 0) {
			str1[new_len++] = str1[i];
		}
	}
	
	str1[new_len] = '\0';
	return new_len;
}
int main() {
	char str1[50], str2[50];
	printf("Enter the 1st string: ");
	int len1 = input_string(str1);
	printf("Enter the 2nd string: ");
	int len2 = input_string(str2);
	
	printf("string Before squeezing with 2nd string is %s\n", str1);
	len1 = squeeze(str1, len1, str2, len2);
	printf("string after squeezing with 2nd string becomes %s\n", str1);
	
}
