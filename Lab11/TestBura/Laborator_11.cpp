#include "Header.h"
#include <iostream>
using namespace std;


int main () {
    int x[] = {1,3,3,2};
    selectionSort(x, 4);
    for (int i = 0; i < 4; i++)
        cout << x[i] << " ";
}
