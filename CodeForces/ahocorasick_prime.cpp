#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define loop(i,a,b) for(int i = a; i < b; ++i)
using namespace std;

//DP + ahocorasick 
const int K = 9;
struct Vertex {
    int next[K];
    bool leaf = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - '1';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.push_back( Vertex(v, ch) );
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
}

int go(int v, char ch);
int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
        
        if(t[ t[v].link ].leaf)
            t[v].leaf = true;
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - '1';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
} 

string s;
int x;

bool divisible(string word){
    int sums[1+word.size()];
    sums[0] = 0;
    loop(i, 0, 1+word.size()){
        sums[i+1] = word[i]-'0';
        if(i > 0) sums[i+1] += sums[i];
    }
    loop(i, 3, x){
        if(x%i != 0) continue;
        loop(j, 0, word.size())
        loop(z, j+1, word.size()){
            if( sums[z+1]-sums[j] == i)
                return true;
        }    
    }
    return false;
}
void generateForbidden(string word, int remainder){
    if(remainder == 0){
        if(!divisible(word))
            add_string(word);
        return;
    }
    for(int i = 2; i <= 9 && i<x; ++i){
        if( (x%i)!=0 && i <= remainder){
            generateForbidden(word+to_string(i), remainder - i);
        }
    }
}

const int maxState = 5000, maxS = 1005;
bool visited[maxState][maxS];
int memo[maxState][maxS];
int dp(int state, int indx){
    if(t[state].leaf) return 10000;
    if(indx == s.size()) return 0;
    if(!visited[state][indx]){
        visited[state][indx] = true;
        //si borro
        memo[state][indx] = 1+dp(state, indx+1);
        //no borro, avanzo en el automata
        memo[state][indx] = min(memo[state][indx], dp(go(state, s[indx]), indx+1));
    }
    return memo[state][indx];
}

int main(){
    cin>>s>>x;
    if(x < 10) add_string(to_string(x));
    generateForbidden("",x);
    cout<<dp(0, 0)<<"\n";
    return 0;
}