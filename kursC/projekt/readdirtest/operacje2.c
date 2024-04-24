#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ncurses.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "operacje2.h"
#include "stb/stb_image.h"
#include "stb/stb_image_write.h"
#include "stb/stb_image_resize.h"

FILE *plik;
DIR *dir;
char *ha_value(char *output_dir, char *filename, unsigned char *img, int width, int height, int channels)
{
    size_t len = strlen(output_dir);
    char *output_file = malloc(len + 1 + 1);
    sprintf(output_file, "%s/%s", output_dir, "hash.txt");

    plik = fopen(output_file, "a+");

    size_t img_size = width * height * channels;
    int gray_channels = 1;

    size_t gray_img_size = width * height * gray_channels;

    unsigned char *gray_img = malloc(gray_img_size);
    if (gray_img == NULL)
    {
        printf("Unable to allocate memory for the gray image.\n");
        exit(1);
    }

    ///////////////////////////////////// TO GRAY

    for (unsigned char *p = img, *pg = gray_img; p != img + img_size; p += channels, pg += gray_channels)
    {
        *pg = (uint8_t)((*p + *(p + 1) + *(p + 2)) / 3.0);
    }
    img = gray_img;
    channels = gray_channels;

    ///////////////////////////////////// RESIZE

    int new_width = 8;
    int new_height = 8;
    unsigned char *out = malloc(new_width * new_height);

    stbir_resize_uint8(img, width, height, 0,
                       out, new_width, new_height, 0, channels);

    img = out;
    width = new_width;
    height = new_height;

    //////////////////////////////////////// DHASH

    width = 9;
    height = 8;
    img_size = width * height * channels;

    int bw_channels = 1;
    size_t bw_img_size = 8 * 8 * bw_channels;
    unsigned char *bw_img = malloc(bw_img_size);

    char *hash = (char *)malloc(100 * sizeof(char));

    unsigned char *p = img, *pg = bw_img;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++, p += channels, pg += bw_channels)
        {
            if (*p > *(p + channels))
            {
                fprintf(plik, "1");
                *hash = '1';
                *pg = 0;
            }
            else
            {
                fprintf(plik, "0");
                *hash = '0';
                *pg = 255;
            }
            hash++;
        }
    }

    fprintf(plik, " ");
    fputs(filename, plik);
    fprintf(plik, "\n");

    img = bw_img;
    channels = bw_channels;

    //////////////////////////////////// OUTPUT

    char *output_converted_img = malloc(len + 1 + 1);
    sprintf(output_converted_img, "%s/%s", output_dir, filename);
    stbi_write_jpg(output_converted_img, 8, 8, channels, img, 100);

    return hash - 64;
    fclose(plik);
}

void Clear(char dir_path[])
{
    char *path = malloc(100 * sizeof(char));
    strcpy(path, dir_path);

    char path_to_output_dir[120];
    sprintf(path_to_output_dir, "%s/%s", path, "output");
    mkdir(path_to_output_dir, 0700);

    char path_to_output_file[200];
    sprintf(path_to_output_file, "%s/%s", path_to_output_dir, "hash.txt");

    plik = fopen(path_to_output_file, "w");
    fclose(plik);

    char path_to_output_dup[200];
    sprintf(path_to_output_dup, "%s/%s", path_to_output_dir, "duplikaty");
    mkdir(path_to_output_dup, 0700);

    Empty(path_to_output_dup);
    Empty(path_to_output_dir);
    return;
}

void Empty(char name[])
{
    DIR *theFolder = opendir(name);
    struct dirent *next_file;
    char filepath[256];

    while ((next_file = readdir(theFolder)) != NULL)
    {
        sprintf(filepath, "%s/%s", name, next_file->d_name);
        char *ptr = strstr(next_file->d_name, ".");

        if (ptr > 0)
            remove(filepath);
    }
    closedir(theFolder);
}

int duplicate(int similarity, char *hash, char *dir_path, char *filename1, int num)
{
    size_t len = strlen(dir_path);
    size_t filename_len = strlen(filename1);
    *(filename1 + filename_len) = 0;
    char *path_to_output_dir = malloc(len + 20);
    sprintf(path_to_output_dir, "%s/%s%s", dir_path, "output/duplikaty", "\0");

    char *path_to_output_file = malloc(len + 20);
    sprintf(path_to_output_file, "%s/%s", dir_path, "output/hash.txt");

    FILE *plik;
    char ch;
    plik = fopen(path_to_output_file, "r");

    if (NULL == plik)
        printf("file can't be opened \n");

    char *path_to_img1 = malloc(len + 20);
    sprintf(path_to_img1, "%s/%s", dir_path, filename1);

    int width, height, channels;
    unsigned char *img = stbi_load(path_to_img1, &width, &height, &channels, 0);

    char *filename2 = malloc(100 * sizeof(char));
    int num1 = 0;
    char *hash2 = malloc(64);
    int is_dup = 0;

    while (!feof(plik))
    {
        ch = fgetc(plik);
        if (!feof(plik))
        {
            for (int i = 0; i < 64; i++)
            {
                *(hash2 + i) = ch;
                ch = fgetc(plik);
            }
            int dist = hammingDistance(hash, hash2);

            ch = fgetc(plik);
            num1++;
            int j = 0;
            while (ch != '\n')
            {
                *(filename2 + j) = ch;
                *(filename2 + j + 1) = 0;
                ch = fgetc(plik);
                j++;
            }

            if (dist <= similarity && num != num1)
            {
                if (is_dup == 0)
                {
                    is_dup++;
                    printw("%s     ", filename1);
                    char *path2 = (char *)malloc(len + 50);
                    sprintf(path2, "%s/%s", path_to_output_dir, filename1);
                    
                    stbi_write_jpg(path2, width, height, channels, img, 100);
                }

                printw("%s    ", filename2);
                refresh();

                char *path1 = (char *)malloc(len + 50);
                char *path_to_img = (char *)malloc(len + 50);

                sprintf(path_to_img, "%s/%s", dir_path, filename2);
                int width1, height1, channels1;
                unsigned char *img2 = stbi_load(path_to_img, &width1, &height1, &channels1, 0);

                sprintf(path1, "%s/%s", path_to_output_dir, filename2);

                stbi_write_jpg(path1, width1, height1, channels1, img2, 100);
            }
        }
    }
    fclose(plik);
    if (is_dup > 0)
        return 1;

    return 0;
}
int hammingDistance(char *str1, char *str2)
{
    char hash1[64];
    char hash2[64];

    char ch;
    ch = *str1;
    int i = 0;
    while (i < 64)
    {
        hash1[i] = ch;
        ch = *(str1 + 1 + i);
        i++;
    }

    ch = *str2;
    i = 0;
    while (i < 64)
    {
        hash2[i] = ch;
        ch = *(str2 + 1 + i);
        i++;
    }
    int count = 0;
    for (int i = 0; i < 64; i++)
    {
        if (hash1[i] != hash2[i])
            count++;
    }
    return count;
}