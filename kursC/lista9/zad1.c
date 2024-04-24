// Ktrzyna Trzos
// Lista 9 zadanie 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char latitude[20];
char longitude[20];
char wiersz[200];

double distance(int x1, int y1, int z1, int x2, int y2, int z2);

int main()
{
    FILE *fp;
    fp = fopen("gpx.xml", "r");

    int ilewierszy = 0;
    int ilepunktow = 0;
    double dist = 0;
    double R = 6378137; // Promień Ziemi jest zwykle podawany jako 6378137 metrów

    double x1 = 0, y1 = 0, z1 = R + 1;
    double x2 = 0, y2 = 0, z2 = 0;

    while (fgets(wiersz, 200, fp) != NULL)
    {
        ilewierszy++; // zwieksza sie za kazdym razem gdy wczytujemy wieersz
        int i = 0;

        while (wiersz[i] != '"' && i < 20) // sprawdzamy i do 20, ponewaz gdy w lini wiersz znajduje sie wartosc lat i lon to znajduje sie w pierwszych 20 znakach
            i++;

        if (wiersz[i] == '"' && wiersz[i - 9] == 'r' && wiersz[i - 8] == 'k') // warunki sprawdzaja czy mamy na wejsciu <trkpt, a nie <wpt
        {
            i++;
            ilepunktow++; // zwieksza sie za kazdym razem gdy wczytujemy punkt
            int j = i;
            while (wiersz[i] != '"')
            {
                latitude[i - j] = wiersz[i];
                i++;
            }

            double lat = atof(latitude);
            double latrad = (lat * M_PI) / 180.0; // zamiana na radiany

            while (wiersz[i] != '"')
                i++;

            i++;
            j = i;

            while (wiersz[i] != '"')
            {
                longitude[i - j] = wiersz[i];
                i++;
            }

            double lon = atof(longitude);
            double lonrad = (lon * M_PI) / 180.0; // zamiana na radiany

            if (z1 > R) // wykonuje sie tylko przy wczytaniu pierwszzego punktu
            {
                x1 = R * cos(latrad) * cos(lonrad);
                y1 = R * cos(latrad) * sin(lonrad);
                z1 = R * sin(latrad); // po tym kroku z1 bedzie wynosilo maksymalnie R

                x2 = R * cos(latrad) * cos(lonrad);
                y2 = R * cos(latrad) * sin(lonrad);
                z2 = R * sin(latrad);
            }
            else
            {
                x1 = x2;
                y1 = y2;
                z1 = z2;

                x2 = R * cos(latrad) * cos(lonrad);
                y2 = R * cos(latrad) * sin(lonrad);
                z2 = R * sin(latrad);

                dist += distance(x1, y1, z1, x2, y2, z2);
            }
        }
    }

    long int res = ftell(fp); // liczy ilosc bajtow w plilku

    printf("\ndlugosc pliku w bajtach: %ld\n", res);
    printf("ilosc wierszy w wejsciu: %d\n", ilewierszy);
    printf("ilosc punktow w wejsciu: %d\n", ilepunktow);
    printf("dlugosc sciezki w metrach: %.lfm\n\n", dist);

    return 0;
}

double distance(int x1, int y1, int z1, int x2, int y2, int z2)
{
    double sum = ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)) + ((z2 - z1) * (z2 - z1));
    sum = sqrt(sum);
    return sum;
}