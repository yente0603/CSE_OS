#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <ctype.h>
#define buf 1000
#define nullptr ((void *)0)

char path[buf];
char cmd[buf];
char *process1[buf], *process2[buf];
bool ifpipe;

int preprocess(char *cmd) // deal with "cd"
{
    if (cmd == nullptr || cmd[0] == 'c' && cmd[1] == 'd' && cmd[2] == 0)
        return 1;
    char *temp = cmd;
    char newpath[buf];

    if (temp[0] == 'c' && temp[1] == 'd' && temp[2] == ' ')
    {
        int i = 2;
        while (isspace(temp[i]))
            ++i;
        getcwd(newpath, buf);
        int change = strlen(newpath);
        newpath[change] = '/';
        newpath[change + 1] = 0;
        strcat(newpath, temp + i);
        // printf("to dir : %s\n", newpath);
        chdir(newpath);
        return 1;
    }
    return 0;
}
void read_command() // check whether it has two process or not
{
    char *split_cmd[2];
    split_cmd[0] = strtok(cmd, "|");  /*process 1*/
    split_cmd[1] = strtok(NULL, "|"); /*process 2*/
    int len = 0;
    process1[len] = strtok(split_cmd[0], " ");
    while (process1[len] != NULL) // not empty command
    {
        len++;
        process1[len] = strtok(NULL, " ");
    }
    process1[len] = NULL;     // set NULL at the end of the process
    if (split_cmd[1] != NULL) // check whether it has two process or not
    {
        ifpipe = true;
        len = 0;
        process2[len] = strtok(split_cmd[1], " ");
        while (process2[len] != NULL)
        {
            len++;
            process2[len] = strtok(NULL, " ");
        }
        process2[len] = NULL;
    }
    // execvp(process1[0], process1);
    // execvp(process2[0], process2);
}
void create_pipe()
{
    int fd[2];
    if (pipe(fd) == -1)
    {
        perror("create pipe error!\n");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    int status;
    if (pid == -1)
    {
        perror("fork error!\n");
        exit(EXIT_FAILURE);
    }
    else if (pid != 0) /*parent code*/
    {
        close(fd[1]);
        close(0);     // stdout
        dup(fd[0]);   // use the lowest-numbered unused file descriptor, which is 0
                      // set stdout to fd[0]
        close(fd[0]); // close original fd[0], which is dupilcated
        waitpid(pid, &status, WUNTRACED | WCONTINUED);
        if (execvp(process2[0], process2) < 0)
            printf("command error!\n");
        exit(0);
    }
    else /*child code*/
    {
        close(fd[0]);
        close(1);
        dup(fd[1]);   // use the lowest-numbered unused file descriptor, which is 1
                      // set stdout to fd[1]
        close(fd[1]); // close original fd[1], which is dupilcated
        if (execvp(process1[0], process1) < 0)
            printf("command error!\n");
        exit(0);
    }
}
void execute()
{
    int status;
    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork error!\n");
        exit(EXIT_FAILURE);
    }
    else if (pid != 0) /*parent code*/
        waitpid(pid, &status, WUNTRACED | WCONTINUED);
    else /*child code*/
    {
        if (ifpipe == true)
            create_pipe();
        else
        {
            if (execvp(process1[0], process1) < 0)
                printf("command error!\n");
            // execvp(process1[0], process1);
        }
        exit(0);
    }
}
int main()
{
    while (true)
    {
        /*initialize*/
        ifpipe = false;
        fprintf(stdout, "$ ");
        // fprintf(stdout, "B096060041@%s $ ", getcwd(path, buf));
        fgets(cmd, sizeof(cmd), stdin);
        cmd[strlen(cmd) - 1] = '\0'; // change EOF by '\0'

        /*execute*/
        if (preprocess(cmd))
            continue;
        read_command();
        if (strcmp(cmd, "exit") == 0 || strcmp(cmd, "EXIT") == 0)
            // return 0 means that cmd equals to "exit"
            break;
        execute();
    }
    return 0;
}
