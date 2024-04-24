#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "operacje2.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb/stb_image_resize.h"

#define _POSIX_SOURCE
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#undef _POSIX_SOURCE
#include <stdio.h>
#include <string.h>

char *array_of_sim_img[100][100];

FILE *plik;

int main(int argc, char *argv[])
{
    DIR *dir;
    struct dirent *entry;
    int similarity = -1;

    goto again;

again:
    initscr();
    int x_max, y_max;
    getmaxyx(stdscr, y_max, x_max);

    int y_win = y_max / 4;
    int x_win = (x_max - 80) / 2;

    WINDOW *win = newwin(5, 80, y_win, x_win);
    refresh();

    mvprintw(y_win - 1, x_win + 22, "Enter the path to the image file:");
    int y_path, x_path;
    y_path = y_win + 2;
    x_path = x_win + 2;

    move(y_path, x_path);
    box(win, 0, 0);
    wrefresh(win);

    char *dir_path = (char *)malloc(100 * sizeof(char));
    char *end = dir_path;

    if (GetPath(end, y_path, x_path) == 0)
    {
        endwin();
        return 0;
    }
find:
    if ((dir = opendir(dir_path)) == NULL)
    {
        mvprintw(y_path, x_path, "                  Invalid path, press ENTER to try again               ");
        getch();
        endwin();
        goto again;
    }
    Clear(dir_path);
    int num = 0;
    wrefresh(win);
    if (similarity < 0)
    {
        int y_choice, x_choice_sim, x_choice_dup;
        y_choice = y_win + 5 + y_max / 8;
        x_choice_sim = x_win + 10;
        x_choice_dup = x_choice_sim + 35;

        WINDOW *sim = newwin(5, 25, y_choice, x_choice_sim);
        refresh();
        WINDOW *dup = newwin(5, 25, y_choice, x_choice_dup);
        refresh();

        mvprintw(y_choice + 2, x_choice_sim + 3, "Find simmilar images");
        box(sim, 0, 0);
        wrefresh(sim);
        refresh();

        mvprintw(y_choice + 2, x_choice_dup + 2, "Find duplicate images");
        box(dup, 0, 0);
        wrefresh(dup);

        int choice = 0;
        similarity = sim_or_dup(choice, y_choice, x_choice_dup, x_choice_sim);
    }
    wrefresh(win);

    erase();
    refresh();
    y_win = y_max / 11;
    x_win = x_max / 11;

    WINDOW *win2 = newwin(40, 80, y_win, x_win);
    refresh();
    box(win2, 0, 0);
    wrefresh(win2);

    if (similarity > 0)
        mvprintw(y_win - 1, x_win + (x_win / 2) + 20, "Simmilar images are:");
    else
        mvprintw(y_win - 1, x_win + (x_win / 2) + 20, "Duplicate images are:");

    mvprintw(y_max - (y_win / 2) - 1, x_max / 20, "press \"esc\" to exit");

    int i = 1;
    move(y_win + i, x_win + 1);

    while ((entry = readdir(dir)) != NULL)
    {

        char *filename = (char *)malloc(100 * sizeof(char));
        strcpy(filename, entry->d_name);

        char *ptr = strstr(filename, ".jpg");
        char *ptr2 = strstr(filename, ".JPG");

        if (ptr > 0 || ptr2 > 0)
        {
            size_t len = strlen(dir_path);
            num++;
            char *path_to_output_dir = malloc(len + 1 + 1);
            char *path_to_output_file = malloc(len + 1 + 1);
            sprintf(path_to_output_dir, "%s/%s", dir_path, "output");
            sprintf(path_to_output_file, "%s/%s", path_to_output_dir, "hash.txt");

            plik = fopen(path_to_output_file, "+p");
            int width, height, channels;
            char *path_to_img = malloc(len + 1 + 1);
            sprintf(path_to_img, "%s/%s", dir_path, filename);

            unsigned char *img = stbi_load(path_to_img, &width, &height, &channels, 0);
            if (img == NULL)
            {
                printf("Error in loading the image\n");
                printf("  %s\n", filename);
                exit(1);
            }
            refresh();

            char *hash = (char *)malloc(100 * sizeof(char));
            hash = ha_value(path_to_output_dir, filename, img, width, height, channels);

            fclose(plik);

            ////////////// SEARCH SIMILAR IMAGES

            if (1 == duplicate(similarity, hash, dir_path, filename, num))
            {
                i++;
                move(y_win + i, x_win + 1);
                wrefresh(win2);
                refresh();
            }
        }
    }

    int y_del = y_max - (y_win / 2) - 8;
    int x_del = (x_max / 10) - 2;

    WINDOW *delwin = newwin(5, 80, y_del, x_del);
    refresh();
    
entername:
    mvprintw(y_del - 1, x_del + 17, "Enter the name of the image you want to delete:");

    y_path = y_win + 2;
    x_path = x_win + 2;

    move(y_path, x_path);
    box(delwin, 0, 0);
    wrefresh(delwin);

    move(y_del + 2, x_del + 1);
    char *filename_to_del = (char *)malloc(100 * sizeof(char));
    char *en = filename_to_del;

    if (GetPath(en, y_del, x_del) == 0)
    {
        closedir(dir);
        endwin();
        return 0;
    }

    refresh();

    char *path_to_del = malloc(100 * sizeof(char));
    sprintf(path_to_del, "%s/%s", dir_path, filename_to_del);

    refresh();
    move(y_del + 2, x_del + 1);
    if (remove(path_to_del) == 0)
    {
        closedir(dir);
        Clear(dir_path);
        goto find;
    }
    else
    {
        mvprintw(y_del + 2, x_del + 1, "File %s can not be deleted. Press ENTER to tryagain.", filename_to_del);
        char c = getch();
        if (c == 10)
            goto entername;
        if (c == 27)
        {
            closedir(dir);
            endwin();
        }
    }
    refresh();
    closedir(dir);
    endwin();
    return 0;
}
