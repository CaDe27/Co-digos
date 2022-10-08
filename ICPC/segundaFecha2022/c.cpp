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
int n, m, arre[maxN];
unordered_map<int, unordered_set<int> > requests;
map<int, unordered_set<int> > changes;

bool f_abs(const int &a, const int &b){
    return abs(a) < abs(b);
}

void solve(){
    cin>>n>>m;
    int id, r, c;
    loop(i, 0, n){
        cin>>id>>r;
        loop(j, 0, r){
            cin>>c;
            requests[id].insert(c);
        }
    }
    int notR=0, missed =0;
    loop(i, 0, m){
        cin>>id>>r;
        loop(j, 0, r){
            cin>>c;
            if(requests[id].find(c) == requests[id].end()){
                ++notR;
                changes[id].insert(-c);
            }
            else{
                requests[id].erase(c);
            }
        }
        
    }
    for(auto p:requests){
        for(int x : p.second){
            ++missed;
            changes[p.first].insert(x);
        }
    }
    int foo[16];
    if(missed>0 || notR > 0){
        
        for(auto p : changes){
            int indx=0;
            cout<<p.first;
            for(int change:p.second)
                foo[indx++] = change;
            sort(foo, foo+indx, f_abs);
            loop(z, 0, indx){
                if(foo[z] > 0)
                    cout<<" +"<<foo[z];
                else
                    cout<<" "<<foo[z];
            }
            cout<<"\n";
        }
        cout<<"MISTAKES IN "<<changes.size()<<" STUDENTS: "<<notR<<" NOT REQUESTED, "<<missed<<" MISSED\n";
    }
    else{
        cout<<"GREAT WORK! NO MISTAKES FOUND!\n";
    }
    
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