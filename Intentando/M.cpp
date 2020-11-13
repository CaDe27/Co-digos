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
#include <unordered_map>
#include <sstream>

using namespace std;

typedef int64_t ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

#define MOD 188888881

#define m(a,b) (a%b + b)%b
#define loop(i,n) for(int i = 0; i < n; ++i)    

const int maxN = 405;
int n;

void solve(){

    ll total = 0, una = 1;
    ll l[4], u[4];
    loop(i, 4){
        cin>>u[i]>>l[i];
    }
    loop(i, 4) 
        una *= (l[i]-u[i]+1);    

    total =una*una;
    
    ll otras, gauss, miMin, low, up;
    
    if(u[0] == 0 && u[1] == 0 && u[2] == 0 && u[3] == 0){
        for(int j = 0; j <= 3; ++j){
            otras = una/(l[j]-u[j]+1);
            gauss = (l[j])*(l[j]+1)/2;
            total -= otras*gauss;
        }
    }
    cout<<total<<endl;
    
    bool sePuede;
    for(int j = 0; j<=3; ++j){
        sePuede = true;
        for(int i = 0; i <= 3; ++i){
            if(u[i]>0 && i != j) sePuede = false;
        }
        if(!sePuede || l[j]==0) continue;

        otras = una/(l[j]-u[j]+1);
        miMin = max(l[j]+1, 2*u[j]);
        low = miMin - 2*u[j] - 1;
        up = 2*l[j] - 2*u[j];
        low = low*(low+1)/2;
        up = up*(up+1)/2;
        total -= otras*(up - low);
    }



    cout<<total<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;


    loop(i, n){
        solve();
    }
   

    return 0; 

}
