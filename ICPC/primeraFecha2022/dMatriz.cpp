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
#include <unordered_map>
using namespace std;
 
typedef int64_t ll;
 
#define MOD 1000000007
#define loop(i,a,b) for(int i = a; i < b; ++i)

struct matrix{
    vector< vector<ll> > m;
    ll mod, sz;
    ll mod2;
 
    matrix (ll n,ll modc) : sz(n),m(n), mod(modc) {
        for(int i=0;i<n;i++)
            m[i].resize(n);
        mod2=mod*mod;
    }
 
    matrix operator*(matrix b)
    {
        matrix ans(sz,mod);
        for(int i=0;i<sz;i++)
        for(int j=0;j<sz;j++)
            for(int u=0;u<sz;u++)
            {
                ans.m[i][u]+=m[i][j]*b.m[j][u];
                if(ans.m[i][u]>=mod2)
                    ans.m[i][u]-=mod2;
            }
        for(int i=0;i<sz;i++)
            for(int j=0;j<sz;j++)
                ans.m[i][j]%=mod;
        return ans;
    }
 
    matrix pow(ll e)
    {
        if(e==1)
            return *this;
        matrix x =pow(e/2);
        x=(x*x);
        if(e&1)
            x=(x*(*this));
        return x;
    }
};


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, k;
	cin>>n>>m>>k;
    matrix grafo(n, MOD);

    int a,b;
	loop(i, 0, m){
        cin>>a>>b;
        --a;--b;
        grafo.m[a][b] = grafo.m[b][a] = 1;
    }
    
    grafo = grafo.pow(k);
    ll resp = 0;
    loop(i, 0, n)
        resp = (resp + grafo.m[0][i])%MOD;
    cout<<resp<<"\n";
}