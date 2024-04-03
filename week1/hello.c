#include <cs50.h>
#include <stdio.h>
int main(void)
{
    string name;
    name = get_string("Please type in your name here: ");
    printf("hello, %s\n", name);
}
