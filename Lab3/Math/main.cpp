#include "Math.h"
#include <iostream>

using namespace std;

int main() {
	Math m;
    cout << m.Add(10, 20) << '\n';
    cout << m.Add(15, 100, 34) << '\n';
    cout << m.Add(1.15, 2.34) << '\n';
    cout << m.Add(100.13, 23.6, 15.67) << '\n';
    cout << m.Mul(10, 20) << '\n';
    cout << m.Mul(15, 2, 6) << '\n';
    cout << m.Mul(2.5, 13.6) << '\n';
    cout << m.Mul(1.7, 2.15, 5.9) << '\n';
    cout << m.Add(5, 10, 20, 30, 40, 50) << '\n';
    cout << m.Add("Hello, ", "World!") << '\n';

    return 0;
}