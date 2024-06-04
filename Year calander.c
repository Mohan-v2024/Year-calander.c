#include <stdio.h>

// Function to check if a given year is a leap year
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1; // Leap year
    } else {
        return 0; // Not a leap year
    }
}

// Function to print the calendar for a given month and year
void printCalendar(int month, int year) {
    // Array to store the number of days in each month
    int daysInMonth[] = {31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Array to store the names of the months
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    // Print the month and year
    printf("\n%s %d\n", months[month - 1], year);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    // Calculate the day of the week for the first day of the month
    int startingDay = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
    for (int i = 0; i < month - 1; i++) {
        startingDay += daysInMonth[i];
    }
    startingDay %= 7;

    // Print the spaces for the first week
    for (int i = 0; i < startingDay; i++) {
        printf("    ");
    }

    // Print the days of the month
    for (int day = 1; day <= daysInMonth[month - 1]; day++) {
        printf("%3d ", day);
        startingDay++;
        if (startingDay % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    int year, month;
    
    // Input year and month
    printf("Enter year: ");
    scanf("%d", &year);
    printf("Enter month (1-12): ");
    scanf("%d", &month);
    
    // Print the calendar
    printCalendar(month, year);
    
    return 0;
}
