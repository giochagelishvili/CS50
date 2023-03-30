#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string first = get_string("What is your first name? ");
    string last = get_string("What is your last name? ");
    int age = get_int("What is your age? ." );
    printf("Hello, %s %s %d\n", first, last, age);
}