#include<iostream>
#include<vector>
#include<limits>
using namespace std;


class BankSystem{
   private:
     string name;
     int accountNo;
     double balance;
     double savingsGoal;
     double loanAmount;
     double interestRate;
     string loanType;

   public:
     BankSystem(string n, int ac, double bal){
        name = n;
        accountNo = ac;
        balance = bal;
        savingsGoal = 0.0;
        loanAmount = 0.0;
        interestRate = 0.0;
        loanType="";
     }
     //getter
     string getName(){
        return name;
     }
     int getAccountNum(){
        return accountNo;
     }
     double getBalance(){
        return balance;
     }
     double getsavingsGoal(){
      return savingsGoal;
     }
     double getloanAmount(){
      return loanAmount;
     }
     double getInterestRate(){
      return interestRate;
     }
     string getloanType(){
      return loanType;
     }
     void deposit(double amount){
         balance = balance + amount;
      }

      void withdraw(double amount){
         if(balance >= amount){
            balance = balance - amount;
            cout<<"\t\t Money Withdrawn Successfully...."<<endl;
         }
         else{
            cout<<"\t\t Insufficient Balance...."<<endl;
         }
      }
         void setSavingsGoal(double goal){
         savingsGoal = goal;
         cout << "\t\t Savings Goal Set Successfully...." << endl;
     }

     double trackSavingsGoalProgress(){
      if(savingsGoal == 0)
      return 0;
      return(balance / savingsGoal) * 100;
     }

     // Apply for a loan
     void applyLoan(double amount, double rate, string type){
         loanAmount = amount;
         interestRate = rate;
         loanType = type;
         cout << "\t\t Loan Applied Successfully...." << endl;
     }
};

class BankManagment{
    private:
     vector<BankSystem> account;
    public:
      void AddAccount(string name, int accountNo, double balance){
        account.push_back(BankSystem(name,accountNo,balance));
      }
      
      void showAllAccounts(){
          cout<<"\t\t Account Holder "<<endl;
          for(int i=0;i<account.size();i++){
              cout<<"Name  :"<<account[i].getName()
              <<" | Account Number :"<<account[i].getAccountNum()
              <<" | Total Balance :"<<account[i].getBalance()
              <<" | Savings Goal :"<<account[i].getsavingsGoal()
              <<" | Loan Amount :"<<account[i].getloanAmount()
              <<" | Interest Rate :"<<account[i].getInterestRate()
              <<" | Loan Type :"<<account[i].getloanType()<<endl;

          }
      }

      void searchAccount(int acc){
         cout<<"\t\t Account Holder "<<endl;
         for(int i=0;i<account.size();i++){
            if(account[i].getAccountNum()==acc){
                  cout<<"Name  :"<<account[i].getName()
                  <<" | Account Number :"<<account[i].getAccountNum()
                  <<" | Total Balance :"<<account[i].getBalance()
                  <<" | Savings Goal :"<<account[i].getsavingsGoal()
                  <<" | Loan Amount :"<<account[i].getloanAmount()
                  <<" | Interest Rate :"<<account[i].getInterestRate()
                  <<" | Loan Type :"<<account[i].getloanType()<<endl;
            }
         }
      }
      BankSystem * findAccount(int accountNum){
         for(int i=0;i<account.size();i++){
            if(account[i].getAccountNum()==accountNum){
               return &account[i];
            }
         }
         return nullptr;
      }
       
};

main(){ 
    BankManagment bank;
    int choice;
    char op;
    do{
    cout<<"\t\t BANK MANAGMENT SYSTEM"<<endl;
    cout<<"\t\t\tMain Menu"<<endl;
    cout<<"\t\t 1.Create Your Account"<<endl;
    cout<<"\t\t 2.Show All Accounts"<<endl;
    cout<<"\t\t 3.Show Account"<<endl;
    cout<<"\t\t 4. Deposit Money"<<endl;
    cout<<"\t\t 5. Withdraw Money"<<endl;
    cout<<"\t\t 6.Set Savings Goal"<<endl;
    cout<<"\t\t 7. Apply for Loan"<<endl;
    cout<<"\t\t 8.Track Savings Goal Progess"<<endl;
    cout<<"\t\t 9. EXIT"<<endl;
    cout<<"____________________________________________________"<<endl;
    cout<<"\t\t Enter Your Choice"<<endl;
    cin>>choice;

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    switch(choice){
        case 1:{
            string name;
            int accountNo;
            double balance;
            cout<<"\t\t Enter Your Name:"<<endl;
            cin>>name;
            cout<<"\t\t Enter Account Number:"<<endl;
            cin>>accountNo;
            cout<<"\t\tEnter Initial Balance:"<<endl;
            cin>>balance;
            bank.AddAccount(name,accountNo,balance);
            cout<<"\t\t Account Created Successfully...."<<endl;
            break;
        }

        case 2:{
             bank.showAllAccounts(); 
             break;
        }
        
        case 3:{
         int accountNum;
         cout<<"Enter your Account number :"<<endl;
         cin>>accountNum;
         bank.searchAccount(accountNum);
         break;
        }

        case 4:{
         int accountNum;
         double amount;
         cout<<"\t\t Enter Account Number to Deposit Money :"<<endl;
         cin>>accountNum;
         BankSystem * account = bank.findAccount(accountNum);
         if(account != NULL){
            cout<<"\t\t Enter Amount to Deposit :"<<endl;
            cin>>amount;
            account -> deposit(amount);
            cout<<"\t\t"<<amount<<" Money Deposited Successfully..."<<endl;
         }
         else{
            cout<<"\t\t Account Not Found....."<<endl;
         }
         break;
        }

        case 5:{
         int accountNum;
         double amount;
         cout<<"\t\t Enter Account Number to Withdraw Money :"<<endl;
         cin>>accountNum;
         BankSystem * account = bank.findAccount(accountNum);
         if(account != NULL){
            cout<<"\t\t Enter Amount to Withdraw :"<<endl;
            cin>>amount;
            account -> withdraw(amount);
         }
         else{
            cout<<"\t\t Account Not Found....."<<endl;
         }
         break;
        }
        
        case 6:{
          int accountNum;
                double goal;
                cout << "\t\t Enter Account Number to Set Savings Goal: ";
                cin >> accountNum;
                BankSystem* account = bank.findAccount(accountNum);
                if(account != nullptr){
                    cout << "\t\t Enter Savings Goal Amount: ";
                    cin >> goal;
                    account->setSavingsGoal(goal);
                }
                else{
                    cout << "\t\t Account Not Found...." << endl;
                }
         break;
        }

        case 7:{
           int accountNum;
                double loanAmount, interestRate;
                string loanType;
                cout << "\t\t Enter Account Number to Apply for Loan: ";
                cin >> accountNum;
                BankSystem* account = bank.findAccount(accountNum);
                if(account != nullptr){
                    cout << "\t\t Enter Loan Amount: ";
                    cin >> loanAmount;
                    cout << "\t\t Enter Interest Rate (%): ";
                    cin >> interestRate;
                    cout<<"\t\t Enter Loan Type(Personal, Vehicle, Education, Home, Other):";
                    cin>>loanType;
                    account->applyLoan(loanAmount, interestRate,loanType);
                }
                else{
                    cout << "\t\t Account Not Found...." << endl;
                }
         break;
        }

        case 8:{
         int accountNum;
         cout<<"\t\t Enter Account Number to Track Savings Goal Progress:";
         cin>>accountNum;
         BankSystem * account = bank.findAccount(accountNum);
         if(account != nullptr){
            double progress = account->trackSavingsGoalProgress();
            cout<<"\t\t Savings Goal Progress : "<<progress<<"%"<<endl;
         }
         else{
            cout<<"\t\t Account Not Found...."<<endl;
         }
         break;
        }

        case 9:{
         cout<<"\t\t Exiting the System..."<<endl;
         exit(1);
         return 0;
        }
        default:{
         cout<<"\t\t INVALID CHOICE, PLEASE TRY AGAIN....."<<endl;
        }


    }
    cout<<"\t\t Do You Want to Continue or Exit[YES/NO] ??";
    cin>>op;
    }while(op=='y'||op=='Y');
    
}
