#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100
#define PATTERN_LENGTH 5

int main() {
    char text[MAX_LENGTH], pattern[PATTERN_LENGTH + 1]; // +1 for null terminator
    int i = 0, j = 0;

    printf("Enter pattern (max 5 characters): ");
    scanf("%5s", pattern); // Limit input to 5 characters

    FILE *file = fopen("input.txt", "r");
    if (!file) { 
        printf("Error opening file!\n"); 
        return 1; 
    }

    fgets(text, MAX_LENGTH, file);
    fclose(file);

    int textLength = strlen(text);
    int patternLength = strlen(pattern);

    for (i = 0; i <= textLength - patternLength; i++) {
        for (j = 0; j < patternLength; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == patternLength) {
            printf("Pattern found at index: %d\n", i);
            return 0;
        }
    }

    printf("Pattern not found.\n");
    return 0;
}
