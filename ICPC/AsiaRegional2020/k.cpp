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
typedef pair<ll,ll> pii;

#define INF 1000000000000
#define MOD 1000000007
#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 100005;
int n, arre[maxN];
map<int, pii> bucket;

ll gcd(ll a, ll b){
    if(a == 0)
        return b;
    else
        return gcd(b%a, a);
}

struct frac{
    ll x, y;
    frac(){ x = 0;y = 1;}
    frac(ll _x, ll _y): x(_x), y(_y){};
    bool operator < (const frac &p) const { return x*p.y < y*p.x;}
    frac operator + (const frac &p) const { return frac(x*p.y + y*p.x, y*p.y).normaliza(); }
    frac operator - (const frac &p) const { return frac(x*p.y - y*p.x, y*p.y).normaliza(); }
    frac operator * (const frac &p) const { return frac(x*p.x, y*p.y).normaliza(); }
    frac normaliza () const { ll g = gcd(x, y); return g==0? frac(x,y) : frac(x/g, y/g);}
};

void solve(){
    cin>>n;
    int s; char c;
    int totP=0, totM=0;
    loop(i, 0, n){
        cin>>c>>s;
        if(c=='+'){
            ++totP;
            bucket[s] = pii(bucket[s].first+1, bucket[s].second);
        }
        else{
            ++totM;
            bucket[s] = pii(bucket[s].first, bucket[s].second+1);
        }

    }
    ll tn =0, fn = 0;
    frac tpr, fpr; 
    map<frac, frac> fprs;
    ll fp, tp;
    for(auto par : bucket){
        tn += par.second.second;
        fn += par.second.first;
        tp = totP - fn;
        fp = totM - tn;
        tpr = frac(tp, tp+fn).normaliza();
        fpr = frac(fp, tn + fp).normaliza();
        fprs[fpr] = max(fprs[fpr], tpr);
    }
    fprs[frac(1,1)] = frac(0, 1);

    double resp = 0;
    double num1, num2;
    double  area;
    frac maxiTPR = frac(0, 1), antFPR = frac(0,1);
    for(auto pp : fprs){
        num1 =(double(maxiTPR.x))/maxiTPR.y;
        num2 = (double((pp.first - antFPR).x))/(pp.first - antFPR).y;
        area = num1*num2;
        resp += area;
        maxiTPR = max(maxiTPR, pp.second);
        antFPR = pp.first;
    }
    cout<<fixed<<setprecision(14)<<resp<<"\n";

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
