#include <iostream>
#include <iomanip>
#include <vector>
#include <map>

using namespace std;

class tracking{
private:
        int noOfTransactions=0, max=0, maxAlign=25;
        double expenseAmount=0, totalExpense=0, averageExpense=0;
        string expenseCategory="", highestSpendingCategory="", status="";
        vector<double> expenses;
        map<string,double> categoryTotalExpenseMap;
public:
        tracking(){

            cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl<<endl;
            cout<<"                     Smart Expense Analyser                         "<<endl<<endl;
            cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl<<endl;

            cout<<"How many transactions did you make? : ";
            cin>>noOfTransactions;
            for(int i=0; i<noOfTransactions; i++){

                cout<<"Enter Expense Amount "<<i+1<<" : ";
                cin>>expenseAmount;
                if(expenseAmount>500) cout<<"*****High Expense Detected*****"<<endl;

                cin.ignore();

                cout<<"Enter Expense "<< i+1 << " category : ";
                getline(cin, expenseCategory);
                cout<<endl;
                formatString(expenseCategory);
                expenses.push_back(expenseAmount);
                categoryTotalExpenseMap[expenseCategory]+=expenseAmount;

            }

        }

        void processing(){

            for(int i=0; i<expenses.size(); i++){
                totalExpense += expenses[i];
            }

            averageExpense = totalExpense / noOfTransactions;

            for(auto v : categoryTotalExpenseMap){
                if(v.second>max){
                    max = v.second;
                    highestSpendingCategory = v.first;
                }
                else if(v.second==max){
                    highestSpendingCategory+=" and ";
                    highestSpendingCategory+=v.first;
                }
            }

            if(averageExpense<=200) status = "Controlled Spending";
            else if(averageExpense<=400) status = "Moderate Spending";
            else status = "High Spending";

            for(auto v : categoryTotalExpenseMap){
                if(v.first.size() > maxAlign){
                    maxAlign = v.first.size();
                }
            }
        }

        void display(){

            cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl<<endl;
            cout<<"                        Expenditure Analysis                          "<<endl<<endl;
            cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl<<endl;

            cout<<left<<setw(maxAlign+2)<<"Total Expense"<<"-> "<<totalExpense<<endl;
            cout<<left<<setw(maxAlign+2)<<"Average Expense"<<"-> "<<averageExpense<<endl<<endl;

            cout<<"Category Wise Expense : "<<endl;
            for(auto v : categoryTotalExpenseMap){
                cout<<left<<setw(maxAlign+2)<<v.first<<"-> "<<v.second<<endl;
            }

            cout<<left<<setw(maxAlign+2)<<"Highest Spending Category"<<"-> "<<highestSpendingCategory<<endl;
            cout<<left<<setw(maxAlign+2)<<"Spending Status"<<"-> "<<status<<endl<<endl;

        }
        
        // formatting string
        
        bool upperCase(char c){
            if(c>='A' && c<='Z') return true;
            else return false;
        }

        void lowerToUpper(char c, string &ans){
            if(upperCase(c)) ans += c;
            else{
                char temp = c - 32;
                ans += temp;
            }
        }

        void upperToLower(char c, string &ans){
            if(upperCase(c)){
               char temp = c + 32;
               ans += temp;
            }
            else ans += c;      
        }

        void formatString(string &str){

            string ans="";

            for(int i=0; i<str.size(); i++){
                if( (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || str[i] == ' '){
                    if(str[i]!=' '){
                        if(i==0){
                            lowerToUpper(str[i], ans);
                        }
                        else{
                            if(str[i-1]==' ') lowerToUpper(str[i], ans);
                            else upperToLower(str[i], ans);
                        }
                    }

                    else{
                        if(i==0) continue;
                        else{
                            if(str[i-1]==' ') continue;
                            else ans += str[i];
                        }
                    }
                }
                else{
                    str[i]=' ';
                }
            }
            str=ans;
        }
};


int main(){
    tracking today;
    today.processing();
    today.display();
    return 0;
}
