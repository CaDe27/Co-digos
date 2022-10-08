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
string solve(){
    cin>>n;
    vector<string> w(n);
    bool hay[26+5];
    fill(begin(hay), end(hay), false);
    loop(i, 0, n) cin>>w[i];
    loop(i, 0, n){
        hay[w[i][0]-'A'] = true;
    }
    int cont;
    loop(i, 0, n){
        cont = 0;
        loop(j, 0, w[i].size()){
            if(hay[w[i][j]-'A']) ++cont;
        }
        if(cont == w[i].size())
            return "Y";
    }
    return "N";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t = 1;
    //int t; cin>>t;
    loop(i, 0, t){
        cout<<solve()<<"\n";
    }
    return 0; 
}