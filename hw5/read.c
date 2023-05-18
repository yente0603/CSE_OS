#include "read.h"
void test_read(const char *file, void *buf)
{
    int fd;
    void *src;
    fd = open(file, O_RDONLY);

    if (fd == -1)
        _error("read error.\n");

    src = mmap(NULL, getpagesize(), PROT_READ, MAP_SHARED, fd, 0);
    close(fd); // Close fd first, Be sure it read from memory immediately.

    if (src == MAP_FAILED)
        _error("mmap error.\n");

    memcpy(buf, src, getpagesize());
    munmap(src, getpagesize());
}
