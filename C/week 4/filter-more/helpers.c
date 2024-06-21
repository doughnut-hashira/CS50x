#include <math.h>
#include <stdio.h>

#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = (int) image[i][j].rgbtRed;
            int blue = (int) image[i][j].rgbtBlue;
            int green = (int) image[i][j].rgbtGreen;
            float gray = round((red + blue + green) / 3.0);
            image[i][j].rgbtGreen = image[i][j].rgbtBlue = image[i][j].rgbtRed = (uint8_t) gray;
        }
    }
    // Done
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        RGBTRIPLE temp[1][width];
        for (int j = 0; j < width; j++)
        {
            temp[0][j] = image[i][width - (j + 1)];
        }
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[0][j];
        }
    }
    // Done
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = 0;
            int blue = 0;
            int green = 0;
            float avgno = 0.0;
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if (i + k >= 0 && i + k < height && j + l >= 0 && j + l < width)
                    {
                        red += (int) image[i + k][j + l].rgbtRed;
                        blue += (int) image[i + k][j + l].rgbtBlue;
                        green += (int) image[i + k][j + l].rgbtGreen;
                        avgno += 1;
                    }
                }
            }
            temp[i][j].rgbtRed = round(red / avgno);
            temp[i][j].rgbtBlue = round(blue / avgno);
            temp[i][j].rgbtGreen = round(green / avgno);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    int n[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int m[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float gxred = 0, gxblue = 0, gxgreen = 0;
            float gyred = 0, gyblue = 0, gygreen = 0;

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if (i + k >= 0 && i + k < height && j + l >= 0 && j + l < width)
                    {
                        int red = (int) image[i + k][j + l].rgbtRed;
                        int blue = (int) image[i + k][j + l].rgbtBlue;
                        int green = (int) image[i + k][j + l].rgbtGreen;

                        gxred += red * n[k + 1][l + 1];
                        gxblue += blue * n[k + 1][l + 1];
                        gxgreen += green * n[k + 1][l + 1];
                        gyred += red * m[k + 1][l + 1];
                        gyblue += blue * m[k + 1][l + 1];
                        gygreen += green * m[k + 1][l + 1];
                    }
                }
            }

            int red = round(sqrt(pow(gxred, 2) + pow(gyred, 2)));
            int blue = round(sqrt(pow(gxblue, 2) + pow(gyblue, 2)));
            int green = round(sqrt(pow(gxgreen, 2) + pow(gygreen, 2)));

            temp[i][j].rgbtRed = (red > 255) ? 255 : red;
            temp[i][j].rgbtBlue = (blue > 255) ? 255 : blue;
            temp[i][j].rgbtGreen = (green > 255) ? 255 : green;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}
