#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "figlet.h"
#ifndef dashboard_h
#define dashboard_h

// This function is responsible for displaying the main menu of the application
void home() {
    // Clear the console screen
    system("CLS");

    // Print the dashboard header
    printf("========================================================================================\n");
    allthelines(); // This is a function call to draw lines on the screen
    printf("\n");
    printf("\n");

    // Display the menu options
    printf("1.Create an invoice\n");
    printf("2.Show all invoices\n");
    printf("3.Invoice lookup\n");
    printf("4.Exit\n");
    printf("\n\n");

    // Print the dashboard footer
    printf("========================================================================================\n");
}
#endif