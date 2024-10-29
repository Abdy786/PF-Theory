#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_HEX_LENGTH 20

// Function prototypes
int BinaryToDecimal(int number);
int DecimalToBinary(int number);
void DecimalToHexadecimal(int number);
void HexadecimalToDecimal(char hexNumber[]);
void BinaryToHexadecimal(int number);
void HexadecimalToBinary(char hexNumber[]);

// Function to show the menu and get user's choice
int displayMenu() {
    int choice;
    
    printf("\nNumber Conversion Options:\n");
    printf("1. Convert Binary to Decimal\n");
    printf("2. Convert Decimal to Binary\n");
    printf("3. Convert Decimal to Hexadecimal\n");
    printf("4. Convert Hexadecimal to Decimal\n");
    printf("5. Convert Binary to Hexadecimal\n");
    printf("6. Convert Hexadecimal to Binary\n");
    printf("7. Exit the Program\n");
    printf("Please select an option: ");
    
    // Loop to ensure valid input
    while (scanf("%d", &choice) != 1) {
        printf("Invalid entry! Kindly enter a number.\n");
        while(getchar() != '\n'); // Clear the input buffer
        printf("Select an option: ");
    }
    
    return choice;
}

int main() {
    int choice, decimalNumber, binaryNumber;
    char hexNumber[MAX_HEX_LENGTH];

    while (1) {
        choice = displayMenu(); // Get user input from the menu

        switch (choice) {
            case 1:
                printf("Input a binary number: ");
                scanf("%d", &binaryNumber);
                printf("Decimal result: %d\n", BinaryToDecimal(binaryNumber));
                break;

            case 2:
                printf("Input a decimal number: ");
                scanf("%d", &decimalNumber);
                printf("Binary result: %d\n", DecimalToBinary(decimalNumber));
                break;

            case 3:
                printf("Input a decimal number: ");
                scanf("%d", &decimalNumber);
                DecimalToHexadecimal(decimalNumber);
                break;

            case 4:
                printf("Input a hexadecimal number: ");
                scanf("%s", hexNumber);
                HexadecimalToDecimal(hexNumber);
                break;

            case 5:
                printf("Input a binary number: ");
                scanf("%d", &binaryNumber);
                BinaryToHexadecimal(binaryNumber);
                break;

            case 6:
                printf("Input a hexadecimal number: ");
                scanf("%s", hexNumber);
                HexadecimalToBinary(hexNumber);
                break;

            case 7:
                printf("Terminating the program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please enter a valid number from the menu.\n");
        }
    }

    return 0;
}

// Function to convert binary to decimal
int BinaryToDecimal(int number) {
    int decimal = 0, base = 1, remainder;
    
    while (number > 0) {
        remainder = number % 10;
        decimal += remainder * base;
        number /= 10;
        base *= 2;
    }
    
    return decimal;
}

// Function to convert decimal to binary
int DecimalToBinary(int number) {
    int binary = 0, base = 1;
    
    while (number > 0) {
        int lastDigit = number % 2;
        binary += lastDigit * base;
        number /= 2;
        base *= 10;
    }
    
    return binary;
}

// Function to convert decimal to hexadecimal
void DecimalToHexadecimal(int number) {
    char hex[20];
    int i = 0;

    if (number == 0) {
        printf("Hexadecimal result: 0\n");
        return;
    }

    while (number != 0) {
        int temp = number % 16;
        
        if (temp < 10)
            hex[i++] = temp + '0';
        else
            hex[i++] = temp - 10 + 'A';
        
        number /= 16;
    }

    // Print hexadecimal in reverse order
    printf("Hexadecimal result: ");
    for (int j = i - 1; j >= 0; j--) {
        putchar(hex[j]);
    }
    putchar('\n');
}

// Function to convert hexadecimal to decimal
void HexadecimalToDecimal(char hexNumber[]) {
    int decimal = (int)strtol(hexNumber, NULL, 16);
    printf("Decimal result: %d\n", decimal);
}

// Function to convert binary to hexadecimal
void BinaryToHexadecimal(int number) {
    int decimal = BinaryToDecimal(number);
    DecimalToHexadecimal(decimal);
}

// Function to convert hexadecimal to binary
void HexadecimalToBinary(char hexNumber[]) {
    int decimal = (int)strtol(hexNumber, NULL, 16);
    
    if (decimal == 0) {
        printf("Binary result: 0\n");
        return;
    }

    char binary[100];
    int index = 0;

    while (decimal > 0) {
        binary[index++] = (decimal % 2) + '0';
        decimal /= 2;
    }

    // Print binary in reverse order
    printf("Binary result: ");
    for (int j = index - 1; j >= 0; j--) {
        putchar(binary[j]);
    }
    putchar('\n');
}
