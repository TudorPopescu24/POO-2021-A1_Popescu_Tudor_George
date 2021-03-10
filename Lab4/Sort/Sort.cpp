#include "Sort.h"
#include <cstdlib>

Sort::Sort(int nr, int minim, int maxim) {
    List->st = nullptr;
    List->info = rand() % (maxim - minim + 1) + minim;
    for (int i = 1; i < nr; i++) {
        nod* new_node = new(nod);
        new_node->info = rand() % (maxim - minim + 1) + minim;
        new_node->st = List;
        new_node->dr = nullptr;
        List->dr = new_node;
    }
}

Sort::Sort(int a1, int a2, int a3, int a4, int a5) {
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
