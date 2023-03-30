#include <stdio.h>
#include <cs50.h>

// Typedef
typedef struct
{
    string name;
    int votes;
}
candidate;

// Function declaration
candidate get_candidate(string prompt);

int main(void)
{
    candidate candidates_array[3];
    for (int i = 0; i < 3; i++)
    {
        candidates_array[i] = get_candidate("Enter a candidate: ");
        printf("%s\n", candidates_array[i].name);
        printf("%i\n", candidates_array[i].votes);
    }
}

candidate get_candidate(string prompt)
{
    printf("%s\n", prompt);

    candidate c;
    c.name = get_string("Enter a name: ");
    c.votes = get_int("Enter a number of votes: ");

    return c;
}