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
    unsigned char *img = stbi_load("image1.jpg", &width, &height, &channels, 0);

    if (img == NULL)
    {
        printf("Error in loading the image\n");
        exit(1);
    }

    //int n = 8;
    // int new_width = width / n;
    // int new_height = height / n;
    int new_width =  8;
    int new_height = 8;

    unsigned char *out = malloc(new_width * new_height);

    stbir_resize_uint8(img, width, height, 0,
                       out, new_width, new_height, 0, channels);

    stbi_write_jpg("outresize.jpg", new_width, new_height, channels, out, 100);

    stbi_image_free(img);
}