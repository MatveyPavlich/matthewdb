#include <fcntl.h>     // open()
#include <unistd.h>    // write(), close()
#include <sys/stat.h>  // S_IRUSR, S_IWUSR
#include <stdio.h>     // perror()
#include <stdlib.h>    // exit()

int main(void) {
        // Open (or create) the database file
        int my_file = open("./build/mk.db", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
        if (my_file == -1) {
                perror("Db file could not be opened");
                exit(EXIT_FAILURE);
        }

        // Data to write
        const char *data = "Yoo\n";
        ssize_t bytes_written = write(my_file, data, 4);  // 4 = length of "Yoo\n"
        if (bytes_written == -1) {
                perror("Write failed");
                close(my_file);
                exit(EXIT_FAILURE);
        }

        // Always close the file
        close(my_file);
        return 0;
}
