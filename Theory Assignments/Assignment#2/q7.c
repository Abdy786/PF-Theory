#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void fill(char arr[6][5]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            arr[i][j] = 'A' + (rand() % 26);
        }
    }
    arr[5][0] = '0';
    arr[5][1] = '5';
    arr[5][2] = '6';
    arr[5][3] = '0';
}

void disparr(char arr[6][5]) {
    printf("\nGenerated Character Grid:\n");
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

int search(char arr[6][5], const char *str) {
    int len = strlen(str);
    
    // Search horizontally (left to right)
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j <= 5 - len; j++) {
            if (strncmp(&arr[i][j], str, len) == 0) {
                return 1;
            }
        }
    }

    // Search vertically (top to bottom)
    for (int j = 0; j < 6; j++) {
        for (int i = 0; i <= 5 - len; i++) {
            int found = 1;
            for (int k = 0; k < len; k++) {
                if (arr[i + k][j] != str[k]) {
                    found = 0;
                    break;
                }
            }
            if (found) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    char characters[6][5];
    char input[100];
    int score = 0;

    srand(time(NULL)); // Initialize random number generator

    while (1) {
        fill(characters);
        disparr(characters);

        while (1) {
            printf("Type a string to find (or 'END' to refresh the grid): ");
            scanf("%s", input);

            if (strcmp(input, "END") == 0) {
                break; // Exit inner loop to repopulate the array
            }

            if (search(characters, input)) {
                score++;
                printf("'%s' is located! Current Score: %d\n", input, score);
            } else {
                score--;
                printf("'%s' is absent. Current Score: %d\n", input, score);
            }
        }
    }

    return 0;
}
