#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Function declaration
int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else if (score1 == score2)
    {
        printf("Tie !\n");
    }
}

// Calculates the score of the word given
int compute_score(string word)
{
    // Array to store alphabet
    int alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    // This variable stores length of the word
    int length = strlen(word);
    // This variable stores the score of the word
    int score = 0;

    // Calculates the score of the word
    for (int i = 0; i < length; i++)
    {
        // Checks if character is uppercase
        // Adds 32 (makes it lowercase) in case it is
        if (word[i] > 64 && word[i] < 91)
        {
            word[i] += 32;
        }
        // Checks where does the letter stand in alphabet array
        for (int j = 0; j < 26; j++)
        {
            if (word[i] == alphabet[j])
            {
                // Adds the relevant points to the score
                score += POINTS[j];
            }
        }
    }
    // Returns calculated score
    return score;
}
