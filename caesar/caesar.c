#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(int key, string plaintext);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");
    encrypt(key, plaintext);

    return 0;
}

void encrypt(int key, string plaintext)
{
    key = key % 26;

    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        char c = plaintext[i];

        if (isupper(c))
        {
            printf("%c", (c - 'A' + key) % 26 + 'A');
        }
        else if (islower(c))
        {
            printf("%c", (c - 'a' + key) % 26 + 'a');
        }
        else
        {
            printf("%c", c);
        }
    }

    printf("\n");
}
