#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable:4996)
#include <stdio.h>

int findThirdDot(const char* filename, int* lineIndex, int* charIndex) {
    FILE* file = NULL;
    errno_t err = fopen_s(&file, filename, "r");
    if (err != 0 || file == NULL) {
        printf("Failed to open file: %s\n", filename);
        return 0;
    }

    int dotCount = 0;
    int currentLineIndex = 1;
    int currentCharIndex = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            currentLineIndex++;
            currentCharIndex = 0;
        }
        else {
            currentCharIndex++;
        }

        if (ch == '.') {
            dotCount++;
            if (dotCount == 3) {
                *lineIndex = currentLineIndex;
                *charIndex = currentCharIndex;
                fclose(file);
                return 1;
            }
        }
    }

    fclose(file);
    return 0;
}

int main() {
    const char* filename = "t.txt";
    int lineIndex = 0, charIndex = 0;

    if (findThirdDot(filename, &lineIndex, &charIndex)) {
        printf("The third dot was found in file %s:\n", filename);
        printf("Line: %d, Position: %d\n", lineIndex, charIndex);
    }
    else {
        printf("The third dot was not found in file %s.\n", filename);
    }

    return 0;
}
