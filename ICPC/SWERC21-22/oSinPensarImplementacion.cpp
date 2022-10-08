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
using namespace std;

typedef int64_t ll;
typedef pair<int,int> pii;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 100005;
int n, arcos[21][360], lineas[21][360], uf[21*360*2+20];
map<pii, int> lpi, upi; 

void mapea(){
    int id = 1;
    loop(i, 0, 21)
    loop(j, 0, 360){
        lpi.insert(make_pair(pii(i, j), id));

        upi.insert(make_pair(pii(i, j), id+21*360));  
        ++id;
    }
}

void limpia(){
    loop(i, 0, 21){
        fill(arcos[i], arcos[i]+360, 0);
        fill(lineas[i], lineas[i]+360, 0);
    }
    loop(i, 0, 21*360*2+20)
        uf[i] = i;
}


pii helper;
int ancestor(int v){
    if(uf[v] == v)
        return uf[v];
    else
        return uf[v] = ancestor(uf[v]);
}

void unite(int u, int v){
    int u1, u2;
    u1 = ancestor(u);
    u2 = ancestor(v);
    uf[u2] = u1;

}


void uneArcosMisma(){
    //por arriba
    loop(r, 1, 21){
        loop(o, 0, 359){
            if(r == 20 || lineas[r][o+1]==0)
                unite( upi[pii(r, o)], upi[pii(r, o+1)]);
        } 
        //angulo 359
        if(r == 20 || lineas[r][0]==0)
             unite(upi[pii(r, 359)], upi[pii(r, 0)]);
    }

    //por abajo
    loop(r, 1, 21){
        loop(o, 0, 359){
            if(r == 1 || lineas[r-1][o+1]==0)
                unite( lpi[pii(r, o)],lpi[pii(r, o+1)]);
        } 
        //angulo 359
        if(r ==1 || lineas[r-1][0]==0)
             unite(lpi[pii(r, 359)], lpi[pii(r, 0)]);
    }
}

void uneArcosDif(){
    loop(r, 1, 20){
    loop(o, 0, 359){
        unite( upi[pii(r, o)], lpi[pii(r+1, o)]);
    }
    }
}


void solve(){
    limpia();
    cin>>n;
    char letter;
    int r1, r2, o1, o2;
    loop(i, 0, n){
        cin>>letter;
        if(letter == 'C'){
            cin>>r1>>o1>>o2;
            int i = o1; 
            while(i != o2){
                arcos[r1][i] = 1;
                ++i;
                if(i == 360) 
                    i = 0;
            }
        }
        else{
            cin>>r1>>r2>>o1;
            loop(i, r1, r2){
                lineas[i][o1] = 1;
            }
        }
    }

    loop(i, 0, 359)
        uf[lpi[pii(1, i)]] = 0;
    //uno la parte superior e inferior del arco solo si 
    //no hay pared
    loop(r, 1, 21)
    loop(o, 0, 360){
        if(arcos[r][o] == 0){
            unite(lpi[pii(r,o)], upi[pii(r, o)]);
        }
    }    
    uneArcosMisma();
    uneArcosDif();
    string resp = "NO";
    if(ancestor(upi[pii(20, 0)]) == ancestor(0))
        resp = "YES";
    cout<<resp<<"\n";

    //cout<<ancestor(lpi[pii(10, 180)])<<" "<<ancestor(upi[pii(10, 145)])<<endl;

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    //int t = 1;
    mapea();
    int t; cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}
