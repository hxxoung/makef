#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main() {
    char dirname[256];
    printf("Enter the name of the new directory: ");
    scanf("%s", dirname);

    // Create the new directory
    int status = mkdir(dirname, 0777);
    if (status != 0) {
        printf("Failed to create the directory.\n");
        return 1;
    }

    // Create 10 files in the new directory
    for (int i = 1; i <= 10; i++) {
        char filename[256];
        printf("Enter the name of file %d: ", i);
        scanf("%s", filename);

        // Generate the file path
        char filepath[256];
        snprintf(filepath, sizeof(filepath), "%s/%s", dirname, filename);

        // Create the file
        FILE* file = fopen(filepath, "w");
        if (file == NULL) {
            printf("Failed to create file '%s'.\n", filename);
            continue;
        }

        // Close the file
        fclose(file);
    }

    printf("Files created successfully in the directory '%s'.\n", dirname);

    return 0;
}
