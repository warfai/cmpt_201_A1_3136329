/*------------------------------------------
 Student’s Name: Idris Warfa
 Assignment #1 - countingCovid Program
 Lab Section: X02L
 Lab Instructor’s Name: Salwa Abougamila
--------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ---------------------------------------------
// Function: processLine
// Description: Parses a CSV line and extracts the date.
// Parameters: line - input CSV line, date - output date string
// Returns: 1 if successful, 0 otherwise.
// ---------------------------------------------
int processLine(const char *line, char *date) {
    if (sscanf(line, "%*[^,],%19[^,]", date) == 1) return 1;
    return 0;
}

// ---------------------------------------------
// Function: printCount
// Description: Prints the date and count of COVID cases.
// Parameters: date - the date string, count - number of cases
// ---------------------------------------------
void printCount(const char *date, int count) {
    printf("%s %d\\n", date, count);
}

// ---------------------------------------------
// Function: countingCovid
// Description: Counts the number of COVID-19 cases per date from CSV data.
// Notes: Handles multiple entries per date and outputs aggregated results.
// ---------------------------------------------
void countingCovid(FILE *file) {
    char line[1024], prevDate[20] = "";
    int count = 0;

    printf("\\n[INFO] Running countingCovid...\\n");
    if (fgets(line, sizeof(line), file) == NULL) {
        printf("[ERROR] CSV file is empty or missing header.\\n");
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        char date[20];
        if (processLine(line, date)) {
            if (strcmp(date, prevDate) == 0) count++;
            else {
                if (count > 0) printCount(prevDate, count);
                strcpy(prevDate, date);
                count = 1;
            }
        } else {
            printf("[WARNING] Malformed line skipped: %s", line);
        }
    }
    if (count > 0) printCount(prevDate, count);
    printf("[INFO] countingCovid function execution complete.\\n");
}

// ---------------------------------------------
// Main Function
// Description: Entry point for countingCovid program. Reads from standard input.
// ---------------------------------------------
int main() {
    printf("[INFO] Counting COVID-19 cases per date from standard input...\\n");
    countingCovid(stdin);
    printf("[INFO] Processing complete.\\n");
    return 0;
}
