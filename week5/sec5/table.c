#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Declare struct node
typedef struct node
{
    char *phrase;
    struct node *next;
}
node;

// Declare node array of size 26
node *table[26];

// Function declaration
int hash(char *phrase);

int main(void)
{
    // Prompt the user for phrases
    for (int i = 0; i < 3; i++)
    {
        char* phrase = get_string("Phrase: ");
        int index = hash(phrase);
        printf("%s hashes to %i\n", phrase, index);
    }
}

// Calculate the index
int hash (char *phrase)
{
    return toupper(phrase[0]) - 'A';
}