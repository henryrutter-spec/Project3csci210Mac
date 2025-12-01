#include <stdio.h>
#include <stdlib.h>
#include <spawn.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

#define N 12

extern char **environ;

char *allowed[N] = {"cp","touch","mkdir","ls","pwd","cat","grep","chmod","diff","cd","exit","help"};

int isAllowed(const char*cmd) {
	// TODO
	
	for(int k=0; k<N; k++){

	int compareValue=strcmp(allowed[k],cmd);
	if(compareValue==0){
	return 1;
	}
	
	
	}

	
	// return 1 if cmd is one of the allowed commands
	// return 0 otherwise
	
	return 0;
}

int main() {

    // TODO
    // Add variables as needed
    //
    pid_t cpid;
    int status=0;
    posix_spawnattr_t attr;
    //cpid=fork();

    char line[256];



	char*  inputList[256];
	

    while (1) {
	//posix_spawnattr_t attr;
	fprintf(stderr,"rsh>");

	if (fgets(line,256,stdin)==NULL) continue;

	if (strcmp(line,"\n")==0) continue;

	line[strlen(line)-1]='\0';
	


    
	


	// TODO
	// Add code to spawn processes for the first 9 commands
	// And add code to execute cd, exit, help commands
	// Use the example provided in myspawn.c
	int i=0;
	char* token=strtok(line, " ");
	while (token!=NULL) {
	
	//printf("bbbbbbbbbbbb");

	
        inputList[i]=token;
	token=strtok(NULL," ");
	i+=1;
	

	}
	inputList[i]=NULL;


	int cmdAllowed=0;
	//for(int j=0; j<sizeof(inputList)/(sizeof(char)); j++)
	
	cmdAllowed=isAllowed(inputList[0]);
	//printf("%d", cmdAllowed);


		
	if(cmdAllowed!=1){
	printf("NOT ALLOWED\n");
	//exit(EXIT_FAILURE);
	continue;
	}
	

	
	if(strcmp(inputList[0],"help")==0){
        	printf("1: cp\n2: touch\n3: mkdir\n4: ls\n5: pwd\n6: cat\n7: grep\n8: chmod\n9: diff\n10: cd\n11: exit\n12: help\n");
	continue;
        }



	if(strcmp(inputList[0],"cd")==0){
	
		if(i==2){
			chdir(inputList[1]);
	
		}
		else{
			printf("-rsh: cd: too many arguments");
		}
	continue;
	}

	
	if(strcmp(inputList[0],"exit")==0){
		return 0;
	}

	posix_spawnattr_init(&attr);


	if(posix_spawnp(&cpid, inputList[0], NULL, &attr, inputList, environ)!=0){
	perror("Spawn failed");
	exit(EXIT_FAILURE);
	}
	


	//else{
	//if(inputList[j]=="ls"){
	
	//}
	
	
	
	
	//}
	//printf("fasdsdffsdfdsfa");

	if (waitpid(cpid, &status, 0) == -1) {
        perror("waitpid failed");
        exit(EXIT_FAILURE);
    }
	


	
	posix_spawnattr_destroy(&attr);

    	//return EXIT_SUCCESS;


	


	//if(cpid==0){
	//execlp("ls", "ls", "-al", (char*)0);
	//posix_spawn("ls", "ls", "-al", (char*)0);
	//cpid=fork("ls");
	//}
	//else{
	
	//}
	


    }
   

     return 0;

    }
