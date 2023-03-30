#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Function declaration
bool valid(string password);

int main(void)
{
    // Prompts the user for string (password)
    string password = get_string("Enter your password: ");

    // Checks if input is valid according to valid function
    if (valid(password))
    {
        // Prints this if it is valid
        printf("Your password is valid!\n");
    }
    else
    {
        // Prints this if it is invalid
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// Checks if input has at least one uppercase letter,
// lowercase letter, number and symbol
bool valid(string password)
{
    // Calculates length of given word
    int length = strlen(password);

    // Boolean declaration for each requirement
    bool uppercase = false;
    bool lowercase = false;
    bool number = false;
    bool symbol = false;

    for (int i = 0; i < length; i++)
    {
        // Checks if character is number according to ASCII chart
        if (password[i] > 47 && password[i] < 58)
        {
            number = true;
        }
        // Checks if character is uppercase according to ASCII chart
        else if (password[i] > 64 && password[i] < 91)
        {
            uppercase = true;
        }
        // Checks if character is lowercase according to ASCII chart
        else if (password[i] > 96 && password[i] < 123)
        {
            lowercase = true;
        }
        // Checks if character is symbol according to ASCII chart
        else if (password[i] > 32)
        {
            symbol = true;
        }
        // Returns true if all requirements are satisfied
        if (number == true && uppercase == true && lowercase == true && symbol == true)
        {
            return true;
        }
    }
    // Returns false if word does not have at least one
    // number, uppercase letter, lowercase letter or symbol
    return false;
}
