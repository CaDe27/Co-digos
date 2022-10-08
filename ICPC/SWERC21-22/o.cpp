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
typedef pair<int,int> pii;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)

bool h[21][360], v[21][360], vis[21][360];

void limpia(){
    loop(i, 0, 21){
        fill(v[i], v[i]+360, 0);
        fill(h[i], h[i]+360, 0);
        fill(vis[i], vis[i]+360, 0);
    }
}

void dfs(int i, int j){
    if(vis[i][j]) return;
    vis[i][j] = true;

    if(!vis[i][(j+360-1)%360] && !v[i][j])
        dfs(i, (j+360-1)%360);

    if(!vis[i][(j+1)%360] && !v[i][(j+1)%360])
        dfs(i, (j+1)%360);
    
    if(i > 0 && !vis[i-1][j] && !h[i][j])
        dfs(i-1, j);
    
    if(i < 20 && !vis[i+1][j] && !h[i+1][j])
        dfs(i+1, j);
}

void solve(){
    limpia();
    int n; cin>>n;
    char letter;
    int r1, r2, o1, o2;
    loop(i, 0, n){
        cin>>letter;
        if(letter == 'C'){
            cin>>r1>>o1>>o2;
            for(int i = o1; i != o2; i= (i+1)%360)
                h[r1][i] = 1;
        }
        else{
            cin>>r1>>r2>>o1;
            loop(i, r1, r2)
                v[i][o1] = 1;
        }
    }
    dfs(0, 0);
    string resp = vis[20][0]? "YES" : "NO";
    cout<<resp<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    //int t = 1;
    int t; cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}