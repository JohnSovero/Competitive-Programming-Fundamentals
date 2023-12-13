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

// Función que implementa el algoritmo de Dijkstra
void dijkstra(const vector<vector<pair<int, int>>> &grafo, int origen, vector<int> &distancias)
{
    int n = grafo.size();

    // Inicializar todas las distancias como infinito
    distancias.assign(n, numeric_limits<int>::max());

    // Cola de prioridad para seleccionar el siguiente nodo con la menor distancia
    priority_queue<Nodo> cola;

    // Insertar el nodo de origen en la cola
    cola.push({origen, 0});
    distancias[origen] = 0;

    while (!cola.empty())
    {
        // Obtener el nodo con la menor distancia de la cola
        Nodo nodoActual = cola.top();
        cola.pop();

        int u = nodoActual.indice;
        int distanciaActual = nodoActual.distancia;

        // Si la distancia actual es mayor que la distancia almacenada, ignorar este nodo
        if (distanciaActual > distancias[u])
        {
            continue;
        }

        // Recorrer los vecinos del nodo actual
        for (const auto &vecino : grafo[u])
        {
            int v = vecino.first;
            int peso = vecino.second;

            // Calcular la distancia acumulada hasta el vecino
            int distanciaNueva = distanciaActual + peso;

            // Si la distancia acumulada es menor que la distancia almacenada, actualizarla
            if (distanciaNueva < distancias[v])
            {
                distancias[v] = distanciaNueva;
                cola.push({v, distanciaNueva});
            }
        }
    }
}

// Función auxiliar para agregar una arista a un grafo no dirigido
void agregarArista(vector<vector<pair<int, int>>> &grafo, int u, int v, int peso)
{
    grafo[u].push_back({v, peso});
    grafo[v].push_back({u, peso});
}

int main()
{
    int n = 6; // Cantidad de nodos en el grafo

    // Crear el grafo
    vector<vector<pair<int, int>>> grafo(n);

    // Agregar las aristas del grafo
    agregarArista(grafo, 0, 1, 2);
    agregarArista(grafo, 0, 2, 5);
    agregarArista(grafo, 1, 2, 1);
    agregarArista(grafo, 1, 3, 6);
    agregarArista(grafo, 2, 3, 3);
    agregarArista(grafo, 2, 4, 8);
    agregarArista(grafo, 3, 4, 2);
    agregarArista(grafo, 3, 5, 7);
    agregarArista(grafo, 4, 5, 4);

    int origen = 0; // Nodo de origen para el algoritmo

    // Vector para almacenar las distancias desde el origen a cada nodo
    vector<int> distancias;

    // Aplicar el algoritmo de Dijkstra
    dijkstra(grafo, origen, distancias);

    // Imprimir las distancias desde el origen a cada nodo
    cout << "Distancias desde el nodo " << origen << ":\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Nodo " << i << ": " << distancias[i] << endl;
    }

    return 0;
}
