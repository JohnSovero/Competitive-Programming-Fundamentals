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
class Cola
{
private:
    Nodo<G> *inicio;
    Nodo<G> *fin;

public:
    Cola() { inicio = NULL, fin = NULL; }
    void push(G v)
    {
        Nodo<G> *aux = new Nodo<G>(v, NULL);
        if (isEmpty())
        {
            inicio = aux;
            fin = aux;
        }
        else
        {
            fin->setSiguiente(aux);
            fin = aux;
        }
    }
    G pop()
    {
        if (inicio == NULL)
            return 0;
        G valor = inicio->getValor();
        inicio = inicio->getSiguiente();
        return valor;
    }
    void mostrarTodo()
    {
        Nodo<G> *aux = inicio;
        while (aux != NULL)
        {
            cout << aux->getValor() << " ";
            aux = aux->getSiguiente();
        }
    }
    bool isEmpty()
    {
        if (inicio == NULL)
            return 1;
        else
            return 0;
    }
};

Cola<int> crearColaMultiplicada(Cola<int> &a, Cola<int> &b)
{
    Cola<int> cola_resultado;
    while (!(a.isEmpty()))
    {
        int aux = a.pop() * b.pop();
        cola_resultado.push(aux);
    }
    return cola_resultado;
}
int main()
{
    Cola<int> cola_A, cola_B;
    cola_A.push(2);
    cola_A.push(5);
    cola_A.push(5);
    cola_A.push(6);

    cola_B.push(3);
    cola_B.push(2);
    cola_B.push(4);
    cola_B.push(3);

    Cola<int> nueva = crearColaMultiplicada(cola_A, cola_B);
    nueva.mostrarTodo();

    return 0;
}
