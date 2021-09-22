#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5+10;
vector<int> G[MAXN];
int dp[MAXN];
int P[MAXN];
const int INF = 1e9;
const int MOD = 998244353;

ll fast(ll a, ll b){
    if(b == 0) return 1;
    if(b == 1) return a%MOD;
    ll c = fast(a,b/2);
    c = (c*c)%MOD;
    if(b&1){
        c *= a;
        c %= MOD;
    }
    return c;
}

void dfs(int u, int p){
    for(auto v:G[u]){
        if(v != p){
            dfs(v,u);
            dp[u] = min(dp[u],dp[v]+1);
        }
    }
    if(G[u].size() == 1 && u != 1){
        dp[u] = 1;
    }
}

void q(int u){
    for(auto v:G[u]){
        if(v != P[u]){
            dp[u] = min(dp[u],dp[P[u]]+1);
            q(v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    P[1] = 1;

    for(int i=2;i<=n;i++){
        int a; cin >> a;
        G[a].push_back(i);
        G[i].push_back(a);
        P[i] = a;
    }

    for(int i=1;i<=n;i++){
        dp[i] = INF;
    }

    dfs(1,1);
    q(1);

    ll Q = 0;

    for(int i=1;i<=n;i++){
        Q += dp[i];
    }

    Q %= MOD;

    ll r = fast(n,MOD-2);

    cout << (Q*r)%MOD << "\n";

    return 0;
}
