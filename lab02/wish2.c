/* yamoah wish  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 15

void doWish();
void doBatchWish();


int main(int argc, char *argv[]){
	
    char *batchfile = argv[1];
    char *otherCommand = argv[2];
    if (batchfile==NULL){
    	doWish();
	}
    else{
    	if (otherCommand==NULL){
    		doBatchWish();
		}
		else{
			printf("use either one argument or no arguments");
		}
	}
    return 0;
}

void doWish(){
	printf("wish> ");
	
	char buf[MAX]; 
    fgets(buf, MAX, stdin);
    
    //char* myString;
    //scanf("%s", &myString);
    //while(myString!="exit"){
    while(buf!="exit"){
    	//printf("%s", &myString);
    	//scanf("%s", &myString);
		printf("string is: %s", buf);
		printf("wish> ");
		fgets(buf, MAX, stdin);
		if(buf=="exit"){
			printf("A match");
		}
		
	}
	//printf("the no arg one");
}

void doBatchWish(){
	printf("the batch one");
}
