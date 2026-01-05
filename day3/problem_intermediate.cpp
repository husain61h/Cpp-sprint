#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <unordered_set>
#include <string>
#include <iomanip>
using namespace std;

struct product{
    string name;
    double price;
    string category;
};

class shopping{
private: string name,paymentOption; 
         map<int,product> mp; 
         bool b=true;
         int num,discount=0; 
         double total=0.0, finalPrice=0.0; 
         vector<product> productBought;
public:

    shopping(){
        cout<<"=================================================================="<<endl;
        cout<<"Enter Your Name : ";
        getline(cin,name);
        cout<<"Available Products "<<endl;
        products();
        for(auto v:mp){
            cout<<v.first<<" - "<<v.second.name<<" -> "<<v.second.price<<" ("<<v.second.category<<")"<<endl;
        }
        cout<<endl;
        for(int i=0; i<3; i++){
            cout<<"Select Product to buy (Enter ID) "<<": ";
            cin>>num;
            productBought.push_back(mp[num]);
        }
        cout<<"Enter Payment Method(UPI/CARD/COD) ";
        cin>>paymentOption;
    }

    void products(){
        mp.insert({1,{"Shirt",399.0,"Clothing"}});
        mp.insert({2,{"Laptop",12239.5,"Electronics"}});
        mp.insert({3,{"Oil",279.0,"Grocery"}});
        mp.insert({4,{"Smart Watch",3199.0,"Electronics"}});
    }

    void processing(){
        if(paymentOption=="COD"){
            for(auto it=productBought.begin(); it!=productBought.end(); it++){
                if(it->category=="Electronics"){
                    b=false;
                }
            }
        }
        for(auto v:productBought){
            total+=v.price;
        }
        if(paymentOption=="CARD"){
            if(total>30000) discount+=5;
        }
        if(total>=5000) discount+=20;
        else if(total>=2000) discount+=10;
        else discount=0;
        finalPrice=total-((total*discount)/100);
    }

    void summary(){
        cout<<endl;
        cout<<"=================================================================="<<endl<<endl;
        cout<<"                          Purchase Summary                        "<<endl<<endl;
        cout<<"=================================================================="<<endl<<endl;
        cout<<left<<setw(16)<<"User Name"<<": "<<name<<endl;
        cout<<left<<setw(16)<<"Products"<<": "<<"[";
        for(auto v:productBought){
            cout<<"'"<<v.name<<"'"<<",";
        }
        cout<<"]"<<endl;
        cout<<left<<setw(16)<<"Categories"<<": "<<"[";
        for(auto v:productBought){
            cout<<"'"<<v.category<<"'"<<",";
        }
        cout<<"]"<<endl;
        cout<<left<<setw(16)<<"Payment Method"<<": "<<paymentOption<<endl<<endl;

        cout<<left<<setw(16)<<"Total Amount"<<": "<<total<<endl;
        cout<<left<<setw(16)<<"Discount"<<": "<<discount<<"%"<<endl;
        cout<<left<<setw(16)<<"Final Amount"<<": "<<finalPrice<<endl;
        if(b==true) cout<<left<<setw(16)<<"Status"<<": "<<"Order Placed"<<endl;
        else cout<<left<<setw(16)<<"Status"<<": "<<"Order Not Allowed (COD not available for Electronics)"<<endl;
    }
};

int main(){
    shopping order;
    order.processing();
    order.summary();
    return 0;
}
