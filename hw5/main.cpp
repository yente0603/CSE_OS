#include <signal.h>
#include "lib/write.h"
#include "lib/read.h"
// char context[4096];
// void sig()
// {
//     sleep(1);
//     printf("\nTerminate...\n");
//     exit(EXIT_FAILURE);
// }
void output(int _signal);
int main()
{
    // signal(SIGINT, sig);
    pid_t pid = fork();
    int fd = open("file.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);
    /*
    O_TRUNC: If the file already exists and is a regular file and the access
             mode allows writing it will be truncated to length 0. If the
             file is a FIFO or terminal device file, the O_TRUNC flag is ignored.
             Otherwise, the effect of O_TRUNC is unspecified.
    0777:the protection mode in octal.
    */

    while (1)
    {
        if (pid) /*parent mode*/
        {
            test_write("file.txt", context);
            int status;
            waitpid(pid, &status, 0);
        }
        else if (pid == 0) /*child mode*/
        {
            // test_read("file.txt", context);
            // // printf("read: %s\n", context);

            char buf[sysconf(_SC_PAGESIZE)];
            test_read("file.txt", buf);
            printf("READ: %s", buf);
        }
        else
        {
            perror("fork error.\n");
            exit(EXIT_FAILURE);
        }
    }
    return 0;
}
