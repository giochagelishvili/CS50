#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    // Get the word from the user
    string word = get_string("Word: ");

    int word_length = strlen(word);
    for (int i = 0; i < word_length - 1; i++)
    {
        // Check if the word is NOT alphabetical
        if (word[i] > word[i + 1])
        {
            printf("No\n");
            return 0;
        }
    }

    // Print out yes if the word is alphabetical
    printf("Yes\n");
    return 0;
}