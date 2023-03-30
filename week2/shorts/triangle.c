#include <stdio.h>
#include <cs50.h>

// Function declaration
bool valid_triangle(int x, int y, int z);

int main(void)
{
    // Declare side variables
    int side1;
    int side2;
    int side3;

    // Get the side lengths from user
    side1 = get_int("Length: ");
    side2 = get_int("Length: ");
    side3 = get_int("Length: ");

    // Check if the trianlge is valid
    if (valid_triangle(side1, side2, side3))
    {
        // Print "Valid !" if lengths are valid
        printf("Valid !\n");
    }
    else
    {
        // Print "Invalid !" if lengths are invalid
        printf("Invalid !\n");
    }
}


// Checks if the integers could be valid side lengths for triangle
bool valid_triangle(int x, int y, int z)
{
    // Check if all sides are positive
    if (x < 1 || y < 1 || z < 1)
    {
        return false;
    }

    // Check if sum of two sides are greater than third one
    if (x + y >= z && x + z >= y && z + y >= x)
    {
        return true;
    }
    else
    {
        return false;
    }
}