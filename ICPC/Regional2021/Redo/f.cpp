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

const int maxN = 3e5 + 5;
int n;
char repre[maxN];
vector<int> adj[maxN];

bool visited[maxN];
void dfs(int nd, int fa){
    if(visited[nd]) return;
    visited[nd] = true;
    repre[nd] = 'B';
    for(int son : adj[nd]){
        if(son != n && son != fa && !visited[son])
            dfs(son, nd);
    }
}
void solve(){
    cin>>n;
    int m; cin>>m;
    loop(i, 0, m){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    fill(begin(repre), end(repre), 'A');
    dfs(n-1, n-1);
    loop(i, 1, n+1){
        cout<<repre[i];
    }
    cout<<"\n";
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