//create graph
//create DAG
//visit reverge graph  Turning on and off landscapes

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
#include <ccomplex>
#include <deque>

using namespace std;
typedef int64_t ll;
typedef pair<int,int> pii;

#define INF 1000000000000
#define MOD 1000000007
#define M_PI 3.14159265358979323846264338327950288

#define loop(i,a,b) for(int i = a; i < b; ++i)
const int maxN = 500*500+5, maxR = 500;
int r,c, V;
char mat[maxR][maxR];

int indx(int i, int j){return i*c + j;}
bool isLand(int i, int j){
    return mat[i][j] == '#' || mat[i][j] == '.';
}
bool valid(int i, int j){
    if(i < 0 || i >= r) return false;
    if(j < 0 || j >= c) return false;
    return true;
}

pii moves[4];


vector<int> adj[maxN], transpose[maxN];
vector<int> landmarks[maxN];
set<int> adj2[maxN], transpose2[maxN];
set<int> landmarks2[maxN];

int activeResp, resp = 0;
int activeLandmarks[maxN];

bool visited[maxN];
bool land[maxN];
stack<int> nextS;
void dfs1(int v){
    visited[v] = true;
    for(int son: adj[v])
        if(!visited[son])
            dfs1(son);
    nextS.push(v);
}

int repre[maxN];
int repreActual;
void dfs2(int v){
    visited[v] = true;
    repre[v] = repreActual;
    for(int son: transpose[v])
        if(!visited[son])
            dfs2(son);
}

void dfs3(int i){
    //augment landmarks
    for(int z : landmarks2[i]){
        
        ++activeLandmarks[z];
        if(activeLandmarks[z] == 1)
            ++activeResp;
    }
    //update resp
    resp = max(activeResp, resp);
    //dfs transpose
    for(int z : transpose2[i])
        dfs3(z);

    //delete landmarks
    for(int z : landmarks2[i]){
        --activeLandmarks[z];
        if(activeLandmarks[z] == 0)
            --activeResp;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    moves[0] = pii(0, -1);
    moves[1] = pii(0,1);
    moves[2] = pii(-1,0);
    moves[3] = pii(1, 0);
    
    cin>>r>>c;
    loop(i, 0, r)
    loop(j, 0, c)
        cin>>mat[i][j];

    loop(i, 0, r)
    for(int j = 0, sig; j<c; ++j){
        char z = mat[i][j];
        if(z == '.'){ 
            land[indx(i,j)] = true;
            continue;
        }
        if(z == '#') { 
            land[indx(i,j)] = true;
            for(pii m : moves){
                if(valid(i+m.first, j+m.second) && !isLand(i+m.first, j+m.second)){
                    landmarks[indx(i+m.first, j+m.second)].push_back(indx(i,j));
                }
            }
            continue;
        }
        pii foo;
        if(z == '<') foo = pii(i, j-1);
        if(z == '>') foo = pii(i, j+1);
        if(z == 'v') foo = pii(i+1, j);
        if(z == '^') foo = pii(i-1, j);
        if(valid(foo.first, foo.second) && !isLand(foo.first, foo.second)){
            adj[indx(i, j)].push_back(indx(foo.first, foo.second));
            transpose[indx(foo.first, foo.second)].push_back(indx(i, j));
        }
    }

    stack<int> next;
    V = r*c;
    fill(visited, visited+V, false);
    for(int i = 0; i < V; ++i){
        if(!visited[i] && !land[i])
            dfs1(i);
    }

    fill(visited, visited+V, false);
    while(!nextS.empty()){
        int aux = nextS.top(); nextS.pop();
        if(!visited[aux] && !land[aux]){
            repreActual = aux;
            dfs2(aux);
        }
        
    }

    //construct DAG and landmarks
    for(int i = 0; i < V; ++i){
        for(int z : adj[i]){
            if(repre[i] == repre[z]) continue;
            adj2[repre[i]].insert(repre[z]);
            transpose2[repre[z]].insert(repre[i]);
        }
        for(int z : landmarks[i]){
            landmarks2[repre[i]].insert(z);
        }
    }

    //we iterate transpose graph 
    activeResp = 0;
    loop(i, 0, V){
        if(land[i]) continue;
        if(repre[i] != i) continue;
        if(!adj2[i].empty()) continue;
        //then I'm a leaf in the new 
        dfs3(i);
    }
    cout<<resp<<"\n";


}
