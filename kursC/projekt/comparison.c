#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image/stb_image_write.h"
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image/stb_image_resize.h"

int main(void)
{
    int width, height, channels;
    unsigned char *img = stbi_load("outgray.jpg", &width, &height, &channels, 0);
    // unsigned char *bw = malloc(width * height);
    size_t img_size = width * height * channels;

    // printf("image size %d \n", width * height * channels);
    // printf("width %d height %d \n", width, height);
    // printf("channels %d \n", channels);
    // printf("\n");

    if (img == NULL)
    {
        printf("Error in loading the image\n");
        exit(1);
    }

    int bw_channels = 1;

    size_t bw_img_size = width * height * bw_channels;

    unsigned char *bw_img = malloc(bw_img_size);
    if (bw_img == NULL)
    {
        printf("Unable to allocate memory for the gray image.\n");
        exit(1);
    }

    // printf("image bw size %d \n", width * height * bw_channels);
    // printf("width bw %d height %d \n", width, height);
    // printf("channels  bw %d \n", bw_channels);
    // printf("\n");

    // for (unsigned char *p = img, *pg = gray_img; p != img + img_size; p += channels, pg += gray_channels
    for (unsigned char *p = img, *pg = bw_img; p != img + img_size; p += channels, pg += bw_channels)
    {
        // printf("red %d, green %d, blue %d \n", *p, *(p + 1), *(p + 2));
        if (*p < 126)
            *pg = 0;
        else
            *pg = 255;

        // printf("szary %d, cxzarny bialy %d \n", *p, *pg);
    }

    stbi_write_jpg("outcom.jpg", width, height, bw_channels, bw_img, 100);

    stbi_image_free(img);
}