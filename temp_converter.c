#include <stdio.h>

int main() {
    char choice;
    double temp, converted;

    printf("Choose Conversion Type ('C' for Celsius to Fahrenheit, 'F' for Fahrenheit to Celsius): ");
    scanf(" %c", &choice);

    if (choice == 'C' || choice == 'c') {
        printf("Enter temperature in Celsius: ");
        scanf("%lf", &temp);
        converted = (temp * 9.0 / 5.0) + 32;
        printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", temp, converted);
    } else if (choice == 'F' || choice == 'f') {
        printf("Enter temperature in Fahrenheit: ");
        scanf("%lf", &temp);
        converted = (temp - 32) * 5.0 / 9.0;
        printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", temp, converted);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
