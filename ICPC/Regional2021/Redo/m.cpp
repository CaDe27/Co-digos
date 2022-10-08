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

#define INF 1000000000000
#define MOD 1000000007
#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 5005;
int n;
ll t[maxN], d[maxN];
int pos[maxN];

bool f(int i, int j){ return d[i] <= d[j];}
bool sePuede(){
    ll suma = 0;
    int indx;
    loop(i, 0, n){
        indx = pos[i];
        suma += t[indx];
        if(suma > d[indx])
            return false;
    }
    return true;
}

ll acumT = 0;
void fijaPos(int p){
    int indx = pos[p];
    int nuevoIni = indx, posNuevoIni = p;
    ll acum = acumT + t[indx];
    ll minDist = d[indx] - acum;
    loop(i, p+1, n){
        indx = pos[i];
        if(t[indx] <= minDist && indx < nuevoIni){
            posNuevoIni = i;
            nuevoIni = indx;
        }
        acum += t[indx];
        minDist = min(minDist, d[indx] - acum);
    }
    
    //ponemos a nuevoIni en su lugar;
    for(int i = posNuevoIni; i>p; --i){
        pos[i] = pos[i-1];
    }
    pos[p] = nuevoIni;
    acumT += t[ nuevoIni ];
}

void solve(){
    cin>>n;
    loop(i,0,n){
        cin>>t[i]>>d[i];
        pos[i] = i;
    }
    sort(pos, pos+n, f);
    if(!sePuede()){
        cout<<"*\n";
        return;
    }
    loop(i, 0, n){
        fijaPos(i);
    }   
    cout<<1+pos[0];
    loop(i, 1, n){
        cout<<" "<<pos[i]+1;
    }
    cout<<"\n";
}   

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t = 1;
    //int t; cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}