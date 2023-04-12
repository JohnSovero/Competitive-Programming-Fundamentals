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
        Nodo* cola;
        Nodo* fondo;    
    public:
        Cola(){cola = NULL;}
        void push(G v){
            Nodo *aux = new Nodo(v, NULL);
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
            Nodo* aux = cola;
            while (aux !=NULL){
                cout<<aux->getValor()<<" ";
                aux = aux->getSiguiente();
            }
        }
        bool isEmpty(){
            if(cola == NULL) return 1;S
            else return 0;
        }
};
int main(){
    Cola<int> cola;
    cola.push(20);
    cola.push(10);
    cola.push(15);
    cola.push(16);
    cola.push(17);
    cola.mostrar();
    cout<<endl;
    cout<<cola.isEmpty()<<endl;
    cola.pop();
    cola.pop();
    cola.pop();
    cola.pop();
    cola.pop();
    cout<<cola.isEmpty()<<endl;
    return 0;
}