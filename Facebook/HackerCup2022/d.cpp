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

const int maxN = 200005;
int n,m,q;
unordered_set<int> adj[maxN];
unordered_map<int, unordered_map<int,int> > costs;
unordered_map<int, unordered_map<int,ll> > memo;
unordered_map<int, unordered_map<int,bool> > answered;
ll query(int x, int y){
    ll resp = ((ll)costs[x][y])<<1;
    if(adj[x].size() > adj[y].size()) swap(x,y);
    for(int node : adj[x]){
        if(adj[y].find(node) != adj[y].end())
            resp += min(costs[x][node], costs[node][y]);
    }
    return resp;
}

void solve(){
    cin>>n>>m>>q;
    int a, b,c;
    loop(i, 0, m){
        cin>>a>>b>>c;
        --a;--b;
        costs[a][b] = c;
        costs[b][a] = c;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    
    vector<ll> resp;
    loop(i, 0, q){
        cin>>a>>b;
        --a;--b;
        if(a > b) swap(a,b); 
        if(!answered[a][b]){
            answered[a][b] = true;
            memo[a][b] = query(a,b);
        }
        cout<<memo[a][b]<<(i<q-1? " ":"\n"); 
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    //int t = 1;
    int t; cin>>t;
    loop(i, 1, t+1){
        cout<<"Case #"<<i<<": ";
        solve();
        if(i < t){
            loop(i, 0, n) {
                adj[i].clear();
                answered[i].clear();
                memo[i].clear();
                costs[i].clear();
            }
        }
    }
    return 0; 
}