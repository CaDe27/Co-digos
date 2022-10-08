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
typedef long long ll;

 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n = 20;
    int ans = 0;
    vector<string> S;
    
    for(int i=0;i<(1<<n);i++){
        int s = 0;
        int evens = 1;
        string k = "";
        
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                k += "1";
            }
            else
                k += "0";
        }
            
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                s++;
                if(s%2 == 0){
                    evens++;
                }
            }
            else{
                if(s%2 == 0){
                    evens++;
                }
            }
        }
        if((evens == (n+2)/2) || (evens == (n+1)/2)){
            ans++;
            S.push_back(k);
        }
    }
    
    sort(S.begin(),S.end());
    
    for(int i=0;i<100 && i < S.size();i++){
        cout << i << ": " << S[i] << "\n";
    }
    
    cout << "For " << n << " ans is " << ans << "\n";
    

    
    return 0;
}