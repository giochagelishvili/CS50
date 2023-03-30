#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    string name = "Emma";
    int length = strlen(name);
    for (int i = 0; i < length; i++)
    {
        printf("%i ", name[i]);
    }
    printf("\n");
}