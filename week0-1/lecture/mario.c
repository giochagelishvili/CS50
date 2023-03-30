#include <cs50.h>
#include <stdio.h>

int get_size(void);
void print_grid(int size);

int main(void)
{
    // get size of the grid
    int n = get_size();

    // print the grid of the size given above
    print_grid(n);
}



// functions

int get_size(void)
{
    int n;
    do {
        n = get_int("Size: ");
    }
    while(n < 1);
    return n;
}

void print_grid(int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}