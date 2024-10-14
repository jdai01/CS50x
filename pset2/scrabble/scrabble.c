#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int score(string);

int main(void)
{
    // Get word from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Get scores from both players
    int score1 = score(word1);
    int score2 = score(word2);

    // print output
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int score(string input)
{
    char alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int scores[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int score = 0;

    for (int i = 0; i < strlen(input); i++) // to iterate through input
    {
        for (int j = 0; j < strlen(alphabet); j++) // to iterale through alphabet
        {
            // if score match, add corresponding score. Note: input is capatilised
            if (toupper(input[i]) == alphabet[j])
            {
                score += scores[j];
            }
        }
    }

    return score;
}
