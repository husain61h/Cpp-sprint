#include <iostream>
#include <iomanip>
#include <vector>
#include <set>

using namespace std;

class clinic{
private:
        string name="", age="", noOfReadings="", warning="NONE", status="";
        vector<int> readings;
        set<string> flags;

        pair<int,bool> valid(string str){
            int x=0;
            try{
                x = stoi(str);
                return {x,true};
            }
            catch(...){
                return {0,false};
            }
        }

public:
        void getInfo(){

            cout<<endl<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl<<endl;
            cout<<"                         Clinical Data System                       "<<endl<<endl;
            cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl<<endl;

            cout<<"Enter your Name : ";
            getline(cin,name);
            cout<<"Enter your Age : ";
            cin>>age;

            auto agePair = valid(age);
            if(agePair.second==false || agePair.first>120 || agePair.first<0) flags.insert("'Invalid Age'");

            cout<<"How many Heart Rate Readings you want to enter? : ";
            cin>>noOfReadings;
            auto noOfReadingsPair = valid(noOfReadings);

            if(noOfReadingsPair.second){
                getReading(noOfReadingsPair.first, 0);
            }
            else{
                flags.insert("'Invalid no of readings'");
            }
        }

        void getReading(int noOfReadings, int cnt){

            if(cnt==noOfReadings) return;

            string reading="";
            cout<<"Enter Heart Rate Reading : ";
            cin>>reading;
            auto readingPair = valid(reading);

            if(readingPair.second){
                readings.push_back(readingPair.first);
                getReading(noOfReadings, cnt+1);
            }
            else{
                flags.insert("'Invalid Reading'");
                getReading(noOfReadings, cnt+1);
            }

        }
        

        void process(){

            for(int i=0; i<readings.size(); i++){
                if(readings[i]>180){
                    warning="High Heart Rate Detected";
                }
            }

            if(flags.size()==0 && warning!="NONE"){
                status = "Review";
            }
            if(flags.size()==0 && warning=="NONE"){
                status = "Pass"; 
            }
            if(flags.size()!=0){
                status = "Fail";
            }

        }

        void display(){

            cout<<endl<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl<<endl;
            cout<<"                        Clinical Audit Result                         "<<endl<<endl;
            cout<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl<<endl;

            cout<<left<<setw(14)<<"Patient Name"<<"-> "<<name<<endl;
            cout<<left<<setw(14)<<"Status"<<"-> "<<status<<endl;
            cout<<left<<setw(14)<<"Flags"<<"-> "<<"[";
            bool first = true;
            for (auto f : flags) {
                if (!first) cout << ", ";
                cout << f;
                first = false;
            }
            cout<<"]"<<endl;
            cout<<left<<setw(14)<<"Warning"<<"-> "<<warning<<endl;
            
        }

};


int main(){
    clinic c;
    c.getInfo();
    c.process();
    c.display();
    return 0;
}
