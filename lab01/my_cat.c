/*yamoah bentil   my_cat */
#include <stdio.h>
#include <stdlib.h>
/*
int main(void){
	printf("Hello");
	printf("\n");
	int c;
	while((c=getchar())!=EOF)
		putchar(c);
}
int main(int argc, char *argv[]){
	int i;
	for(i=1; i<argc; ++i)
		printf("%s", argv[i]);
	printf("\n");
}*/
int main(){
	char c;
	FILE *infile;
	infile = fopen("testdoc.txt","r");
	c = fgetc(infile);
	while (c !=EOF){
		printf("%c", c);
		c = fgetc(infile);
	}
	fclose(infile);
	return 0;
}
