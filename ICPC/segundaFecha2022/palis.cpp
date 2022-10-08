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
void solve(int i){
    int ot = 0, ori  =i;
    while(i>0){
        ot <<= 1;
        if(i&1) 
        {
            ot += 1;
        }
        i>>=1;
    }
    if(ori == ot)
        cout<<ori<<endl;

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    ll t = (1LL<<31)-1;
    //int t; cin>>t;
    for(ll i = 0; i < t; ++i){
        solve(i);
    }
    return 0; 
}