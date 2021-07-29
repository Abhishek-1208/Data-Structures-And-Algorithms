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


int  strend(char *str, int len1, char *pat, int len2) {
    if(len2 > len1)
    	return 0;
    
	for(int i = len1 -1 , j = len2 - 1; j >= 0; j--, i-- ) {
		if(str[i] != pat[j]) {
			return 0;
		}
	}	
    
    
    return 1;
}

int main() {
	char str[50], pat[50];
	
	printf("Enter the string: ");
	int len1 = input_string(str);
	
	printf("Enter the patter to be searched: ");
	int len2 = input_string(pat);

	int index =  strend(str, len1, pat, len2);
	printf("%d", index);
	
}
