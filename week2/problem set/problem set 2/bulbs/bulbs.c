#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Constant bits in byte
const int BITS_IN_BYTE = 8;

// Function declarations
void binary(string text);
void print_bulb(int bit);

int main(void)
{
    // Prompts the user for string
    string message = get_string("Message: ");
    // Turns the message to binary and prints out the bulbs of ones and zeros
    binary(message);
}

// This function turns given text into binary and prints out the bulbs
void binary(string text)
{
    // Array to store binary value of character
    int binary[] = {0, 0, 0, 0, 0, 0, 0, 0};
    // Integer variable to store length of given text
    int length = strlen(text);
    // Gets every character from text one by one and turns them into binary values
    for (int i = 0; i < length; i++)
    {
        // Stores the letter at i position of text
        char letter = text[i];
        // Turns character's decimal value to binary value
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            binary[j] = letter % 2;
            letter = letter / 2;
        }
        // Prints out the bulbs according to character's binary value
        for (int k = BITS_IN_BYTE - 1; k >= 0; k--)
        {
            print_bulb(binary[k]);
        }
        printf("\n");
    }
}

// Prints the bulb emojis
void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
