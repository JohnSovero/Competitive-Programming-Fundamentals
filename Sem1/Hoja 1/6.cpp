#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[3];
    for (int i = 0; i < 3; i++)
    {
        do
        {
            cin >> a[i];
        } while (a[i] < 1);
    }
    int r1 = a[0] % a[1];
    int r2 = a[2] % a[0];
    cout << a[1] % r2;

    return 0;
}