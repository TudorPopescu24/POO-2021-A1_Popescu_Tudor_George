#include "Sort.h"
#include <cstdlib>
#include <time.h>
#include <stdarg.h>
#include <iostream>
#include <cstring>

using namespace std;

Sort::Sort(int nr, int minim, int maxim) {
    srand(time(NULL));
    List = new(nod);
    List = NULL;
    for (int i = 0; i < nr; i++) {
        nod* new_node = new(nod);
        new_node->info = rand() % (maxim - minim + 1) + minim;
        new_node->st = NULL;
        new_node->dr = NULL;
        if (List == NULL)
            List = new_node;
        else {
            nod* current_node = List;
            while (current_node->dr != NULL) current_node = current_node->dr;
            current_node->dr = new_node;
            new_node->st = current_node;
        }
    }
}

Sort::Sort(int a1, int a2, int a3, int a4, int a5) {
    List = new(nod);
    List->st = NULL;
    List->dr = NULL;
    List->info = a1;
    nod* new_node;
    nod* current_node;

    new_node = new(nod);
    new_node->info = a2;
    new_node->st = NULL;
    new_node->dr = NULL;
    current_node = List;
    while (current_node->dr != NULL) current_node = current_node->dr;
    current_node->dr = new_node;
    new_node->st = current_node;

    new_node = new(nod);
    new_node->info = a3;
    new_node->st = NULL;
    new_node->dr = NULL;
    current_node = List;
    while (current_node->dr != NULL) current_node = current_node->dr;
    current_node->dr = new_node;
    new_node->st = current_node;

    new_node = new(nod);
    new_node->info = a4;
    new_node->st = NULL;
    new_node->dr = NULL;
    current_node = List;
    while (current_node->dr != NULL) current_node = current_node->dr;
    current_node->dr = new_node;
    new_node->st = current_node;

    new_node = new(nod);
    new_node->info = a5;
    new_node->st = NULL;
    new_node->dr = NULL;
    current_node = List;
    while (current_node->dr != NULL) current_node = current_node->dr;
    current_node->dr = new_node;
    new_node->st = current_node;
}

Sort::Sort(int nr, int v[]) {
    List = new(nod);
    List = NULL;
    for (int i = 0; i < nr; i++) {
        nod* new_node = new(nod);
        new_node->info = v[i];
        new_node->st = NULL;
        new_node->dr = NULL;
        if (List == NULL)
            List = new_node;
        else {
            nod* current_node = List;
            while (current_node->dr != NULL) current_node = current_node->dr;
            current_node->dr = new_node;
            new_node->st = current_node;
        }
    }
}

Sort::Sort(int nr, ...) {
    List = new(nod);
    va_list list;
    va_start(list, nr);
    List = NULL;
    for (int i = 0; i < nr; i++) {
        nod* new_node = new(nod);
        new_node->info = va_arg(list, int);
        new_node->st = NULL;
        new_node->dr = NULL;
        if (List == NULL)
            List = new_node;
        else {
            nod* current_node = List;
            while (current_node->dr != NULL) current_node = current_node->dr;
            current_node->dr = new_node;
            new_node->st = current_node;
        }
    }
    va_end(list);
}

Sort::Sort(char* string)
{
    char* ptr;
    int number, i;
    nod* new_node;
    nod* current_node;
    ptr = strtok(string, ",");
    List = new(nod);
    List = NULL;
    while (ptr != NULL) {
        number = 0;
        for (i = 0; i < strlen(ptr); i++) {
            number = number * 10 + ptr[i] - '0';
        }
        new_node = new(nod);
        new_node->info = number;
        new_node->st = NULL;
        new_node->dr = NULL;
        if (List == NULL)
            List = new_node;
        else {
            nod* current_node = List;
            while (current_node->dr != NULL) current_node = current_node->dr;
            current_node->dr = new_node;
            new_node->st = current_node;
        }
        ptr = strtok(NULL, ",");
    }
}

void Sort::BubbleSort(bool ascendent)
{
    int i, j, size = 0, aux;
    nod* current_node;
    current_node = List;
    while (current_node != NULL) {
        size++;
        current_node = current_node->dr;
    }
    for (i = 0; i < size - 1; i++) {
        current_node = List;
        for (j = 0; j < size - i - 1; j++) {
            if (current_node->info > current_node->dr->info) {
                aux = current_node->info;
                current_node->info = current_node->dr->info;
                current_node->dr->info = aux;
            }
            current_node = current_node->dr;
        }
    }
}

void Sort::Print()
{
    nod* current_node = List;
    while (current_node != NULL) {
        cout << current_node->info << ' ';
        current_node = current_node->dr;
    }
    cout << endl;
}

int Sort::GetElementsCount()
{
    nod* current_node = List;
    int size = 0;
    while (current_node != NULL) {
        size++;
        current_node = current_node->dr;
    }
    return size;
}

int Sort::GetElementFromIndex(int index)
{
    nod* current_node = List;
    int size;
    for (size = 0; size < index; size++)
        current_node = current_node->dr;
    return current_node->info;
}
