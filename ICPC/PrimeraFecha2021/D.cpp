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
#include <fstream>

using namespace std;

typedef int64_t ll;

typedef pair<int,ll> pill;
typedef vector<pill> vill;

typedef pair<int,int> pii;
typedef pair<pii,int> piii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<int, pii> viii;

#define MINF -1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(ll i = a; i < b; ++i)
int n; 
struct pizza{
    int ing[4];
}pizzas[100005];


ll tiempo(const pizza &a, const pizza &b){
    int it1 = 0, it2 = 0;
    int curr1, curr2;
    ll resp = 0;
    curr1 = a.ing[0];
    curr2 = b.ing[0];
    while(it1 != 4){
        if(it1 == it2){
            resp += curr1;
            ++it1;
            if(it1 < 4) curr1 = a.ing[it1];
        }
        else{
            if(curr1 < curr2){
                resp += curr1;
                curr2 -= curr1;
                ++it1;
                if(it1 < 4) curr1 = a.ing[it1];
            }
            else{
                resp += curr2;
                curr1 -= curr2;
                ++it2;
                curr2 = b.ing[it2];
            }
        }
    }
    
    resp += curr2;
    ++it2;
    while(it2 != 4){
        resp += b.ing[it2];
        ++it2;
    }

    return resp;
}

ll tiempo2(int a, int b){
    int it1 = 0, it2 = 0;;
    ll resp = 0;
    while(it1 != 4){
        if(it1 == it2){
            resp += pizzas[a].ing[it1];
            pizzas[a].ing[it1] = 0;
            ++it1;
        }
        else{
            if(pizzas[a].ing[it1] < pizzas[b].ing[it2]){
                resp += pizzas[a].ing[it1];
                pizzas[b].ing[it2] -= pizzas[a].ing[it1];
                pizzas[a].ing[it1] = 0;
                ++it1;
            }
            else{
                resp += pizzas[b].ing[it2];
                pizzas[a].ing[it1] -= pizzas[b].ing[it2];
                ++it2;
                pizzas[b].ing[it2] = 0;
            }
        }
    }
    
    resp += pizzas[b].ing[it2];
    ++it2;
    while(it2 != 4){
        resp += pizzas[b].ing[it2];
        ++it2;
    }

    return resp;
}

bool f(const pizza &a, const pizza &b){
    return tiempo(a, b) < tiempo(b, a);
}

const int N  = 100005;
int T1[N+1],T2[N+1],T3[N+1],T4[N+1];
int A[N+1],B[N+1],C[N+1],D[N+1];
    
void solve(){
   cin>>n;
   loop(i, 0, n){
       loop(j, 0, 4)
        cin>>pizzas[i].ing[j];
   }
   sort(pizzas, pizzas + n, f);
    ll resp = 0;
    T1[0] = T2[0] = T3[0] = T4[0] = 0;
    
    loop(i, 0, n){
        A[i] = pizzas[i].ing[0];
        B[i] = pizzas[i].ing[1];
        C[i] = pizzas[i].ing[2];
        D[i] = pizzas[i].ing[3];
    }
    for(int i=1;i<=N;i++){
        T1[i] = (T1[i-1]+A[i]);
    }

    for(int i=1;i<=N;i++){
        T2[i] = (max(T2[i-1],T1[i])+B[i]);
    }

    for(int i=1;i<=N;i++){
        T3[i] = (max(T3[i-1],T2[i])+C[i]);
    }

    for(int i=1;i<=N;i++){
        T4[i] = (max(T4[i-1],T3[i])+D[i]);
    }

    cout << T4[N] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    /*pizza a, b;
    a.ing[0] = 0;
    a.ing[1] = 0;
    a.ing[2] = 25;
    a.ing[3] = 10;

    b.ing[0] = 10;
    b.ing[1] = 25;
    b.ing[2] = 15;
    b.ing[3] = 0;

    cout<<tiempo(a, b)<<endl;
    */
    int t = 1;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}