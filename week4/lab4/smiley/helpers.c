#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate through every row of pixels
    for (int i = 0; i < height; i++)
    {
        // Iterate through every column of pixels
        for (int j = 0; j < width; j++)
        {
            // If pixel is black change color
            if (image[i][j].rgbtRed == 0x00 && image[i][j].rgbtGreen == 0x00 && image[i][j].rgbtBlue == 0x00)
            {
                image[i][j].rgbtGreen = 0xff;
            }
        }
    }
}
