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
int n,m, arre[maxN];
pii rain[maxN];
vector<pair<pii, pii> > events;
void solve(){
    cin>>n>>m;
    events.clear();
    int xi, pi;
    loop(i, 0, n){
        cin>>xi>>pi;
        rain[i] = pii(xi ,pi);
        events.push_back(make_pair( pii(xi, pi), pii(1,1)));
        events.push_back(make_pair( pii(xi+pi, 0), pii(1, -1)) );

        events.push_back(make_pair( pii(xi-pi, 0), pii(0,1)));
        events.push_back(make_pair( pii(xi, 0), pii(0, -1)) );
    }
    
    sort(events.begin(), events.end());
    map<int, ll> flood;
    ll ctSuman = 0, ctResta = 0;
    ll suma=0, resta=0;
    int last = 0;
    for(auto e : events){
        xi = e.first.first;
        suma += ctSuman * (xi - last);
        resta -= ctResta * (xi - last);
        flood[xi] += suma + resta;
        if(e.second.first == 1){
            
        }
    }


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
