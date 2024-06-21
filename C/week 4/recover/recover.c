#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }
    char filename[8];
    int i = 0;

    // open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file %s.\n", argv[1]);
        return 1;
    }

    // create a buffer for a block of data
    BYTE buffer[512];
    FILE *img = NULL;

    // while there's still data left to read from the memory card
    while (fread(buffer, sizeof(BYTE), 512, card) == 512)
    {
        // create JPEGs from the data
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            ((buffer[3] & 0xf0) == 0xe0))
        {
            // close image file if it is already open
            if (img != NULL)
            {
                fclose(img);
            }

            // create a new img file
            sprintf(filename, "%03i.jpg", i);
            img = fopen(filename, "w");

            if (img == NULL)
            {
                printf("Could not create file %s.\n", filename);
                fclose(card);
                return 1;
            }

            // start writing the img file
            fwrite(buffer, sizeof(BYTE), 512, img);
            i++;
        }
        else if (img != NULL)
        {
            // continue
            fwrite(buffer, sizeof(BYTE), 512, img);
        }
    }
    // close all files
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(card);
}
