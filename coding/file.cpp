#include <stdio.h>
int main() {
	
	FILE *fptr;
	fptr = fopen("E:/abhi/Documents/input.txt.txt","r");
	if (fptr == NULL) {
        printf("unable to  open file \n");
        return 0;
    }
    char pos;
	do {
		int len = 0;
		char temp[1000];
		do{
			pos = fgetc(fptr);
			temp[len++] = pos;
		}while(pos != '\n' && pos != EOF);
		
		if(len >= 80) {
			for(int i = 0; i < len; i++) {
				printf("%c", temp[i]);
			}
		}
		
	}while(pos != EOF);
	
	fclose(fptr);
	
}
