#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int coleman_liau_index(float L, float S);
int count_letters(string input);
int count_words(string input);
int count_sentences(string input);

int main(void)
{
    // get text inputs
    string text = get_string("Text: ");

    // calculate Coleman-Liau index
    int letter_cnt = count_letters(text);
    int word_cnt = count_words(text);
    int sentence_cnt = count_sentences(text);
    float L = letter_cnt / ((float) word_cnt / 100);
    float S = sentence_cnt / ((float) word_cnt / 100);
    int index = coleman_liau_index(L, S);

    // output
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int coleman_liau_index(float L, float S)
{
    float index = 0.0588 * L - 0.296 * S - 15.8;
    return round(index);
}

int count_letters(string input)
{
    int letters = 0;

    for (int i = 0; i < strlen(input); i++)
    {
        if (isalpha(input[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string input)
{
    int words = 0;

    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == ' ')
        {
            words++;
        }
    }
    words++; // to add in last word
    return words;
}

int count_sentences(string input)
{
    int sentences = 0;

    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == '.' || input[i] == '?' || input[i] == '!')
        {
            sentences++;
        }
    }
    return sentences;
}
