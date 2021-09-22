#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

typedef int64_t ptype;
struct PT {
    ptype x,y;
 
    PT(){};
    PT(ptype x, ptype y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y) {}
    PT operator + (const PT &p) const {  return PT(x+p.x, y+p.y);  }
    PT operator - (const PT &p) const {  return PT(x-p.x, y-p.y);  }
    bool operator < (const PT &p) const { return x < p.x || (x == p.x && y < p.y);}
    bool operator == (const PT &p) const {return x == p.x && y == p.y;}
    
    int cuad(){
        if(x > 0 && y >= 0) return 0;
        if(x <= 0 && y > 0) return 1;
        if(x < 0 && y <=0) return 2;
        return 3;
    }  
    ptype pp(const PT &p) {return x*p.x + y*p.y;}
    bool paralelo(const PT &p){
        PT ort = PT(y, -x);
        return ort.pp(p) == 0;
    }
    bool aMiDer(const PT &p ){
        PT ort = PT(y, -x);
        if(ort.cuad() != (cuad() - 1 + 4)%4) 
            ort = PT(-y, x);
        return ort.pp(p) > 0;
    }
    bool aMiIzq(const PT &p){return !paralelo(p) && !aMiDer(p);}

    void print(){cout<<x<<" "<<y<<endl;}
};
ptype cross(const PT &a, const PT &b){return a.x*b.y - a.y*b.x;}
 
int n;
vector<PT> mon, orig;
PT centro;
 
bool counterClock(const PT &c, const PT &d){
    if( c==centro || d==centro) return c == centro;
    PT a = c - centro, b = d - centro; 
    return a.cuad() == b.cuad() ? a.x * b.y > a.y * b.x : a.cuad() < b.cuad();
}
 
//te dice si C esta por encima de la recta dirigida que va del centro actual a B
bool arriba(const PT &b, const PT &c){return  cross(b -centro, c - centro) > 0;}
 
ptype resp;
// el recorrido se basa en considerar todas las rectas desde el centro 
// hacia los otros puntos
 
 
 
 //la idea es llevar dos apuntadores
// uno que tenga al primer punto que esta por encima de la recta,
// y otro que tenga el primero por debajo
// cuando mueves la recta al que ahora está por encima, necesitas actualizar
// los que pasaron de estar abajo hacia arriba
/*void clockSweep(){
    //ordenamos los puntos en sentido antihorario con respecto al centro
    //pone automaticamente al centro como el primer elemento
    sort(mon.begin(), mon.end(), counterClock);
    
    //tomamos el primer punto del vector y es ahi donde comenzamos la primera recta
    int act, sigUp, sigDown;
    act = 1;
    sigUp = 2;
 
    //f guarda la informacion de fuera de la recta
    // si estas arriba suma, si abajo restas
    //entonces f tiene la resta de lo de arriba menos lo de abajo
    ll f = 0;
 
    //hacemos un recorrido para meter a todos los puntos en la informacion 
    //de uno de los dos lados
    //estas por encima de la recta si la componente en z del producto cruz 
    //de (B-A) y (C-A) es mayor a cero y estas por debajo si el producto cruz 
    // es menor a cero
    for(int i = 2; i <= n;++i)
        f += arriba(mon[act], mon[i])? mon[i].g: -mon[i].g;
    
    resp = min(resp, abs(f));
    
    //hago un recorrido para identificar el primer punto que esta por abajo 
    //de la recta
    sigDown = 2;
    while(sigDown < n && arriba(mon[act], mon[sigDown])) ++sigDown;
    if(sigDown == n) sigDown = 1;
 
    //hago el sweep line
    // me muevo al sig de arriba y actualizo sigDown
    while(act < n-1){
        //preparo la transicion al siguiente y calculo su resp
        f -= mon[act++].g; //pasa de estar en ambos a estar abajo
        f -= mon[sigUp++].g; //de estar arriba, pasa a estar en ambos
 
        //avanzo sigDown hacia abajo
        //si el siguiente estaba abajo, no marca que este abajo y por eso este parche
        // también pensé en hacer while(!abajo)
        // pero si el sig está abajo, ninguno va a quedar abajo y se va a ciclar
        // y solo queremos que de a lo máximo una vuelta, por eso deje este parche
        if(mon[sigDown] == mon[act]){
            f += 2*mon[sigDown].g; //pasas de estar abajo, a estar arriba (de -5 pasas a +5,)
                                   // por eso suma doble
            
            //voy al siguiente, pero sin pasar nunca por el centro
            sigDown = sigDown + 1 == n? 1 : sigDown + 1;
            
        }
        while( sigDown!=act && arriba(mon[act], mon[sigDown])){
            f+= 2*mon[sigDown].g;
            sigDown = sigDown + 1 == n? 1 : sigDown + 1;
            
        }
 
        //actualizo resp
        resp = min(resp, abs(f));
    }
}
 */

int main(){ return 0;}