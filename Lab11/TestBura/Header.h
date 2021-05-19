#pragma once
#include<iostream>

template <class T>
void selectionSort(T a[], int n) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                int aux = a[j];
                a[j] = a[min];
                a[min] = aux;
                min = j;
            }
        }
    }
}
