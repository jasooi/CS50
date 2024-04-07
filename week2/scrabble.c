#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int points[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int wordscore(string word);
void capitaliseinput(string playerword);

int main(void)
{
    string p1 = get_string("Player 1, word please: ");
    string p2 = get_string("Player 2, word please: ");
    capitaliseinput(p1);
    capitaliseinput(p2);
    int p1score = wordscore(p1);
    int p2score = wordscore(p2);

    if (p1score > p2score)
        printf("Player 1 wins!\n");
    else if (p2score > p1score)
        printf("Player 2 wins!\n");
    else
        printf("Tie!\n");

    return 0;
}

int wordscore(string word)
{
    int score = 0;
    int offset = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (word[i] >= 'A' && word[i] <= 'Z')
        {
            offset = word[i] - 65;
            score += points[offset];
        }
    }
    return score;
}

void capitaliseinput(string playerword)
{
    for (int i = 0; playerword[i] != '\0'; i++)
    {
        if (isalnum(playerword[i]))
            playerword[i] = toupper(playerword[i]);
    }
}
