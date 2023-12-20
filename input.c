#include "header.h"

void getName(char *name, int *length) {
    do {
        printf(" Enter the name [up to 19 characters]: ");
        fgets(name, 20, stdin);
        name[strcspn(name, "\n")] = '\0';

        *length = strlen(name);

        if (*length == 0 || (*length == 1 && isspace(name[0]))) {
            printf(" Please enter a name.\n");
        } else if (*length > 18) {
            clearInputBuffer();
            printf(" Name is too long. Please enter a name with up to 18 characters.\n");
        } else {
            break;
        }
    } while (1);
}

int inputBoardSize(const char *prompt, int minValue, int maxValue) {
    int value;
    int validInput = 0;

    while (!validInput) {
        printf("%s", prompt);

        if (scanf("%d", &value) != 1) {
            printf("Enter a valid integer between %d and %d!\n", minValue, maxValue);
            clearInputBuffer();
        } else if (value >= minValue && value <= maxValue) {
            validInput = 1;
        } else {
            printf("Enter a valid integer between %d and %d!\n", minValue, maxValue);
        }
    }
    return value;
}

char scanValue(const char *prompt, char minValue, int maxValue) {
    char value;
    int validInput = 0;
    maxValue+=96;

    while (!validInput) {
        printf("%s", prompt);

        if (scanf("%c", &value) != 1) {
            printf("Enter a alphabet !\n");
        }
        else if (value >= minValue && value <= maxValue) {
            validInput = 1;        
        } else {
            printf("Enter a valid alphabet among %c and %c!\n", minValue, maxValue);
            clearInputBuffer();
        }
    }
    return value;
}

void generateRing(char digit, char output[50]) {
    if (digit >= '1' && digit <= '9') {
        int numSpaces = (digit - '0'), digSpaces = (105 - 2 * digit);
        int index = 0;

        for (int i = digSpaces - 1; i >= 0 && numSpaces < 5; i--) {
            output[index++] = '-';
        }

        for (int i = 0; i < numSpaces * 2; i++) {
            output[index++] = '|';
        }

        output[index++] = digit;

        for (int i = 0; i < numSpaces * 2; i++) {
            output[index++] = '|';
        }

        for (int i = digSpaces - 1; i >= 0 && numSpaces < 5; i--) {
            output[index++] = '-';
        }

        output[index] = '\0';
    }
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
