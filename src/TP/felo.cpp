#include <iostream>
#include <set>

using namespace std;

int main()
{
    // Crear el conjunto de números
    set<int> numeros = {3, 5, 8, 1, 4, 6, 2, 7, 9};

    // Definir el valor k
    int k = 10;

    // Crear el conjunto de pares que suman k
    set<pair<int, int>> pares;

    // Recorrer el conjunto de números
    for (auto it = numeros.begin(); it != numeros.end(); ++it)
    {
        // Buscar el número complementario en el conjunto
        int complementario = k - *it;
        auto it_complementario = numeros.find(complementario);
        if (it_complementario != numeros.end())
        {
            // Se encontró el número complementario
            if (*it < complementario)
            {
                // Agregar el par al conjunto de pares
                pares.insert(make_pair(*it, complementario));
            }
            else
            {
                // Agregar el par al conjunto de pares
                pares.insert(make_pair(complementario, *it));
            }
        }
    }

    // Mostrar los pares que suman k
    cout << "Los pares que suman " << k << " son: " << endl;
    for (auto it = pares.begin(); it != pares.end(); ++it)
    {
        cout << "(" << it->first << ", " << it->second << ")" << endl;
    }
    return 0;
}