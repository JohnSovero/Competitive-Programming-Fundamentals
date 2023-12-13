#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10, M = 1e6 + 5;
int lst[N], fen[M], ans[N], L[M];
vector<int> R[M], p[M];

int obtenerSiguiente(int index)
{
    // index - LSB(index)
    return index + (index & -index); // obtener el bit menos significativo (LSB)
}

void actualizar(int index, int val)
{
    while (index < M)
    {
        fen[index] += val;
        index = obtenerSiguiente(index);
    }
}


int obtenerSuma(int ind)
{
    int res = 0;
    for (; ind > 0; ind -= (ind & (-ind)))
    {
        res += fen[ind];
    }
    return res;
}

int main()
{
    // Para optimizar la entrada de variables
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    // Obtenemos la cantidad de segmentos y querys
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        // Obtenemos la posicion mas hacia la izquierda y derecha de cada segmento
        int l, r;
        cin >> l >> r;
        // Aumentamos en 1 la posición mas hacia la izquierda del segmento en un arreglo
        L[l]++;
        // Insertamos en la posicion mas hacia la derecha del segmento, el valor de la posición mas hacia la izquierda del segmento
        R[r].push_back(l);
    }
    for (int i = 1; i <= m; i++)
    {
        // Obtenemos la cantidad de coordenadas a consultarse
        int cnt;
        cin >> cnt;
        for (int j = 1, a; j <= cnt; j++)
        {
            // Para cada coordenada a consultarse guardamos en un arreglo el numero de query en el que se realizó
            cin >> a;
            p[a].push_back(i);
        }
    }

    for (int i = 1; i < M; i++)
    {
        // Insertamos en el arbol de fenwick la posicion mas hacia la izquierda de cada segmento, en caso no exista se inserta 0
        actualizar(i, L[i]);

        for (auto x : p[i])
        {
            // Aumentamos a un arreglo de respuestas la cantidad de veces que la coordenada está en el rango de los segmentos
            ans[x] += obtenerSuma(i) - obtenerSuma(lst[x]);
            // Guardamos la mayor coordenada consultada hasta el momennto que está en uno de los segmentos, para evitar que se repita en un segmento ya consultado
            lst[x] = i;
        }
        // Si ya se consutó la posición mas a la derecha de un segmento, se elimina del arbol de fenwick este segmento
        for (auto x : R[i])
        {
            actualizar(x, -1);
        }
    }
    // Mostramos las respuestas para cada query
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << endl;
    }
}