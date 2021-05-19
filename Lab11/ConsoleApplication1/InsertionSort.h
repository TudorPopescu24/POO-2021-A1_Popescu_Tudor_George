#include <iostream>

template <class T>
void insertionSort(T arr[], int n)
{
    int i, key, j;
    for (i = 0; i < n - 1; i++)
    {
        if (arr[i] == 0)
            key = arr[i - 1];
        else if (arr[i] < 0)
            key = 0;
        else
            key = arr[i];
        j = i - 1;
        while (arr[j] >= key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

template <>
void insertionSort(double arr[], int n)
{
    int i, key, j;
    for (i = 0; i < n - 1; i++)
    {
        if (arr[i] == 0)
            key = arr[i - 1];
        else if (arr[i] < 0)
            key = 0;
        else
            key = arr[i];
        j = i - 1;
        while (arr[j] <= key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
