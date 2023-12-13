
#include <limits>
#ifndef _P_QUEUE_H
#define _P_QUEUE_H
#endif

#include <iostream>

class p_queue
{
public:
    p_queue(int *A, int n);
    void insert(int x);
    int maximum(void);
    int extract_max(void);
    void increase_key(int i, int x);

private:
    int a[10000];
    int size;

    int parent(int i);
    int left(int i);
    int right(int i);
    void maxHeapify(int A[], int n, int i);
    void buildMaxHeap(int A[], int n);
    void heapsort(int A[], int n);
};

p_queue::p_queue(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = A[i];
    }
    size = n;
    buildMaxHeap(a, size);
}

void p_queue::insert(int x)
{
    size++;
    a[size - 1] = x;
    int i = size - 1;
    while (i > 0 && a[parent(i)] < a[i])
    {
        std::swap(a[i], a[parent(i)]);
        i = parent(i);
    }
}

int p_queue::maximum()
{
    if (size <= 0)
    {
        std::cerr << "heap overflow" << std::endl;
        return -1;
    }
    return a[0];
}

int p_queue::extract_max()
{
    if (size <= 0)
    {
        std::cerr << "heap overflow" << std::endl;
        return -1;
    }
    int max = a[0];
    a[0] = a[size - 1];     // quitar a max del heap
    size--;                 // reducir el tamaño
    maxHeapify(a, size, 0); // ordenar de nuevo!
    return max;
}

void p_queue::increase_key(int i, int x)
{
    a[i] = std::max(a[i], x);

    while (i > 0 && a[parent(i)] < a[i])
    {
        std::swap(a[parent(i)], a[i]);
        i = parent(i);
    }
}

int p_queue::parent(int i)
{
    return (i - 1) / 2;
}

int p_queue::left(int i)
{
    return 2 * i + 1;
}

int p_queue::right(int i)
{
    return 2 * i + 2;
}

void p_queue::maxHeapify(int A[], int n, int i)
{
    int l = left(i);
    int r = right(i);
    int largest(0);
    if (l <= (n - 1) && A[l] > A[i])
        largest = l;
    else
        largest = i;
    if (r <= (n - 1) && A[r] > A[largest])
        largest = r;
    if (largest != i)
    {
        std::swap(A[i], A[largest]);
        maxHeapify(A, n, largest);
    }
}

void p_queue::buildMaxHeap(int A[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(A, n, i);
}

void p_queue::heapsort(int A[], int n)
{
    buildMaxHeap(A, n);
    for (int i = n - 1; i > 0; i--)
    {
        std::swap(A[0], A[i]);
        maxHeapify(A, --n, 0);
    }
}

int main()
{
    int A[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    p_queue q1(A, 10);

    std::cout << q1.maximum() << std::endl; // imprime 10
    q1.insert(20);                          // maximo es 20
    q1.insert(10);                          // añade 10
    std::cout << q1.maximum() << std::endl; // imprime 20
    q1.extract_max();                       // quitar el máximo
    std::cout << q1.maximum() << std::endl; // imprimir 10
    q1.increase_key(0, 5);
    std::cout << q1.maximum() << std::endl; // imprimir 10
    q1.extract_max();                       // quitar el máximo (10), pero queda el 10 de linea 116
    std::cout << q1.maximum() << std::endl; // imprimir 10
    q1.increase_key(1, 30);
    std::cout << q1.maximum() << std::endl; // devolver el 30

    return 0;
}
