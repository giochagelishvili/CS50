#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

const int BLOCK_SIZE = 512;
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Checks that user is using the program correctly
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    printf("%s\n", argv[1]);

    // Open input file
    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        printf("Could not open %s\n", argv[1]);
        return 2;
    }

    // Create buffer to read into
    BYTE buffer[BLOCK_SIZE];

    // Keep track of jpeg files found
    int counter = 0;

    // Filename
    char filename[8] = {0};

    // Initialize output value to NULL
    FILE *outptr = NULL;

    // Reads input into buffer
    while (fread(buffer, 1, BLOCK_SIZE, inptr) == BLOCK_SIZE)
    {
        // Checks for new JPG file
        if (buffer[0] == 0xFF && buffer[1] == 0xD8 && buffer[2] == 0xFF && (buffer[3] & 0xF0) == 0xE0)
        {
            // Checks if it's the first file
            if (counter == 0)
            {
                sprintf(filename, "%03i.jpg", counter);
                outptr = fopen(filename, "w");
                fwrite(buffer, 1, BLOCK_SIZE, outptr);
                counter++;
            }
            else
            {
                fclose(outptr);
                sprintf(filename, "%03i.jpg", counter);
                outptr = fopen(filename, "w");
                fwrite(buffer, 1, BLOCK_SIZE, outptr);
                counter++;
            }
        }
        // If it's not new JPG file keeps writing into current output file
        else if (outptr != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, outptr);
        }
    }

    // Close files
    fclose(outptr);
    fclose(inptr);
}