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

const int maxN = 1000+5;
int n, k;
vector<pii> adj[maxN];
int lastSeen[maxN];
bool posible[maxN]; //posible infectada en su ultimo dia vista

void infecta(int persona, int dia){
    int son, diaContacto;
    for(pii contacto : adj[persona]){
        son = contacto.first;
        diaContacto = contacto.second;
        if(diaContacto != dia) continue;
        
        if(lastSeen[son] == dia+1)
            infecta(son, dia+1);
        if(dia == k)
            posible[son] = true;
    }
}
void solve(){
    int c;
    cin>>n>>k>>c;
    loop(i, 0, c){
        int a,b,d;
        cin>>a>>b>>d;
        --a;--b;
        adj[a].push_back(pii(b,d));
        adj[b].push_back(pii(a,d));
        lastSeen[a] = max(lastSeen[a], d);
        lastSeen[b] = max(lastSeen[b], d);
    }
    for(int i = 0; i < n; ++i){
        if(lastSeen[i] == 1)
            infecta(i, 1);
    }
    vector<int> resp;
    for(int i = 0; i < n; ++i){
        if(posible[i])
            resp.push_back(i);
    }
    cout<<resp.size()<<"\n";
    for(int v : resp)
        cout<<v+1<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t = 1;
    //int t; cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}