#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // asks the user for their name and greets to them
    // by printing out Hello, "given name"!
    string name = get_string("What is your name? ");
    printf("Hello, %s!\n", name);
}