#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int length;
    // Get the length from the user
    do
    {
        length = get_int("Length: ");
    }
    while (length < 1);

    int twice[length];

    // Declare the first element of the array and print it out
    twice[0] = 1;
    printf("%i\n", twice[0]);

    for (int i = 1; i < length; i++)
    {
        // Make the current element two times the element before it
        twice[i] = 2 * twice[i - 1];
        printf("%i\n", twice[i]);
    }
}