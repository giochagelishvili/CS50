#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterates through every pixel in the image
    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculates average of pixel's RGB values
            float average = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;
            int rounded = round(average);

            // Makes sure that value is between 0 and 255
            if (rounded > 255)
            {
                rounded = 255;
            }
            else if (rounded < 0)
            {
                rounded = 0;
            }

            image[i][j].rgbtRed = rounded;
            image[i][j].rgbtGreen = rounded;
            image[i][j].rgbtBlue = rounded;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterates through every pixel of the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Stores original RGB values of the pixel at [i][j]
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            // Calculates sepia filter RGB values using sepia filter formula
            float sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
            float sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
            float sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;

            // Rounds values to closest integer
            int roundedRed = round(sepiaRed);
            int roundedGreen = round(sepiaGreen);
            int roundedBlue = round(sepiaBlue);

            // Check that red is between 0 and 255
            if (roundedRed > 255)
            {
                roundedRed = 255;
            }
            else if (roundedRed < 0)
            {
                roundedRed = 0;
            }

            // Check that green is between 0 and 255
            if (roundedGreen > 255)
            {
                roundedGreen = 255;
            }
            else if (roundedGreen < 0)
            {
                roundedGreen = 0;
            }

            // Check that blue is between 0 and 255
            if (roundedBlue > 255)
            {
                roundedBlue = 255;
            }
            else if (roundedBlue < 0)
            {
                roundedBlue = 0;
            }

            image[i][j].rgbtRed = roundedRed;
            image[i][j].rgbtGreen = roundedGreen;
            image[i][j].rgbtBlue = roundedBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterates through every pixel of the image
    for (int i = 0; i < height; i++)
    {
        // Checks if width is even
        if (width % 2 == 0)
        {
            for (int j = 0; j < width / 2; j++)
            {
                // Replaces pixels from left to right
                RGBTRIPLE temp[height][width];
                temp[i][j] = image[i][j];
                image[i][j] = image[i][width - (j + 1)];
                image[i][width - (j + 1)] = temp[i][j];
            }
        }
        else if (width % 2 != 0)
        {
            for (int j = 0; j < (width - 1) / 2; j++)
            {
                RGBTRIPLE temp[height][width];
                temp[i][j] = image[i][j];
                image[i][j] = image[i][width - (j + 1)];
                image[i][width - (j + 1)] = temp[i][j];
            }
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Copy of the image
    RGBTRIPLE imageCopy[height][width];

    // Iterates through every pixel of the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Stores the sum of RGB values of the pixels around the pixel at [i][j]
            float sumRed = 0;
            float sumGreen = 0;
            float sumBlue = 0;
            float counter = 0;

            // Iterates through every pixel around and including the pixel at [i][j]
            for (int row = -1; row < 2; row++)
            {
                for (int column = -1; column < 2; column++)
                {
                    if (i + row < 0 || i + row > height - 1)
                    {
                        continue;
                    }
                    else if (j + column < 0 || j + column > width - 1)
                    {
                        continue;
                    }

                    sumRed += image[i + row][j + column].rgbtRed;
                    sumGreen += image[i + row][j + column].rgbtGreen;
                    sumBlue += image[i + row][j + column].rgbtBlue;
                    counter++;
                }
            }

            // Assigns RGB values to pixels of copy
            imageCopy[i][j].rgbtRed = round(sumRed / counter);
            imageCopy[i][j].rgbtGreen = round(sumGreen / counter);
            imageCopy[i][j].rgbtBlue = round(sumBlue / counter);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Replaces original image pixels with copy's pixels
            image[i][j].rgbtRed = imageCopy[i][j].rgbtRed;
            image[i][j].rgbtGreen = imageCopy[i][j].rgbtGreen;
            image[i][j].rgbtBlue = imageCopy[i][j].rgbtBlue;
        }
    }
}
