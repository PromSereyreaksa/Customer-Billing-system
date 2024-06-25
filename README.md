# Customer Billing System
This is a customer billing system application developed by group 4 for an advanced programming course. The application allows customers to manage their billing accounts, view invoices, and make payments.

## Description
The Customer Billing System is a C-based application that provides the following features:

Customer Account Management: Customers can create and manage their billing accounts, including updating personal information and viewing transaction history.
Invoice Generation: The system can generate invoices for customers based on their usage or service plans.
Payment Processing: Customers can make payments towards their outstanding invoices using the application.
Admin Functionality: The system has an admin module that allows authorized personnel to create and manage admin accounts, view customer accounts, and generate reports.
User Interface: The application has a simple and intuitive command-line interface (CLI) that guides users through the various functionalities.
## Directory Structure
The repository contains the following files and directories:

## main.c: 
The main entry point of the application.
## homepage.h: 
Header file for the main homepage functionality.
## adminlogin.h: 
Header file for the admin login functionality.
## invoiceoperation.h: 
Header file for invoice-related operations.
## makeadminaccount.c: 
Source file for creating and managing admin accounts.
## allheaderfiles.h: 
Includes all the header files in one place.
## db.txt: Text file storing the application's database.
## admin account.txt: 
Text file storing admin account information.
## check_makeadminaccount.txt: 
Text file used for checking the admin account creation process.
## time.h: 
Header file for time-related operations.
## figlet.h: 
Header file for displaying ASCII art.
## main.exe: 
Compiled executable file for the application.

## Installation and Usage
To use the Customer Billing System, follow these steps:

## Clone the repository to your local machine.
Open a terminal or command prompt and navigate to the project directory.
Compile the source code using a C compiler (e.g., gcc):
gcc -o main main.c

Run the compiled executable:
./main
Follow the on-screen instructions to navigate through the application's features.

## Fork the repository.
Create a new branch for your feature or bug fix.
Make your changes and ensure the application is working as expected.
Commit your changes and push the branch to your forked repository.
Submit a pull request to the original repository, describing your changes.
