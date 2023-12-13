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
    int aprobados, desaprobados;

public:
    Cola() { inicio = NULL, fin = NULL, aprobados = 0, desaprobados = 0; }
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
    void contarNotas()
    {
        Nodo<G> *aux = inicio;
        while (aux != NULL)
        {
            if (aux->getValor() > 13)
            {
                aprobados++;
            }
            else
            {
                desaprobados++;
            }
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
    int returnAprobados() { return aprobados; }
    int returnDesaprobados() { return desaprobados; }
};

int main()
{
    Cola<int> notas_estudiantes;
    for (int i = 1; i < 16; i++)
    {
        notas_estudiantes.push(i * rand() % 10 + rand() % 10);
    }
    notas_estudiantes.mostrarTodo();
    cout << endl;
    notas_estudiantes.contarNotas();
    cout << "Aprobados: " << notas_estudiantes.returnAprobados() << endl;
    cout << "Desaprobados: " << notas_estudiantes.returnDesaprobados() << endl;

    return 0;
}