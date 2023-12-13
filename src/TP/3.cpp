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

void KMPsearch(string text, string pattern)
{
    int cant_apariciones = 0;
    int n = text.length();
    int m = pattern.length();
    vector<int> pi = KMPpreprocess(pattern);
    cout << endl;
    int j = 0;
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
            cout << "Patron encontrado en el indice: " << i - m + 1 << endl;
            j = pi[j - 1];
            int first_pos = i - m + 1;
            int last_pos = i + 1;
            text.erase(text.begin() + first_pos, text.begin() + last_pos);
            cout << "Nuevo texto: " << text << endl;
            cant_apariciones++;
        }
    }
    if (cant_apariciones > 3)
    {
        cout << "El patron es muy frecuente en el texto" << endl;
    }
    else if (cant_apariciones == 0)
    {
        cout << "No encontro patron" << endl;
    }
}

int main()
{
    srand(time(NULL));
    int t;
    cout << "Ingrese el numero de casos de prueba: ";
    do
    {
        cin >> t;
    } while (t <= 1 || t >= 10000);
    while (t--)
    {
        string text, pattern;
        int tamano_text = 60, tamano_pattern = 3;
        for (int i = 0; i < tamano_text; i++)
        {
            text.push_back(rand() % 26 + 97);
        }
        for (int i = 0; i < tamano_pattern; i++)
        {
            pattern.push_back(rand() % 26 + 97);
        }
        cout << endl;
        cout << "Texto: " << text << endl;
        cout << "Patron: " << pattern << endl;
        KMPsearch(text, pattern);
    }
    return 0;
}