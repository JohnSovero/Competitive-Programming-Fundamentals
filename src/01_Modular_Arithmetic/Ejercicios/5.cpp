#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n1, n2, r1, r2;
    cin >> n1 >> n2;
    r1 = pow(3, n1);
    r2 = pow(3, n2);
    cout << r1 % 100 + r2 % 100;
    return 0;
}