#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include "json.hpp"
#include <chrono>
#include <thread>
using json = nlohmann :: json;
using namespace std;

class Vault{
private:
    bool run = true;
    string websiteName="", username="", password="", newPassword="";

    bool validate(string str, int &x){
            try{
                x = stoi(str);
                return true;
            }
            catch(...){
                return false;
            }
    }
    void clearAndReturn(){

        cout<<endl<<"Returning to Main Menu...."<<endl;
        this_thread :: sleep_for(chrono :: seconds(3));
        system("cls");

    }

    void initDB() {

        ifstream in("vault.json");

        if (in.good()) {
            return;
        }

        json db;
        db["credentials"] = json :: array();

        ofstream out("vault.json");
        out << db;

    }

    json loadDB() {

        ifstream file("vault.json");

        if (!file.is_open()) {
            return json{{"credentials", json :: array()}};
        }

        json db;
        file >> db;
        return db;

    }

    void saveDB(const json& db) {

        ofstream file("vault.json");
        file << setw(4) << db;

    }

public:
        void menuRun();
        bool access();
        void storage();
        void update();
        void remove();
};

void Vault :: menuRun(){
    initDB();
    int x=0;
    while(run){

        cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;
        cout<<"                        Welcome to Vault OS 1.0                        "<<endl<<endl;
        cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;

        cout<<"Choose an Operation : "<<endl<<endl;
        cout<<"1. Access stored credentials"<<endl<<endl;;
        cout<<"2. Store a new credential"<<endl<<endl;
        cout<<"3. Update an existing credential"<<endl<<endl;
        cout<<"4. Remove a saved credential"<<endl<<endl;
        cout<<"5. Exit the application"<<endl<<endl;

        cout<<"Enter Command : ";

        string input="";
        cin>>input;

        if(!validate(input,x)){
            cout<<"Invalid Entry"<<endl;
        }
        else{
            switch(x){

                case 1 :
                access();
                cin.ignore();
                cout<<"Press Enter to return to Main Menu : ";
                cin.get();
                clearAndReturn();
                break;

                case 2 :
                storage();
                break;

                case 3 :
                update();
                break;

                case 4 :
                remove();
                break;

                case 5 :
                run = false;
                break;

                default : 
                cout<<"Enter a Valid Choice"<<endl;
                clearAndReturn();
                break; 
 
            }
        }
    }
}

bool Vault :: access() {

    json db = loadDB();

    if( db["credentials"].empty() ){
        cout<<"Nothing to show"<<endl;
        clearAndReturn();
        return false;
    }

    int i=1;

    for (auto& c : db["credentials"]) {
        cout<<endl<<i<< ". "<<c["username"].get<string>() << "'s ";
        cout<<c["website"].get<string>() <<" -> ";
        cout<<c["password"].get<string>()<<endl<<endl ;
        i++;
    }

    return true;
}

void Vault :: storage(){

    cout<<"Enter Website : ";
    cin.ignore();
    getline(cin,websiteName);
    cout<<"Enter Username : ";
    getline(cin,username);
    cout<<"Enter Password : ";
    getline(cin,password);

    json db = loadDB();

    db["credentials"].push_back({
        {"website", websiteName},
        {"username", username},
        {"password", password}
    });

    saveDB(db);
    cout <<endl<< "Credential Stored Successfully"<<endl<<endl;

    cout<<"Press Enter to return to Main Menu : ";
    cin.get();

    clearAndReturn();
}

void Vault :: update(){
    
    json db = loadDB();
    if(!access()){
        return;
    }

    else{

        string number = "";
        cout<<"Enter number to update : ";
        int x=0;
        cin>>number;
        validate(number,x);

        x = x-1;

        if ( x < 0 || x >= db["credentials"].size() ) {
            cout << "Invalid selection"<<endl;
            clearAndReturn();
            return;
        }

        cout<<"Enter new Pasword : ";
        cin.ignore();
        getline(cin,newPassword);
        db ["credentials"] [x] ["password"] = newPassword;

        saveDB(db);
        cout <<endl<< "Credential Updated Successfully"<<endl<<endl;

        cout<<"Press Enter to return to Main Menu : ";
        cin.get();

        clearAndReturn();
    }
}

void Vault :: remove(){

    json db = loadDB();

    if(!access()){
        return;
    }
    else{
        string number = "";
        cout<<"Enter number to remove : ";
        int x=0;
        cin>>number;
        validate(number,x);

        x = x-1;

        if ( x < 0 || x >= db["credentials"].size() ) {
            cout << "Invalid selection"<<endl;
            clearAndReturn();
            return;
        }

        db["credentials"].erase( db["credentials"].begin() + x );

        saveDB(db);
        cout<<endl<<"Credential Removed Successfully"<<endl<<endl;

        cin.ignore();
        cout<<"Press Enter to return to Main Menu : ";
        cin.get();

        clearAndReturn();
    }
    
}



int main(){

    Vault now;
    now.menuRun();
    return 0;
    
}
