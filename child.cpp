#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstdlib>
#include <sched.h>
#include <stdio.h>
#include "./utils.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
    u_int8_t cpu = 0;
    if (argc <= 1)
    {
        printf("Error** Missing cpu! %d\n", argc);
        return -1;
    }

    cpu = (u_int8_t)atoi(argv[1]);
    int current_cpu = sched_getcpu();
    printf("Currently using cpu %d, Requested cpu is %u\n", current_cpu, cpu);

    cpu_set_t mask;
    CPU_ZERO(&mask);
    CPU_SET(cpu, &mask);
    if (sched_setaffinity(0, sizeof(mask), &mask) < 0)
    {
        printf("sched_setaffinity Failed\n");
        print_errno();
        return -1;
    }

    printf("sched_setaffinity() success!\n");
    current_cpu = sched_getcpu();
    printf("now using cpu %d\n", current_cpu);

    int counter = 0;
    while (counter < 100)
    {
        printf("[%d]: Hello from cpu %d\n", counter, current_cpu);
        counter++;
        sleep(10);
    }

    return 0;
}