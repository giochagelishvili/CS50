#include <cs50.h>
#include <stdio.h>

int start;
int end;
int years;
int get_start_size(void);
int get_end_size(void);
int calculate_years(void);

int main(void)
{
    // TODO: Prompt for start size

    start = get_start_size();

    // TODO: Prompt for end size

    end = get_end_size();

    // TODO: Calculate number of years until we reach threshold

    years = calculate_years();

    // TODO: Print number of years

    printf("Years: %d \n", years);
}



// gets the start size from the user
// if input is less than 9 user is re-prompted

int get_start_size(void)
{
    int n;
    do
    {
        n = get_int("Start size: ");
    }
    while (n < 9);
    return n;
}

// gets the end size from the user
// if input is less than or equal to start size user is re-prompted

int get_end_size(void)
{
    int n;
    do
    {
        n = get_int("End size: ");
    }
    while (n < start);
    return n;
}

// calculates how many years do llamas need
// to reach a certain amount of population
// if /3 llamas are born and /4 llamas are passed away every year

int calculate_years(void)
{
    int n = 0;
    if (start == end)
    {
        return n;
    }
    else
    {
        do
        {
            int new_llamas = start / 3;
            int passed_away_llamas = start / 4;
            start = start + new_llamas - passed_away_llamas;
            n++;
        }
        while (start < end);
        return n;
    }
}