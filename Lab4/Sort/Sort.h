#pragma once

struct nod {
    nod* st;
    nod* dr;
    int info;
};

class Sort
{
    nod* List;
public:
    Sort(int nr, int minim, int maxim);
    Sort(int a1, int a2, int a3, int a4, int a5);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};