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
int n, arre[maxN];
ll s[maxN],d[maxN], tTot;
map<int, multiset<pii> >atras, enfrente;
vector<int> respE, respA;

void leeLinea(map<int, multiset<pii> > &linea){
    vector<pair<int, pii> > a;
    vector<int> price(n), height(n);

    loop(i, 0, n){
        cin>>price[i];
    }
    loop(i, 0, n){
        cin>>height[i];
    }
    loop(i, 0, n){
        linea[price[i]].insert(pii(height[i], i));
    }
}

void solve(){
    cin>>n;

    leeLinea(atras);
    leeLinea(enfrente);
    
    map<int, multiset<pii> >::iterator itA, itE;
    itA = atras.begin(); 
    itE = enfrente.begin();
    while(itA != atras.end() && itE != enfrente.end()){
        int sizeA = itA->second.size();
        int sizeE = itE->second.size();

        multiset<pii> ::iterator it;
        if(sizeA < sizeE){
            //por cada uno en A borro al mayor que le gano en E
            for(pii v : itA->second){
                it = itE->second.lower_bound(pii(v.first, -1));
                if(it == itE->second.begin()){
                    cout<<"impossible\n";
                    return;
                }
                --it;
                respE.push_back(it->second);
                respA.push_back(v.second);

                itE->second.erase(it);
            }
            ++itA;
        }
        else{
            //por cada uno en E borro el primero mas grande en A
            for(pii v : itE->second){
                it = itA->second.upper_bound(pii(v.first,1e6));
                if(it == itA->second.end()){
                    cout<<"impossible\n";
                    return;
                }
                respE.push_back(v.second);
                respA.push_back(it->second);
                itA->second.erase(it);
            }
            ++itE;
        }
    }

    loop(i, 0, n){
        if(i > 0) cout<<" ";
        cout<<1+respA[i];
    }
    cout<<"\n";
    loop(i, 0, n){
        if(i > 0) cout<<" ";
        cout<<1+respE[i];
    }
    cout<<"\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t = 1;
    //int t; cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}