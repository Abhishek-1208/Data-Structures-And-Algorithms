/**
 * program to find the rightmost occurence of given pattern in the given string
 * compilation: gcc strrindex.c
  Execution: Data-Structures-And-Algorithms/coding/strrindex.c
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

//function to find the rightmost occurence of given pattern
//return starting index where rightmost occurence found ..if there is no occurence ..then it will return -1
int strrindex(char *str, int len1, char *pat, int len2) {
    int res = -1;

    for(int i = 0; i < len1; i++)
    {
    	
    	int j = i, k = 0;
    	//comparing pattern with given string starting from ith position
	while( j < len1 && k < len2  && str[j] == pat[k]) {
    		j++,k++;
	}
    	//if the whole pattern is traversed sucessfully ..it means patter is present and note down its occurence
	if(k == len2) {
            res = i;
	}
    
	}
    return res;
}

int main() {
	char str[50], pat[50];
	
	printf("Enter the string: ");
	int len1 = input_string(str);
	
	printf("Enter the patter to be searched: ");
	int len2 = input_string(pat);

	//calling the function to get the appropriate index if pattern is present
	int index = strrindex(str, len1, pat, len2);
	
	if(index == -1) {
		printf("there is no occurence of given pattern in the string\n");
	}
	
	else {
    	printf("rightmost occurence is found at index: %d\n", index);
	}
	
}
