#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool comparacion(pair<string, int> p1, pair<string, int> p2)
{
    return (p1.second > p2.second);
}

int main()
{
    int c;
    vector<pair<string, int>> numeros_candidatos;
    do
    {
        cout << "Ingresar numeros de candidatos: ";
        cin >> c;
    } while (c < 0 || c > 30);
    for (int i = 0; i < c; i++)
    {
        string nombre_producto;
        int numero_compras;
        cin >> nombre_producto >> numero_compras;
        numeros_candidatos.push_back(make_pair(nombre_producto, numero_compras));
    }
    for (auto i : numeros_candidatos)
        cout << i.first << " - " << i.second << endl;
    cout << endl;
    sort(numeros_candidatos.begin(), numeros_candidatos.end(), comparacion);
    if (c < 2)
        cout << " ";
    else
    {
        for (int i = 0; i < 2; i++)
            cout << numeros_candidatos[i].first << " - " << numeros_candidatos[i].second << endl;
    }
    cout << endl;
    cout << numeros_candidatos[0].first << " - " << numeros_candidatos[0].second << " - "
         << "Producto mas vendido" << endl;
    return 0;
}