#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // Goes through every candidate one by one
    for (int i = 0; i < candidate_count; i++)
    {
        // Compares the input with candidate's name
        if (strcmp(name, candidates[i].name) == 0)
        {
            // Adds one to votes if names match
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Stores the largest amount of votes
    int votes = 0;
    // Stores the number of winners
    int winners = 0;
    // Array for the names of winners
    string names[MAX];
    // Goes through every candidate one by one
    for (int i = 0; i < candidate_count; i++)
    {
        // Checks if ith candidates votes are larger than one that is stored in votes variable
        if (candidates[i].votes > votes)
        {
            // Assigns ith candidate's votes to votes variable
            votes = candidates[i].votes;
            // Declares the first winner and assigns their name to names[0]
            names[0] = candidates[i].name;
        }
    }
    // Adds one to winners
    winners++;

    // Goes through every candidate one by one
    for (int j = 0; j < candidate_count; j++)
    {
        // Checks if any other candidate has the same amount of votes as winner
        if ((candidates[j].votes == votes) && (strcmp(candidates[j].name, names[0]) != 0))
        {
            // Adds jth candidate in the winner list
            names[winners] = candidates[j].name;
            winners++;
        }
    }
    // Prints names of winners
    for (int k = 0; k < winners; k++)
    {
        printf("%s\n", names[k]);
    }
}