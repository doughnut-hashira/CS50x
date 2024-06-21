#include <cs50.h>
#include <stdio.h>

void pyramids(int h);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height <= 0 || height > 8);

    pyramids(height);
}

void pyramids(int h)
{
    for (int i = 1; i <= h; i++)
    {
        for (int m = 0; m < (h - i); m++)
        {
            printf(" ");
        }
        for (int n = 0; n < i; n++)
        {
            printf("#");
        }
        printf("  ");
        for (int n = 0; n < i; n++)
        {
            printf("#");
        }
        printf("\n");
    }
}
