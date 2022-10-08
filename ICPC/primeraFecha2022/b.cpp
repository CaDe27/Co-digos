#include<iostream>
#include <vector>
#include <queue>
#include <bitset>

using namespace std;
#define loop(i, a, b) for(int i = a; i < b; ++i)
priority_queue<int, vector<int>, greater<int> > minHeap;

const int maxN = 1e5+1, maxK = 100+1;
int n, k;
int f[maxN];
bitset<100001> visited, isLeaf;
bitset<101> visitedUnlock[maxN];
vector<int> adj[maxN];

void dfs(int nd, int fa){
    f[nd] = fa;
    if(nd != 1 && adj[nd].size() == 1) 
        isLeaf.set(nd, 1);
    for(int son : adj[nd]){
        if(son != fa){
            dfs(son, nd);
        }
    }   
}

void unlockUp(int v){
    while(!visited[v]){
        visited.set(v, 1);
        minHeap.push(v);
        v = f[v];
    }
}

//unlockUp all nodes in subtree of node with distances <= length
void process(int node, int length){
    if(length == 0 || isLeaf[node]){
        unlockUp(node);
        return;
    }

    if(!visitedUnlock[node][length]){
        visitedUnlock[node].set(length, 1);
        for(int v : adj[node]){
            if(v == f[node]) continue;
            process(v, length - 1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cin>>n>>k;
    
    for(int i=0, a,b; i < n-1; ++i){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 1);

    vector<int> resp;
    int node, length; 
    minHeap.push(1);
    visited[1] = true;
    while(!minHeap.empty()){
        node = minHeap.top();
        minHeap.pop();

        resp.push_back(node);

        //for each node up, unlock all nodes in subtree
        //at distance <= k for node
        //at distanche <= k-1 for f[node]
        //at distance <= k-2 for f[f[node]]
        length = k;
        while(length >= 1){
            process(node, length);
            --length;
            if(node == f[node]) break;
            node = f[node];
        }
    }
    loop(i, 0, n)
        cout<<resp[i]<<(i<n-1? " ":"\n");
    return 0;
}