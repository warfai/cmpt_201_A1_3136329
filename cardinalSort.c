/*------------------------------------------
 Student’s Name: Idris Warfa
 Assignment #1 - Milestone 1
 Lab Section: [X02L]
 Lab Instructor’s Name: [Salwa Abougamila]
 
--------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#define ASCII_RANGE 128  // Total ASCII characters

void cardinalSort(const char *line) {
    int count[ASCII_RANGE] = {0};  // Array to store character frequencies

    // Count occurrences of each character
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] >= 32 && line[i] < 127) { // Printable ASCII characters
            count[(int)line[i]]++;
        }
    }

    // Print characters in sorted order
    for (int i = 32; i < 127; i++) {
        while (count[i] > 0) {
            putchar(i);
            count[i]--;
        }
    }
    putchar('\n');  // Newline after sorting a line
}

int main() {
    char buffer[1024];

    // Read input line by line
    while (fgets(buffer, sizeof(buffer), stdin)) {
        cardinalSort(buffer);
    }

    return 0;
}
