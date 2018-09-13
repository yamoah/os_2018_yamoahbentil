/*yamoah bentil   my_cat */
#include <stdio.h>
#include <stdlib.h>

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
		printf("%c", c);
		c = fgetc(infile);
	}
	fclose(infile);
	return 0;
}

