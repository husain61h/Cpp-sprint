#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

int main(){
    string name;
    cout<<"Enter name: ";
    getline(cin,name);

    int age;
    cout<<"Enter age: ";
    cin>>age;

    vector<string> favSub;
    for(int i=0;i<3;i++){
        string temp;
        cout<<"Enter subject "<<i+1<<": ";
        getline(cin>>ws,temp);
        favSub.push_back(temp);
    }

    string roll,branch;
    cout<<"Enter roll number: ";
    cin>>roll;
    cout<<"Enter branch: ";
    getline(cin>>ws,branch);

    tuple<string,string> student=make_tuple(roll,branch);

    unordered_map<string,int> marks;
    int m;
    for(int i=0;i<favSub.size();i++){
        cout<<"Enter " <<favSub[i]<< " marks: ";
        cin>>m;
        marks[favSub[i]]=m;
    }

    unordered_set<string> skills;
    for(int i=0;i<3;i++){
        string temp;
        cout<<"Enter skill "<<i+1<<": ";
        getline(cin>>ws,temp);
        skills.insert(temp);
    }

    cout<<"\nStudent Details \n\n";
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<age<<endl;

    cout<<"Favorite Subjects: [";
    for(int i=0;i<favSub.size();i++){
        cout<<"'"<<favSub[i]<<"'";
        if(i!=favSub.size()-1) cout<<", ";
    }
    cout<<"]"<<endl;

    cout<<"Student Info: ['"<<"roll no "<<get<0>(student)<<"', '"<<get<1>(student)<<"']"<<endl;

    cout<<"Marks: [";
    bool first=true;
    for(const auto&p:marks){
        if(!first) cout<<", ";
        cout<<"'"<<p.first<<"': "<<p.second;
        first=false;
    }
    cout<<"]"<<endl;

    cout<<"Technical Skills: [";
    bool firstSkill=true;
    for(const auto&s:skills){
        if(!firstSkill) cout<<", ";
        cout<<"'"<<s<<"'";
        firstSkill=false;
    }
    cout<<"]"<<endl;

    return 0;
}
