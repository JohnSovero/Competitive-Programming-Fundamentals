#include <bits/stdc++.h>
using namespace std;

int main()
{
    const int n = 5;
    float a[5];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << fixed << setprecision(1);
    for (int i = 0; i < n; i++)
    {
        cout << "A[" << i << "] = " << a[i] << endl;
    }
    return 0;
}