#include <stdio.h>
// #include <fcntl.h>    // open
// #include <unistd.h>   // read, write, close
// #include <sys/stat.h> // file permission

/*
int open_db(const char *filename)
{
    int fd = open(filename, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    return fd;
}
*/

int main(void)
{
        FILE *my_file;
        my_file = fopen("./build/test.txt", "w");
        fclose(my_file);

        return 0;
}
