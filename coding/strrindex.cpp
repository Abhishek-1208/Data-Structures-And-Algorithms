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


int strrindex(char *str, int len1, char *pat, int len2) {
    int res = -1;

    for(int i = 0; i < len1; i++)
    {
    	
    	int j = i, k = 0;
    	while( j < len1 && k < len2  && str[j] == pat[k]) {
    		j++,k++;
		}
    	
		if( k > 0 && pat[k] == '\0')
            res = i;
    
	}
    return res;
}

int main() {
	char str[50], pat[50];
	
	printf("Enter the string: ");
	int len1 = input_string(str);
	
	printf("Enter the patter to be searched: ");
	int len2 = input_string(pat);

	int index = strrindex(str, len1, pat, len2);
	
	if(index == -1) {
		printf("there is no occurence of given pattern in the string\n");
	}
	
	else {
    	printf("rightmost occurence is found at index: %d\n", index);
	}
	
}
