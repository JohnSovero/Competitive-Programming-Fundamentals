#include <iostream>
using namespace std;

void binario(int n)
{
    if (n <= 0) return;
    if (n & 1)
    {
        binario(n >> 1);
        cout << 1;
    }
    else
    {
        binario(n >> 1);
        cout << 0;
    }
}
int main()
{
    int n;
    cin >> n;
    binario(n);
    return 0;
}