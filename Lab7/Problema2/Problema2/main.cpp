#include <iostream>
#include "Vector.h"

using namespace std;

bool esteMaiMare(char x, char y)
{
    return x > y;
}

bool esteEgal(char x, char y)
{
    return x == y;
}

int main()
{
    Vector<char> s(2);
    s.Push('A');
    s.Push('B');
    s.Push('C');
    s.Push('D');
    s.Push('E');
    s.Push('F');
    s.Pop();
    s.Pop();
    s.Print();
    s.Push('E');
    s.Push('F');
    s.Insert('Z', 2);
    s.Delete(4);
    s.Print();
    s.Push('F');
    s.Push('F');
    s.Print();
    cout << s.Count() << '\n';
    s.Push('F');
    s.Push('E');
    s.Push('A');
    s.Sort(esteMaiMare);
    s.Print();
    cout << s.firstIndexOf('F', esteEgal) << '\n';
}
