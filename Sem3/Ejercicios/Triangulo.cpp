#include <bits/stdc++.h>
using namespace std;

template<class T>
class Triangulo{
    public:
    int base, altura;

    Triangulo(int base, int altura): base(base), altura(altura)
    {}
    int hallarArea(){
        return (this->base*this->altura)/2;
    }
    ~Triangulo(){}

};

int main(){
    double b,a;
    cin>>b>>a;
    Triangulo<int>* enteros = new Triangulo<int>(b, a);
    Triangulo<double>* decimales = new Triangulo<double>(b, a);

    cout<<enteros->altura<<" "<<enteros->base<<endl;
    cout<<enteros->hallarArea()<<endl;

    cout<<decimales->altura<<" "<<decimales->base<<endl;
    cout<<decimales->hallarArea()<<endl;
}