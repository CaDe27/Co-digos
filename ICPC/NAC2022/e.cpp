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

const int maxN = 5000 + 5, maxP = 2*maxN;
int n;
vector<int> adj[maxN];
int ancestor[maxN];
int val[maxN];

vector<int> prime;
bool primo[maxP];
int sPrime[maxP], gPrime[maxP];

vector<int> V;
unordered_map<int, int> VIndex;
bool simple(int v){
    int p;
    while(v != 1){
        p = sPrime[v];
        v/=p;
        if(v%p == 0) 
            return false;
    }
    return true;
}

void generateV(){
    int limit = max(2*n, 100);

    loop(i, 2, limit+1){
        if( i <= 100 || (gPrime[i] < 100 && simple(i))){
            VIndex[i] = V.size();
            V.push_back(i);
        }
    }
}

void sieve () {
    fill (primo, primo + maxP, true);
    primo[0] = primo[1] = false;
    for (int i = 2; i < maxP; ++i) {
        if (primo[i]){ 
            prime.push_back(i);
            sPrime[i] = gPrime[i] = i;
        }
        for (int j = 0; j < prime.size() && i * prime[j] < maxP; ++j) {
            primo[i * prime[j]] = false;
            sPrime[i*prime[j]] = prime[j];
            gPrime[i*prime[j]] = gPrime[i];
            if (i % prime[j] == 0) break;
        }
    }
}

void dfs(int node, int fa){
    ancestor[node] = fa;
    for(int h : adj[node]){
        if(h != fa)
            dfs(h, node);
    }
}
const int maxV = 2000;
int F[maxN][maxV], G[maxN][maxV];
bool vF[maxN][maxV], vG[maxN][maxV];

int f(int i, int v);

void fillGPrimos(int i){
    int valorF;
    for(int p : prime){
        if(p > 100) break;
        vG[i][ VIndex[p] ] = true;
        G[i][ VIndex[p] ] = 2*n + 1;
    }
    int p;
    for(int v : V){
        valorF = f(i,v);
        while(v != 1){
            p = sPrime[v];
            G[i][VIndex[p]] = min(G[i][VIndex[p]], valorF);
            while(v%p == 0) 
                v /= p;
        }
    }
}

int g(int i, int v){
    if(!vG[i][ VIndex[v] ]){
        vG[i][ VIndex[v] ] = true;
        if(!primo[v]){
            G[i][ VIndex[v] ] = min(g(i, sPrime[v]), g(i, v/sPrime[v]));
        }
        else
        {
            fillGPrimos(i);
        }
    }
    return G[i][ VIndex[v] ];
}

int f(int i, int v){
    if(!vF[i][ VIndex[v] ]){
        vF[i][ VIndex[v] ] = true;
        F[i][ VIndex[v] ] = v == val[i]? 0 : v;
        for(int h  : adj[i])
            if(h != ancestor[i])
                F[i][ VIndex[v] ] += g(h,v);
    }
    return F[i][ VIndex[v] ];
}

void solve(){
    cin>>n;
    loop(i, 0, n) cin>>val[i];
    for(int a,b,i = 0; i < n-1; ++i){
        cin>>a>>b;
        --a;--b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    sieve();
    generateV();
    dfs(0, 0);
    int resp = f(0, 2);
    loop(i, 1, V.size()){
        resp = min(resp, f(0, V[i]));
    }
    cout<<resp<<"\n";
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    solve();
    return 0; 
}