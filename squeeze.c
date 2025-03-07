/*------------------------------------------
 Student’s Name: Idris Warfa
 Assignment #1 - Squeeze Program
 Lab Section: X02L
 Lab Instructor’s Name: Salwa Abougamila
--------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ---------------------------------------------
// Function: compressSequence
// Description: Compresses sequences of repeated characters into character + count.
// Parameters: prev - previously encountered character, count - count of repetitions
// Notes: If count exceeds 9, splits into multiple segments.
// ---------------------------------------------
void compressSequence(char prev, int count) {
    while (count > 9) {
        printf("%c9", prev);
        count -= 9;
    }
    printf("%c%d", prev, count);
}

// ---------------------------------------------
// Function: squeezeLine
// Description: Processes a line of text, compressing repeated character sequences.
// Parameters: line - input string
// ---------------------------------------------
void squeezeLine(const char *line) {
    char prev = '\0';
    int count = 0;
    for (int i = 0; line[i] != '\0'; i++) {
        char curr = line[i];
        if (curr == prev) {
            count++;
            if (count == 9) {
                compressSequence(prev, count);
                count = 0;
            }
        } else {
            if (count > 0) compressSequence(prev, count);
            prev = curr;
            count = 1;
        }
    }
    if (count > 0) compressSequence(prev, count);
    printf("\\n");
}

// ---------------------------------------------
// Function: detailedSqueeze
// Description: Provides detailed breakdown of compression for each sequence.
// Parameters: line - input string
// ---------------------------------------------
void detailedSqueeze(const char *line) {
    printf("\\n[INFO] Running detailed squeeze breakdown...\\n");
    char prev = '\0';
    int count = 0;
    for (int i = 0; line[i] != '\0'; i++) {
        char curr = line[i];
        if (curr == prev) {
            count++;
            printf("Character '%c' repeated %d times.\\n", prev, count);
            if (count == 9) {
                printf("[INFO] Max compression length reached: '%c9'\\n", prev);
                count = 0;
            }
        } else {
            if (count > 0) printf("Compressed segment: '%c%d'\\n", prev, count);
            prev = curr;
            count = 1;
            printf("[INFO] New character sequence started: '%c'\\n", curr);
        }
    }
    if (count > 0) printf("Compressed segment: '%c%d'\\n", prev, count);
    printf("[INFO] Detailed squeeze breakdown complete.\\n");
}

// ---------------------------------------------
// Main Function
// Description: Entry point for the squeeze program with extended menu for testing.
// ---------------------------------------------
int main() {
    char buffer[1024];
    int choice;
    do {
        printf("\\n=== Squeeze Program - Idris Warfa (3136329) ===\\n");
        printf("1. Run Basic Squeeze\\n");
        printf("2. Run Detailed Squeeze Breakdown\\n");
        printf("3. Exit\\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("\\nEnter text for basic squeeze (Ctrl+D to end input):\\n");
                while (fgets(buffer, sizeof(buffer), stdin)) squeezeLine(buffer);
                break;
            case 2:
                printf("\\nEnter text for detailed squeeze (Ctrl+D to end input):\\n");
                while (fgets(buffer, sizeof(buffer), stdin)) detailedSqueeze(buffer);
                break;
            case 3:
                printf("[INFO] Exiting the program. Goodbye!\\n");
                break;
            default:
                printf("[ERROR] Invalid choice. Please try again.\\n");
        }
    } while (choice != 3);

    return 0;
}
