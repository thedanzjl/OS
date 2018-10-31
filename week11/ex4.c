#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h> 
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv){

    int srcFile, dstFile;
    char *s, *d;
    size_t filesize;
    srcFile = open("ex1.txt", O_RDONLY);
    filesize = lseek(srcFile, 0, SEEK_END);
    s = mmap(NULL, filesize, PROT_READ, MAP_PRIVATE, srcFile, 0);
    dstFile = open("ex1.memcpy.txt", O_RDWR | O_CREAT, 0666);
    ftruncate(dstFile, filesize);
    d = mmap(NULL, filesize, PROT_READ | PROT_WRITE, MAP_SHARED, dstFile, 0);
    memcpy(d, s, filesize);
    munmap(s, filesize);
    munmap(d, filesize);
    close(srcFile);
    close(dstFile);

    return 0;
}


