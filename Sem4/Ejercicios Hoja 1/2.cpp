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
    Cola() { inicio = NULL; }
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
int main()
{
    Cola<int> cola;
    cola.push(20);
    cola.push(10);
    cola.push(15);
    cola.push(16);
    cola.push(17);
    cola.mostrarTodo();
    cout << endl;
    cout << cola.isEmpty() << endl;
    cola.pop();
    cola.pop();
    cola.mostrarTodo();
    cola.pop();
    cola.pop();
    cout << cola.isEmpty() << endl;
    return 0;
}