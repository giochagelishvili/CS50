#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}


// this function checks if given number is
// prime or not
bool prime(int number)
{
    // if number is 1 function returns false
    // because 1 is not considered as prime number
    if (number == 1)
    {
        return false;
    }

    // this loop divides the given number to every
    // number starting from 2. if remainder is 0, it returns false
    // otherwise it keeps dividing
    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}
