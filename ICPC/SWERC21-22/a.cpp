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

using namespace std;

typedef int64_t ll;
typedef pair<int,int> pii;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 100005;
int n, arre[11];
void solve(){
    cin>>n;
    int b, d, cont =0;
    fill(arre, arre+11, -1);
    loop(i, 0, n){
        cin>>b>>d;
        if(arre[d] == -1) ++cont;
        arre[d] = max(arre[d], b);
    }
    if(cont == 10){
        int total = 0;
        loop(i,1, 11) 
            total += arre[i];
        cout<<total<<"\n";
    }
    else{
        cout<<"MOREPROBLEMS\n";
    }
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
