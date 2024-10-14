#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// argc: Argument count
// argv: Argument vector

int getUpperIndex(char c);
int getLowerIndex(char c);

int main(int argc, char *argv[])
{
    // Check if there is exactly one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1; // Exit with error
    }

    // Check if the one command-line argument is 26-char long string
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1; // Exit with error
    }

    // Check for invalid characters
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must contain 26 characters.\n");
            return 1; // Exit with error
        }
    }

    // Check for duplicate letters
    int check[26];
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        char c = argv[1][i];
        if (isalpha(c))
        {
            int index = toupper(c) - 'A';
            check[index]++;

            if (check[index] > 1)
            {
                return 1;
            }
        }
    }

    // Get input
    string plaintext = get_string("plaintext: ");

    // Get key
    string key = argv[1];

    // Encrypt text
    string ciphertext = malloc(strlen(plaintext) + 1); // +1 for null terminator;
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            ciphertext[i] = toupper(key[getUpperIndex(plaintext[i])]);
        }
        else if (islower(plaintext[i]))
        {
            ciphertext[i] = tolower(key[getLowerIndex(plaintext[i])]);
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

int getUpperIndex(char c)
{
    return c - 'A';
}

int getLowerIndex(char c)
{
    return c - 'a';
}
