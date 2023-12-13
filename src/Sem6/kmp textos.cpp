#include <iostream>
#include <string>
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
    int n = text.length();
    int m = pattern.length();
    vector<int> pi = KMPpreprocess(pattern);
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
            cout << "Patrón encontrado en el indice: " << i - m + 1 << endl;
            j = pi[j - 1];
        }
    }
}

int main()
{
    string text = "El curso de FPC esta genial. FPC es mejor que fisica";
    string pattern = "FPC";
    KMPsearch(text, pattern);
    return 0;
}
