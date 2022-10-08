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

const int maxN = 100005;
ll arre[25];
ll n, x;
int active[25];
ll gcd(ll a, ll b){
    if(a == 0) return b;
    return gcd(b%a, a);
}

ll cuenta(){
    ll tot = 0;
    ll lcm;
    loop(i, 0, n)
        if(active[i]==1){
            lcm = arre[i];
            break;        
        }
    loop(i, 0, n){
        if(lcm > x) return 0;
        if(active[i]==1)
            lcm = lcm*arre[i]/gcd(lcm,arre[i]);
    }
    return x/lcm;
}
void solve(){
    cin>>n>>x;
    ll resp = 0;
    loop(i, 0, n) cin>>arre[i];
    
    loop(i, 0, n){  // cuántos unos activos   0
        cout<<i<<" ceros"<<endl;
        loop(j, 0, i) active[j] = 0;
        loop(j, i, n) active[j] = 1;
        do{
            if( (n-i) & 1)
                resp += cuenta();
            else
                resp -= cuenta();
            
            loop(k, 0, n)
                cout<<active[k];
            cout<<endl;
        }while(next_permutation(active, active+n));
    }
    cout<<resp<<"\n";    
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