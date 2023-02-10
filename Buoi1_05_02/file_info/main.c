#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <cstring>

int main(int argc, char const *argv[])
{
    struct stat sb;
    int fd, num_write;
    const char* content = argv[1];
    int f_len = strlen(content);

    fd = open("test_file_info.txt", O_RDWR | O_CREAT);
    if(fd  == -1)
    {
      printf("Fail nhe!!\n");
    }
    
    num_write = write(fd, content, f_len);
    if(num_write != f_len)
    {
      printf("Error from write: %d\n", num_write);
    }
    
    if (stat(argv[2], &sb) == -1) 
    {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    printf("\nFile Type: ");
    switch (sb.st_mode & S_IFMT) 
    {
        case S_IFBLK:   printf("block device\n");       break;
        case S_IFCHR:   printf("character device\n");   break;
        case S_IFDIR:   printf("directory\n");          break;
        case S_IFIFO:   printf("FIFO/pipe\n");          break;
        case S_IFLNK:   printf("symlink\n");            break;
        case S_IFREG:   printf("regular file\n");       break;
        case S_IFSOCK:  printf("socket\n");             break;
        default:        printf("unknown?\n");
    }
    
    printf("File size:  %lld bytes\n\n",  (long long)sb.st_size);
    printf("Last status change:     %s", ctime(&sb.st_ctim.tv_sec));
    printf("Last file modification: %s\n", ctime(&sb.st_mtim.tv_sec));

    return 0;
}
