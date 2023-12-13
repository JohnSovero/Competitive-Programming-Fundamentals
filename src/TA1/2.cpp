#include <iostream>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

bool esPrimo(int x)
{
    if (x == 1)
        return false;
    int limite = sqrt(x);
    for (int i = 2; i <= limite; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
void recorrer_vector(map<int, int> &m, vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        int x = v[i];
        if (esPrimo(x))
            m[x]++;
    }
}
void hallar_numeros_primos_misma_frecuencia(vector<int> &v1, vector<int> &v2)
{
    map<int, int> m1;
    map<int, int> m2;
    recorrer_vector(m1, v1);
    recorrer_vector(m2, v2);
    for (auto i : m1)
        if (i.second == m2[i.first])
            cout << i.first << " ";
}
int main()
{
    int n, m;
    vector<int> v1, v2;
    do
    {
        cout << "Ingrese tamano V1: ";
        cin >> n;
    } while (n < 1 || n > 26);
    do
    {
        cout << "Ingrese tamano V2: ";
        cin >> m;
    } while (m < 1 || m > 26);
    cout << "V1: " << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        do
        {
            cin >> x;
        } while (x <= 0);
        v1.push_back(x);
    }
    cout << "V2: " << endl;
    for (int i = 0; i < m; i++)
    {
        int x;
        do
        {
            cin >> x;
        } while (x <= 0);
        v2.push_back(x);
    }
    hallar_numeros_primos_misma_frecuencia(v1, v2);
    return 0;
}