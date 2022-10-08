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
int w, l;
int gcd(int a, int b){
    if(a == 0)
        return b;
    else
        return gcd(b%a, a);
}


set<int> divs;
void addDivs(int g){
    for(int i = 1; i*i <= g; ++i){
        if(g%i == 0){
            divs.insert(i);
            divs.insert(g/i);
        }
    }
}
void solve(){
    cin>>w>>l;
    divs.clear();
    divs.insert(1);
    divs.insert(2);
    addDivs(gcd(w-1, l-1));
    addDivs(gcd(w, l-2));
    addDivs(gcd(w-2, l));
    cout<<divs.size();
    for(int d : divs){
        cout<<" "<<d;
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    //int t = 1;
    int t; cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}
