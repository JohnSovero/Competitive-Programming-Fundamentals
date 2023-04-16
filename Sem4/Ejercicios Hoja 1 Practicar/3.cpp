#include <bits/stdc++.h>
using namespace std;

int main()
{
    double array[8] = {100.00, 50.00, 20.00, 10.00, 5.00, 2.00, 1.00, 0.50};
    int monedas[8];
    double n;
    cin >> n;
    while (n >= 0.50)
    {
        for (int i = 0; i < 8; i++)
        {
            monedas[i] = n / array[i];
            monedas[i] = ceil(monedas[i]);
            cout << monedas[i] << endl;
            n = n - (monedas[i] * array[i]);
            cout << "N: " << n << endl;
        }
    }
    cout << "NOTAS:" << endl;
    cout << fixed << setprecision(2);
    for (int i = 0; i < 6; i++)
    {
        cout << monedas[i] << " notas(s) de R$ " << array[i] << endl;
    }
    cout << "MONEDAS:" << endl;
    for (int i = 6; i < 8; i++)
    {
        cout << monedas[i] << " monedas de R$ " << array[i] << endl;
    }
    return 0;
}