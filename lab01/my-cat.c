/*yamoah bentil   my_cat */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	char c;
	char myLine[255];
	
	FILE *infile;
	infile = fopen(argv[1],"r");
	
	if (infile == NULL){
		printf("Cannot open file \n");
		exit(0);
    }
    
    while(fgets(myLine, 255, infile)){
    	printf(myLine);
	}
	
	fclose(infile);
	return 0;
}

