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
    Node *equ;
    Node *right;
};

template <class T>
class TreeTB
{
    typedef function<int(T, T)> Comp;
    Node<T> *root;
    void (*procesar)(T);
    Comp compare;

private:
    bool _insert(Node<T> *&node, T e)
    {
        if (node == nullptr)
        {
            node = new Node<T>();
            node->element = e;
            return true;
        }
        else
        {
            int n = compare(node->element, e);
            if (n < 0)
                return _insert(node->right, e);
            else if (n == 0)
                return _insert(node->equ, e);
            else
                return _insert(node->left, e);
        }
    }

    void _preOrden(Node<T> *node)
    {
        if (node == nullptr)
            return;
        procesar(node->element);
        _preOrden(node->left);
        _preOrden(node->equ);
        _preOrden(node->right);
    }

    int _quantity(Node<T> *node)
    {
        if (node == nullptr)
            return 0;
        else
        {
            int ql, qr, qe;
            ql = _quantity(node->left);
            qr = _quantity(node->right);
            qe = _quantity(node->equ);
            return ql + qr + qe + 1;
        }
    }

public:
    TreeTB(void (*value)(T))
    {
        this->procesar = value;
        this->compare = [](T a, T b) -> int
        { return a - b; };
        root = nullptr;
    }

    bool insert(T e)
    {
        return _insert(root, e);
    }
    void preOrden()
    {
        _preOrden(root);
    }
    int quantity()
    {
        return _quantity(root);
    }
};

void print(int e)
{
    cout << " " << e;
}

int main()
{
    TreeTB<int> *tree = new TreeTB<int>(print);
    // for (int i = 0; i < 15; i++)
    //	tree->insert(rand() % 100);
    tree->insert(15);
    tree->insert(15);
    tree->insert(18);
    tree->insert(16);
    tree->insert(18);
    tree->insert(8);
    tree->insert(5);
    tree->insert(11);
    tree->insert(40);
    tree->insert(20);
    tree->insert(29);
    tree->insert(19);
    cout << "\nElementos: ";
    tree->preOrden();
    cout << "\n";
    cout << "\nCantidad: " << tree->quantity();
    cin.get();
    cin.ignore();
    return 0;
}
