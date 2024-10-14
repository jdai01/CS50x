#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// argc: Argument count
// argv: Argument vector

int main(int argc, char *argv[])
{
    // Check if there is exactly one command-line argument
    if (argc != 2)
    {
        printf("Error: Please provide exactly one argument.\n");
        return 1; // Exit with error
    }

    // Check if the one command-line argument is a digit
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1; // Exit with error
        }
    }

    // Get input
    string plaintext = get_string("plaintext: ");

    // Get key
    int key = atoi(argv[1]); // converts argv[1] to an integer

    // Encrypt text
    string ciphertext = malloc(strlen(plaintext) + 1); // +1 for null terminator;
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            // Wrap around for uppercase letters (A-Z)
            ciphertext[i] = ((plaintext[i] - 'A' + key) % 26) + 'A';
        }
        else if (islower(plaintext[i]))
        {
            // Wrap around for lowercase letters (a-z)
            ciphertext[i] = ((plaintext[i] - 'a' + key) % 26) + 'a';
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[strlen(plaintext)] = '\0'; // Add the null terminator

    // Make output
    printf("ciphertext: %s\n", ciphertext);
    free(ciphertext); // Free allocated memory
    return 0;         // Exit program
}
