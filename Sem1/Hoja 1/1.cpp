#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[4];
    for (int i = 0; i < 4; i++)
    {
        cin >> a[i];
    }
    cout << sizeof(a) << " " << sizeof(a[0]);
    sort(a, a + 4, greater<int>());
    for (int i = 0; i < 4; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}