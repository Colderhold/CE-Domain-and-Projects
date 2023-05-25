#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
fork();
printf("Process id: %d\n",getpid());
printf("Group id: %d\n",getgid());
printf("User id: %d\n",getuid());
printf("Effective User id: %d\n",geteuid());
printf("Parent Process id: %d\n",getppid());
printf("Effective Group id: %d\n",getegid());
return 0;
}
