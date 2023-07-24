#include <stdio.h>

int main() {
    int num, sum = 0;
    printf("Enter an integer: ");
    scanf("%d", &num);

    int temp = num;
    while (temp != 0) {
        sum += temp % 10;
        temp /= 10;
    }

    printf("Sum of digits in %d is: %d\n", num, sum);
    return 0;
}
