#include<iostream>
#include<algorithm>
#include<set>

using namespace std;
#define loop(i, a, b) for(int i = a; i <b;++i)
typedef int64_t ll;

const int maxN = 200005;
pair<ll,int> arre[maxN];
set<pair<int, ll> > indexes;
int n;

void solve(){
    cin>>n;
    ll a;
    loop(i, 0, n){
        cin>>a;
        arre[i] = make_pair(a, i);
    }
    sort(arre, arre+n);
    ll resp = abs(arre[0].first);
    indexes.clear();
    indexes.insert(make_pair(arre[0].second, arre[0].first));
    
    set<pair<int, ll> > :: iterator it; 
    int bounds;
    ll difference;
    loop(i, 1, n){
        bounds = 0;
        difference = 1e15;
        it = indexes.upper_bound(make_pair(arre[i].second, arre[i].first));
        
        if(it != indexes.end()){
            ++bounds;
            difference = arre[i].first - it->second;
        }
        if(it != indexes.begin()){
            --it;
            ++bounds;
            difference = min(difference, arre[i].first - it->second);
        }
        if(bounds == 2)
            resp += 3*difference;
        else
            resp += difference;
        indexes.insert(make_pair(arre[i].second, arre[i].first));
    }
    cout<<resp<<"\n";
}
int main(){
    int t; cin>>t;
    while(t--){
        solve();
    }
}