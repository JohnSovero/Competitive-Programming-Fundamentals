#include <iostream>
using namespace std;

bool esPerfecto(int x){
    int cont = 0;
    for (int i = 1; i <= x/2; i++)
    {
        if(x % i == 0) cont+= i;
    }
    if(cont == x) return true;
    return false;
}

int main(){
    int n;
    cin>>n;
    int x;
    for (int i = 0; i < n; i++){ 
        cin>>x;
        if(esPerfecto(x)) cout<<x <<" es perfecto"<<endl;
        else cout<<x <<" no es perfecto"<<endl;
    }
    return 0;
}