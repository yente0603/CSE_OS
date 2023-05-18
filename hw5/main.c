#include <signal.h>
#include "read.h"
#include "write.h"
char context[4096];
void _signal()
{
    sleep(1);
    printf("\nTerminate...\n");
    exit(EXIT_FAILURE);
}
int main()
{
    signal(SIGINT, _signal);
    int status;
    pid_t pid = fork();
    if (pid > 0) /*parent mode*/
    {
        printf("write: \n");
        while (~scanf("%[^\n]s", &context) && getchar())
        {
            size_t len = strlen(context);
            context[len++] = '\n';
            test_write("file", context);
            // signal(SIGCONT, writeout())
            kill(pid, SIGCONT); //?
        }

        waitpid(pid, &status, 0);
    }
    else if (pid == 0) /*child mode*/
    {
        char buf[sysconf(_SC_PAGESIZE)];
        // Size of a page in bytes. Must not be less than 1.
        test_read("file", buf);
        printf("read: %s\n", buf);
    }
    else
    {
        perror("fork error.\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}
