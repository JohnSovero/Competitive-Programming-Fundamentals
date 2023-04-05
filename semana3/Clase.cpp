#include <bits/stdc++.h>
using namespace std;
template <typename T>

T mayorNumero(T a, T b){
    return a>b ? a:b;
}

int main(){
    double a, b;
    cin>>a>>b;
    cout<< mayorNumero<int>(a,b);
    cout<< mayorNumero<double>(a,b);
    return 0;   
}