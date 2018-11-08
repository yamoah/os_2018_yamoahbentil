
// A C/C++ program for splitting a string
// using strtok()
#include <stdio.h>
#include <string.h>

char* strsplit(char* myString){
	char* str[strlen(myString)];
  
    // Returns first token
    char *token = strtok(myString, ",");
    
    // Keep printing tokens while one of the
    // delimiters present in str[].
    int count = 0;
    while (token != NULL)
    {
        printf("%s\n", token);
        str[count] = token;
        token = strtok(NULL, ",");
        count++;
    }
    return str;
}

int main()
{
	char str[] = "one,two,three,four";
	char* result = strsplit(str);
     return 0;
}
