/*yamoah bentil  my-grep_2 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findPattern(char pattern[], char text[]);
void helpMessage();
char myLine[255];

int main(int argc, char *argv[]){
	
	char *patt = argv[1];
	if (patt==NULL){
		helpMessage();
	}
	
	FILE *infile = fopen(argv[2],"r");
	if (infile == NULL){
		helpMessage();
    }
    
    while(fgets(myLine, 255, infile)){
		findPattern(patt, myLine);
	}
	fclose(infile);
	return 0;
}

int findPattern(char pattern[], char text[]){
	int i, j, count, lenPattern, lenText = 0;
	lenPattern = strlen(pattern);
	lenText = strlen(text);
	if(lenPattern > lenText)
		return 0;
	else{
		for(i=0; i<=lenText-lenPattern; i++){
			count = 0;
			for(j=0; j<lenPattern; j++){
				if(pattern[j]==text[j+i])
					count++;
			}
			if(count==lenPattern){
				i=(lenText-lenPattern)+1;
				printf(text);
			}	
		}
	}
	return 0;
}

void helpMessage(){
	printf("missing parameter(s), quiting.....\n");
	printf("try 'my-grep' 'pattern' 'filename' \n");
	printf("eg my-grep foo hello.txt\n");
	exit(0);
}
