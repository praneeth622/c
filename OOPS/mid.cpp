// Design a class to represent a bank account. The class should have the following attributes: account number, account holder name, account balance, and account type. The class should also have the following methods: deposit(), withdraw(), and getBalance().
#include<iostream>

using namespace std;

class account{
    private:
        int acc_num;
        double acc_balance;
        string acc_type;
    public:
        account(int num = 0,double bala=0.0,string type ="savings"){
            acc_num = num;
            acc_balance = bala;
            acc_type= type;
            cout<<"Your Account created";
        }
        void deposit(double num){
            acc_balance = num+acc_balance;
            cout<<"Your Present Account Balance is "<<acc_balance;
        }
        void withdraw(double num){
            acc_balance = acc_balance-num;
            cout<<"You Withdrawed : "<<num<<endl;
        }
        void getBalance(){//Getter
            cout<<"Your Balance is : "<< acc_balance <<endl;
        }
        // void setBalance(double num){
        //     acc_balance = num;
            
        // }
};

int main(){
    int choice,temp =1;
    account a1;
    while(temp){
        cout<<"1. Create account"<<endl;
        cout<<"2. Deposit"<<endl;
        cout<<"3. Get Balance"<<endl;
        cout<<"4. Withdraw"<<endl;
        cout<<"5. Log out"<<endl;
        cin>>choice;
        switch(choice){
            case 1: {
                cout << "1. Manual Creation " << endl;
                cout << "2. Automatic" << endl;
                int creation;
                cin >> creation;
                switch (creation) {
                    case 1:{
                        int acc_number;
                        double acc_Balance;
                        string acc_type;
                        cout<<"Enter the Account Number : "<<endl;
                        cin>>acc_number;
                        cout<<"Enter the account Balance"<<endl;
                        cin>>acc_Balance;
                        cout<<"Enter Account Type"<<endl;
                        cin>>acc_type;
                        a1 = account(acc_number,acc_Balance,acc_type);
                        break;
                    }
                    case 2:
                        a1 = account();
                        break;
                }
                break;
            case 2:{
                cout<<"Enter the money Deposit"<<endl;
                double deposit;
                a1.deposit(deposit);
                a1.getBalance();
                break;
            }
            case 3:{
                a1.getBalance();
                break;
            }
            case 4:{
                cout<<"Enter the amount to withdraw"<<endl;
                int withdraw_amt;
                a1.withdraw(withdraw_amt);
                break;
            }
            case 5:{
                choice =0;
                break;
            }
            }
        }
    }
}