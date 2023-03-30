// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>

#define NUM_CITIES 10

typedef struct
{
    string city;
    int temp;
}
avg_temp;

avg_temp temps[NUM_CITIES];

void sort_cities(void);

int main(void)
{
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    sort_cities();

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

void sort_cities(void)
{
    // This variables will store swapping values
    avg_temp swap_one;
    avg_temp swap_two;

    // Counter to set the loop breakpoint
    int counter = 1;

    // While breakpoint is not equal to 0 loop will keep sorting cities
    while (counter != 0)
    {
        // Goes through every city one by one
        for (int i = 0; i < NUM_CITIES; i++)
        {
            // Compares the temperature of two adjacent cities
            if (temps[i].temp < temps[i + 1].temp)
            {
                // If ith city's temperature is lower than i+1th city's temperature, they swap places
                swap_one = temps[i];
                swap_two = temps[i + 1];
                temps[i] = swap_two;
                temps[i + 1] = swap_one;
                // Add one to counter
                counter++;
            }
        }
        // Check if counter is equal to one
        // If all of the cities were sorted in the right order, counter will be equal to one
        // If counter is not equal to one, we set it to one
        if (counter != 1)
        {
            counter = 1;
        }
        // If counter is equal to one it means that all cities are sorted
        // We set counter to 0 and while loop breaks
        else if (counter == 1)
        {
            counter = 0;
        }
    }
}
