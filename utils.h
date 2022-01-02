#include <stdio.h>
#include <string.h>
#include <cerrno>

void print_errno()
{
    char error_buffer[256];
    char *errorMsg = strerror_r(errno, error_buffer, 256);
    printf("Errno: '%s'\n", errorMsg);
}