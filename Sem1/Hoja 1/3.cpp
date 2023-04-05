#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[3];
    int div, res = 0;
    for (int i = 0; i < 3; i++)
    {
        do
        {
            cin >> a[i];
        } while (a[i] < 1);
    }
    cin >> div;
    for (int i = 0; i < 3; i++)
    {
        res += a[i] % div;
    }
    cout << "Respuesta " << res << "\n";
    return 0;
}