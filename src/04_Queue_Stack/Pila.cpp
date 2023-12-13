#include <iostream>

template <typename T>
class Pila
{
public:
    Pila() : tope(nullptr) {}
    ~Pila()
    {
        while (!esta_vacia())
        {
            pop();
        }
    }
    void push(const T &valor)
    {
        Nodo *nuevo_nodo = new Nodo{valor, tope};
        tope = nuevo_nodo;
    }
    void pop()
    {
        Nodo *nodo_a_eliminar = tope;
        tope = tope->siguiente;
        delete nodo_a_eliminar;
    }
    bool esta_vacia() const
    {
        return tope == nullptr;
    }
    T top() const
    {
        if (esta_vacia())
        {
            throw std::out_of_range("La pila está vacía");
        }
        return tope->dato;
    }

private:
    struct Nodo
    {
        T dato;
        Nodo *siguiente;
    };
    Nodo *tope;
};

int main()
{
    Pila<int> mi_pila;
    mi_pila.push(1);
    mi_pila.push(2);
    mi_pila.push(3);
    while (!mi_pila.esta_vacia())
    {
        std::cout << mi_pila.esta_vacia() << ": " << mi_pila.top() << std::endl;
        mi_pila.pop();
    }
    return 0;
}
