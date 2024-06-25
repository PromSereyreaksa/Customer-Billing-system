#include <stdio.h>
#include <string.h>
#include <time.h>

void printCurrentTimeToFile(const char* filename) {
    // Get the current time
    time_t currentTime = time(NULL);

    // Format the time using ctime()
    char* timeStr = ctime(&currentTime);

    // Remove the newline character from the end of the string
    timeStr[strlen(timeStr) - 1] = '\0';

    // Open the file for writing
    FILE* ptr = fopen("db.txt", "a");
    if (ptr == NULL) {
        ptr = fopen("db.txt", "w");
    }
    fprintf(ptr, "\n\nInvoice - %s", timeStr);

    // Close the file
    fclose(ptr);
}