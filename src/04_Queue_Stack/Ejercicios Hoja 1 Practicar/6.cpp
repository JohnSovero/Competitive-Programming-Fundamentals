#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Nodo
{
public:
    T elemento;
    Nodo *sig;
    Nodo(T elemento, Nodo *sig) : elemento(elemento), sig(sig) {}
};

template <typename G>
class Cola
{
private:
    Nodo<G> *inicio;
    Nodo<G> *fin;
    Nodo<G> *otro;

public:
    Cola() { inicio = nullptr; }
    void push(G v)
    {
        Nodo<G> *nuevo = new Nodo<G>(v, nullptr);
        if (isEmpty())
        {
            inicio = fin = nuevo;
        }
        else
        {
            fin->sig = nuevo;
            fin = nuevo;
        }
    }
    G pop()
    {
        if (inicio == nullptr)
            return 0;
        G elemento = inicio->elemento;
        inicio = inicio->sig;
        return elemento;
    }
    void mostrarTodo()
    {
        Nodo<G> *aux = inicio;
        while (aux != nullptr)
        {
            cout << aux->elemento << " ";
            aux = aux->sig;
        }
    }
    bool eliminar(function<bool(G)> condicion, function<bool(G)> condicion2)
    {
        
        Nodo<G> *actual = inicio;
        Nodo<G> *antes = nullptr;

        while (actual != nullptr && !condicion(actual->elemento))
        {
            antes = actual;
            actual = actual->sig;
        }
        if (condicion2(actual->elemento))
        {
            return false;
        }
        else if (actual == nullptr)
        {
            return false;
        }
        else if (antes == nullptr)
        {
            inicio = inicio->sig;
            cout << actual->elemento << ",";
            delete actual;
        }
        else if (actual->sig == nullptr)
        {
            antes->sig = nullptr;
            fin = antes;
            cout << actual->elemento << ",";
            delete actual;
        }
        else
        {
            antes->sig = actual->sig;
            cout << actual->elemento << ",";
            delete actual;
        }
        return true;
    }
    bool isEmpty()
    {
        if (inicio == nullptr)
            return 1;
        else
            return 0;
    }
};

void operaciones(Cola<int> &cola, int d, int a)
{
    int x;
    cin >> x;
    bool can = true;
    cout<<"Cartas retiradas: ";
    while (can)
        can = cola.eliminar([=](int e){ return e % a == d; }, [=](int e){ return e > x; });
    cout<<endl;
    cout<<"Carta ingresada: "<<x<<endl;
}
int main()
{
    int n;
    Cola<int> cola;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cola.push(i);
    int num_op = 3;
    operaciones(cola, 1, 2);
    operaciones(cola, 0, 2);
    operaciones(cola, 0, 3);
    cout<<"Cartas no retiradas ";
    cola.mostrarTodo();
    cout<<endl;
    cout<<"Carta ingesante "<<n<<endl; 
    return 0;
}