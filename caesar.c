
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int only_digits(const char text[]);
char rotate(char c, int key);

int main(int argc, char *argv[])
{
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);
    key = key % 26;

    char plaintext[256];

    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("ciphertext: ");

    for (int i = 0; plaintext[i] != '\0' && plaintext[i] != '\n'; i++)
    {
        printf("%c", rotate(plaintext[i], key));
    }

    printf("\n");

    return 0;
}

int only_digits(const char text[])
{
    if (text[0] == '\0')
    {
        return 0;
    }

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (!isdigit((unsigned char) text[i]))
        {
            return 0;
        }
    }

    return 1;
}

char rotate(char c, int key)
{
    if (c >= 'A' && c <= 'Z')
    {
        return (c - 'A' + key) % 26 + 'A';
    }

    if (c >= 'a' && c <= 'z')
    {
        return (c - 'a' + key) % 26 + 'a';
    }

    return c;
}
