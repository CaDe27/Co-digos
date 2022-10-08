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
int n, tot = 0;
vector<string> words;
string w= "aaaaaa";

void segundaP();
void aumenta();
void primeraP(){
    while(w[0] != 'z'){
        segundaP();
        w[0] += 1;
        words.push_back(w);
        w[1] += 1;
        words.push_back(w);
    }
    segundaP();
}

void segundaP(){
   if(w[2] == 'a'){
        while(w[2] != 'z'){
            aumenta();
            w[3] += 1;
            words.push_back(w);
            w[2] += 1;
            words.push_back(w);
        }
        aumenta();
    }
    else{
        while(w[2] != 'a'){
            aumenta();
            w[3] -= 1;
            words.push_back(w);
            w[2] -= 1;
            words.push_back(w);
        }
        aumenta();
    }
}

void aumenta(){
    if(w[w.size()-1] == 'a'){
        while(w[4] != 'z'){
            w[4] += 1;
            words.push_back(w);
            w[5] += 1;
            words.push_back(w);
        }
    }
    else{
        while(w[4] != 'a'){
            w[w.size()-1] -= 1;
            words.push_back(w);
            w[w.size()-2] -= 1;
            words.push_back(w);
        }
    }
    
}
void solve(){
    cin>>n;
    words.push_back(w);
    primeraP();
    loop(i, 0, n){
        cout<<words[i]<<"\n";
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