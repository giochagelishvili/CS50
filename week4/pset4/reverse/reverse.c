#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    char *infile = argv[1];
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s\n", infile);
        return 1;
    }

    // Read header
    WAVHEADER header;
    fread(&header, sizeof(WAVHEADER), 1, inptr);

    // Use check_format to ensure WAV format
    if (check_format(header) == 0)
    {
        printf("Input file must be WAV format.\n");
        return 1;
    }

    if (header.audioFormat != 1)
    {
        printf("Input file must be WAV format.\n");
        return 1;
    }

    // Open output file for writing
    char *outfile = argv[2];
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        printf("Could not open %s\n", outfile);
        return 1;
    }

    // Write header to file
    fwrite(&header, sizeof(WAVHEADER), 1, outptr);

    // Use get_block_size to calculate size of block
    int block_size = get_block_size(header);

    // Write reversed audio to file
    if (fseek(inptr, block_size, SEEK_END))
    {
        return 1;
    }

    BYTE buffer[block_size];
    while (ftell(inptr) - block_size > sizeof(header))
    {
        if (fseek(inptr, - 2 * block_size, SEEK_CUR))
        {
            return 1;
        }

        fread(buffer, block_size, 1, inptr);
        fwrite(buffer, block_size, 1, outptr);
    }

    // Close files
    fclose(inptr);
    fclose(outptr);
}

int check_format(WAVHEADER header)
{
    // Ensure that file is WAV format
    if (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int get_block_size(WAVHEADER header)
{
    // Calculate block size
    return header.numChannels * (header.bitsPerSample / 8);
}