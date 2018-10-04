/* yamoah wish  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#define MAX 15

void doWish();
void doBatchWish(char* filename);
char **wish_split_line(char *line);
int wish_execute(char **args);
int wish_launch(char **args);
int wish_cd(char **args);
int wish_help(char **args);
int wish_path(char **args);

char *builtin_str[] = {"cd", "help", "path"};

int (*builtin_func[]) (char **) = {
&wish_cd, &wish_help, &wish_path};

int wish_num_builtins() {
  return sizeof(builtin_str) / sizeof(char *);
}

//.....................................
int wish_cd(char **args){
    if (args[1] == NULL){
        fprintf(stderr, "wish: expected argument to \"cd\"\n");
    }
    if (args[2]==NULL){
        if (chdir(args[1]) != 0) {perror("wish> ");}
    }
    else {
        fprintf(stderr, "wish: expected only one argument to \"cd\"\n");
    }
    return 1;
}
int wish_help(char **args){
  int i;
  printf("Type program names and arguments, and hit enter.\n");
  printf("The following are built in:\n");

  for (i = 0; i < wish_num_builtins(); i++) {
    printf("->%s\n", builtin_str[i]);
  }

  return 1;
}
int wish_path(char **args){
    printf("The path function\n");
    if (access(args[1], X_OK)!=-1){
        perror("wish> ");
    }
    if (access(args[1], X_OK)!=-1){
        perror("wish> ");
    }
        //printf("path set to ");

    return 1;
}//access("/bin/ls", X_OK).....access("/usr/bin/ls", X_OK)..


//.....................................


int main(int argc, char *argv[]){
    char *batchfile = argv[1];
    char *otherCommand = argv[2];
    if (batchfile==NULL){
    	doWish();
	}
    else{
    	if (otherCommand==NULL){
    		doBatchWish(batchfile);
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
    char **args;
    int status;
    while(memcmp(buf, "exit", strlen("exit") )!=0){
        args = wish_split_line(buf);
        status = wish_execute(args);
		printf("wish> ");
		fgets(buf, MAX, stdin);
	}
}

void doBatchWish(char* filename){
    char c, myLine[255];
    char **args;
    int status;
	FILE *infile;
	infile = fopen(filename,"r");
	
	if (infile == NULL){
		printf("Cannot open file \n");
		exit(0);
    }
    while(fgets(myLine, 255, infile)){
        args = wish_split_line(myLine);
        status = wish_execute(args);
	}
	fclose(infile);
}

//.............................................................//
#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"
char **wish_split_line(char *line){
    int bufsize = LSH_TOK_BUFSIZE, position = 0;
    char **splitArray = malloc(bufsize * sizeof(char*));
    char *token;

  if (!splitArray) {
    fprintf(stderr, "wish> : allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = strtok(line, LSH_TOK_DELIM);
  while (token != NULL) {
    splitArray[position] = token;
    position++;

    if (position >= bufsize) {
      bufsize += LSH_TOK_BUFSIZE;
      splitArray = realloc(splitArray, bufsize * sizeof(char*));
      if (!splitArray) {
        fprintf(stderr, "wish> : allocation error\n");
        exit(EXIT_FAILURE);
      }
    }
    token = strtok(NULL, LSH_TOK_DELIM);
  }
  splitArray[position] = NULL;
  return splitArray;
}

//............................................./
int wish_execute(char **args)
{
  int i;

  if (args[0] == NULL) {
    // An empty command was entered.
    return 1;
  }

  for (i = 0; i < wish_num_builtins(); i++) {
    if (strcmp(args[0], builtin_str[i]) == 0) {
      return (*builtin_func[i])(args);
    }
  }

  return wish_launch(args);
}

int wish_launch(char **args){
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("wish> ");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Error forking
        perror("wish> ");
    } else {
        // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
      }

  return 1;
}



