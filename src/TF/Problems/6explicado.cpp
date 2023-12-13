#include <bits/stdc++.h>

#define ld long double
#define ll long long
#define F first
#define S second

using namespace std;

const int N = 3e5 + 10, M = 1e6 + 5;
int n, m, lst[N], fen[M], ans[N], L[M];
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

int calc(int ind)
{
    int res = 0;
    for (; ind > 0; ind -= (ind & (-ind)))
    {
        res += fen[ind];
    }
    return res;
}
void mostrar_arbol()
{
    for (int i = 0; i < 30; i++)
    {
        cout << fen[i] << " ";
    }
    cout << endl;
}

int main()
{
    // Obtenemos la cantidad de segmentos y querys
    cin >> n >> m;
    // Obtenemos la posicion mas hacia la izquierda y derecha de cada segmento
    for (int i = 1, l, r; i <= n; i++)
    {
        cin >> l >> r;
        // Guardamos en un arreglo de left
        L[l]++;
        // Guardamos en un arreglo de right
        R[r].push_back(l);
    }
    for (int i = 1, cnt; i <= m; i++)
    {
        // Obtenemos la cantidad de coordenadas a consultarse
        cin >> cnt;
        for (int j = 1, a; j <= cnt; j++)
        {
            // Para cada coordenada a consultarse guardamos en que numero de query se realizo
            cin >> a;
            p[a].push_back(i);
        }
    }

    mostrar_arbol();
    for (int i = 1; i < M; i++)
    {
        // Insertamos en el arbol de fenwick la posicion mas a la izquierda de cada segmento
        actualizar(i, L[i]);
        if (i < 10)
        {
            mostrar_arbol();
        }
        for (auto x : p[i])
        {

            cout << "I: " << i << endl;
            cout << "L[" << i << "]: " << L[i] << endl;
            cout << "X: " << x << endl;
            cout << "lst[x]: " << lst[x] << endl;
            cout << "ANS[" << x << "] = " << ans[x] + calc(i) - calc(lst[x]) << " = CALC(" << i << "): " << calc(i) << " - CALC(" << lst[x] << "): " << calc(lst[x]) << endl;
            ans[x] += calc(i) - calc(lst[x]);
            lst[x] = i;
        }
        // Si ya se consulto la posicion de la posicion mas a la derecha de un segmento, se elimina del arbol de fenwich
        for (auto x : R[i])
        {
            actualizar(x, -1);
            if (i < 10)
                        {
                            cout << "QUITANDO: ";
                            mostrar_arbol();
                        } 
        }
    }
    // Mostramos las respuestas para cada query
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << endl;
    }
}