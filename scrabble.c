
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int points[] = {
        1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,
        1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10
    };

    char word1[100];
    char word2[100];
    int score1 = 0;
    int score2 = 0;

    printf("Player 1: ");
    scanf("%99s", word1);

    printf("Player 2: ");
    scanf("%99s", word2);

    for (int i = 0; word1[i] != '\0'; i++)
    {
        if (isalpha(word1[i]))
        {
            score1 += points[toupper(word1[i]) - 'A'];
        }
    }

    for (int i = 0; word2[i] != '\0'; i++)
    {
        if (isalpha(word2[i]))
        {
            score2 += points[toupper(word2[i]) - 'A'];
        }
    }

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}
