#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <locale.h>

// Function to generate a random code
void generateCode(char *str, int length) {
    for (int i = 0; i < length; i++) {
        str[i] = '0' + (rand() % 10);
    }
    str[length] = '\0';
}

// Function to find a random unused index
int findRandomUnusedIndex(int *usedIndex, int length) {
    int index;
    do {
        index = rand() % length;
    } while (usedIndex[index]);
    usedIndex[index] = 1;
    return index;
}

// Function to check if the input consists only of digits
int isOnlyDigits(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0; // Return 0 if any character is not a digit
        }
    }
    return 1; // Return 1 if all characters are digits
}

// Function to process a round
void processRound(char *h, char *v, char *userAttempt, char *code) {
    for (int i = 0; i < 5; i++) {
        v[i] = userAttempt[i];
    }

    int usedCode[5] = {0};
    int usedAttempt[5] = {0};
    int usedIndex[5] = {0};

    for (int i = 0; i < 5; i++) {
        if (userAttempt[i] == code[i]) {
            int randomIndex = findRandomUnusedIndex(usedIndex, 5);
            h[randomIndex] = 'X';
            usedCode[i] = 1;
            usedAttempt[i] = 1;
        }
    }

    for (int i = 0; i < 5; i++) {
        if (!usedAttempt[i]) {
            for (int j = 0; j < 5; j++) {
                if (!usedCode[j] && userAttempt[i] == code[j]) {
                    int randomIndex = findRandomUnusedIndex(usedIndex, 5);
                    h[randomIndex] = 'o';
                    usedCode[j] = 1;
                    break;
                }
            }
        }
    }
}

void mastermind() {
    char code[6];
    generateCode(code, 5);
    char userAttempt[6];
    int round = 0;

    char v1[6] = "-----";
    char v2[6] = "-----";
    char v3[6] = "-----";
    char v4[6] = "-----";
    char v5[6] = "-----";
    char v6[6] = "-----";
    char v7[6] = "-----";
    char v8[6] = "-----";
    char v9[6] = "-----";
    char v10[6] = "-----";
    char v11[6] = "-----";
    char v12[6] = "-----";
    char h1[6] = "-----";
    char h2[6] = "-----";
    char h3[6] = "-----";
    char h4[6] = "-----";
    char h5[6] = "-----";
    char h6[6] = "-----";
    char h7[6] = "-----";
    char h8[6] = "-----";
    char h9[6] = "-----";
    char h10[6] = "-----";
    char h11[6] = "-----";
    char h12[6] = "-----";

    // Null-termination of strings
    v1[strlen(v1)] = '\0';
    v2[strlen(v2)] = '\0';
    v3[strlen(v3)] = '\0';
    v4[strlen(v4)] = '\0';
    v5[strlen(v5)] = '\0';
    v6[strlen(v6)] = '\0';
    v7[strlen(v7)] = '\0';
    v8[strlen(v8)] = '\0';
    v9[strlen(v9)] = '\0';
    v10[strlen(v10)] = '\0';
    v11[strlen(v11)] = '\0';
    v12[strlen(v12)] = '\0';
    h1[strlen(h1)] = '\0';
    h2[strlen(h2)] = '\0';
    h3[strlen(h3)] = '\0';
    h4[strlen(h4)] = '\0';
    h5[strlen(h5)] = '\0';
    h6[strlen(h6)] = '\0';
    h7[strlen(h7)] = '\0';
    h8[strlen(h8)] = '\0';
    h9[strlen(h9)] = '\0';
    h10[strlen(h10)] = '\0';
    h11[strlen(h11)] = '\0';
    h12[strlen(h12)] = '\0';

    // Display the generated code (for debugging)
    // printf("Generated Code: %s\n", code);

    while (strcmp(code, userAttempt) != 0 && round < 12) {
        system("cls");
        printf("  CODE BREAKER V1.1");
        printf("\n   %s    %s", v1, h1);
        printf("\n   %s    %s", v2, h2);
        printf("\n   %s    %s", v3, h3);
        printf("\n   %s    %s", v4, h4);
        printf("\n   %s    %s", v5, h5);
        printf("\n   %s    %s", v6, h6);
        printf("\n   %s    %s", v7, h7);
        printf("\n   %s    %s", v8, h8);
        printf("\n   %s    %s", v9, h9);
        printf("\n   %s    %s", v10, h10);
        printf("\n   %s    %s", v11, h11);
        printf("\n   %s    %s", v12, h12);

        printf("\n\n Enter the code: ");
        scanf("%5s", userAttempt);
        userAttempt[strlen(userAttempt)] = '\0';

        // Check if the input is exactly 5 characters long and consists only of digits
        if (strlen(userAttempt) != 5 || !isOnlyDigits(userAttempt)) {
            printf(" Invalid input!\n"); sleep(2);
            continue; // Prompt the user to enter again
        }

        round++;

        if (round == 1) { processRound(h1, v1, userAttempt, code); }
        if (round == 2) { processRound(h2, v2, userAttempt, code); }
        if (round == 3) { processRound(h3, v3, userAttempt, code); }
        if (round == 4) { processRound(h4, v4, userAttempt, code); }
        if (round == 5) { processRound(h5, v5, userAttempt, code); }
        if (round == 6) { processRound(h6, v6, userAttempt, code); }
        if (round == 7) { processRound(h7, v7, userAttempt, code); }
        if (round == 8) { processRound(h8, v8, userAttempt, code); }
        if (round == 9) { processRound(h9, v9, userAttempt, code); }
        if (round == 10) { processRound(h10, v10, userAttempt, code); }
        if (round == 11) { processRound(h11, v11, userAttempt, code); }
        if (round == 12) { processRound(h12, v12, userAttempt, code); }
    }

    system("cls");
    printf("  CODE BREAKER V1.1");
    printf("\n   %s    %s", v1, h1);
    printf("\n   %s    %s", v2, h2);
    printf("\n   %s    %s", v3, h3);
    printf("\n   %s    %s", v4, h4);
    printf("\n   %s    %s", v5, h5);
    printf("\n   %s    %s", v6, h6);
    printf("\n   %s    %s", v7, h7);
    printf("\n   %s    %s", v8, h8);
    printf("\n   %s    %s", v9, h9);
    printf("\n   %s    %s", v10, h10);
    printf("\n   %s    %s", v11, h11);
    printf("\n   %s    %s", v12, h12);

    if (round == 12 && strcmp(code, userAttempt) != 0) {
        printf("\n\nUnfortunately, you lost! The correct code was: %s\n\n", code);
    }
    if (strcmp(code, userAttempt) == 0) {
        printf("\n\nCongratulations! You've cracked the code!\n\n");
    }
}

int main() {
    setlocale(LC_ALL, "");
    srand(time(0));
    char choice;

    system("cls");
    do {
        mastermind();
        printf("\nWould you like to restart the game? (y/n): ");
        scanf(" %c", &choice);
        choice = tolower(choice); // Ensure the input is lowercase
    } while (choice == 'y');

    return 0;
}
