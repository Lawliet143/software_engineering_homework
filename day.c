#include <stdio.h>

const char* getDayOfWeek(int year, int month, int day) {
    // Zeller's Congruence algorithm
    if (month < 3) {
        month += 12;
        year -= 1;
    }
    int K = year % 100;
    int J = year / 100;
    int f = day + 13 * (month + 1) / 5 + K + K / 4 + J / 4 + 5 * J;
    int dayOfWeek = f % 7;

    switch (dayOfWeek) {
        case 0: return "Saturday";
        case 1: return "Sunday";
        case 2: return "Monday";
        case 3: return "Tuesday";
        case 4: return "Wednesday";
        case 5: return "Thursday";
        case 6: return "Friday";
    }
    return "";
}

int main() {
    int year, month, day;
    printf("Enter year: ");
    scanf("%d", &year);
    printf("Enter month: ");
    scanf("%d", &month);
    printf("Enter day: ");
    scanf("%d", &day);

    const char* dayOfWeek = getDayOfWeek(year, month, day);
    printf("The day of the week is: %s\n", dayOfWeek);

    return 0;
}