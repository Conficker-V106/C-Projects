#include <stdio.h>

int main() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    char data[100];
    printf("Enter data to write to the file (max 100 characters): ");
    scanf(" %[^\n]", data);

    fprintf(file, "%s", data);
    fclose(file);

    printf("Data written to the file successfully.\n");
    return 0;
}
