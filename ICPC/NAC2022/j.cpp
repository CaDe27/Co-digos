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
#define X 'X'
#define O 'O'
const int maxN = 200005;
bool visitados[maxN];
int omemo[maxN], xmemo[maxN];
string s;

int getNumber() {
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        ans *= 3;
        if (s[i] == X) {
            ans += 2;
        } else if (s[i] == O) {
            ans += 1;
        }
    }
    return ans;
}

char S(int i, int j) {
    return s[i * 3 + j];
}

bool hayGanador(){
    loop(i, 0, 3){
        if(S(i,0) == S(i,1) && S(i,1) == S(i,2) && S(i, 0)!='.')
            return true;
        if(S(0, i)==S(1,i) && S(1,i)==S(2,i) && S(0,i)!='.')
            return true;
    }
    //diagonales
    if(S(0, 0) == S(1,1) && S(1,1) == S(2,2) && S(1, 1)!='.')
        return true;
    if(S(0, 2) == S(1,1) && S(1,1) == S(2,0) && S(1, 1)!='.')
        return true;
    return false;
}

void genera(char sig){
    int numero = getNumber();
    if(visitados[numero]) return;
    visitados[numero] = true;

    if(hayGanador()){
        if(sig == X) omemo[numero] = 1;
        else xmemo[numero] = 1;
        return;
    }
    //si no gana nadie, expando
    int numeroHijo;
    loop(i, 0, 9){
        if(s[i] != '.') continue;
        s[i] = sig;
        numeroHijo = getNumber();
        genera(sig == X? O : X);
        xmemo[numero] += xmemo[numeroHijo];
        omemo[numero] += omemo[numeroHijo];
        s[i] = '.';
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    s = ".........";
    genera(X);
    int t; cin>>t;
    int numero;
    loop(i, 0, t){
        cin>>s;
        numero = getNumber();
        if(visitados[numero])
            cout<<s<<" "<<xmemo[numero]<<" "<<omemo[numero]<<"\n";
        else{
            cout<<s<<" -1 -1\n";
        }
    }
    return 0; 
}