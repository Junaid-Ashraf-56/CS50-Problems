#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string paragraph);
int count_words(string paragraph);
int count_sentences(string paragraph);

int main(void)
{
    string paragraph = get_string("Enter paragraph: ");

    int letters = count_letters(paragraph);
    int words = count_words(paragraph);
    int sentences = count_sentences(paragraph);

    double L = (letters / (double) words) * 100;
    double S = (sentences / (double) words) * 100;

    double index = (0.0588 * L) - (0.296 * S) - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", (int) round(index));
    }
}

int count_letters(string paragraph)
{
    int count = 0;
    for (int i = 0, len = strlen(paragraph); i < len; i++)
    {
        if (isalpha(paragraph[i]))
        {
            count++;
        }
    }
    return count;
}

int count_words(string paragraph)
{
    int count = 0;
    for (int i = 0, len = strlen(paragraph); i < len; i++)
    {
        if (isspace(paragraph[i]) || (i == len - 1 && paragraph[i] != ' '))
        {
            count++;
        }
    }
    return count;
}

int count_sentences(string paragraph)
{
    int count = 0;
    for (int i = 0, len = strlen(paragraph); i < len; i++)
    {
        if (paragraph[i] == '.' || paragraph[i] == '?' || paragraph[i] == '!')
        {
            count++;
        }
    }
    return count;
}
