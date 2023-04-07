#include <bits/stdc++.h>
using namespace std;

void print_numbers(int n)
{
    if (n > 0)
    {
        print_numbers(n - 1);
        cout << n;
    }
}

void print_pattern(int n)
{
    if (n > 1)
    {
        print_pattern(n - 1);
    }
    print_numbers(n);
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    print_pattern(n);
    return 0;
}