#include <iostream>
#include <string>
using namespace std;

class base{
    public:
        int m;
        int n;
        void add(int m,int n){
            cout<< m+n<<endl;;
        }
        void add(double m,int n){
            cout<< m+n<<endl;;
        }
};
int main (){
    base b;
    b.add(1.5,2);
    b.add(1,1);
}