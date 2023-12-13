#include <iostream>
#include <cstdio>
#include <set>

using namespace std;
int n, m, q, len, sum;
set<int> pos;

int main()
{
    cin >> n >> m >> len >> q;
    pos.insert(0);
    pos.insert(n + 1);
    // cantidad de barcos máximos que entran en el tablero
    sum = (n + 1) / (len + 1);

    for (int i = 1; i <= q; ++i)
    {
        int x, l, r;
        cin >> x;
        // Si la bala actual ya existe, continua a la siguiente iteracion
        if (pos.find(x) != pos.end())
            continue;
        // Se obtiene la posicion de la bala mas cercana por encima de la actual
        auto it = pos.upper_bound(x);
        // Se obtiene la posicion de la bala mas cercana por debajo de la actual
        l = *prev(it);
        r = *it;
        // Restamos a la cantidad de barcos maximos los barcos que entran fuera de los lugares donde cayeron las balas
        sum -= (r - l) / (len + 1);
        // Sumamos la cantidad de barcos que entran en el rango entre la bala minima - actual y bala actual - maxima
        sum += (x - l) / (len + 1) + (r - x) / (len + 1);
        // Insertamos la posicion de la bala actual, se usa set en caso se dispare a la misma posicion varias veces
        pos.insert(x);
        // Si sum es menor que la cantidad de barcos maximos que deberian entrar en el tablero, se hizo trampa
        if (sum < m)
        {
            cout << i << '\n';
            return 0;
        }
    }
    // No se hizo trampa
    cout << "-1\n";
    return 0;
}