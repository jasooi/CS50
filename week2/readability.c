#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

void get_counts(string text, float *letter_count, float *word_count, float *sent_count);

int main(void)
{
    float lc;
    float wc;
    float sc;

    string text = get_string("Type text here: ");

    get_counts(text, &lc, &wc, &sc);
    int index = round(0.0588 * (lc / wc * 100) - 0.296 * (sc / wc * 100) - 15.8);

    if (index >= 16)
        printf("Grade 16+\n");
    else if (index < 1)
        printf("Before Grade 1\n");
    else
        printf("Grade %i\n", index);
}

void get_counts(string text, float *letter_count, float *word_count, float *sent_count)
{
    float lc = 0;
    float wc = 0;
    float sc = 0;
    int start_word = 1;
    int start_sent = 1;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == 32 || (text[i] >= 9 && text[i] <= 13))
            start_word = 1;
        else if (isalpha(text[i]))
        {
            lc += 1;
            if (start_word == 1)
            {
                start_word = 0;
                wc += 1;
            }
            if (start_sent == 1)
            {
                start_sent = 0;
                sc += 1;
            }
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            start_sent = 1;
    }
    *letter_count = lc;
    *word_count = wc;
    *sent_count = sc;
}
