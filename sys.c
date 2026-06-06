#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
  /*
  fork();
  fork();
  fork();
  printf("PID: %d\n", getpid());
  fflush(stdout);
  */
  pid_t pid = fork();

  if(pid == 0){
    execlp("ls", "ls", "-1", NULL);
  } else if(pid > 0){
    wait(NULL);
    printf("\n-----child has dead-----\n");
  }
  /*
  if (pid > 0) {
     // Parent exits immediately
     exit(0); 
  } */
  // Child continues
  //sleep(5);
  //printf("Orphan Child: My new parent is PID %d\n", getppid());
  return 0;
}
