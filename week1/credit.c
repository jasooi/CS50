#include <cs50.h>
#include <stdio.h>

int digitsum(int n)
{
    int r = 0;
    while (n > 0)
    {
        r += n % 10;
        n /= 10;
    }
    return r;
}

int main(void)
{
    int start1, start2, checksum, i;
    long n;
    i = 1;
    checksum = 0;
    do
    {
        n = get_long("Enter Credit Card no.: ");
    }
    while (n < 10);

    while (n > 0)
    {
        if (n / 10 == 0)
            start1 = n % 10;
        else if (n / 100 == 0)
            start2 = n % 10;

        if (i % 2 == 0)
            checksum += digitsum(2 * (n % 10));
        else
            checksum += n % 10;
        n /= 10;
        i++;
    }
    i--;
    // printf("%i %i %i\n", checksum , checksum % 10, i);
    if (checksum % 10 == 0 && start1 == 3 && (start2 == 4 || start2 == 7) && i == 15)
        printf("AMEX\n");
    else if (checksum % 10 == 0 && start1 == 5 && start2 >= 1 && start2 <= 5 && i == 16)
        printf("MASTERCARD\n");
    else if (checksum % 10 == 0 && start1 == 4 && (i == 13 || i == 16))
        printf("VISA\n");
    else
        printf("INVALID\n");
}
