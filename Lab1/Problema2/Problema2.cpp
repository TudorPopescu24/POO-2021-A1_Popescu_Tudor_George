#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

char propozitie[50];
char cuvinte[20][20];
char aux[20];

int main()
{
    char* p;
    int lg = 0, i, j, minim;
    scanf("%[^\n]s", propozitie);
    p = strtok(propozitie, " ");
    while (p) {
        strcpy(cuvinte[lg++], p);
        p = strtok(NULL, " ");
    }
    for (i = 0;i < lg - 1;i++) {
        minim = i;
        for (j = i + 1;j < lg;j++)
            if (strlen(cuvinte[minim]) > strlen(cuvinte[j])) {
                minim = j;
            }
        strcpy(aux, cuvinte[i]);
        strcpy(cuvinte[i], cuvinte[minim]);
        strcpy(cuvinte[minim], aux);
    }
    for (i = lg-1;i >= 0;i--)
        printf("%s \n", cuvinte[i]);
}

