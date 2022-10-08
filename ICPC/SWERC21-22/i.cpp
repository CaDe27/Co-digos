#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <stack>
#include <utility>
#include <queue>
#include <set>
#include <iomanip>

#define ENTRADA 1
#define SALIDA 0
using namespace std;

typedef int64_t ll;
typedef pair<ll,int> pii;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 2e5;
set<ll> shops;
vector< pair<pii, int> > eventos;
int n, m, p[maxN];
void solve(){
    cin>>n>>m;
    loop(i, 0, n){
        cin>>p[i];
    }
    ll loc;
    loop(i, 0, m){
        cin>>loc;
        shops.insert(loc);
    }

    //for each hub define both events
    set<ll> :: iterator it;

    ll minDist;
    loop(i, 0, n){
        loc = i*100;
        it = shops.lower_bound(loc);
        minDist = 1e9+100;
        if(it != shops.end()){
            minDist = min(minDist, *it - loc);
        }
        if(it != shops.begin()){
            --it;
            minDist = min(minDist, loc - *it);
        }
        //cout<<loc<<" "<<minDist<<endl;
        eventos.push_back(make_pair(pii(loc-minDist, ENTRADA),i));
        eventos.push_back(make_pair(pii(loc+minDist, SALIDA), i));
    }
    sort(eventos.begin(), eventos.end());
    ll resp = 0, acum = 0;
    for(pair<pii, int> e : eventos){
        if(e.first.second == SALIDA)
            acum -= p[e.second];
        else
            acum += p[e.second];
        resp = max(resp, acum);
    }
    cout<<resp<<"\n";
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
