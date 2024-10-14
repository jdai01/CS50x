#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Declare variables
    int n = 0;

    // Get input from the user
    while (n < 1 || n > 8)
    {
        n = get_int("Height: ");
    }

    // To create pyrimaid
    // For each row
    for (int i = 1; i < n + 1; i++)
    {
        int space = (n - i);
        int hash = i;

        // Forward pyrimaid (space)
        for (int j = space; j != 0; j--)
        {
            printf(" ");
        }
        // Forward pyrimaid (hash)
        for (int j = hash; j != 0; j--)
        {
            printf("#");
        }
        // Middle
        printf("  ");
        // Backward pyrimaid (hash)
        for (int j = hash; j != 0; j--)
        {
            printf("#");
        }
        // Go to new line
        printf("\n");
    }
}
