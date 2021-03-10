#include "Sort.h"
#include <cstdlib>
#include <time.h>
#include <stdarg.h>

Sort::Sort(int nr, int minim, int maxim) {
    List = new(nod);
    List->st = NULL;
    srand(time(NULL));
    List->info = rand() % (maxim - minim + 1) + minim;
    for (int i = 1; i < nr; i++) {
        nod* new_node = new(nod);
        srand(time(NULL));
        new_node->info = rand() % (maxim - minim + 1) + minim;
        new_node->st = List;
        new_node->dr = NULL;
        List->dr = new_node;
    }
}

Sort::Sort(int a1, int a2, int a3, int a4, int a5) {
    List = new(nod);
    List->st = nullptr;
    List->info = a1;
    nod* new_node;

    new_node = new(nod);
    new_node->info = a2;
    new_node->st = List;
    new_node->dr = nullptr;
    List->dr = new_node;

    new_node = new(nod);
    new_node->info = a3;
    new_node->st = List;
    new_node->dr = nullptr;
    List->dr = new_node;

    new_node = new(nod);
    new_node->info = a4;
    new_node->st = List;
    new_node->dr = nullptr;
    List->dr = new_node;

    new_node = new(nod);
    new_node->info = a5;
    new_node->st = List;
    new_node->dr = nullptr;
    List->dr = new_node;
}

Sort::Sort(int nr, int v[]) {
    List = new(nod);
    List->st = nullptr;
    List->info = v[0];
    for (int i = 1; i < nr; i++) {
        nod* new_node = new(nod);
        new_node->info = v[i];
        new_node->st = List;
        new_node->dr = nullptr;
        List->dr = new_node;
    }
}

Sort::Sort(int nr, ...) {
    List = new(nod);
    va_list list;
    va_start(list, nr);
    List->st = NULL;
    List->info = va_arg(list, int);;
    for (int i = 1; i < nr; i++) {
        nod* new_node = new(nod);
        new_node->info = va_arg(list, int);
        new_node->st = List;
        new_node->dr = nullptr;
        List->dr = new_node;
    }
    va_end(list);
}