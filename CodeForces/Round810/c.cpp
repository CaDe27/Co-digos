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
ll n,m, k;
ll arre[maxN], num[maxN];;
string solve(){
    cin>>n>>m>>k;
    loop(i, 0, k)
        cin>>arre[i];
    
    //check for columns
    ll maxi = 0, total = 0, add;
    loop(i, 0, k){
        add = arre[i]/n;
        if(add == 1) continue;
        if(total == m-1 && add == 2 && maxi < 3) continue;
        total += add;
        maxi = max(maxi, add);
        if(total >= m) return "Yes";
    }

    //for rows
    maxi = total = 0;
    loop(i, 0, k){
        add = arre[i]/m;
        if(add == 1) continue;
        if(total == n-1 && add == 2 && maxi < 3) continue;
        total += add;
        maxi = max(maxi, add);
        if(total >= n) return "Yes";
    }
    return "No";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    //int t = 1;
    int t; cin>>t;
    loop(i, 0, t){
        cout<<solve()<<"\n";;
    }
    return 0; 
}
