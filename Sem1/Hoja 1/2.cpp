#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin >> x;
    int aux = x / 100;
    cout << x / 1000 << "+" << aux % 10 << "+" << x % 100 << "\n";
    cout << x / 1000 + aux % 10 + x % 100;
    return 0;
}