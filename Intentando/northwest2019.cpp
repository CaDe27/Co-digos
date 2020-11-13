#include <iostream>
#include <list>
#include <vector>
#include <cmath>

#define loop(i, a, b) for(int i = a; i < b; ++i)
#define modula(a, b) (a%b + b)%b
using namespace std;

const int maxN = 200005;
string n;
int sizeN, total;
int inva0;
int digs[30];
string resp, resp2;
bool imposible;

int procesoImpar(int i, vector<int> &a){
    int c = digs[i] / 2;
    loop(j, 1, i/2 + 1){
        c -= a[j]*a[i-j];
    }
    int ai = modula(c*inva0, 5);
    if( modula( (digs[2*i] - ai) ,2) == 1)
        ai = ai+5;
    return ai;
}

int procesoPar(int i, vector<int> &a){
    int c = modula(digs[i] - a[i/2]*a[i/2], 10);
    c = c/2;
    loop(j, 1, i/2){
        c -= a[j]*a[i-j];
    }
    int ai = modula(c*inva0, 5);  
    if( modula( (digs[2*i] - ai) ,2) == 1)
        ai = ai+5;
    return ai;
}

bool comprueba(int i, vector<int> &a){
    int c = 0;
    loop(j, 0, i){
        if(j < total && i-j < total)
            c = modula( c + a[j]*a[i-j], 10);
    }
    //cout<<"compruebo: indice="<<i<<" original="<<digs[i]<<" me da="<<c<<endl;
    return digs[i] == c;
}

string funcion(int a0){
    vector<int> a(total);
    a[0] = a0;
    //cout<<"nuevo\n";
    //cout<<0<<" "<<a0<<endl;
    //sacamos el inverso modulo 5 del primer digito
    inva0 = pow(a0, 3);
    inva0 = modula(inva0, 5);

    loop(i, 1, total){
        if(i&1) a[i] = procesoImpar(i, a);
        else    a[i] = procesoPar(i, a);
        //cout<<i<<" "<<a[i]<<endl;
    }

    bool band = true;
    for(int i = total; i < sizeN && band; ++i){
        band = comprueba(i, a);
    }

    string miResp = "";
    for(int x  : a){
        miResp = to_string(x) + miResp;
    }
    return band? miResp : "";
}

void quitaInicial(){
    int it = 0;
    while(!imposible && it < sizeN && digs[it]%5 == 0 ){
        if(it+1 >= sizeN || digs[it+1] == 0){
            resp = to_string(digs[it]) + resp;
            it += 2;
        }
        else
            imposible = true;
    }
    //paso los digitos que quedan al inicio y con esos trabajo
    if(!imposible && it < sizeN){
        loop(i, it, sizeN){
            digs[i-it] = digs[i];
        }
    }
    sizeN -= it;
    if(sizeN < 0)
        sizeN = 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    reverse(n.begin(), n.end());

    sizeN = 0;
    for(char c : n){
        digs[sizeN++] = c-'0';
    }

    //borra 05s y 00s iniciales
    // esto es para que el número con el que iniciemos n0 tenga inverso modulo 5
    imposible = false;
    quitaInicial();

    //checo que todos los digitos impares sean numeros pares
    for(int i = 1; i < sizeN; i+=2){
        if(digs[i]&1)
            imposible = true;
    }

    if(sizeN == 0){
        cout<<resp<<"\n";
        return 0;
    }

    if(imposible){
        cout<<"-1\n";
        return 0;
    }

    //total es la cantidad de digitos que tendra el resto de mi respuesta
    total = (sizeN+1)/2;


    //veo las opciones para mi digito cero
    vector<int> opciones;
    loop(i, 0, 10){
        if( (i*i)%10 == digs[0] )
            opciones.push_back(i);
    }

    resp2 = "";
    for(int x : opciones){
        string opcion = funcion(x);
        if(resp2 == "") 
            resp2 = opcion;
        else if(opcion != "" && opcion < resp2){
            resp2 = opcion;
        }
    }

    if(resp2 == "")
        imposible =true;
    
    if(imposible){
        cout<<"-1\n";
    }
    else{
        resp = resp2 + resp;
        cout<<resp<<"\n";
    }

    return 0;

}