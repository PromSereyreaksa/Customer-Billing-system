#include "allheaderfiles.h" // this file includes all the other header files so it doesnt look messy
#include "time.h"

// Invoice ID struct
struct info info;

int main() {
    system("CLS"); // Clear the screen
    adminlogo(); // Display the admin logo
    printf("\n");
    printf("Welcome to the Admin Panel\n");
    printf("<<Login to gain access to the database>>\n");
    login(); // Perform login procedure

    adminaccess: // Label for admin access
    home(); // Display the admin home screen

    int choice;
    FILE *ptr;
    printf("Select an option: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        system("CLS"); // Clear the screen
        invoicemake: // Label for invoice making
        ptr = fopen("db.txt", "a"); // Open the file in append mode
        struct info invoice_info;

        // Consume any newline left in the input buffer before capturing customer name
        int c;
        while ((c = fgetc(stdin)) != '\n' && c != EOF);
        customer_name(&invoice_info); // Get the customer name
        writeInventoryToFile(&invoice_info); // Write the invoice information to the file

        fprintf(ptr, "\n"); // Add a new line to separate entries
        fclose(ptr); // Close the file

        int choice1;
        printf("Do you want to add another invoice? (1 for yes, 0 for no): "); // Ask the user if they want to add another invoice
        scanf("%d", &choice1);
        if (choice1 == 1) {
            goto invoicemake; // Go back to the invoice making label
        } else {
            goto adminaccess; // Go back to the admin access label
        }
        break;

    case 2:
        system("CLS"); // Clear the screen
        FILE *file;
        char cAD;

        // Open the file "db.txt" in read mode
        file = fopen("db.txt", "r");

        // Check if the file was opened successfully
        if (file == NULL) {
            printf("Error opening the file.\n");
            return 1;
        }

        // Read and print the contents of the file
        while ((cAD = fgetc(file)) != EOF) {
            printf("%c", cAD);
        }
        int choice2;
        printf("Press 1 to go back or 0 to exit program\n"); // Ask the user if they want to add another invoice
        scanf("%d", &choice2);
        if (choice2 == 1) {
            goto adminaccess; // Go back to the admin access label
        } else {
            return 0; // Exit the program
        }

        // Close the file
        fclose(file);
        break;

    case 3:
        char search_name[50];
        while ((c = fgetc(stdin)) != '\n' && c != EOF); // Clear input buffer
        printf("Enter customer name to search: ");
        fgets(search_name, sizeof(search_name), stdin);
        search_name[strcspn(search_name, "\n")] = '\0'; // Remove newline character
        search_customer_invoice(search_name); // Search for the customer invoice

        int choice3;
        printf("Press 1 to go back or 0 to exit program\n"); // Ask the user if they want to add another invoice
        scanf("%d", &choice3);
        if (choice3 == 1) {
            goto adminaccess; // Go back to the admin access label
        } else {
            return 0; // Exit the program
        }
        break;

    case 4:
        return 0; // Exit the program
        break;

    default:
        printf("Invalid choice. Please choose a valid option.\n");
    }
    return 0;
}