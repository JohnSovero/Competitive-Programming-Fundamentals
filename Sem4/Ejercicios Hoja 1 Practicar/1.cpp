#include <bits/stdc++.h>
using namespace std;

int main()
{
    string vendedor;
    double salario, ventas;
    cin >> vendedor;
    cin >> salario;
    cin >> ventas;
    cout << "TOTAL = R$" << salario + ventas * 0.15;
    return 0;
}