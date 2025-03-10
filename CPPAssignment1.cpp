/*Q1. Write a menu driven program for Date in a C. 
      Declare a structure Date having data members
      day, month, year. Implement the following functions.
      void printDateOnConsole(struct Date* ptrDate);
      void acceptDateFromConsole(struct Date* ptrDate);*/

#include <stdio.h>

// Define structure Date
struct Date {
    int day;
    int month;
    int year;
};

// Function to accept date from user
void acceptDateFromConsole(struct Date* ptrDate) {
    printf("Enter Day, Month and Year: ");
    scanf("%d %d %d", &ptrDate->day, &ptrDate->month, &ptrDate->year);
}

// Function to print the date
void printDateOnConsole(struct Date* ptrDate) {
    printf("Entered Date: %02d-%02d-%04d\n", ptrDate->day, ptrDate->month, ptrDate->year);
}

int main() {
    struct Date d1;

    // Accept the date
    acceptDateFromConsole(&d1);

    // Print the date
    printDateOnConsole(&d1);

    return 0;
}






