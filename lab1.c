#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>

int main()
{
  pid_t pid = fork();

  if(pid < 0)
     return;
  else if(pid == 0)
  {

      char *arg[] = {"",NULL};
      execve("/bin/ls",arg,NULL);  	
      printf("Parent PID = %d    ",getppid());
      printf("Child PID=%d\n",getpid());
      exit(88);
  }
  else
  {
  	wait();
    printf("Child finished.\n");

  }

  return 0;
}
