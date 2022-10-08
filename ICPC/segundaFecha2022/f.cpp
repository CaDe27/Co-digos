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

const int maxN = 100;
int n;
pii pares[maxN];

bool colineales(int i, int j, int k){
    pair<ll,ll> v1, v2;
    v1.first = pares[j].first - pares[i].first;
    v1.second = pares[j].second - pares[i].second;

    v2.first = pares[k].first - pares[i].first;
    v2.second = pares[k].second - pares[i].second;   

    //saco determinante
    return v1.first*v2.second - v2.first*v1.second == 0;
}

void solve(){
    cin>>n;
    int total = 0;
    bool fake;
    loop(i, 0, n) 
        cin>>pares[i].first>>pares[i].second;
        
    loop(i, 0, n)
    loop(j, i+1, n)
    loop(k, j+1, n)
    loop(l, k+1, n){
        fake = false;
        fake = colineales(i, j, k) || colineales(i,j,l) || colineales(i,k,l) || colineales(j,k,l);
        if(!fake) ++total;
    }
    cout<<total<<"\n";
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