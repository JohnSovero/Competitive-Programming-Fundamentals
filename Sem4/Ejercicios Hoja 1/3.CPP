#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Nodo{
    private:
        T valor;
        Nodo* siguiente;
    public:
        Nodo(T v, Nodo *sig){
            valor = v;
            siguiente = sig;
        }
    T getValor(){ return valor; }
    Nodo *getSiguiente(){ return siguiente;}
    Nodo *setSiguiente(Nodo* sig){
        siguiente = sig;
    }
};

template<typename G>
class Cola{
    private:
        Nodo<G>* cola;
        Nodo<G>* fondo;    
    public:
        Cola(){cola = NULL, fondo = NULL;}
        void push(G v){
            Nodo<G> *aux = new Nodo<G>(v, NULL);
            if(isEmpty()){
                cola = aux;
                fondo = aux;
            }
            else{
                fondo->setSiguiente(aux);
                fondo = aux;
            }
        }
        G pop(){
            if(cola == NULL) return 0;
            G valor = cola->getValor();
            cola = cola->getSiguiente();
            return valor;
        }
        void mostrar(){
            Nodo<G>* aux = cola;
            while (aux !=NULL){
                cout<<aux->getValor()<<" ";
                aux = aux->getSiguiente();
            }
        }
        bool isEmpty(){
            if(cola == NULL) return 1;
            else return 0;
        }
};

Cola<int> crearColaMultiplicada(Cola<int>& a, Cola<int>& b){
    Cola<int> cola_resultado;
    while(!(a.isEmpty())){
        int aux = a.pop() * b.pop();
        cola_resultado.push(aux);
    }
    return cola_resultado;
} 
int main(){
    Cola<int> cola_A, cola_B;
    cola_A.push(2);
    cola_A.push(5);
    cola_A.push(5);
    cola_A.push(6);

    cola_B.push(3);
    cola_B.push(2);
    cola_B.push(4);
    cola_B.push(3);

    Cola<int> nueva = crearColaMultiplicada(cola_A, cola_B);
    nueva.mostrar();

    return 0;
}
