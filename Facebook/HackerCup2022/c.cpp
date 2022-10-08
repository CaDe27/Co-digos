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

const int maxN = 105;
int n; 
vector<string> codesDot, codesDash;

void generate(string path, vector<string> &container){
    if(path.length() == 10)
        container.push_back(path);
    else{
        generate(path+".", container);
        generate(path+"-", container);
    }
}

void solve(){
    cin>>n;
    string code; cin>>code;
    if(code[0] =='.'){
        loop(i, 0, n-1)
            cout<<codesDash[i]<<"\n";
    }
    else{
        loop(i, 0, n-1)
            cout<<codesDot[i]<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    generate(".", codesDot);
    generate("-", codesDash);
    int t; cin>>t;
    loop(i, 0, t){
        cout<<"Case #"<<(i+1)<<":\n";
        solve();
    }
    return 0; 
}