#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

// Declare node
typedef struct node
{
    char *phrase;
    struct node *next;
}
node;

// Define list size
#define LIST_SIZE 2

// Function declarations
void visualize(node *list);
void unload(node *list);

int main(void)
{
    // Pointer for linked list
    node *list = NULL;

    // Add phrases to linked list
    for (int i = 0; i < LIST_SIZE; i++)
    {
        // Prompt the user for phrase
        string phrase = get_string("Phrase: ");

        // Create new pointer to allocate memory
        node *n = malloc(sizeof(node));
        // Make sure memory allocation was successful
        if (n == NULL)
        {
            printf("Couldn't allocate memory for node\n");
            return 1;
        }

        // Assign phrase to new node (n)
        n->phrase = phrase;
        // Point node (n) to list
        n->next = list;

        // Point list to node (n)
        list = n;

        // Visualize list
        visualize(list);
    }

    // Free allocated memory
    unload(list);
}

// Free allocated memory
void unload(node *list)
{
    while (list != NULL)
    {
        node *ptr = list->next;
        free(list);
        list = ptr;
    }
}

// Visualize the list
void visualize(node *list)
{
    printf("\n+-- List Visualizer --+\n\n");
    while (list != NULL)
    {
        printf("Location %p\n", list);
        printf("Phrase %s\n", list->phrase);
        printf("Next: %p\n\n", list->next);
        list = list->next;
    }
    printf("+---------------------+\n");
}