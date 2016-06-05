/**
 * recover.c
 * emrul hasan zawad
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>

#define BLOCK_SIZE 512

int main(int argc, char* agrv[])
{
    FILE* fileRaw;

    if ((fileRaw = fopen("card.raw", "r")) == NULL)
    {
        printf("Error opening the file \"card.raw\"...");
        return 1;
    }

    unsigned char buf[BLOCK_SIZE];

    int counter = 0;
    FILE* fw = NULL;

    // Iterate over file contents
    while (fread(buf, sizeof(buf), 1, fileRaw))
    {
        // Check if the first four bytes are a JPEG signature
        if ((buf[0] == 0xff && buf[1] == 0xd8 && buf[2] == 0xff && buf[3] == 0xe0)
            ||
            (buf[0] == 0xff && buf[1] == 0xd8 && buf[2] == 0xff && buf[3] == 0xe1))
        {
            // Close the file, if it is opened otherwise>>(leaked still reachable 15 blocks)
            if (fw != NULL)
            {
                fclose(fw);
            }

            char filename[8];

            sprintf(filename, "%03d.jpg", counter);

            // Open a new JPEG file for writing
            fw = fopen(filename, "w");
            counter++;
        }

        // if already found a jpeg write it to stream
        if (fw != NULL)
        {
            fwrite(buf, BLOCK_SIZE, 1, fw);
        }
    }

    // close last jpg
    if (fw != NULL)
    {
        fclose(fw);
    }
    // close card raw file
    fclose(fileRaw);
 }
