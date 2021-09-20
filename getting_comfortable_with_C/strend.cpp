/**
 * program to check if the pattern is present at the end of string or not
 * compilation: gcc strend.c
 * Execution: Data-Structures-And-Algorithms/coding/strend.c
 * @Abhishek (1910991168) 
 * 29/07/2021
 * Assignemnt: 3
**/
#include<stdio.h>
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

//helper function to check if the patter is present or not at the end of given string
int  strend(char *str, int len1, char *pat, int len2) {
	if(len2 > len1)
		return 0;
    
	for(int i = len1 -1 , j = len2 - 1; j >= 0; j--, i-- ) {
		//if any character from end is not equal with character of given string...then the pattern does'nt exist at the end so return false
		if(str[i] != pat[j]) {
			return 0;
		}
		
	}	
    
	//reaching at this point means all character of the given pattern were found at the end of string ..so returning true
	return 1;
}

int main() {
	char str[50], pat[50];
	
	printf("Enter the string: ");
	int len1 = input_string(str);
	
	printf("Enter the patter to be searched: ");
	int len2 = input_string(pat);
	//function to check if pattern exist at the end of string or not
	int index =  strend(str, len1, pat, len2);
	printf("%d", index);
	
}
