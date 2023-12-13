#include <iostream>
#include <map>
typedef long long ll;
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        m[x]++;
    }
    ll sum = 0;
    for (auto i : m)
    {
        if (i.second > i.first)
        {
            sum += i.second - i.first;
        }
        else if (i.first > i.second)
        {
            sum += i.second;
        }
    }
    cout << sum;
    return 0;
}