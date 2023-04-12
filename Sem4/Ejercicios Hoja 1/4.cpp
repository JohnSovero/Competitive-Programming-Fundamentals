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
        int aprobados, desaprobados;
    public:
        Cola(){cola = NULL, fondo = NULL, aprobados = 0, desaprobados= 0;}
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
        void contarNotas(){
            Nodo<G>* aux = cola;
            while (aux !=NULL){
                if(aux->getValor() > 13){
                    aprobados++;
                }
                else{
                    desaprobados++;
                }
                aux = aux->getSiguiente();
            }
        }
        bool isEmpty(){
            if(cola == NULL) return 1;
            else return 0;
        }
        int returnAprobados(){return aprobados;}
        int returnDesaprobados(){return desaprobados;}
};

int main(){
    Cola<int> notas_estudiantes;
    for (int i = 1; i < 16; i++)
    {
        notas_estudiantes.push(i*rand()%10 + rand()%10);
    }
    notas_estudiantes.mostrar();
    cout<<endl;
    notas_estudiantes.contarNotas();
    cout<<"Aprobados: "<<notas_estudiantes.returnAprobados()<<endl;
    cout<<"Desaprobados: "<<notas_estudiantes.returnDesaprobados()<<endl;
    
    return 0;
}