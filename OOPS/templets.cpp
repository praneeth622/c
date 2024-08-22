#include<iostream>
using namespace std;

class Vector{
    public:
        int *arr;
        int size;
    
        Vector(int m){//Parametrised Constructor
            size = m;
            arr = new int[size];
        }
        int dotprod(Vector &v){
            int d = 0;
            for(int i =0;i=size;i++){
                d = d+ this->arr[i]*v.arr[i];
                
            }
            return d;
        }
};
int main(){
    
}