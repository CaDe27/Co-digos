#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;
typedef int64_t ll;
typedef pair<int,int> pii;

#define loop(i,a,b) for(int i = a; i < b; ++i)

vector<int> palindromos;

int refleja(int a){
    int reflejo = 0; 
    while(a != 0){
        reflejo<<=1;
        if(a&1) ++reflejo;
        a>>=1;
    }
    return reflejo;
}

void generaPalis(){
    palindromos.push_back(0);
    palindromos.push_back(1);
    //primero los generamos
    // d representa los digitos de la parte reflejada
    // queremos llegar hasta 15 digitos para generar numeros de hasta 31 digitos 
    // (la parte simetrica + la del centro + la parte simetrica)
    int limite, pali, reflejo;
    for(int d = 1; d <= 15; ++d){
        limite = 1<<d;
        for(int i = 1<<(d-1); i<limite; ++i){
            reflejo = refleja(i);
            // i  y su simetrico 
            palindromos.push_back((i<<d) + reflejo);
            // ahora ponemos un 0 y un 1 entre ellos
            palindromos.push_back((i<<(d+1)) + reflejo);
            palindromos.push_back((i<<(d+1)) + (1<<d) + reflejo);
        }
    }
    
    //los ordenamos
    sort(palindromos.begin(), palindromos.end());
}

//busca el indice del palindromo mas grande que es menor o igual al numero
// + + + +  - - - 
int binaria(int numero){
    int ini = 0, fin = palindromos.size() - 1, mitad;
    while(ini != fin){
        mitad = (ini + fin + 1)/2;
        if(palindromos[mitad] <= numero)
            ini = mitad;
        else
            fin = mitad - 1;
    }
    return ini;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    generaPalis();

    int q; cin>>q;
    int a, b, indxa, indxb, resp;
    loop(i, 0, q){
        cin>>a>>b;
        //resolver query 
        indxa = binaria(a);
        indxb = binaria(b);
        resp = indxb - indxa;
        //if(a == palindromos[indxa])
        //    ++resp;
        cout<<resp<<"\n";
    }
    
    return 0; 
}