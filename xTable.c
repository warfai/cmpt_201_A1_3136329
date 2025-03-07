/*------------------------------------------
 Student’s Name: Idris Warfa
 Assignment #1 - xTable Program
 Lab Section: X02L
 Lab Instructor’s Name: Salwa Abougamila
--------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ---------------------------------------------
// Function: calculateExpression
// Description: Calculates the expression (x^4 / y^4) + sqrt(y)
// Parameters: x, y - integer values
// Returns: Result of the calculation as a double
// ---------------------------------------------
double calculateExpression(int x, int y) {
    return pow(x, 4) / pow(y, 4) + sqrt(y);
}

// ---------------------------------------------
// Function: printHeader
// Description: Prints the header row for the xTable.
// ---------------------------------------------
void printHeader() {
    printf("+        ");
    for (int x = 5; x <= 100; x += 5) printf("%12d", x);
    printf("\\n");
}

// ---------------------------------------------
// Function: printRow
// Description: Prints a row of the xTable for a specific y value.
// Parameters: y - integer value for the row
// ---------------------------------------------
void printRow(int y) {
    printf("%3d  ", y);
    for (int x = 5; x <= 100; x += 5) {
        double result = calculateExpression(x, y);
        printf("%12.4f", result);
    }
    printf("\\n");
}

// ---------------------------------------------
// Function: xTable
// Description: Generates and prints the xTable with calculations.
// Notes: Covers values 5 to 100 in increments of 5 for both x and y.
// ---------------------------------------------
void xTable() {
    printf("\\n[INFO] Running xTable...\\n");
    printHeader();
    for (int y = 5; y <= 100; y += 5) printRow(y);
    printf("[INFO] xTable function execution complete.\\n");
}

// ---------------------------------------------
// Main Function
// Description: Entry point for the xTable program.
// ---------------------------------------------
int main() {
    printf("[INFO] Generating xTable for values 5 to 100 in increments of 5...\\n");
    xTable();
    printf("[INFO] xTable generation complete.\\n");
    return 0;
}
