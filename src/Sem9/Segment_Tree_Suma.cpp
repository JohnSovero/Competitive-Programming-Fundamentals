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
            tree[index] = tree[index * 2] + tree[index * 2 + 1];
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
        int sumLeft = query(left, right, node * 2, nodeLeft, mid);
        int sumRight = query(left, right, node * 2 + 1, mid, nodeRight);

        return sumLeft + sumRight;
    }

    // Calcula la suma de valores en el rango [left, right)
    int query(int left, int right)
    {
        return query(left, right, 1, 0, size);
    }
};

int main()
{
    // Ejemplo de uso
    int n = 5; // Número de elementos
    SegmentTree st(n);

    // Actualiza los valores iniciales
    st.update(0, 1);
    st.update(1, 2);
    st.update(2, 3);
    st.update(3, 4);
    st.update(4, 5);

    // Consulta la suma de valores en el rango [2, 4)
    int sum = st.query(2, 4);
    cout << "Suma en el rango [2, 4): " << sum << endl;

    return 0;
}
