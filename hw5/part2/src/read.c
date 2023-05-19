#include "../lib/read.h"
void test_read(const char *file, char *context)
{
    int fd;
    char *src;
    fd = open(file, O_RDONLY);
    if (fd == -1)
        _error("read error.\n");
    /*
     * a way for checking an empty file
     * struct stat {
     *      dev_t     st_dev;         // ID of device containing file
     *      ino_t     st_ino;         // Inode number
     *      mode_t    st_mode;        // File type and mode
     *      nlink_t   st_nlink;       // Number of hard links
     *      uid_t     st_uid;         // User ID of owner
     *      gid_t     st_gid;         // Group ID of owner
     *      dev_t     st_rdev;        // Device ID (if special file)
     *      off_t     st_size;        // Total size, in bytes
     *      blksize_t st_blksize;     // Block size for filesystem I/O
     *      blkcnt_t  st_blocks;      // Number of 512B blocks allocated
     * } buf;
     *
     * if(buf.st_size==0){ printf("empty file.\n"); }
     */

    src = (char *)mmap(NULL, getpagesize(), PROT_READ, MAP_SHARED, fd, 0);
    close(fd); // Close fd first, Be sure it read from memory immediately.

    if (src == MAP_FAILED)
        _error("mmap error.\n");

    // if(signal(SIGCONT,output)==SIG_ERR){}

    // printf("READ: \n");
    // for (int i = 0; i < getpagesize(); i++)
    //     printf("%s\n", context[i]);

    memcpy(context, src, getpagesize());
    // printf("read: %s\n", buf);
    munmap(src, getpagesize());
}
// void output(int _signal)
// {
//     // memcpy(context, p, getpagesize());
//     printf("read: %s\n", context);
// }