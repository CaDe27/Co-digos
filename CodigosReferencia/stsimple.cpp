
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
#include <sstream>
#include <unordered_map>

using namespace std;

typedef int64_t ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;

#define MINF -1000000000000
#define MOD 1000000007

#define m(a,b) (a%b + b)%b
#define loop(i,a,b) for(int i = a; i < b; ++i)
#define invl(i,a,b) for(int i = a; i > b; --i)

const int maxN = 2*1e5;
int n;

unordered_map<int, int> comp;
vector<pair<pii, int> > pares;
vector<pair<pii, int> > espera;
int resp[maxN + 5];

int l[4*maxN+5], r[4*maxN+5], f[4*maxN+5]; 
    
    //procedure to initiliaze segment tree
    void init(int i, int a, int b){
        l[i] = a;
        r[i] = b;
        if(a==b) return;
        int m = (a+b)/2;
        init(2*i, a, m);
        init(2*i+1, m+1, b);
    }
    
    void SegmentTree(){
        init(1, 1, maxN+5);
    }

    void update(int i, int a, int val){
        //if I'm totally out of the segment, don't do nothing
        if(a < l[i] || r[i] < a)
            return;
        
        //if I'm fully contained in the segment update my lazy
        //funct update is only made when you update children
        if(l[i] == r[i]){
            //this may change depending on how update works on certain problem
            f[i] = val;
        }
        else{
        //apply my lazy changes to my children and lazy update them 
            if( r[2*i] >= a) update(2*i, a, val);
            else update(2*i+1, a, val); 

            f[i] = max(f[2*i], f[2*i+1]);
        }
    }

    void update(int a, int val){
        update(1, a, val);
    }

    int query(int i, int a, int b){
        if(b < l[i] || r[i] < a)
            return 0; 

        if(a <= l[i] && r[i] <= b)
            return f[i];

        //BE CAREFUL with overflow
        int leftQ =  query(2*i, a, b);
        int rightQ = query(2*i+1, a, b);

        return max(leftQ, rightQ);
    }

    int query(int a, int b){
        return query(1, a, b);
    }



void solve(){
    cin>>n;

    pares.clear();
    comp.clear();
    espera.clear();
    fill(f, f + 4*maxN + 1, 0);


    vector<int> todas;
    int a, b;
    loop(i, 0, n){
        cin>>a>>b;
        if(a > b) swap(a, b);
        pares.push_back(make_pair(pii(a, b), i+1));
        todas.push_back(b);
    }
     
    //compresion de coordenadas
    sort(todas.begin(), todas.end());
    int indx = 0, anterior = 0;
    for(int v : todas){
        if(v > anterior){++indx; comp.insert( pii( v,indx) ); }//cout<<"map "<<v<<" "<<indx<<endl;}
        anterior = v;   
    }
    

    //resolvemos queries
    sort(pares.begin(), pares.end());
    int size = pares.size(), altura;
    loop(i, 0, size){
        altura = pares[i].first.second;
        resp[pares[i].second] = (comp[altura]-1 == 0)? -1 : query(1, comp[altura]-1 );

        espera.push_back(pares[i]);
        if(i < size && pares[i].first.first < pares[i+1].first.first){
            while(!espera.empty()){
                altura = espera.back().first.second;
                indx = espera.back().second;
                update(comp[altura], indx);
                espera.pop_back();
            }
        }
    }

    cout<<resp[1];
    loop(i, 2, n+1){cout<<" "<<resp[i];}
    cout<<"\n";


}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    SegmentTree();
    loop(i, 0, t){
        solve();
    }
}
    
