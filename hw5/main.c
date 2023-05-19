#include "lib/write.h"
#include "lib/read.h"
// void sig()
// {
//     sleep(1);
//     printf("\nTerminate...\n");
//     exit(EXIT_FAILURE);
// }
int main()
{
    // signal(SIGINT, sig);
    // int fd = open("file.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);

    pid_t pid = fork();
    if (pid > 0) /*parent mode*/
    {
        test_write("test.txt");
        int status;
        waitpid(pid, &status, 0);
    }
    else if (pid == 0) /*child mode*/
    {
        // test_read("file.txt", context);
        // // printf("read: %s\n", context);

        char buf[sysconf(_SC_PAGESIZE)];
        test_read("test.txt", buf);
        printf("READ: %s", buf);
    }
    else
    {
        perror("fork error.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
