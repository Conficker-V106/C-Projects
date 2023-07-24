#include <stdio.h>

int main() {
    double balance = 0;
    int option;
    double amount;

    while (1) {
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Balance: %.2lf\n", balance);
                break;
            case 2:
                printf("Enter the amount to deposit: ");
                scanf("%lf", &amount);
                balance += amount;
                printf("Deposited %.2lf\n", amount);
                break;
            case 3:
                printf("Enter the amount to withdraw: ");
                scanf("%lf", &amount);
                if (amount <= balance) {
                    balance -= amount;
                    printf("Withdrawn %.2lf\n", amount);
                } else {
                    printf("Insufficient balance.\n");
                }
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option. Try again.\n");
        }
    }
}
