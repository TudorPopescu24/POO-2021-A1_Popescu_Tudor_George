#include "Map.h"

using namespace std;

int main()
{
    Map<int, const char*> m;
    Map<int, const char*> n;
    Map<int, const char*> o;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    n[20] = "exercitiu";
    o[15] = "problema";
    cout << m.Includes(n) << endl;
    cout << m.Includes(o) << endl;
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m.Set(10, "Java");
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    const char* value;
    m.Get(30, value);
    cout << value << endl;
    cout << m.Count() << endl;
    m.Delete(10);
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    return 0;

}