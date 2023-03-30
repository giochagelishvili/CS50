#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function declarations
bool is_valid(string key);
string cipher(string text, string key);

int main(int argc, string argv[])
{
    // If user enters no arguments or more than one argument program gives error message and stops
    if (argc != 2)
    {
        printf("Enter command-line argument !\n");
        return 1;
    }
    // Program stops if key is invalid
    if (is_valid(argv[1]) == false)
    {
        return 1;
    }
    // Prompts the user for the text which should be ciphered
    string plaintext = get_string("Plaintext: ");
    // Stores the ciphered text
    string ciphertext = cipher(plaintext, argv[1]);
    // Prints the ciphered text
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

// Ciphers the given text by given key
string cipher(string text, string key)
{
    // Stores the length of the given text
    int length = strlen(text);
    // Uppercase and lowercase alphabet arrays
    char uppercase[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char lowercase[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    // Goes through every character of the given text
    for (int i = 0; i < length; i++)
    {
        // Stores the alphabetical location of letter
        int location = 0;
        // Checks if letter is uppercase
        if (text[i] > 64 && text[i] < 91)
        {
            // Calculates the alphabetical location of letter by substracting 65 (ASCII value of letter A) from letter's ASCII value
            location = text[i] - 65;
            // Uppercases the letter at the position of "location" in key array
            key[location] = toupper(key[location]);
            text[i] = key[location];
            location = 0;
        }
        else if (text[i] > 96 && text[i] < 123)
        {
            // Calculates the alphabetical location of letter by substracting 65 (ASCII value of letter A) from letter's ASCII value
            location = text[i] - 97;
            // Lowercases the letter at the position of "location" in key array
            key[location] = tolower(key[location]);
            text[i] = key[location];
            location = 0;
        }
    }

    return text;
}

// Checks if key is valid
bool is_valid(string key)
{
    // Stores the length of the given string
    int length = strlen(key);
    // Goes though every character of the given string
    for (int i = 0; i < length; i++)
    {
        // If string contains less than or more than 26
        // characters program gives error message and returns false (invalid key)
        if (length != 26)
        {
            printf("Key must contain 26 characters.\n");
            return false;
        }
        // If any character of the string is not alphabetical
        // the program gives error message and returns false
        else if (!(key[i] > 64 && key[i] < 91) && !(key[i] > 96 && key[i] < 123))
        {
            printf("Usage: ./substitution key\n");
            return false;
        }
        // If letter is used twice program gives error message and returns false
        for (int j = i + 1; j < length; j++)
        {
            if (key[i] == key[j] || key[i] == (key[j] - 32) || key[i] == (key[j] + 32))
            {
                printf("You should use each character only once.\n");
                return false;
            }
        }
    }
    return true;
}