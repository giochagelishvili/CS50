#include <stdio.h>
#include <cs50.h>

int factorial(int number);

int main(void)
{
    int num = get_int("Enter a number: ");
    printf("%i\n", factorial(num));
}

int factorial(int number)
{
    if (number == 1)
        return number;
    else
        return number * factorial(number - 1);
}