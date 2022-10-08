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
int dia(string s){
    if(s == "Mon")
        return 0;
    if(s == "Tue")
        return 1;
    if(s == "Wed")
        return 2;
    if(s == "Thu")
        return 3;
    if(s == "Fri")
        return 4;
    if(s == "Sat")
        return 5;
    else
        return 6;
}

int espero(int hoy, int d){
    int ini = d%7;
    ini = (hoy + (7-ini)) % 7;
    int pasado = 0;
    do{
        if(ini == 0 && d >= 91){
            d %= 91;
        }
        else if(ini == 0){
            ini = 2;
            d -= 30;
        }
        else if(ini == 2){
            ini = 4;
            d -= 30;
        }
        else if(ini == 4){
            ini = 0;
            d -= 31;
        }
        else if(ini == 1){
            ini = 3;
            d -= 30;
        }
        else if(ini == 3){
            ini = 0;
            d -= 32;
        }
    }while(d > 0);
    return abs(d);
}

void solve(){
    string s; int n, hoy;
    cin>>s>>n;
    hoy = dia(s);
    int resp = 100, d;
    loop(i, 0, n){
        cin>>d;
        resp = min(resp, espero(hoy, d));
    }
    cout<<resp<<"\n";
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