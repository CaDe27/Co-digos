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
typedef int64_t ll ;
typedef pair<int,int> pii;

#define INF 1000000000000
#define MOD 1000000007
#define loop(i,a,b) for(ll i = a; i < b; ++i)

const ll maxN = 2e6;;
ll n;

void solve(){
    cin>>n;
    ll dura[2*n-1];
    loop(i, 0, n-1)cin>>dura[2*i+1];
    loop(i, 0, n)  cin>>dura[2*i];

    ll salidaA[n+(n-1)], salidaB[n+(n-1)];
    salidaA[0] = dura[0];
    loop(i, 1, 2*n-1)salidaA[i] = salidaA[i-1] + dura[i];

    salidaB[2*n-2] = dura[2*n-2];
    for(ll i = 2*n-3; i>=0; --i) 
        salidaB[i] = salidaB[i+1] + dura[i];

    ll iniA,iniB,finA, finB, ini, fin;
    ll resp = 0;
    for(ll i = 0; i < 2*n-1;++i){
        if(i&1) continue;
        iniA = i==0? 0:salidaA[i-1];
        finA = salidaA[i];

        iniB = i==2*n-1? 0 : salidaB[i+1];
        finB = salidaB[i];
        ini = max(iniA, iniB);
        fin = min(finA, finB);
        if(fin - ini > 0)
            resp = max((ll)0, fin-ini);
    }
    cout<<resp<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    ll t = 1;
    //ll t; cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}