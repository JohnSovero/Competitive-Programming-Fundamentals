#include <bits/stdc++.h>
using namespace std;

double hallar_potencia(int base, int exp)
{
    if (exp == 0) return 1;
    else if (exp < 0) return 1 / hallar_potencia(base, -exp);
    else return base * hallar_potencia(base, exp - 1);
}
int main()
{
    double base;
    int exp;
    cin >> base >> exp;
    double result = hallar_potencia(base, exp);
    cout<<result<<endl;
    return 0;
}