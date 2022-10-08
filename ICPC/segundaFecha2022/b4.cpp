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

vector<int64_t> palindromos;

int64_t refleja(int64_t a){
    int64_t reflejo = 0LL; 
    while(a != 0LL){
        reflejo<<=(1LL);
        if(a&(1LL)) ++reflejo;
        a>>=(1LL);
    }
    return reflejo;
}

void generaPalis(){
    palindromos.push_back(0LL);
    palindromos.push_back(1LL);
    //primero los generamos
    // d representa los digitos de la parte reflejada
    // queremos llegar hasta 15 digitos para generar numeros de hasta 31 digitos 
    // (la parte simetrica + la del centro + la parte simetrica)
    int64_t limite, pali, reflejo;
    for(int64_t d = 1LL; d <= 16LL; ++d){
        limite = ( (int64_t) 1)<<d;
        for(int64_t i = ( (int64_t) 1)<<(d-1); i<limite; ++i){
            reflejo = refleja(i);
            // i  y su simetrico 
            palindromos.push_back((i<<d) + reflejo);
            // ahora ponemos un 0 y un 1 entre ellos
            palindromos.push_back((i<<(d+1LL)) + reflejo);
            palindromos.push_back((i<<(d+1LL)) + (( (int64_t) 1)<<d) + reflejo);
        }
        
    }
    //los ordenamos
    sort(palindromos.begin(), palindromos.end());
}

//busca el indice del palindromo mas grande que es menor o igual al numero
// + + + +  - - - 
int64_t binaria(int64_t numero){
    int64_t ini = 0, fin = palindromos.size() - 1, mitad;
    while(ini != fin){
        mitad = (ini + fin + 1)/2;
        if(palindromos[mitad] < numero)
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

    int64_t q; cin>>q;
    int64_t a, b, indxa, indxb, resp;
    for(int64_t i = 0; i < q; ++i){
        cin>>a>>b;
        if(a > b) swap(a, b);
        //resolver query 
        indxa = binaria(a);
        indxb = binaria(b);
        resp = indxb - indxa;
        cout<<resp<<"\n";
    }
    return 0; 
}