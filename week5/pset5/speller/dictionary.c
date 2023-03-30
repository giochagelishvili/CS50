// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Keep track of amount of words added from dictionary
int counter = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int index = hash(word);

    node *cursor = table[index];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open up the dictionary file
    FILE *inptr = fopen(dictionary, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s\n", dictionary);
        return false;
    }

    // Read strings from the file
    char word[LENGTH + 1];

    while (fscanf(inptr, "%s", word) != EOF)
    {
        // Create a new node and check if memory allocation was successful
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Could not allocate memory.\n");
            return false;
        }

        // Copy word into node using strcpy
        strcpy(n->word, word);

        // Insert node into hash table
        int index = hash(word);

        // Check if the head is pointing to NULL
        if (table[index] == NULL)
        {
            n->next = NULL;
        }
        else
        {
            n->next = table[index];
        }

        table[index] = n;

        counter++;
    }

    fclose(inptr);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return counter;
}

// Recursive function to free nodes
// Inspiration from Dors Coding School(YT)
void freenode(node *n)
{
    if (n->next != NULL)
    {
        freenode(n->next);
    }
    free(n);
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            freenode(table[i]);
        }
    }
    return true;
}
