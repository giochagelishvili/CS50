#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Function declaration
string replace(string input);

int main(int argc, string argv[])
{
    // If user uses less or more than one command-line argument program gives error
    if (argc != 2)
    {
        printf("Insert command-line argument !\n");
        return 1;
    }
    // string word is command-line argument given by user
    string word = argv[1];

    // Prints the word with replaced vowels
    printf("%s\n", replace(word));
}

// Replaces vowels except for u with numbers
string replace(string input)
{
    string output = input;
    int length = strlen(input);

    // This loop checks every character in the
    // given word and replaces vowels with numbers
    for (int j = 0; j < length; j++)
    {
        switch (output[j])
        {
            case 'a':
                output[j] = '6';
                break;

            case 'e':
                output[j] = '3';
                break;

            case 'i':
                output[j] = '1';
                break;

            case 'o':
                output[j] = '0';
                break;

            case 'A':
                output[j] = '6';
                break;

            case 'E':
                output[j] = '3';
                break;

            case 'I':
                output[j] = '1';
                break;

            case 'O':
                output[j] = '0';
        }
    }
    return output;
}