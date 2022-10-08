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
#define loop(i,a,b) for(int i = a; i < b; ++i)

map<string, vector<int> > sameWord;
vector<string> words;
vector<int> vW;
vector<char> car;
vector< vector<int> > adj;
vector<bool> visited;

void dfs(int i, int vengo){
    if(visited[i]) return;
    visited[i] = true;
    if(car[i] != '.') car[i] = ',';
    for(int v : adj[i]){
        if(v != vengo && !visited[v] && v != i)
            dfs(v, i);
    }
}

void solve(){
    string word;
    while(cin>>word){
        words.push_back(word);
    }
    vW.resize(words.size(), 0);
    car.resize(2*words.size(),0);
    visited.resize(car.size(), 0);
    adj.resize(car.size());

    char foo;
    for(int i = 0; i < words.size(); ++i){
        foo = words[i].at(words[i].size()-1);
        if(foo == '.' || foo == ','){
            words[i] = words[i].substr(0, words[i].size()-1);
            car[2*i+1] = foo;
        }

        if(foo != '.'){
            adj[2*i+1].push_back(2*i+2);
            adj[2*i+2].push_back(2*i+1);
        }
        sameWord[words[i]].push_back(i);

    }

    for(auto x : sameWord){
        int i = x.second[0];
        for(int v : x.second){
            if(v == x.second[0]) continue;
            adj[2*i+1].push_back(2*v+1);
            adj[2*v+1].push_back(2*i+1);
            adj[2*i].push_back(2*v);
            adj[2*v].push_back(2*i);
        }
    }

    loop(i, 0, car.size()){
        if(car[i] == ','){
            if(!visited[i])
                dfs(i, i);
        }
    }

    loop(i, 0, words.size()){
        if(i != 0) cout<<" ";
        cout<<words[i];
        foo = car[2*i+1];
        if(foo == ',' || foo == '.')
            cout<<foo;
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t = 1;
    //int t; cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}