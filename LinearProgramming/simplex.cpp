#include <iostream>
#include <vector>
using namespace std;

#define loop(i, a, b) for(int i = a; i < b; ++i)
typedef int64_t type;
int rows, cols;

type gcd(type a, type b){
    if(a == 0 || b == 0) return a+b;
    else return gcd(b, a%b);
}

struct fraction{
    type num, den;
    fraction(type numerator, type denominator){
        type g = gcd(numerator, denominator);
        num = numerator/g; den = denominator/g;
    }
    fraction(type numerator){ num = numerator; den = 1;}
    fraction(){num = 0; den = 1;}

    fraction operator+(const fraction &other){return fraction(num*other.den + den*other.num, den*other.den);}
    fraction operator-(const fraction &other){return fraction(num*other.den - den*other.num, den*other.den);}
    fraction operator*(const fraction &other){return fraction(num*other.num, den*other.den);}
    fraction operator/(const fraction &other){return fraction(num*other.den, den*other.num);}

    bool operator < (const fraction &other){ return num*other.den < den*other.num;}
    bool operator <= (const fraction &other){ return num*other.den <= den*other.num;}
    bool operator == (const fraction &other){ return num == other.num && den == other.den;}
    string toString(){return den == 1? to_string(num) : to_string(num)+"/"+to_string(den);}
};


//multiplies the row the rescaling factor
void rescaleRow(vector<vector<fraction> > &A, int row, fraction rescale){
    int col = A[row].size();
    loop(j, 0, col)
        A[row][j] = A[row][j]*rescale;
}

void elementaryOperation(vector<vector<fraction> > &A, int pivotRow, int row, fraction rescale){
    loop(i, 0, cols)
        A[row][i] = A[row][i] - rescale*A[pivotRow][i];
}

void simplexStep(vector<vector<fraction> > &A, int col){
    //select the row used as a pivot

    int pivot = -1;
    fraction epsilon = -1;
    loop(i, 0, rows-1){
        if(A[i][col] <= 0) continue;
        if(pivot == -1 || A[i][cols-1]/A[i][col] < epsilon){
            pivot = i;
            epsilon = A[i][cols-1]/A[i][col]; 
        }
    }
    if(pivot == -1){
        cout<<"cannot insert column "<<col<<" to the basis"<<endl;
        return;
    }

    cout<<"pivot row: "<<pivot<<"\n";
    cout<<"epsilon: "<<epsilon.toString()<<"\n";

    //rescale row for the pivot to be 1
    rescaleRow(A, pivot, fraction(1)/A[pivot][col]);

    //make all the other cells in the column 0
    loop(i, 0, rows){
        if(i != pivot)
            elementaryOperation(A, pivot, i, A[i][col]);
    }
}

void print(vector<vector<fraction> > &A){
    if(rows == 0){
        cout<<"Matrix has no rows\n";
        return;
    }
    cout<<"Estado actual de A\n";
    loop(i, 0, rows){
        loop(j, 0, cols)
            cout<<A[i][j].toString()<<"\t";
        cout<<"\n";
    }
    cout<<"\n";
}   

int main(){
    vector< vector<fraction> >A;
    rows = 4;
    cols = 6;

    A.resize(4);
    fraction a1[] = {fraction(4,10), fraction(32,100), fraction(-1), fraction (0), fraction(0), fraction(1e6)};
    fraction a2[] = {fraction(2,10), fraction(4,100), fraction(0), fraction (-1), fraction(0), fraction(4*1e5)};
    fraction a3[] = {fraction(35,100), fraction(2/10), fraction(0), fraction (0), fraction(-1), fraction(25*1e4)};
    fraction a4[] = {fraction(11), fraction(9), fraction (0), fraction(0), fraction (0), fraction(0)};

    A[0] = vector<fraction> (a1, a1+6);
    A[1] = vector<fraction> (a2, a2+6);
    A[2] = vector<fraction> (a3, a3+6);
    A[3] = vector<fraction> (a4, a4+6);

    
    print(A);
    simplexStep(A, 0);
    print(A);
    simplexStep(A, 1);
    print(A);
    simplexStep(A, 2);
    print(A);

    simplexStep(A, 4);
    print(A);

    simplexStep(A, 3);
    print(A);

}