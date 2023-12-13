#include <iostream>
using namespace std;

void showDigits(int n)
{
    if (n < 10)
    {
        cout << n << endl;
    }
    else
    {
        showDigits(n / 10);
        cout << n % 10 << endl;
    }
}
int main()
{
    int n;
    do
    {
        cout << "Ingrese un número entero de 4 cifras: ";
        cin >> n;
    } while (n < 1000 || n > 9999);
    showDigits(n);
    return 0;
}