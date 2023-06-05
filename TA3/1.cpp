#include <iostream>
#include <vector>

using namespace std;

// Estructura del árbol de segmentos
struct SegmentTree
{
    vector<int> tree; // Array para almacenar el árbol
    int size;         // Tamaño del árbol

    // Constructor
    SegmentTree(int n)
    {
        // Calcula el tamaño del árbol basado en el número de elementos
        size = 1;
        while (size < n)
            size *= 2;
        tree.resize(2 * size); // Redimensiona el árbol
    }

    // Actualiza el valor del elemento en la posición index con el valor val
    void update(int index, int val)
    {
        index += size;     // Calcula la posición en el array del árbol
        tree[index] = val; // Actualiza el valor del nodo hoja

        // Propaga los cambios hacia arriba
        while (index > 1)
        {
            index /= 2;
            // Aca se propaga hacia arriba, dependiendo de la operacion que queramos
            tree[index] = max(tree[index * 2], tree[index * 2 + 1]);
        }
    }

    // Calcula la suma de valores en el rango [left, right)
    int query(int left, int right, int node, int nodeLeft, int nodeRight)
    {
        // Si el rango está completamente fuera del rango del nodo actual
        if (nodeRight <= left || right <= nodeLeft)
            return 0;

        // Si el rango está completamente cubierto por el nodo actual
        if (left <= nodeLeft && nodeRight <= right)
            return tree[node];

        // Divide el rango en dos y realiza las consultas recursivas
        int mid = (nodeLeft + nodeRight) / 2;
        int maxLeft = query(left, right, node * 2, nodeLeft, mid);
        int maxRight = query(left, right, node * 2 + 1, mid, nodeRight);

        // busca dependiendo de la operacion que queramos
        return max(maxLeft, maxRight);
    }

    // Calcula la suma de valores en el rango [left, right)
    int query(int left, int right)
    {
        return query(left, right, 1, 0, size);
    }
};

int main()
{
    int n; // Número de elementos
    do
    {
        cin >> n;
    } while (n < 0 || n > 100);
    SegmentTree st(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.update(i, x);
    }
    cout << "Elementos del arbol: ";
    for (int i = 0; i < n; i++)
    {
        cout << st.tree[st.size + i] << " ";
    }
    cout << endl;
    // Actualiza los valores del arbol
    cout << "Elementos del arbol actualizado: ";
    st.update(0, 1);
    st.update(1, 2);
    st.update(2, 3);
    st.update(3, 4);
    st.update(4, 5);
    for (int i = 0; i < n; i++)
    {
        cout << st.tree[st.size + i] << " ";
    }
    cout << endl;
    int q, l, r;
    cout << "Ingrese numero de consultas: ";
    do
    {
        cin >> q;
    } while (q < 1 || q > 200);
    while (q--)
    {
        cout << "Ingrese el rango left, right: " << endl;
        cin >> l >> r;
        int mayor = st.query(l, r + 1); // Sumamos 1 a 'r' para incluir el último elemento del rang
        cout << "Consulta en el rango [" << l << "," << r << "] : " << mayor << endl;
    }
    return 0;
}