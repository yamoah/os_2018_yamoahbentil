
/*yamoah bentil   my_greg */
#include <stdio.h>
#include <string.h>

int findPattern(char pattern[], char text[]);

int main(int argc, char *argv[]){
	char c;
	FILE *infile;
	infile = fopen(argv[1],"r");
	c = fgetc(infile);
	if (infile == NULL){
		printf("Cannot open file \n"); 
		exit(0); 
    }
	while (c !=EOF){
		/*printf("%c", c);*/
		
		c = fgetc(infile);
	}
	fclose(infile);
	return 0;
}

int findPattern(char pattern[], char text[]){
	return 0;
}
