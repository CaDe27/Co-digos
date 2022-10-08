#include <iostream>
#include <string>


using namespace std;
typedef int64_t ll;
#define loop(i,a,b) for(int i = a; i < b; ++i)

#define ODD 1
#define EVEN 0

const int maxN = 100005;
ll n;

string road;
int total = 0;
void dfs(int index, int parityR, int evens, int odds){
    if( (n&1)==ODD && (evens+1>(n+1)/2 || odds>(n+1)/2))
        return;
    if( (n&1)==EVEN && max(odds, 1+evens) > n/2 + 1)
        return;

    if(index == n){
        cout<<road<<"\n";
        ++total;
    }
    else{
        road[index] = 'b';
        if(parityR == EVEN)
            dfs(index+1, parityR, evens+1, odds);
        else    
            dfs(index+1, parityR, evens, odds+1);
        if(total == 100) return;

        road[index] = 'r';
        if(parityR == EVEN)
            dfs(index+1, parityR^1, evens, odds+1);
        else    
            dfs(index+1, parityR^1, evens+1, odds);
        if(total == 100) return;
    }
    
}

void solve(){
    cin>>n;
    road = string(n, 'z');

    ll resp = n&1? (n+1)*(n+1)/4 : (n/2)*(n/2 +1);
    cout<<resp<<"\n";
    dfs(0, EVEN, 0, 0); 
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //int t; cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}