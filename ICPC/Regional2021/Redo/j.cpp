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

const int maxN = 100005;
int w, h;

bool enBorde(int x, int y){
    if(x==0 || x == w) return true;
    if(y == 0 || y == h) return true;
    return false;
}

string solve(){
    int n;
    cin>>w>>h>>n;
    int x1, y1, x2,y2;
    vector<pii> arriba, abajo, izq, der;
    loop(i, 0, n){
        cin>>x1>>y1>>x2>>y2;
        if(enBorde(x1, y1) && enBorde(x2, y2)){
            if(x1 == 0)      izq.push_back(pii(y1, i));
            else if(x1 == w) der.push_back(pii(y1, i));
            else if(y1 == 0) abajo.push_back(pii(x1, i));
            else if(y1 == h) arriba.push_back(pii(x1, i));

            if(x2 == 0)      izq.push_back(pii(y2, i));
            else if(x2 == w) der.push_back(pii(y2, i));
            else if(y2 == 0) abajo.push_back(pii(x2, i));
            else if(y2 == h) arriba.push_back(pii(x2, i));
        }
    }
    sort(begin(arriba), end(arriba));
    reverse(begin(arriba), end(arriba));

    sort(begin(abajo), end(abajo));

    sort(begin(izq), end(izq));
    reverse(begin(izq), end(izq));  

    sort(begin(der), end(der));

    vector<int> numeros;
    for(pii x : abajo)
        numeros.push_back(x.second);
    for(pii x : der)
        numeros.push_back(x.second); 
    for(pii x : arriba)
        numeros.push_back(x.second);  
    for(pii x : izq)
        numeros.push_back(x.second);

    bool vis[n+5];
    stack<int> pila;
    fill(vis, vis+n+5, 0);
    for(int x : numeros){
        if(!vis[x]){
            pila.push(x);
            vis[x] = 1;
        }
        else{
            if(pila.top() != x)
                return "N";
            else
                pila.pop();
        }
    }
    return "Y";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t = 1;
    //int t; cin>>t;
    loop(i, 0, t){
        cout<<solve()<<"\n";
    }
    return 0; 
}