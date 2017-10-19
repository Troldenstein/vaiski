/*
*  Author: Troldenstein
*  created: 19.10.2017
*
*  ABSOLUTELY NO WARRANTY, use at your own risk
*  If using this code, refer to project github link and be open sourced
*
*  In unix environment you may need to kill these processes
*  step 1 to see process pid: ps -A
*  step 2 to kill process:    kill 2345
*
*  in step 2 "2345" is example pid number for process you see in step 1
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//brief: function for child process
void background_process(int order_nro)
{
  printf("Hello, I'm working behind the scenes!\n");
  int awakenings = 1;
  while(1)//be here like forever
  {
    sleep(order_nro);//sleep given seconds
    printf("I %d am still here.. awake %d times\n",order_nro,awakenings);
    awakenings++;
    if(awakenings >= 100)
    {
      exit(0);
    }
  }
  exit(0);
}

//brief: main function, "the mother"
int main()
{
  printf("Setting up background process..\n");
  pid_t pidtemp = fork();
  if(pidtemp == 0)//child
  {
    background_process(1);
  }
  if(fork() == 0)//child 2
  {
    background_process(2);
  }
  return 0;
}
