#include <stdio.h>
#include <cs50.h>

int add_two_ints(int a, int b);

int main(void)
{
    printf("The sum is: %i\n", add_two_ints(5, 10));
}

int add_two_ints(int a, int b)
{
    int sum = a + b;
    return sum;
}