
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int valid_key(const char key[]);
char substitute(char c, const char key[]);

int main(int argc, char *argv[])
{
    if (argc != 2 || !valid_key(argv[1]))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    char plaintext[256];

    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("ciphertext: ");

    for (int i = 0; plaintext[i] != '\0' && plaintext[i] != '\n'; i++)
    {
        printf("%c", substitute(plaintext[i], argv[1]));
    }

    printf("\n");

    return 0;
}

int valid_key(const char key[])
{
    if (strlen(key) != 26)
    {
        return 0;
    }

    int seen[26] = {0};

    for (int i = 0; key[i] != '\0'; i++)
    {
        if (!isalpha((unsigned char) key[i]))
        {
            return 0;
        }

        int index = toupper((unsigned char) key[i]) - 'A';

        if (seen[index] == 1)
        {
            return 0;
        }

        seen[index] = 1;
    }

    return 1;
}

char substitute(char c, const char key[])
{
    if (c >= 'A' && c <= 'Z')
    {
        return toupper((unsigned char) key[c - 'A']);
    }

    if (c >= 'a' && c <= 'z')
    {
        return tolower((unsigned char) key[c - 'a']);
    }

    return c;
}
