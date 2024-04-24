#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image/stb_image_write.h"

int main(void)
{
    int width, height, channels;
    // unsigned char *img = stbi_load("sky.jpg", &width, &height, &channels, 0);
    unsigned char *img = stbi_load("outresize.jpg", &width, &height, &channels, 0);
    if (img == NULL)
    {
        printf("Error in loading the image\n");
        exit(1);
    }
    printf("Loaded image with a width of %dpx, a height of %dpx and %d channels\n", width, height, channels);

    // Convert the input image to gray
    size_t img_size = width * height * channels;
    int gray_channels = 1;
    

    // int gray_channels = channels == 4 ? 2 : 1;
    size_t gray_img_size = width * height * gray_channels;

    unsigned char *gray_img = malloc(gray_img_size);
    if (gray_img == NULL)
    {
        printf("Unable to allocate memory for the gray image.\n");
        exit(1);
    }
    // przechodzi po kazdym pikselu
    // *p value of red
    // *(p+1) value of green
    // *(p+2) value of blue

    for (unsigned char *p = img, *pg = gray_img; p != img + img_size; p += channels, pg += gray_channels)
    {
        *pg = (uint8_t)((*p + *(p + 1) + *(p + 2)) / 3.0);
        if (channels == 4)
        {
            *(pg + 1) = *(p + 3);
        }
    }

    stbi_write_jpg("outgray.jpg", width, height, gray_channels, gray_img, 100);

    stbi_image_free(img);
    free(gray_img);
}
