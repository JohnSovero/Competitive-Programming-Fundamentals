#include <bits/stdc++.h>
using namespace std;

template<typename int>
class Nodo{
    private:
        int valor;
        Nodo* siguiente;
    public:
        Nodo(int v, Nodo *sig){
            valor = v;
            siguiente = sig;
        }
    int getValor(){ return valor; }
    Nodo *getSiguiente(){ return siguiente;}
};

template<typename G>
class Pila{
    private:
        Nodo<G>* tope;
    public:
        Pila(){tope = NULL;}
        void push(G v){
            Nodo<G> *n = new Nodo<G>(v, tope);
            tope = n;
        }
        G pop(){
            if(tope == NULL) return 0;
            G n = tope->getValor();
            tope = tope->getSiguiente();
            return n;
        }
        void mostrar(){
            Nodo<G>* aux = tope;
            while (aux !=NULL){
                cout<<aux->getValor()<<" ";
                aux = aux->getSiguiente();
            }
        }
        bool isEmpty(){
            if(tope == NULL) return 1;
            else return 0;
        }
};
int main(){
    Pila<int> pila;
    pila.push(20);
    pila.push(10);
    pila.push(15);
    pila.mostrar();
    cout<<endl;
    cout<<pila.isEmpty()<<endl;
    pila.pop();
    pila.pop();
    pila.pop();
    cout<<pila.isEmpty()<<endl;
    return 0;
}