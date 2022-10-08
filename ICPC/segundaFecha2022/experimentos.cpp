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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int n = 5;
    int j;
    loop(i, 1, 1<<n){
        string x;
        j = i;
        while(j!=0){
            if(j&1){
                x = "1"+x;
            }
            else
                x = "0"+x;
            j>>=1;
        }
        cout<<i<<" "<<x<<endl;
    }
    return 0; 
}