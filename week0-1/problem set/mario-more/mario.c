#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_pyramids(int number);

int main(void)
{
    // get the height of pyramids
    int height = get_height();

    // this function builds pyramid height of given parameter
    print_pyramids(height);
}


// this function prints pyramids height of given number
void print_pyramids(int number)
{
    // this loop prints rows of pyramids
    for (int i = 0; i < number; i++)
    {
        // this loop prints columns of pyramids
        for (int j = 0; j < number + i + 3; j++)
        {
            if (i + j < number - 1 || j == number || j == number + 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}


// this function gets height from the user
// if number is less than 1 or more than 8 user is re-promted
int get_height(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    return n;
}