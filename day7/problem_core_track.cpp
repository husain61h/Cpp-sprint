#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;
class RPSGame{
private: 
        string playerName="", userMove="", computerMove="";
        int playerScore, computerScore, draws, align=0;

        string getComputerMove(){

            srand(time(0));

            int comp = rand() % 3;
            string computer;

            if (comp == 0) return "rock";
            else if (comp == 1) return "paper";
            else return "scissors";

        }

        bool validateMove(string &str){

            if(str=="rock" || str=="paper" || str=="scissors") return true;
            else return false;

        }
public: 
        RPSGame(string name){
            playerName=name;
            playerScore=0;
            computerScore=0;
            draws=0;
        }
        void play_round();
        void show_score(); 
};

void RPSGame :: play_round(){

    cout<<"Enter Your Move (rock/paper/scissors) : ";
    cin>>userMove;

    if(!validateMove(userMove)){
        cout<<"Invalid Move"<<endl;
    }
    else{
        computerMove = getComputerMove();
        cout<<"Computer chose : "<<computerMove<<endl;
        if (userMove == computerMove){
            cout << "Draw!" << endl;
            draws++;
        }
        else if ((userMove == "rock" && computerMove == "scissors") || (userMove == "paper" && computerMove == "rock") || (userMove == "scissors" && computerMove == "paper")){
            cout << "You win!" << endl;
            playerScore++;
        }
        else{
            cout << "Computer wins!" << endl;
            computerScore++;
        }
    }
}

void RPSGame ::  show_score(){

    align = max<int>(8,playerName.size());
    cout<<endl<<"xxxxxxxxxxxxxxxxxxxxxx ScoreBoard xxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl<<endl;
    cout<<left<<setw(align+2)<<playerName<<"-> "<<playerScore<<endl;
    cout<<left<<setw(align+2)<<"Computer"<<"-> "<<computerScore<<endl;
    cout<<left<<setw(align+2)<<"Draw"<<"-> "<<draws<<endl;

}

bool validateInt(string str, int &x){
    try{
        x = stoi(str);
        return true;
    }
    catch(...){
        return false;
    }
}

int main(){

    string name="";
    cout<<"Enter Your Name : ";
    getline(cin,name);

    string noOfRoundStr = "";
    int noOfRoundInt = 0;

    cout<<"Enter number of rounds you want to play : ";
    cin>>noOfRoundStr;
    if(!validateInt(noOfRoundStr, noOfRoundInt)){
        cout<<"Invalid Entry"<<endl;
        return 0;
    }

    RPSGame user(name);
    for(int i=0; i<noOfRoundInt; i++){
        user.play_round();
    }

    cout<<"Press Enter to see Score Board : ";
    cin.ignore();
    cin.get();
    user.show_score();
    
    return 0;
}
