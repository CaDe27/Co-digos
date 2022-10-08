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
int n, m, part[maxN], uh[maxN], cheaper[maxN];
int solve(){
    cin>>n>>m;
    loop(i, 1, n+1){
        cin>>uh[i];
    }
    int a, b;
    fill(part, part+n+1, 0);
    loop(i, 1, n+1){
        cheaper[i] = 1e6;
    }
    loop(i, 0, m){
        cin>>a>>b;
        part[a]++;
        part[b]++;
        cheaper[a] = min(cheaper[a], uh[b]);
        cheaper[b] = min(cheaper[b], uh[a]);
    }
    ll resp = 0, caseResp;
    if( (m&1) == 0){
        return resp;
    }
    else{
        resp = 1e9;
        loop(i,1,n+1){
            if(part[i] & 1){
                resp = min(resp, (ll)uh[i]);
            }
            else{
                caseResp = uh[i] + cheaper[i];
                resp = min(resp, (ll)caseResp);        
            }
        }
        return resp;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    //int t = 1;
    int t; cin>>t;
    loop(i, 0, t){
        cout<<solve()<<"\n";
    }
    return 0; 
}
