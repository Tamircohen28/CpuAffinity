#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "./utils.h"

int exec_child(char *cpu)
{
    char *argv[3];
    argv[0] = (char *)"./child";
    argv[1] = cpu;
    argv[2] = 0;

    printf("Executing child to run on cpu %s\n", cpu);
    int result = execv("./child", argv);
    if (result < 0)
    {
        printf("Failed executing child to run on cpu %s\n", cpu);
        print_errno();
    }
    sleep(100);
    return result;
}

int main()
{
    if (fork() == 0)
    {
        return exec_child((char *)"0");
    }
    return exec_child((char *)"1");
}