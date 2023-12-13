#include <iostream>
using namespace std;

void invertir(int n){
    cout<<n%10;
    if(n>10)
        invertir(n/10);
}

void binario(int n){
    cout<<n<<" ";
    if(n <= 0) return;
    if(n & 1){
        //cout<<1;
        
    }
    else{
        //cout<<0;
    }
    binario(n>>1);
}
void Ejercicio1(){
    int n;
    cin>>n;
}
int main(){
    int num;
    cout<<"Ingrese un numero: ";
    cin>>num;
    cout<<(1&1);
    Ejercicio1();
    //binario(num);
    return 0;
}