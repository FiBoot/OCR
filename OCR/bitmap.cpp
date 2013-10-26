#include <iostream>
#include <stdio.h>

#include "Bitmap.h"

Bitmap::Bitmap(const char* filename) : isValid(false)
{
    FILE *file;
    file = fopen(filename, "rb");

    if (file != NULL)
    {
        fread(&this->fh, sizeof(BITMAPFILEHEADER), 1, file);

        if (this->fh.bfType != BF_TYPE)
        {
            std::cerr << "File is not of bitmap type" << std::endl;
            return;
        }
        this->isValid = true;

        fread(&this->ih, sizeof(BITMAPINFOHEADER), 1, file);

        std::cout << "size: " << this->ih.biWidth << ", " << this->ih.biHeight << std::endl;

        pixels = new RGBQUAD[this->ih.biWidth * this->ih.biHeight];
        fread(pixels, this->ih.biWidth * this->ih.biHeight * sizeof(RGBQUAD), 1, file);

        fclose(file);

    } else {
        std::cerr << "Error reading file" << std::endl;
        return;
    }
}

Bitmap::~Bitmap()
{
    remove(TMPFILENAME);
}


void Bitmap::negative()
{
    FILE *file;

    file = fopen(TMPFILENAME, "w");

    for (int i = 0; i < this->ih.biWidth * this->ih.biHeight; i++)
    {
        if ((pixels[i].rgbBlue + pixels[i].rgbGreen + pixels[i].rgbRed) / 3 > 128)
        {
            pixels[i].rgbBlue = WHITE;
            pixels[i].rgbGreen = WHITE;
            pixels[i].rgbRed = WHITE;
        } else {
            pixels[i].rgbBlue = BLACK;
            pixels[i].rgbGreen = BLACK;
            pixels[i].rgbRed = BLACK;
        }
    }

    fwrite(&this->fh, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(&this->ih, sizeof(BITMAPINFOHEADER), 1, file);
    fwrite(pixels, this->ih.biWidth * this->ih.biHeight * sizeof(RGBQUAD), 1, file);

    fclose(file);
}


const char *Bitmap::getTmpfilepath()
{
    return TMPFILENAME;
}

