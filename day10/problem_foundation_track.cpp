#include <iostream>
#include <string>
using namespace std;

class Student{
public: 

    string name="";
    int roll=0;
    int marks=0;

    Student(string name, int roll, int marks){

        this->name = name;
        this->roll = roll;
        this->marks = marks;

    }
    void display_Info(){

        cout<<endl<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;
        cout<< "Name        : " << name <<endl;
        cout<< "Roll Number : " << roll <<endl;
        cout<< "Marks       : " << marks <<endl<<endl; 

    }
    void check_Result(){

        if(marks >= 40){
            cout<< "Result : " << "PASS" <<endl;
        }
        else{
            cout<< "Result : " << "FAIL" <<endl;
        }

    }
};

int main(){

    string name = "";
    cout << "Enter Name : " ;
    getline(cin,name);

    int roll=0;
    cout << "Enter Roll Number : " ;
    cin >> roll;

    int marks;
    cout << "Enter Marks : " ;
    cin>>marks;

    Student self(name,roll,marks);
    self.display_Info();
    self.check_Result();

}
