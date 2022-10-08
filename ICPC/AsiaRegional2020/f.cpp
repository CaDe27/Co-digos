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

const int maxN = 1000005;
int n, arre[maxN];
void solve(){
    cin>>n;
    vector<pii> r(n);
    loop(i, 0, n){
        cin>>arre[i];
        r[i] = pii(arre[i], i);
    }
    sort(r.begin(), r.end());

    int grupos = 0, actual = n, posMin = n;
    while(actual > 0){
        do{
            --actual;
            posMin = min(posMin, r[actual].second);
        }while(actual != posMin);
        ++grupos;
    }
    cout<<grupos<<"\n";
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
