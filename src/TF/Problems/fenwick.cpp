#include <iostream>
#include <vector>

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
    vector<int> arreglo = {2, -10, 7, 5, -2};
    vector<int> arbol = construirArbol(arreglo);
    mostrar_arbol(arbol);

    // Actualizar el valor en el índice 3 a 10
    /* int indiceActualizacion = 3; // <--- el valor es -5
    int nuevoValor = 10;
    int diferencia = nuevoValor - arreglo[indiceActualizacion]; // 10 - (-5)
    arreglo[indiceActualizacion] = nuevoValor;                  // arreglo[3] = 10
    actualizar(arbol, indiceActualizacion + 1, diferencia);     // (arbol,4,15)
    mostrar_arbol(arbol); */

    // Obtener la suma acumulada en el rango [2, 6]
    int inicioRango = 3;
    int finRango = 3;
    cout << obtenerSuma(arbol, finRango + 1) << endl;
    cout << obtenerSuma(arbol, inicioRango) << endl;
    int sumaRango = obtenerSuma(arbol, finRango + 1) - obtenerSuma(arbol, inicioRango);
    cout << "La suma del rango [" << inicioRango << ", " << finRango << "] es: " << sumaRango << endl;

    return 0;
}
