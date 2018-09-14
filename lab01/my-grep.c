/*yamoah bentil  my_grep */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findPattern(char pattern[], char text[]);

int main(int argc, char *argv[]){
	char* c;
	int cc;
	/*FILE *infile; char cc = patt; */
	char *patt = argv[1];
	
	FILE *infile = fopen(argv[2],"r");
	c,cc = fgetc(infile);
	if (infile == NULL){
		printf("Cannot open file \n");
		exit(0);
    }
	while (cc !=EOF){
		/*printf("%c", c);*/
		findPattern(patt, c);
		c,cc = fgetc(infile);
	}
	fclose(infile);
	return 0;
}

int findPattern(char pattern[], char text[]){
	int i, j, count, lenPattern, lenText = -1;
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
			if(count==lenPattern){
				printf(text);
				i=(lenText-lenPattern)+1;
			}	
		}
	}
	return 0;
}
