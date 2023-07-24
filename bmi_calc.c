#include <stdio.h>

int main() {
    double weight, height;
    printf("Enter your weight in kilograms: ");
    scanf("%lf", &weight);

    printf("Enter your height in meters: ");
    scanf("%lf", &height);

    double bmi = weight / (height * height);
    printf("Your BMI is: %.2lf\n", bmi);

    if (bmi < 18.5) {
        printf("You are underweight.\n");
    } else if (bmi >= 18.5 && bmi < 25) {
        printf("You are normal weight.\n");
    } else if (bmi >= 25 && bmi < 30) {
        printf("You are overweight.\n");
    } else {
        printf("You are obese.\n");
    }

    return 0;
}
