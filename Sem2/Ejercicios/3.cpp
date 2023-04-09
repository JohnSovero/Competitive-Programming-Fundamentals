#include <bits/stdc++.h>
using namespace std;

// template <typename T>
void imprimir_recursivo(int arr[], int size)
{
    if (size == 0)
        return;
    cout << arr[0] << " ";
    imprimir_recursivo(arr + 1, size - 1);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int size = sizeof(arr) / sizeof(arr[0]);
    imprimir_recursivo(arr, size);
    return 0;
}