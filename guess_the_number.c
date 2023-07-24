#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secretNumber, guess, attempts = 0;
    srand(time(0));
    secretNumber = rand() % 100 + 1;

    printf("Guess the secret number (between 1 and 100)\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess > secretNumber) {
            printf("Too high! Try again.\n");
        } else if (guess < secretNumber) {
            printf("Too low! Try again.\n");
        } else {
            printf("Congratulations! You guessed the secret number %d in %d attempts.\n", secretNumber, attempts);
            break;
        }
    } while (1);

    return 0;
}
