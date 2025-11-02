#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>    // open
#include <unistd.h>   // read, write, close
#include <sys/stat.h> // file permission

#define MAX_INPUT_SIZE 1024


int open_db(const char *filename)
{
    int fd = open(filename, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    return fd;
}


int main(void)
{
        char input[MAX_INPUT_SIZE];

        printf("matthewdb >");
        while (fgets(input, sizeof(input), stdin)) {
                // remove trailing newline
                input[strcspn(input, "\n")] = '\0';

                if (strcmp(input, ".exit") == 0) {
                        break;
                } if (strcmp(input, "db") == 0) {
                        open_db("./build/mk.db");
                        printf("mk.db created\n");
                } else {
                        printf("ERROR: '%s' is unrecognised command\n", input);
                }

                printf("matthewdb >");
        }

        return 0;
}
