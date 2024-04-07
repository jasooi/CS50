#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Enter the height of the pyramid: ");
    }
    while (n < 1 || n > 8);

    for (int j = 1; j <= n; j++)
    {
        for (int i = 1; i <= n + j + 2; i++)
        {
            if (i <= n - j || i == n + 1 || i == n + 2)
                printf(" ");
            else
                printf("#");
        }
        printf("\n");
    }
}
