/* yamoah wish  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	/** int a, b, c;
    printf("Enter the first value:");
    scanf("%d", &a);
    printf("Enter the second value:");
    scanf("%d", &b);
    c = a + b;
    printf("%d + %d = %d\n", a, b, c); **/
    printf("wish>");
    char* myString;
    scanf("%s", &myString);
    while(myString!="exit"){
    	printf("wish >");
    	//printf("%s", &myString);
    	scanf("%s", &myString);
	}
    
    return 0;
}
