#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // Open the forensic image
    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 1;
    }
    BYTE buffer[BLOCK_SIZE];

    FILE *outfile = NULL;
    char filename[8];
    int file_count = 0;

    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, infile) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (outfile != NULL)
            {
                fclose(outfile);
            }
            sprintf(filename, "%03i.jpg", file_count);
            outfile = fopen(filename, "w");
            if (outfile == NULL)
            {
                fprintf(stderr, "Could not create %s.\n", filename);
                fclose(infile);
                return 1;
            }

            file_count++;
        }

        if (outfile != NULL)
        {
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, outfile);
        }
    }

    if (outfile != NULL)
    {
        fclose(outfile);
    }

    fclose(infile);

    return 0;
}
