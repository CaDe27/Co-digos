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
#define rock '#'
#define tree '^'
using namespace std;
typedef int64_t ll;
typedef pair<int,int> pii;

#define INF 1000000000000
#define MOD 1000000007
#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxR = 3005, maxC = 3005;
int r, c;
char mat[maxR][maxC];
bool canBeTree[maxR][maxC];
pii moves[4] = {pii(0,1), pii(0,-1), pii(1,0), pii(-1,0)};

bool IsInvalid(int i, int j){
    if(i < 0 || i >= r) return true;
    if(j < 0 || j >= c) return true;
    if(mat[i][j] == rock) return true;
    if(!canBeTree[i][j]) return true;
    return false;
}

bool CanBeTree(int i, int j){
    int validNeighbors = 4;
    for(pii move : moves){
        if(IsInvalid(i+move.first, j + move.second))
            --validNeighbors;
    }
    return validNeighbors >= 2;
}

bool possible(){
    cin>>r>>c;
    loop(i, 0, r)
    loop(j, 0, c){
        canBeTree[i][j] = true;
        cin>>mat[i][j];
    }

    queue<pii> invalid;
    loop(i, 0, r)
    loop(j, 0, c){
        if(mat[i][j] != rock && !CanBeTree(i, j)){
            invalid.push(pii(i, j));
        }
    }

    int row, column;
    bool resp = true;
    while(!invalid.empty()){
        row = invalid.front().first;
        column = invalid.front().second;
        invalid.pop();
        if(!canBeTree[row][column]) continue;

        canBeTree[row][column] = false;
        if(mat[row][column] == tree) resp = false;

        for(pii move : moves){
            if(!IsInvalid(row+move.first, column+move.second) 
                && !CanBeTree(row+move.first, column+move.second))
                invalid.push(pii(row+move.first, column+move.second));
        }
    }

    if(resp == false)
        return resp;
    
    loop(i, 0, r)
    loop(j, 0, c){
        if(canBeTree[i][j] && mat[i][j] == '.')
            mat[i][j] = tree;
    }
    return true;

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    loop(i, 0, t){
        if(!possible())
            cout<<"Case #"<<(i+1)<<": Impossible\n";
        else{
            cout<<"Case #"<<(i+1)<<": Possible\n";
            loop(i, 0, r){
                loop(j, 0, c){
                    cout<<mat[i][j];
                }
                cout<<"\n";
            }
        }
    }
    return 0; 
}