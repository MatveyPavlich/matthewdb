#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
 
int main(void)
{
        char input[MAX_INPUT_SIZE];

        printf("matthewdb >");
        while (fgets(input, sizeof(input), stdin)) {
                // remove trailing newline
                input[strcspn(input, "\n")] = '\0';

                if (strcmp(input, ".exit") == 0) {
                        break;
                } else {
                        printf("ERROR: '%s' is unrecognised command\n", input);
                }

                printf("matthewdb >");
        }

        return 0;
}
