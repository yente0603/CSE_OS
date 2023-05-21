#include "lib/read.h"
#include "lib/write.h"
char context[4096];
int main()
{

    pid_t pid = fork();
    if (pid > 0) /*parent mode*/
    {
        waitpid(pid, NULL, 0);
        // test_read("foo", context);
        // printf("READ: %s\n", context);

        char buf[sysconf(_SC_PAGESIZE)];
        test_read("foo", buf);
        printf("READ: %s", buf);
    }
    else if (pid == 0) /*child mode*/
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
        test_write("foo", context);
    }
    else
    {
        perror("fork error.\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}