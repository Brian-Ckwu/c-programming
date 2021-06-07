#include <stdio.h>

int main()
{
    // Create structures
    struct Date {
        int year;
        int month;
        int day;
    };

    struct Time {
        int hour;
        int minute;
        int second;
    };

    struct DateAndTime {
        struct Date date;
        struct Time time;
    };

    struct NewTime {
        // Date
        struct {
            int year;
            int month;
            int day;
        } date;
        // Time
        int hour;
        int minute;
        int second;
    } newtime;

    // Declare variables and arrays
    // Variables
    struct Date today = {2021, 6, 7};
    struct Date yesterday = {.month = 6, .day = 6, .year = 2021};
    const int numDays = 10;
    const int year = 2021, month = 7, day = 1;
    struct Date dates[numDays];
    struct DateAndTime now = {{2021, 6, 7}, {15, 1, 0}};
    struct DateAndTime justnow = {.time = {14, 59, 7}, .date = {2021, 6, 7}};

    // Assign values
    for (int i = 0; i < numDays; i++) {
        dates[i].year = year;
        dates[i].month = month;
        dates[i].day = day + i;
    }
    newtime.date.year = 2021;
    newtime.date.month = 6;
    newtime.date.day = 8;
    newtime.hour = 16;
    newtime.minute = 7;
    newtime.second = 2;

    // Display output
    printf("Today is %d/%d/%d\n", today.year, today.month, today.day);
    printf("Yesterday is %d/%d/%d\n", yesterday.year, yesterday.month, yesterday.day);
    printf("\nThe dates:\n\n");
    for (int i = 0; i < numDays; i++) {
        printf("%d/%d/%d\n", dates[i].year, dates[i].month, dates[i].day);
    }
    printf("\nThe current time is: %d-%02d-%02d %02d:%02d:%02d\n", now.date.year, now.date.month, now.date.day, now.time.hour, now.time.minute, now.time.second);
    printf("The time just now: %02d:%02d:%02d\n", justnow.time.hour, justnow.time.minute, justnow.time.second);
    printf("\nNew time: %d-%02d-%02d %02d:%02d:%02d", newtime.date.year, newtime.date.month, newtime.date.day, newtime.hour, newtime.minute, newtime.second);

    return 0;
}