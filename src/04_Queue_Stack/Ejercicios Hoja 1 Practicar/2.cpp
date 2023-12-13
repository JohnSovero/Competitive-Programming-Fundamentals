#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Nodo
{
private:
    T valor;
    Nodo *sig;

public:
    Nodo(T v, Nodo *sig)
    {
        valor = v;
        sig = sig;
    }
    T getValor() { return valor; }
    Nodo *getSiguiente() { return sig; }
    Nodo *setSiguiente(Nodo *sig)
    {
        sig = sig;
    }
};

template <typename G>
class Pila
{
private:
    Nodo<G> *tope;

public:
    Pila() { tope = NULL; }
    void push(G v)
    {
        Nodo<G> *n = new Nodo<G>(v, tope);
        tope = n;
    }
    G pop()
    {
        if (tope == NULL)
            return 0;
        G n = tope->getValor();
        tope = tope->getSiguiente();
        return n;
    }
    void mostrar()
    {
        Nodo<G> *aux = tope;
        while (aux != NULL)
        {
            cout << aux->getValor() << " ";
            aux = aux->getSiguiente();
        }
    }
    bool isEmpty()
    {
        if (tope == NULL)
            return 1;
        else
            return 0;
    }
};

int main()
{
    int n = 100;
    int arr[n];
    do
    {
        cout << "Ingrese la cantidad de elementos: ";
        cin >> n;
    } while (n < 1 || n > 45);
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            arr[0] = 0;
        else if (i == 1)
            arr[1] = 1;
        else
        {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}