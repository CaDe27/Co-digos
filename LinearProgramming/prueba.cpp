#include <iostream>
#include <vector>

using namespace std;
#include <stdio.h>
 
void init(vector<vector<int> > &a, int rows, int cols){
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            a[i][j] = i*cols + j;
        }
    }
}

int main(){
    vector<vector<int> > a;
    a.resize(10);
    int b[] = {1, 2, 4}; 
    for(int i = 0; i < 10;++i)
        a[i] = vector<int> (b, b+3);
    //init(a, 10, 3);
    for(int i = 0; i < 10; ++i){    
        for(int j = 0; j < 3; ++j){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    } 
    return 0;
}