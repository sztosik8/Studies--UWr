#include <stdio.h>
#include <stdlib.h>
#include "operacje2.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image/stb_image_write.h"
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image/stb_image_resize.h"

int main(void)
{
    int width, height, channels;
    unsigned char *img = stbi_load("images/janek.jpg", &width, &height, &channels, 0);
    if (img == NULL)
    {
        printf("Error in loading the image\n");
        exit(1);
    }

    ha_value(img, width, height, channels);
    
    // stbi_write_jpg("images/out2.jpg", width, height, channels, img, 100);

    stbi_image_free(img);
}
