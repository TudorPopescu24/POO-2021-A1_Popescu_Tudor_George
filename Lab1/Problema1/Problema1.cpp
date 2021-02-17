#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <stdio.h>
#include <cstring>

char sirnumar[50];
int suma = 0;
int numar;

int main()
{
    int i;
    FILE* fis1;
    fis1 = fopen("in.txt", "r");
    while (!feof(fis1)) {
        fscanf(fis1, "%s\n", sirnumar);
        numar = 0;
        for (i = 0; i < strlen(sirnumar); i++)
            numar = numar * 10 + (sirnumar[i] - '0');
        suma = suma + numar;
    }
    printf("%d", suma);
}
