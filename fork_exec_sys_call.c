##FORK - to create a child process for the parent processes.
// Default code to print process id.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
  printf("This is a default process \n PID=%d\n", getpid());
  return 0; 
}

// Code to create a child process from a parent process using fork.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
  fork();
  printf("This is a default process \n PID=%d\n", getpid());
  return 0; 
}

// The above program will create two process - 1 parent and 1 child.

// If there are multiple fork commands, it will create a child process for each newly created process, So the number of process 
increases exponentially to the power of 2.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
  fork();
  fork();
  fork();
  printf("This is a default process \n PID=%d\n", getpid());
  return 0; 
}

// the program above creates 8 processes - each fork creates a child, next fork creates child for both parent and newly created
process. 

##EXEC  - To transfer the information from one process to another process without creating a new process

//exec1.c

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(int argc, char *argv) {
  printf("PID of process 1 = %d\n", getpid());
  char *str[] = {"This", "is", "process1", NULL};
  execv("./exec2.c", str);
  printf("Control returned to exec1");
  return 0;
}

//exec2.c

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
        printf("PID of process 2 = %d\n", getpid());
        printf("This is process 2\n");
        return 1;
}

//If we run this program, we will see that process 1 and process 2 will have the same process ID but different data. 
