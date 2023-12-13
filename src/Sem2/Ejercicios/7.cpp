#include <iostream>
using namespace std;

void imprimir_fila(int base)
{
    if (base == 0)
        return;
    cout << "*";
    imprimir_fila(base - 1);
}
void imprimir_rectangulo(int base, int altura)
{
    if (altura == 0)
        return;
    else
    {
        imprimir_fila(base);
        cout << endl;
        imprimir_rectangulo(base, altura - 1);
    }
}
int main()
{
    int base, altura;
    cin >> base >> altura;
    imprimir_rectangulo(base, altura);
    return 0;
}