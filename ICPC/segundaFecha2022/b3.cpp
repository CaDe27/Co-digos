#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef int64_t ll;
#define loop(i,a,b) for(int i = a; i < b; ++i)

vector<int> palindromos;
int sig;
void genera(int ini, int fin){
    if(fin < ini)
        palindromos.push_back(sig);
    else{
        //si el ini y fin son 0
        genera(ini+1, fin-1);
        //si el ini y fin son 1
        sig |= 1<<ini;
        sig |= 1<<fin;
        genera(ini+1, fin-1);
        sig &= ~(1<<ini);
        sig &= ~(1<<fin);
    }
}

void generaPalis(){
    palindromos.push_back(0);
    for(int i = 0; i < 30; ++i){
        sig = 1;
        sig |= 1<<i;
        genera(1, i-1);
    }
}

int binaria(int x){
    int ini = 0, fin = palindromos.size()-1, mitad;
    while(ini != fin){
        mitad = (ini+fin+1)/2;
        if(palindromos[mitad] <= x) ini = mitad;
        else fin = mitad-1;
    }
    return ini;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    generaPalis();
    int q; cin>>q;
    int indxa,indxb,resp;
    int a, b;
    loop(i, 0, q){
        cin>>a>>b;
        indxb = binaria(b);
        indxa = binaria(a);
        resp = indxb - indxa;
        if(palindromos[indxa] == a) resp++;
        cout<<resp<<"\n";
    }
    return 0; 
}