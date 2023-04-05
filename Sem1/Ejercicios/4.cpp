#include <bits/stdc++.h>
using namespace std;

//  2^0 = 1
//  2^1 = 2
//  2^2 = 4
//  2^3 = 8
//  2^4 = 16

//  2^5 = 32
//  2^6 = 64
//  2^7 = 128
//  2^8 = 256

//  2^9 = 512
//  2^10 = 1024
//  2^11 = 2048
//  2^12 = 4096

int LD(int n)
{
    if (n == 0)
        return 1;
    if (n % 4 == 0)
        return 6;
    if (n % 2 == 0)
        return 4;
    if (n % 2 == 1)
        return 8;
    else
        return 2;
}
int main()
{
    int exp, resultado = 1;
    cin >> exp;
    for (int i = 0; i < exp; i++)
    {
        resultado = resultado * 2;
    };
    cout << resultado % 10;

    return 0;
}