#include <iostream>
using namespace std;

template <typename T>
T sumaRecursiva(T lista[], int size)
{
    if (size == 0)
    {
        return 0;
    }
    return lista[size - 1] + sumaRecursiva(lista, size - 1);
}
int main()
{
    int l1[] = {1, 2, 3, 4};
    float l2[] = {1.3, 2.1, 3.5, 4.3};
    int n = sizeof(l1) / sizeof(l1[0]);

    int sum1 = sumaRecursiva<int>(l1, n);
    float sum2 = sumaRecursiva<float>(l2, n);
    cout << sum1 << endl;
    cout << sum2 << endl;
    return 0;
}