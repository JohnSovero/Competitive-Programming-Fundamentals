#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

// Función para obtener el siguiente índice
int obtenerSiguiente(int index)
{
    // index - LSB(index)
    return index + (index & -index); // obtener el bit menos significativo (LSB)
}

// Función para obtener el padre del índice
int obtenerPadre(int index)
{
    // index + LSB(index)
    return index - (index & -index); // obtener el padre de un nodo
}

// Función para actualizar el valor en un índice dado
void actualizar(vector<int> &arbol, int index, int valor)
{
    int tamano = arbol.size();
    while (index < tamano)
    {
        arbol[index] += valor;
        index = obtenerSiguiente(index);
    }
}

// Función para obtener la suma acumulada hasta un índice dado
int obtenerSuma(vector<int> &arbol, int index)
{
    int suma = 0;
    while (index > 0)
    {
        suma += arbol[index];
        index = obtenerPadre(index);
    }
    return suma;
}

// Función para construir el árbol de Fenwick a partir de un arreglo dado
vector<int> construirArbol(const vector<int> &arreglo)
{
    int tamano = arreglo.size();
    vector<int> arbol(tamano + 1, 0);
    for (int i = 0; i < tamano; i++)
    {
        actualizar(arbol, i + 1, arreglo[i]);
    }
    return arbol;
}

void mostrar_arbol(vector<int> &arbol)
{
    int i = 0;
    while (i < arbol.size())
    {
        cout << arbol[i] << " ";
        i++;
    }
    cout << endl;
}

int main()
{
    // srand(time(NULL));
    int n;
    cin >> n;
    vector<int> arreglo;
    for (int i = 0; i < n; i++)
    {
        int x;
        do
        {
            cin >> x;
        } while (x < 100 || x > 2500);
        arreglo.push_back(x);
    }
    vector<int> arbol = construirArbol(arreglo);
    cout << "Valores del arbol: ";
    mostrar_arbol(arbol);
    int q;
    cout << "Ingrese numero de consultas: ";
    cin >> q;

    while (q--)
    {
        char ope;

        do
        {
            cin >> ope;
            ope = tolower(ope);
        } while (ope != 'q' && ope != 'u');
        if (ope == 'q')
        {
            int l, r;
            cin >> l >> r;
            int sumaRango = obtenerSuma(arbol, r + 1) - obtenerSuma(arbol, l);
            cout << "La suma del rango [" << l << ", " << r << "] es: " << sumaRango << endl;
        }
        else if (ope == 'u')
        {
            int i, v;
            cin >> i >> v;
            int diferencia = v - arreglo[i];
            arreglo[i] = v;
            actualizar(arbol, i + 1, diferencia);
            cout << "Valores del arbol con valor actualizado: ";
            mostrar_arbol(arbol);
        }
    }
    return 0;
}