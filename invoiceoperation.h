#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifndef invoiceoperation_h
#define invoiceoperation_h

#define MAX_ITEMS 10

// Defines a structure to store invoice information
struct info {
    char customer_name[50];
    char items[MAX_ITEMS][50];
    int quantities[MAX_ITEMS];
    float prices[MAX_ITEMS];
    int num_items;
    float total;
};

// Function to print a white divider line of the specified length
void print_white_divider(int length) {
    // Print a line of length characters with a white background
    for (int i = 0; i < length; i++) {
        printf("\033[47m "); // ANSI escape code for white background
    }
    printf("\033[0m\n"); // Reset ANSI escape codes and move to the next line
}

// Function to generate a random invoice ID
int generate_invoice_id() {
    srand(time(NULL)); // Seed the random number generator with the current time
    return rand() % 100000; // Generate a random number between 0 and 99,999
}

// Function to print the current date and time to a file
void print_current_date_time(FILE *file) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    fprintf(file, "%02d-%02d-%04d %02d:%02d:%02d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

// Function to print the current date and time to the console
void print_current_date_time2() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("%02d-%02d-%04d %02d:%02d:%02d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

// Function to get the customer name and write it to the struct
void customer_name(struct info *invoice_info) {
    printf("Customer Name: ");
    fgets(invoice_info->customer_name, sizeof(invoice_info->customer_name), stdin);
    // Remove the newline character from the input
    invoice_info->customer_name[strcspn(invoice_info->customer_name, "\n")] = '\0';
}

// Function to get the inventory details and write them to the struct
void writeInventoryToFile(struct info *invoice_info) {
    invoice_info->total = 0.0; // Reset the total value

    printf("Enter amount of items: ");
    scanf("%d", &invoice_info->num_items);

    // Consume the newline character left in the input buffer
    int c;
    while ((c = fgetc(stdin)) != '\n' && c != EOF);

    // Prompt the user to enter items
    for (int i = 0; i < invoice_info->num_items && i < MAX_ITEMS; i++) {
        printf("Item %d: ", i + 1);
        if (fgets(invoice_info->items[i], 50, stdin) == NULL) {
            break; // exit the loop if fgets returns NULL
        }
        // Remove the newline character from the input
        invoice_info->items[i][strcspn(invoice_info->items[i], "\n")] = '\0';
    }

    // Prompt the user for the quantities and prices of each item
    for (int i = 0; i < invoice_info->num_items; i++) {
        printf("Quantity of %s: ", invoice_info->items[i]);
        if (scanf("%d", &invoice_info->quantities[i]) != 1) {
            printf("Invalid input. Skipping item %d.\n", i + 1);
            invoice_info->quantities[i] = 0;
        }
        printf("Price of %s ($): ", invoice_info->items[i]);
        if (scanf("%f", &invoice_info->prices[i]) != 1) {
            printf("Invalid input. Skipping item %d.\n", i + 1);
            invoice_info->prices[i] = 0.0;
        }
        invoice_info->total += invoice_info->quantities[i] * invoice_info->prices[i]; // update the total value
    }

    // Open the output file for writing in append mode
    FILE *outputFile = fopen("db.txt", "a");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return;
    }

    // Write the header
    print_current_date_time2();
    fprintf(outputFile, "\n============== CADT CAFE ===============\n");
    fprintf(outputFile, "Date: ");
    print_current_date_time(outputFile);
    int invoice_id = generate_invoice_id();
    fprintf(outputFile, "Invoice #: %d\n", invoice_id);
    fprintf(outputFile, "Invoice for: %s\n", invoice_info->customer_name);
    fprintf(outputFile, "=======================================\n");
    fprintf(outputFile, "Items\t\tQty\t\tTotal\n");
    fprintf(outputFile, "=======================================\n");

    // Write the items, quantities, and prices to the output file
    for (int i = 0; i < invoice_info->num_items; i++) {
    fprintf(outputFile, "%s        %d    %.2f\n", invoice_info->items[i], invoice_info->quantities[i], invoice_info->quantities[i] * invoice_info->prices[i]);
    }
    fprintf(outputFile, "\n");
    fprintf(outputFile, "       \t\t\t\t%.2f$\n", invoice_info->total);
    fprintf(outputFile, "=======================================\n");
    fprintf(outputFile, "-----------------------------------------------------------------------------------------------------------------------------------------");
    fclose(outputFile);
    printf("Saved.\n");
}

// Function to search for a customer name and print their invoice details
void search_customer_invoice(char *customer_name) {
    FILE *file = fopen("db.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }

    char line[256];
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, customer_name)) {
            found = 1;
            printf("%s", line);
            while (fgets(line, sizeof(line), file) && !strstr(line, "Invoice #:")) {
                printf("%s", line);
            }
            printf("%s", line); // Print the "Invoice #" line
            break;
        }
    }
    if (!found) {
        printf("Invoice for customer %s not found.\n", customer_name);
    }

    fclose(file);
}
#endif