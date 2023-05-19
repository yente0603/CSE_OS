#include "lib/read.h"
#include "lib/write.h"
int main()
{
    pid_t pid = fork();
    if (pid > 0) /*parent mode*/
    {
        size_t _len = 0;
        printf("WRITE: \n");
        while (~scanf("%[^\n]s", context) && getchar())
        {
            size_t len = strlen(context);
            context[len++] = '\n';
            _len += len;
            break;
        }
        test_write("test.txt", context);
        int status;
        waitpid(pid, &status, 0);
    }
    else if (pid == 0) /*child mode*/
    {
        char buf[sysconf(_SC_PAGESIZE)];
        test_read("test.txt", buf);
        // printf("READ: %s\n", buf);
    }
    else
    {
        perror("fork error.\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}