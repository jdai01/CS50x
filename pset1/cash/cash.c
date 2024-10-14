#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    // get change form user input
    int change = 0;
    do
    {
        change = get_int("Change owed: ");
    }
    while (change < 0); // Ensure valid integer input and positive value

    // get coin values and no. of coins
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;
    int coins = 0;

    while (change != 0)
    {
        // check if change is larger than each coin (starting from the largest denomination)
        if (change >= quarter)
        {
            change -= quarter;
        }
        else if (change >= dime)
        {
            change -= dime;
        }
        else if (change >= nickel)
        {
            change -= nickel;
        }
        else if (change >= penny)
        {
            change -= penny;
        }

        coins++;
    }

    printf("%i\n", coins);
}
