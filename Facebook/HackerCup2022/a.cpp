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

const int maxN = 1e2 + 5;
int n, k;
int bucket[maxN];
string solve(){
    string resp = "YES";
    cin>>n>>k;
    int s;
    fill(bucket, bucket + 101, 0);
    
    if(2*k < n) resp = "NO";
    loop(i, 0, n){
        cin>>s;
        bucket[s]++;
        if(bucket[s] == 3)
            resp="NO";
    }
    return resp;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    loop(i, 0, t){
        cout<<"Case #"<<(i+1)<<": "<<solve()<<"\n";
    }
    return 0; 
}