#include <stdio.h>                                                        // Standard input/output functions
#include <string.h>                                                       // For string manipulation functions

/*
*********************************************************************************************************************************************************************
*
*   Program Name:
*             ASStringSort.c
*
*   Class:
*             24FA-COSC-1420-71700
*
*   Invocations:
*             main()                    - the main function where the program execution begins
*             fopen() and fclose()      - to open and close the file
*             fgets()                   - to read lines from the file
*             feof()                    - to check if the end of the file is reached
*             strcspn()                 - to remove newline characters
*             strcmp()                  - to compare strings for sorting
*             strcpy()                  - to copy strings during swapping
*             printf()                  - to display messages, file contents, and status information
*
*   Variables:
*             input_file   FILE*        - pointer to the file being opened and read
*             RetCode      short int    - variable to store the exit status code
*             index        short int    - index to track the number of lines read
*             index_2      short int    - loop counter for displaying original lines
*             index_3      short int    - loop counter for sorting lines (outer loop)
*             index_4      short int    - loop counter for sorting lines (inner loop)
*             index_5      short int    - loop counter for displaying sorted lines             
*             line         char[50][50] - array to store up to 50 lines of text
*             line_2       char[50]    - temporary array for swapping lines during sorting
*             fname        char*        - string to store the filename to be opened and read from
*
*   Functions called:
*             see variables and invocations; all coming from <stdio.h>, <string.h> libraries
*
*   Written by:
*             Angel S.
*
*   Date:
*             11/08/2024
*
*   Modifications:
*             Added clarification for sorting and EOF handling
*
*   Notes:
*             This program reads lines from a file, prints them in their original order, sorts them alphabetically,
*             and then prints the sorted order.
*
*********************************************************************************************************************************************************************
*/

// Main function - where the program execution begins
int main(void)
{
    FILE* input_file;                                                     // File pointer for input file
    short int RetCode = 0;                                                // Return code for program status
    short int index = 0, index_2, index_3, index_4, index_5 = 0;          // Index(s) for line array(s)
    char line[50][50];                                                    // Array to store up to 50 lines of text
    char line_2[50];                                                      // Temporary array for swapping lines during sorting
    char* fname = "WordsToSort.txt";                                      // Need to rename file name for reference

    // I want to open the file to validate it exist
    input_file = fopen(fname, "r");                                       // Open file for reading
    if (input_file == NULL)                                               // Checking if file does not exist
    {
        printf("file not found\n");                                       // Print error message if file can't be opened
        RetCode = 2;                                                      // Need to print specific error # (2) to know problem
        goto EOP;                                                         // Guide the program to the exit point on line 118
    }

    // Read lines from the file (up to 50 lines)
    while (index < 50 && fgets(line[index], 50, input_file))              // Loop until 50 lines are read or EOF is reached
    {
        line[index][strcspn(line[index], "\n")] = 0;                      // Remove the new line character at the end of each line
        index++;                                                          // Increment index to read the next line
    }

    // Print lines in original order
    printf("Original order:\n");                                          // I need to emphasize the original order
    for (index_2 = 0; index_2 < index; index_2++)                         // Loop through all lines read
    {
        printf("%s\n", line[index_2]);                                    // Printing each line in original order
    }

    // Sort lines alphabetically using bubble sort
    for (index_3 = 0; index_3 < index - 1; index_3++)                     // Outer loop for sorting lines
    {
        for (index_4 = index_3 + 1; index_4 < index; index_4++)           // Inner loop for sorting lines
        {
            if (strcmp(line[index_3], line[index_4]) > 0)                 // I need to compare lines alphabetically
            {
                strcpy(line_2, line[index_3]);                            // Temporary variable to swap lines
                strcpy(line[index_3], line[index_4]);                     // Swap lines if out of order
                strcpy(line[index_4], line_2);                            // Place the swapped line in correct position
            }
        }
    }

    // Print sorted lines
    printf("\nSorted order:\n");                                          // I need to emphasize what order this is
    for (index_5 = 0; index_5 < index; index_5++)                         // Loop through all lines
    {
        printf("%s\n", line[index_5]);                                    // Print each sorted line
    }

    // I need to close the file
    fclose(input_file);

EOP:
    return RetCode;                                                       // Return the final status code (0 for success, 2 for error)
}

