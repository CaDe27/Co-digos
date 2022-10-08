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
#include <stdio.h>
#include <fstream>

using namespace std;
typedef int64_t ll;
typedef pair<int,int> pii;

#define INF 1000000000000
#define MOD 1000000007
#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 100005;
int n, arre[maxN];
void solve(){

}

int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    vector<int> a,b;
    int x;
    std::ifstream ins("palis.txt");
    int size = 98303;
    loop(it, 0, size){
        ins>>x;
        a.push_back(x);
    }
   
   std::ifstream ons("bb.txt");
    loop(it, 0, size){
        ons>>x;
        b.push_back(x);
    }
    cout<<a.size()<<" "<<b.size()<<endl;

    for(int i=0; i < min(a.size(), b.size()); ++i){
        if(a[i] != b[i]){
            cout<<i<<" "<<a[i]<<" "<<b[i]<<endl;
            break;
        }

    }
    return 0; 
}