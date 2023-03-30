#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function declarations
bool only_digits(string text);
string rotate(string plaintext, int key);

int main(int argc, string argv[])
{
    // The user gets error message if they don't pass the command-line argument
    if (argc != 2 || only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Prompts the user for plaintext which should be ciphered
    string plaintext = get_string("Plaintext: ");
    // Converts argv[1] to int
    int key = atoi(argv[1]);
    // Stores ciphered text
    string ciphertext = rotate(plaintext, key);
    // Prints ciphered text
    printf("Ciphertext: %s\n", ciphertext);
}

// This function adds "key" amount on every character of "plaintext"
string rotate(string plaintext, int key)
{
    // Calculates the length of "plaintext"
    int length = strlen(plaintext);
    // Goes through every character of "plaintext"
    for (int i = 0; i < length; i++)
    {
        // Checks that character at i position is lowercase or uppercase letter
        if ((plaintext[i] > 64 && plaintext[i] < 91) || (plaintext[i] > 96 && plaintext[i] < 123))
        {
            // This function runs "key" times adding one to the letter at [i] position
            for (int j = 0; j < key; j++)
            {
                plaintext[i]++;
                // If ASCII value of character goes over uppercase letter section ( 65 - 90)
                // character at [i] position becomes 'A' (65) and the loop goes on from there
                if (plaintext[i] == 91)
                {
                    plaintext[i] = 'A';
                }
                // If ASCII value of character goes over lowercase letter section (97 - 122)
                // character at [i] position becomes 'a' (97) and the loop goes on from there
                else if (plaintext[i] == 123)
                {
                    plaintext[i] = 'a';
                }
            }
        }
    }

    return plaintext;
}

// Checks if given string contains only digits
bool only_digits(string text)
{
    // Calculates length of "text"
    int length = strlen(text);
    // Goes through every character of "text"
    for (int i = 0; i < length; i++)
    {
        // If character is outside of ASCII digits section (48 - 57) function returns false
        if (text[i] < 48 || text[i] > 57)
        {
            return false;
        }
    }
    return true;
}