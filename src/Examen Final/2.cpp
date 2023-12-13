#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

// Estructura para representar un nodo y su distancia desde el origen
struct Nodo
{
    int indice;
    int distancia;

    bool operator<(const Nodo &otro) const
    {
        return distancia > otro.distancia;
    }
};

// Función auxiliar para agregar una arista a un grafo no dirigido
void agregarArista(vector<vector<pair<int, int>>> &grafo, int u, int v, int peso)
{
    grafo[u].push_back({v, peso});
    grafo[v].push_back({u, peso});
}

int sumarPesosRango(vector<vector<pair<int, int>>> &grafo, int inicio, int fin)
{
    int pesoTotal = 0;
    for (int i = inicio; i < fin; i++)
    {
        for (int j = 0; j < grafo[i].size(); j++)
        {
            int v = grafo[i][j].first;
            int peso = grafo[i][j].second;
            // Validacion para suma los vertices y que esten en el rango
            if (v >= inicio && v <= fin && i < v)
            {
                pesoTotal += peso;
            }
        }
    }
    return pesoTotal;
}

int multiplicarPesosRango(vector<vector<pair<int, int>>> &grafo, int inicio, int fin)
{
    int pesoTotal = 0;
    for (int i = inicio; i < fin; i++)
    {
        for (int j = 0; j < grafo[i].size(); j++)
        {
            int v = grafo[i][j].first;
            int peso = grafo[i][j].second;
            // Validacion para multiplicar los vertices y que esten en el rango
            if (v >= inicio && v <= fin && i < v)
            {
                if (pesoTotal == 0)
                {
                    pesoTotal += peso;
                }
                else
                {
                    pesoTotal *= peso;
                }
            }
        }
    }
    return pesoTotal;
}

vector<int> menorPeso(vector<vector<pair<int, int>>> &grafo)
{
    int pesoMenor = 1000;
    vector<int> verticesPeso;
    for (int i = 0; i < grafo.size(); i++)
    {
        for (int j = 0; j < grafo[i].size(); j++)
        {
            int v = grafo[i][j].first;
            int peso = grafo[i][j].second;
            // Validacion para que no se repita un vertice desde el otro nodo
            if (i < v)
            {
                if (peso < pesoMenor)
                {
                    pesoMenor = peso;
                    verticesPeso = {i, v, peso};
                }
            }
        }
    }
    return verticesPeso;
}

int main()
{
    // Cantidad de nodos en el grafo
    int n = 3;
    // Crear el grafo
    vector<vector<pair<int, int>>> grafo(n);

    // Agregar las aristas al grafo
    for (int i = 0; i < n; i++)
    {
        int v1, v2, peso;
        cin >> v1 >> v2;
        // Validacion que este en el rango del 1-100
        do
        {
            cin >> peso;
        } while (peso < 1 || peso > 100);
        agregarArista(grafo, v1, v2, peso);
    }
    char letra;
    cout << "Ingrese una operacion:" << endl;
    do
    {
        cin >> letra;
    } while (letra != 's' && letra != 'm' && letra != 'c');
    if (letra == 's')
    {
        int inicio, fin;
        cin >> inicio >> fin;
        cout << "Peso Total sumado basado en rango es: " << sumarPesosRango(grafo, inicio, fin) << endl;
    }
    else if (letra == 'm')
    {
        int inicio, fin;
        cin >> inicio >> fin;
        cout << "Pesos Total multiplicado basado en rango es: " << multiplicarPesosRango(grafo, inicio, fin) << endl;
    }
    else if (letra == 'c')
    {
        vector<int> verticesMenorPeso = menorPeso(grafo);
        cout << "Los vertices con menor peso son : (" << verticesMenorPeso[0] << "," << verticesMenorPeso[1] << ") y el peso es " << verticesMenorPeso[2] << endl;
    }
}