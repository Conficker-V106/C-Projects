#include <stdio.h>
#include <string.h>

#define MAX_TASKS 10
#define MAX_TASK_LENGTH 50

int main() {
    char tasks[MAX_TASKS][MAX_TASK_LENGTH];
    int numTasks = 0;

    printf("To-Do List:\n");

    while (1) {
        printf("Enter a task (or 'q' to quit): ");
        char input[MAX_TASK_LENGTH];
        scanf("%s", input);

        if (strcmp(input, "q") == 0) {
            break;
        }

        if (numTasks < MAX_TASKS) {
            strcpy(tasks[numTasks], input);
            numTasks++;
        } else {
            printf("To-Do list is full!\n");
            break;
        }
    }

    printf("Your To-Do List:\n");
    for (int i = 0; i < numTasks; i++) {
        printf("%d. %s\n", i + 1, tasks[i]);
    }

    return 0;
}
