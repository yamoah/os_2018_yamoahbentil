/*yamoah bentil   my_greg */
#include <stdio.h>
#include <string.h>

int findPattern(char pattern[], char text[]);

int main(int argc, char *argv[]){
	char c;
	FILE *infile;
	char *patt = argv[1];
	infile = fopen(argv[2],"r");
	c = fgetc(infile);
	if (infile == NULL){
		printf("Cannot open file \n"); 
		return 1;/*exit(0);*/
    }
	while (c !=EOF){
		findPattern(patt,c);
		c = fgetc(infile);
	}
	fclose(infile);
	return 0;
}

int findPattern(char pattern[], char text[]){
	int i, j, count, lenPattern, lenText =0;
	lenPattern = strlen(pattern);
	lenText = strlen(text);
	if(lenPattern > lenText)
		return 0;
	else{
		for(i=0; i<=lenText-lenPattern; i++){
			count = 0;
			for(j=0; j<lenPattern; j++){
				if(pattern[j]=text[j+i])
					count++;
			}
			if(count==lenPattern)
				printf(text);
		}
	}
	return 0;
}
