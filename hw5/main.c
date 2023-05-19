#include "lib/read.h"
#include "lib/write.h"
int main()
{
    pid_t pid = fork();
    if (pid > 0) /*parent mode*/
    {
        test_write("test.txt");
        waitpid(pid, NULL, 0);
    }
    else if (pid == 0) /*child mode*/
    {
        char buf[sysconf(_SC_PAGESIZE)];
        test_read("test.txt", buf);
        printf("READ: %s\n", buf);
    }
    else
    {
        perror("fork error.\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}