#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // char* file = "../s9/1312.c";
    char* file = "/Users/charlesgoncalves/git/dei/ppp26/src/s9/1312.c";

    // Open the file in read mode
    FILE* f = fopen(file, "r");

    if (!f) {
        printf("Error opening file: %d, %s\n", errno, strerror(errno));
        return 1;
    }

    // Variável para guardar a linha lida
    char buffer[1024];
    int max_length = 0;
    int max_line_number = 0;
    int line_number = 0;
    // Variável para guardar a maior linha
    char longest_line[1024] = "";

    // Read the file line by line
    while (fgets(buffer, sizeof(buffer), f)) {
        line_number++;
        int len = strlen(buffer);

        // Remove newline if present for accurate length
        if (buffer[len - 1] == '\n') {
            len--;
        }

        // Update if this line is longer than previous maximum
        if (len > max_length) {
            max_length = len;
            max_line_number = line_number;
            strcpy(longest_line, buffer);
        }
    }

    fclose(f);

    printf("Longest line is line %d with %d characters:\n%s\n",
           max_line_number, max_length, longest_line);

    return 0;
}