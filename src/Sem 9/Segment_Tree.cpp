#include<vector>
#include<string>
#include<iostream>
using namespace std;
// typedef vector <int> vi;
// typedef pair <int, int> ii;
// typedef vector <string> vs;
// typedef vector <ii> vii;

const int MAX = 1e5;
struct Node {
    int v;
    Node() {}
    Node(int v) : v(v) {}
};
Node opeMin(Node A, Node B) {
    if (A.v < B.v) return A;
    return B;
}

Node opeMax(Node A, Node B) {
    if (A.v > B.v) return A;
    return B;
}
Node opeSum(Node A, Node B) {
    return (A.v + B.v);
}

Node opeRest(Node A, Node B) {
    return (A.v + B.v)*-1;
}

struct SegmentTree {
    Node t[2 * MAX]; int n;
    //El arreglo incial es t[i+n]
    void build() {
        cout<<endl;
        for (int i = n - 1; i > 0; i--){
            t[i] = opeSum(t[i << 1], t[i << 1 | 1]);
            // cout<<i<<" -> "<<(i<<1)<<" -> "<<(i<<1 | 1)<<endl;
            // cout << t[i].v<<" -> ("<<t[i << 1].v<<") -> "<< t[i << 1 | 1].v<<endl;
        }
    }
    void modify(int p, Node val) {
        for (t[p += n] = val; p >>= 1; )
        t[p] = opeMin(t[p << 1], t[p << 1 | 1]);
    }
    Node get(int l, int r) { //[l,r)
        Node ansl, ansr;
        ansl = ansr = Node(0); //Inicializar con valor nulo
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ansl = opeSum(ansl, t[l++]);
            if (r & 1) ansr = opeSum(t[--r], ansr);
        }
        cout<<ansl.v<<" "<<ansr.v<<endl;
    return opeRest(ansl, ansr);
    }
};

SegmentTree ST;

int main() {
    int n;
    cout << "\nIngresar n elementos: ";
    cin >> n;
    ST.n = n;
    for (int i = 0; i < n; i++) {
        cout << "\nElemento " << i<<": ";
        cin >> ST.t[n + i].v;
    }
    for (int i = 0; i < n; i++) {
        cout << ST.t[n + i].v << " ";
    }
    ST.build();
    cout << "\n";
    int q, l, r;
    cout << "\nIngresar numero de consultas: ";
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cout << "\nIngresar indice l: ";
        cin >> l;
        cout << "\nIngresar índice r: ";
        cin>>r;
        cout << "\nResultado: "<<ST.get(l, r + 1).v;
        cout << "\n";
    }
    return 0;
}