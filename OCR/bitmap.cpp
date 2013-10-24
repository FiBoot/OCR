#include <iostream>
#include <stdio.h>

#include "Bitmap.h"

Bitmap::Bitmap(const char* path)
{
    FILE* file;

    this->filename = path;
    file = fopen(filename, "rb");

    if (file != NULL)
    {
        fread(&this->fh, sizeof(BITMAPFILEHEADER), 1, file);

        if (this->fh.bfType != BF_TYPE)
        {
            std::cerr << "File is not of bitmap type" << std::endl;
            return;
        }

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
