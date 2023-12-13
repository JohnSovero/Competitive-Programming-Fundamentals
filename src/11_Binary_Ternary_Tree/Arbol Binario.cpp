
#pragma once
#include <functional>
#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    T element;
    Node *left;
    Node *right;
};

template <class T>
class TreeBB
{
    typedef function<int(T, T)> Comp;
    Node<T> *root;
    Comp compare;
    void (*procesar)(T);

private:
    bool _insert(Node<T> *&node, T e)
    {
        if (node == nullptr)
        { // si es que  nodo se encuentra sin dirección de memoria, registra el valor
            node = new Node<T>();
            node->element = e; // asigna valor en el elemento del nodo
            return true;
        }
        else
        {
            int n = compare(node->element, e); // se realiza la diferencia para conocer a que dirección irá el valor (izquierda o derecha)
            if (n == 0)
                return false;
            else if (n < 0)
                return _insert(node->right, e); // verifica si el n es negativo, para que el recorrido vaya por la derecha, por ser mayor que el node->element
            else
                return _insert(node->left, e); // verifica si el n es positivo, para que el recorrido vaya por la izquierda, por ser menor que el node->element
        }
    }

    bool _search(Node<T> *node, T e)
    {
        if (node == nullptr)
            return false;
        else
        {
            int n = compare(node->element, e);
            if (n == 0)
                return true;
            else if (n < 0)
                return _search(node->right, e);
            else
                return _search(node->left, e);
        }
    }

    bool _null()
    {
        return root == nullptr;
    }

    int _quantity(Node<T> *node)
    {
        if (node == nullptr)
            return 0;
        else
        {
            int ql = _quantity(node->left);
            int qr = _quantity(node->right);
            return ql + qr + 1;
        }
    }

    int _maximum(Node<T> *node)
    {
        if (node->right == nullptr)
            return node->element;
        else
            return _maximum(node->right);
    }

    int _minimum(Node<T> *node)
    {
        if (node->left == nullptr)
            return node->element;
        else
            return _minimum(node->left);
    }

    void _preOrden(Node<T> *node)
    {
        if (node == nullptr)
            return;
        procesar(node->element);
        _preOrden(node->left);
        _preOrden(node->right);
    }

public:
    TreeBB(void (*value)(T))
    {
        this->compare = [](T a, T b) -> int
        { return a - b; }; // ingresar el "node->element" y el "e" para realizar la resta.
        this->procesar = value;
        root = nullptr;
    }

    bool insert(T e) { return _insert(root, e); } // envía la raiz y el elemento que ingresa
    bool search(T e) { return _search(root, e); }
    int quantity(T e) { return _quantity(root); }
    int minimum() { return _minimum(root); }
    int maximum() { return _maximum(root); }
    void preOrden() { _preOrden(root); }
};

void print(int e)
{
    cout << " " << e;
}

int main()
{
    TreeBB<int> *tree = new TreeBB<int>(print);
    // for (int i = 0; i < 15; i++)
    //	tree->insert(rand() % 100);
    tree->insert(10);
    tree->insert(4);
    tree->insert(15);
    tree->insert(2);
    tree->insert(5);
    cout << "\nElementos: ";
    tree->preOrden();
    cout << "\n";
    int n;
    cout << "\nIngresar n" << char(163) << "mero a buscar: ";
    cin >> n;
    cout << "\nElemento buscado " << n << ": " << tree->search(n);
    cout << "\nMenor elemento: " << tree->minimum();
    cout << "\nMayor elemento: " << tree->maximum();
    cin.get();
    cin.ignore();
    return 0;
}
