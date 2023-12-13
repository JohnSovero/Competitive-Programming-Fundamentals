#include <iostream>
using namespace std;

int sumar_n_naturales(int n)
{
    if (n == 0)
        return 0;
    return n + sumar_n_naturales(n - 1);
}
int main()
{
    int n, res;
    cin >> n;
    res = sumar_n_naturales(n);
    cout << res << endl;
    return 0;
}