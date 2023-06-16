#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_FILES 100
#define FILE_SIZE_MB 1
#define FILE_SIZE (FILE_SIZE_MB * 1024 * 1024)

void generateRandomText(char* buffer, size_t size) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    size_t charsetSize = sizeof(charset) - 1;
    for (size_t i = 0; i < size; i++) {
        buffer[i] = charset[rand() % charsetSize];
    }
}

int main() {
    // Create the directory to store the files
    system("mkdir files");

    char filename[20];
    char buffer[FILE_SIZE];

    for (int i = 0; i < NUM_FILES; i++) {
        // Generate a unique filename
        snprintf(filename, sizeof(filename), "files/file%d.txt", i + 1);

        // Generate random text
        generateRandomText(buffer, FILE_SIZE);

        // Open the file for writing
        FILE* file = fopen(filename, "w");
        if (file == NULL) {
            printf("Error creating file: %s\n", filename);
            return 1;
        }

        // Write the random text to the file
        size_t bytesWritten = fwrite(buffer, 1, FILE_SIZE, file);
        if (bytesWritten != FILE_SIZE) {
            printf("Error writing to file: %s\n", filename);
            fclose(file);
            return 1;
        }

        fclose(file);
    }

    printf("%d files created successfully.\n", NUM_FILES);

    return 0;
}
