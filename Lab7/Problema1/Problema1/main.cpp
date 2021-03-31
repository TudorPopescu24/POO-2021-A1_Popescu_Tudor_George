#include <iostream>

using namespace std;

float operator"" _Kelvin(unsigned long long int x) {
    float value = 0;
    value = value + x - 273.15;
    return value;
}

float operator"" _Fahrenheit(unsigned long long int x) {
    float value = 0;
    value = value + (x - 32) / 1.8;
    return value;
}

int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    cout << a << ' ' << b;
    return 0;
}
