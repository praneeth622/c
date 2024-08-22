#include<iostream>
using namespace std;

class Student{
    private:
        int score[5];
    public :
        void input(){
            for(int i=0;i<=5;i++){
                cin>>score[i];
            }
        }
        void calculateTotalScore(){
            int sum =0;
            for(int i=0;i<=0;i++){
                sum=sum+score[i];
            }
            cout<<"Total Score is : "<<sum;
        }
};