#include <iostream>
#include <vector>
using namespace std;

vector<int> KMPpreprocess(string pattern)
{
    int m = pattern.length();
    vector<int> pi(m);
    pi[0] = 0;
    int j = 0;
    for (int i = 1; i < m; i++)
    {
        while (j > 0 && pattern[j] != pattern[i])
        {
            j = pi[j - 1];
        }
        if (pattern[j] == pattern[i])
        {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

void KMPsearch(string text, string pattern, vector<int> &cantidad)
{
    int cant_apariciones = 0;
    int n = text.length();
    int m = pattern.length();
    vector<int> pi = KMPpreprocess(pattern);
    int j = 0;
    vector<int> first_pos;
    for (int i = 0; i < n; i++)
    {
        while (j > 0 && pattern[j] != text[i])
        {
            j = pi[j - 1];
        }
        if (pattern[j] == text[i])
        {
            j++;
        }
        if (j == m)
        {
            j = pi[j - 1];
            first_pos.push_back(i - m + 1);
            cant_apariciones++;
        }
    }
    cout << "Cantidad de apariciones: " << cant_apariciones << endl;
    cantidad.push_back(cant_apariciones);
    for (int i = 0; i < first_pos.size(); i++)
    {
        cout << "Indice: " << first_pos[i] + 1 << endl;
    }
    if (cant_apariciones > 5)
    {
        cout << "La cadena tiene varios patrones" << endl;
    }
    if (!first_pos.empty())
    {
        text.replace(first_pos[0], 4, "BBBB");
        text.replace(first_pos[first_pos.size() - 1], 4, "BBBB");
        cout << "Cadena modificada: " << endl;
        cout << text << endl;
    }
}

int main()
{
    srand(time(NULL));
    int n;
    do
    {
        cout << "Ingresar numero de simulaciones:" << endl;
        cin >> n;
    } while (n <= 0 || n >= 100);
    vector<int> cant_genes_totales;
    while (n--)
    {
        int c;
        do
        {
            cout << "Ingresar cantidad de elementos en la cadena:" << endl;
            cin >> c;
        } while (c <= 50 || c >= 10000);
        vector<char> caracteres = {'G', 'A', 'H', 'M', 'O'};
        string cadena;
        for (int i = 0; i < c; i++)
        {
            int random = rand() % 5;
            cadena.push_back(caracteres[random]);
        }
        cout << "Cadena: " << endl;
        cout << cadena << endl;
        string gen;
        for (int i = 0; i < 4; i++)
        {
            int random;
            if (i == 0)
            {
                do
                {
                    random = rand() % 5;
                } while (random != 1 && random != 4);
            }
            else
            {
                random = rand() % 5;
            }
            gen.push_back(caracteres[random]);
        }
        cout << "Gen: " << gen << endl;
        KMPsearch(cadena, gen, cant_genes_totales);
        cout << endl;
    }
    int total = 0;
    int menor = INT_MAX;
    int pos;
    for (auto i : cant_genes_totales)
        cout << i << " ";
    cout << endl;
    for (int i = 0; i < cant_genes_totales.size(); i++)
    {
        total += cant_genes_totales[i];
        if (cant_genes_totales[i] < menor)
        {
            menor = cant_genes_totales[i];
            pos = i;
        }
    }
    cout << "Cantidad de veces que aparecieron los genes en las cadenas: " << total << endl;
    cout << "En la simulacion " << pos + 1 << " se encontraron menos genes.";
    return 0;
}