
#include <iostream>
#include <queue>
using namespace std;
template <typename T>

class Cola
{
private:
    queue<T> cola;

public:
    void encolar(const T &elemento)
    {
        cola.push(elemento);
    }

    void desencolar()
    {
        if (!esta_vacia())
        {
            cola.pop();
        }
    }

    const T &frente() const
    {
        if (!esta_vacia())
        {
            return cola.front();
        }
        throw std::out_of_range("La cola está vacía");
    }

    bool esta_vacia() const
    {
        return cola.empty();
    }

    std::size_t tamanio() const
    {
        return cola.size();
    }
};


template <typename T>
Cola<T> multiplicar_colas(Cola<T> cola1, Cola<T> cola2)
{
    Cola<T> c3;
    T resultado = 1;
    while (!cola1.esta_vacia())
    {
        resultado = cola1.frente() * cola2.frente();
        cola1.desencolar();
        cola2.desencolar();
        c3.encolar(resultado);
    }
    return c3;
}

int main()
{
    Cola<int> cola1;
    cola1.encolar(5);
    cola1.encolar(100);
    cola1.encolar(10);
    Cola<int> cola2;
    cola2.encolar(2);
    cola2.encolar(2);
    cola2.encolar(2);
    Cola<int> c3 = multiplicar_colas(cola1, cola2);
    while (!c3.esta_vacia())
    {
        cout << c3.frente() << endl;
        c3.desencolar();
    }
    return 0;
}