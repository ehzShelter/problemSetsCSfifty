// resize.c cs50

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
	// ensure proper usage
	if (argc != 4)
	{
		printf("Usage:resize n infile outfile\n");
		return 1;
	}

	// Check the resize factor
	int factor = atoi(argv[1]);
	if(factor <= 0 || factor > 100)
	{
		printf("The resize factor should be a positive integer <= 100.\n");
		return 2;
	}

	// remember filenames and factor
	char* infile = argv[2];
	char* outfile = argv[3];

	// open input file
	FILE* inptr = fopen(infile, "r");
	if (inptr == NULL)
	{
		printf("Could not open %s.\n", infile);
		return 3;
	}

	// open output file
	FILE* outptr = fopen(outfile, "w");
	if (outptr == NULL)
	{
		fclose(inptr);
		fprintf(stderr, "Could not create %s.\n", outfile);
		return 4;
	}

	// read infile's BITMAPFILEHEADER
	BITMAPFILEHEADER bf;
	fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

	// read infile's BITMAPINFOHEADER
	BITMAPINFOHEADER bi;
	fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

	// ensure infile is (likely) a 24-bit uncompressed BMP 4.0
	if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
			           bi.biBitCount != 24 || bi.biCompression != 0)
	{
		fclose(outptr);
		fclose(inptr);
		fprintf(stderr, "Unsupported file format.\n");
		return 4;
	}

	// construct bitmap headers for the outfile
	BITMAPFILEHEADER out_bf;
	BITMAPINFOHEADER out_bi;
	out_bf = bf;
	out_bi = bi;
	out_bi.biWidth = bi.biWidth * factor;
	out_bi.biHeight = bi.biHeight * factor;

	// determine padding for scanlines
	// Needed for SizeImage calculation
	int in_padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
	int out_padding =  (4 - (out_bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

	// Calculate file and image size
    // biSizeImage calculation.


	out_bi.biSizeImage = 3 * abs(out_bi.biHeight) * out_bi.biWidth + (out_padding * abs(out_bi.biHeight))  ;
	out_bf.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + (out_bi.biSizeImage);

	// write outfile's BITMAPFILEHEADER
	fwrite(&out_bf, sizeof(BITMAPFILEHEADER), 1, outptr);

	// write outfile's BITMAPINFOHEADER
	fwrite(&out_bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // fundamental steps (iterative process) for resizing by n factor
	for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
	{
		fpos_t position;
		fgetpos (inptr, &position);

		for (int m = 0; m < factor; m++)
		{
		    // "RE-COPY" METHOD :
		    // >>Go back to the start of the original row and the
		    // >>Repeat the horizontal resizing

		    // fseek back to beginning of scanline if m < factor
		    if (m < factor)
		    {
		        fsetpos (inptr, &position);
		    }

	         // iterate over pixels in scanline
	        for (int j = 0; j < bi.biWidth; j++)
	        {
			    // temporary storage
			    RGBTRIPLE triple;

				// read RGB triple from infile
				fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

				// write RGB triple to outfile
				for(int n = 0; n < factor; n++)
				{
					fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
				}
			}

				// skip over padding in infile,if any
			fseek(inptr, in_padding, SEEK_CUR);

			// then add it to outfile
			for (int k = 0; k <out_padding; k++)
			{
				fputc(0x00, outptr);
		    }

		}
	}

	// close infile
	fclose(inptr);

	// close outfile
	fclose(outptr);

	// that's all folks
	return 0;
}
