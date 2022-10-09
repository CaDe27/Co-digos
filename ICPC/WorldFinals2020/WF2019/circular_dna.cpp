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

const int maxN = 1e6+1;
int n;
vector<pii> types[maxN], events;


int stringToInt(string s){
    int resp = 0;
    for(char c : s)
        resp= resp*10 + (c-'0');
    return resp;
}

vector<pii> arre;
void generateIntervals(int z){
    if(types[z].empty()) return;
    arre.clear();
    {
        int suma = 0;
        for(pii e : types[z]){
            arre.push_back(e);
            suma += e.second;
        }
        if(suma != 0) return;
    }

    int posMin = 0, sumaMin = arre[0].second;
    int suma = arre[0].second;
    for(int i = 1; i < arre.size(); ++i){
        suma += arre[i].second;
        if(suma < sumaMin){
            posMin = i;
            sumaMin = suma;
        }
    }

    //(0 1) (1, 1) (3 -1) (5 -1)
    suma = 0; 
    int i = (posMin+1)%arre.size();
    for(int z = 0; z < arre.size(); z++){
        suma += arre[i].second;
        if(suma == 0){
            if(i == arre.size()-1){
               events.push_back(pii(0, 1));
               events.push_back(pii(arre[0].first+1, -1));
               events.push_back(pii(arre[i].first+1, 1));
            }
            else{
                events.push_back(pii(arre[i].first+1, +1));
                events.push_back(pii(arre[i+1].first+1, -1));
            }
        }
        i = (i+1)%arre.size();
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    cin>>n;
    string x;
    int indx;
    loop(i, 0, n){
        cin>>x;
        indx = stringToInt(x.substr(1));
        types[indx].push_back(pii(i, x[0] == 's'? 1 : -1));
    }

    loop(i, 1, 1e6+1){
        generateIntervals(i);
    }

    sort(events.begin(), events.end());
    int p = 0, m = 0, acum = 0;
    for(pii e : events){
        acum += e.second;
        if(acum > m){
            p = e.first;
            m = acum;
        }
    }
    cout<<p+1<<" "<<m<<endl;
    return 0; 
}