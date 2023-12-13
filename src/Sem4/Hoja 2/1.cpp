#include <bits/stdc++.h>
using namespace std;

void modificarLista(int l1[], int l2[], int &t1, int &t2)
{
    int pos = 0;
    for (int i = 0; i < t1; i++)
    {
        bool encontrado = false;
        for (int j = 0; j < t2 && !encontrado; j++)
        {
            if (l1[i] == l2[j])
                encontrado = true;
        }
        if (!encontrado)
            l1[pos++] = l1[i];
    }
    t1 = pos;
}

int main()
{
    int l1[] = {1, 2, 3, 4};
    int l2[] = {7, 1, 2, 8};
    int tamanoL1 = sizeof(l1) / sizeof(l1[0]);
    int tamanoL2 = sizeof(l2) / sizeof(l2[0]);
    modificarLista(l1, l2, tamanoL1, tamanoL2);
    for (int i = 0; i < tamanoL1; i++)
        cout << l1[i] << " ";
    return 0;
}