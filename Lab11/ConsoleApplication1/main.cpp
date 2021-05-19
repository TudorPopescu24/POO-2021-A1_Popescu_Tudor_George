#include <iostream>
#include "InsertionSort.h"

using namespace std;

int main()
{
    //Exemplu de utilizare functie InsertionSort
    int v[] = { 2, 10, 1, 5, 16 };
    insertionSort(v, size(v));
    for (int i = 0; i < size(v); i++)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}
