#include <cs50.h>
#include <stdio.h>

int get_size(void);
void print_pyramid(int size);

int main(void)
{
    //get size of the pyramid
    int height = get_size();

    //print out the pyramid
    print_pyramid(height);
}


// this function prints out the pyramid
// size of the input given
void print_pyramid(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i + j < size - 1)
            {
                printf(" ");
            }
            else if (i + j >= size - 1)
            {
                printf("#");
            }
        }
        printf("\n");
    }
}


// this function asks the user for size of the pyramid
// if size is less than 1 or more than 8 user is re-prompted
int get_size(void)
{
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1 || n > 8);
    return n;
}