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
        Cola(){cola = NULL;}
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
        void quitarImpares(){
            Nodo<G>* aux = cola;
            while (aux !=NULL){
                if(aux->getSiguiente()->getValor() % 2 == 1){
                    aux->setSiguiente(aux->getSiguiente()->getSiguiente());
                }
                aux = aux->getSiguiente();
            }
            cola = aux;
        }
        bool isEmpty(){
            if(cola == NULL) return 1;
            else return 0;
        }
};

int main(){
    int x;
    int n;
    Cola<int> cola;
    cin>>n;
    for (int i = 1; i <= n; i++)
        cola.push(i);
    cola.mostrar();
    cola.quitarImpares();
    cola.mostrar();
    return 0;
}