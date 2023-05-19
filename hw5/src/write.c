#include "../lib/write.h"
void test_write(const char *file)
{
    int fd;
    char *dst;
    fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0777);
    if (fd == -1)
        _error("write error.\n");
    // /*
    // O_TRUNC: If the file already exists and is a regular file and the access
    //          mode allows writing it will be truncated to length 0. If the
    //          file is a FIFO or terminal device file, the O_TRUNC flag is ignored.
    //          Otherwise, the effect of O_TRUNC is unspecified.
    // 0777: the protection mode in octal.
    // */

    size_t len;
    printf("WRITE: \n");
    while (~scanf("%[^\n]s", context) && getchar())
    {
        // len = strlen((char *)context);
        len = strlen(context);
        context[len++] = '\n';
        // printf("%ld\n", len);
        break;
    }

    size_t _len = 0;
    lseek(fd, _len + len, SEEK_SET);
    // lseek(fd, _len + len, SEEK_SET);
    /*
    move fd's position to the offset bytes
    and return the new file position for RW
    */

    if (write(fd, "", 1) != 1)
        _error("write error.\n");
    dst = (char *)mmap(NULL, getpagesize(), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    /*
    void *mmap(void *addr, size_t length, int prot, int flags,int fd, off_t offset);
    mmap() creates a new mapping in the virtual address space of the calling process.
    */
    if (dst == MAP_FAILED)
        _error("mmap error.\n");

    memcpy(dst, context, len); // write into the file
    //_len += len;
    sleep(5);
    munmap(dst, getpagesize()); // close mmap
    close(fd);                  // close fd
    /*
    resource: https://welkinchen.pixnet.net/blog/post/41312211-記憶體映射函數-mmap-的使用方法
              https://man7.org/linux/man-pages/man2/mmap.2.html
    */
}
