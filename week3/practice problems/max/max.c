// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    printf("The max value is %i.\n", max(arr, n));
}


int max(int array[], int n)
{
    // Keeps track of the largest value in the array
    // Initially gets first element of the array
    int tracker = array[0];
    // Goes through every element of the array
    for (int i = 1; i < n; i++)
    {
        // Compares the tracker and ith element of the array
        if (tracker < array[i])
        {
            // If tracker is less than ith element tracker gets value of ith element
            tracker = array[i];
        }
    }
    // Returns the largest value stored in tracker
    return tracker;
}
