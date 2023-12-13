#include <bits/stdc++.h>
using namespace std;
template <typename T>

int mayorNumero(int a, int b){
    return a>b ? a:b;
}

int main(){
    double a, b;
    cin>>a>>b;
    cout<< mayorNumero<int>(a,b);
    cout<< mayorNumero<double>(a,b);
    return 0;   
}