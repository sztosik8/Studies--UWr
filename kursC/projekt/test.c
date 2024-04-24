// Load an image and save it in PNG and JPG format using stb_image libraries
#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image/stb_image_write.h"

int main(void)
{
    int width, height, channels;
    unsigned char *img = stbi_load("image1.jpg", &width, &height, &channels, 0);
    if (img == NULL)
    {
        printf("Error in loading the image\n");
        exit(1);
    }
    unsigned char *p = img;

    printf("red %d, green %d, blue %d \n", *p, *(p+1), *(p+2));
    *img=0;
    *(img+1)=0;
    *(img+2)=0;
   
    printf("Loaded image with a width of %dpx, a height of %dpx and %d channels\n", width, height, channels);

    stbi_write_jpg("out.jpg", width, height, channels, img, 100);

    stbi_image_free(img);
}