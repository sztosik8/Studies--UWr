#include <stdio.h>
//#include "operacje1.h"
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image/stb_image_write.h"
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image/stb_image_resize.h"

int main()
{
    int width, height, channels;
    unsigned char *img = stbi_load("image1.jpg", &width, &height, &channels, 0);
    if (img == NULL)
    {
        printf("Error in loading the image\n");
        exit(1);
    }

//////////////////////////////////////

    size_t img_size = width * height * channels;
    int gray_channels = 1;

    size_t gray_img_size = width * height * gray_channels;

    unsigned char *gray_img = malloc(gray_img_size);
    if (gray_img == NULL)
    {
        printf("Unable to allocate memory for the gray image.\n");
        exit(1);
    }

    for (unsigned char *p = img, *pg = gray_img; p != img + img_size; p += channels, pg += gray_channels)
    {
        *pg = (uint8_t)((*p + *(p + 1) + *(p + 2)) / 3.0); 
    }

    img=gray_img;
    channels=gray_channels;

    stbi_write_jpg("gray_m.jpg", width, height, channels, img, 100);
    stbi_write_jpg("out.jpg", width, height, channels, img, 100);

    /////////////////////////////////////

    int new_width = 8;
    int new_height = 8;

    unsigned char *out = malloc(new_width * new_height);

    stbir_resize_uint8(img, width, height, 0,
                       out, new_width, new_height, 0, channels);

    img=out;
    width=new_width;
    height=new_height;

    stbi_write_jpg("resize_m.jpg", width, height, channels, img, 100);

    stbi_write_jpg("out.jpg", width, height, channels, img, 100);

    ////////////////////////////////////////

    width = 8;
    height = 8;

    img_size = width * height * channels;

    int bw_channels = 1;

    size_t bw_img_size = width * height * bw_channels;

    unsigned char *bw_img = malloc(bw_img_size);

    for (unsigned char *p = img, *pg = bw_img; p != img + img_size; p += channels, pg += bw_channels)
    {
        if (*p > *(p+channels))
        {
            printf("%d", 1);
            *pg=0;
        }
        else 
        {
            printf("%d", 0);
            *pg=255;
        }
        
    }
    img=bw_img;
    channels=bw_channels;

    stbi_write_jpg("hash_m.jpg", width, height, channels, img, 100);

    stbi_write_jpg("out.jpg", width, height, channels, img, 100);

}
