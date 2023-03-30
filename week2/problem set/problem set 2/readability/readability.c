#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Function declarations
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float calculate_index(int letters, int words, int sentences);

int main(void)
{
    // Prompts the user for the text
    string text = get_string("Text: ");

    // These integer variables store the amount of letters, words and sentences in the text given by the user
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    // This integer variable stores the level of grade
    int grade = calculate_index(letters, words, sentences);
    // Types out the level of grade
    if (grade < 1)
    {
        // Prints if grade is less than 1
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        // Prints if grade is greater than 16
        printf("Grade 16+\n");
    }
    else
    {
        // Prints if grade is between 1 and 16
        printf("Grade %i\n", grade);
    }
}

// This function calculates grade level of text
// according to Coleman-Liau index and returns the rounded value
float calculate_index(int letters, int words, int sentences)
{
    // Calculates letters per words
    double L = (float) letters / words * 100;
    // Calculates words per sentences
    double S = (float) sentences / words * 100;
    // Coleman-Liau index calculation
    float index = 0.0588 * L - 0.296 * S - 15.8;
    // Stores rounded value of the index
    int rounded_index = round(index);
    return rounded_index;
}

// This function counts sentences in the given text
int count_sentences(string text)
{
    // Stores the length of given text
    int length = strlen(text);
    // This variable is used as sentence counter
    int sentences = 0;

    for (int i = 0; i < length; i++)
    {
        // Checks if character is period, exclamation point or question mark
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            // Adds 1 to sentence counter
            sentences++;
        }
    }
    return sentences;
}

// This function counts words in the given text
int count_words(string text)
{
    // Stores the length of given text
    int length = strlen(text);
    // This variable is used as word counter
    int words = 0;

    for (int i = 0; i < length; i++)
    {
        // Space between character counts as word
        if (text[i] == 32)
        {
            // Adds one to words counter
            words++;
        }
        // If the last character is period, exclamation point
        // or question mark the last word is counted as well
        if (i == length - 1 && (text[i] == 33 || text[i] == 46 || text[i] == 63))
        {
            words++;
        }
    }
    return words;
}

// This function counts letters in the given text
int count_letters(string text)
{
    // Stores the length of given text
    int length = strlen(text);
    // This variable is used as letter counter
    int letters = 0;

    for (int i = 0; i < length; i++)
    {
        // Uppercase and lowercase letters count as one
        if ((text[i] > 64 && text[i] < 91) || (text[i] > 96 && text[i] < 123))
        {
            letters++;
        }
    }
    return letters;
}