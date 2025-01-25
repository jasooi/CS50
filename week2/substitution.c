#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int check_key_validity(string key);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Please enter one and only one key when running program, e.g. %s key\n", argv[0]);
        return 1;
    }
    else if (!check_key_validity(argv[1]))
    {
        printf("Invalid key. Enter a valid key!\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
            plaintext[i] = tolower(argv[1][plaintext[i] - 97]);
        else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
            plaintext[i] = toupper(argv[1][plaintext[i] - 65]);
    }
    printf("ciphertext: %s\n", plaintext);
    return 0;
}

// strlen, toupper are pre-defined in cs50

int check_key_validity(string key)
{
    if (strlen(key) != 26)
        return 0;

    int duplicate_check[26] = {0};

    for (int i = 0; key[i] != '\0'; i++)
    {
        if (!isalpha(key[i]))
            return 0;
        duplicate_check[toupper(key[i]) - 65] += 1;
    }
    for (int j = 0; j < 26; j++)
    {
        if (duplicate_check[j] > 1)
            return 0;
    }
    return 1;
}
