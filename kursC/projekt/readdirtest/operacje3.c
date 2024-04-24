#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "operacje2.h"


int GetPath(char *s, int y_path, int x_path)
{
    for (;; x_path++, s++)
    {
        int c = getch();
        if (c == 10) // enter
            return 1;
        if(c == 27) // escape
            return 0; 
        if (c == 127) // backspace
        {
            mvprintw(y_path, x_path - 1, "   ");
            move(y_path, x_path - 1);
            x_path -= 2;
            s--;
            *s = '\0';
            s--;
            refresh();
        }
        else if(c>=32 && c<=126)
            *s = (char)c;
        else
        {
            c=getchar();
            c=getchar();
            mvprintw(y_path, x_path, "   ");
            move(y_path, x_path);
            x_path -= 1;
        }
        refresh();
    }
}
int sim_or_dup(int choice, int y_choice, int x_choice_dup, int x_choice_sim)
{
    keypad(stdscr, true);
    choice = getch();

    int si = 0;

    while (choice != 10)
    {
        if (choice == KEY_LEFT)
        {
            attron(A_REVERSE);
            mvprintw(y_choice + 2, x_choice_sim + 3, "Find simmilar images");
            attroff(A_REVERSE);
            refresh();
            attron(A_NORMAL);
            mvprintw(y_choice + 2, x_choice_dup + 2, "Find duplicate images");
            attroff(A_NORMAL);
            refresh();
            si = 15;
        }
        if (choice == KEY_RIGHT)
        {
            attron(A_NORMAL);
            mvprintw(y_choice + 2, x_choice_sim + 3, "Find simmilar images");
            attroff(A_NORMAL);
            refresh();
            attron(A_REVERSE);
            mvprintw(y_choice + 2, x_choice_dup + 2, "Find duplicate images");
            attroff(A_REVERSE);
            refresh();
            si = 0;
        }
        choice = getch();
    }
    return si;
}