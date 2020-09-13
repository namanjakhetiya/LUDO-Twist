#include<iostream>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#define RAND_MAX 7
#define MAX_STEP 61
#define No_Of_Objects 4
using namespace std;
class plyr{
    int c[4]={159,111,79,175};
    char fstplyr[4]={'1','2','3','4'};      //  Icons on Players Pins
    char *location[4]={nullptr,nullptr,nullptr,nullptr};     // Keeps tracks of Location of players on board.
    int Count[4]={-1,-1,-1,-1};         //  Keeps the Track of location (index) where moved Player's pin is placed on *ludo[].
    int stepCount[4]={-1,-1,-1,-1};     //  Keeps the Track of Steps moved by each Player.
    bool insideStep[4]={false,false,false,false};
	string	name = " ";
	int pin;

	public:

	void setName(string name){
		this->name = name;
	}

	void getName(){
		cout<<" "<<name<<" ";
	}

	string checkName(){
		return name;
	}

	int getColor(int activePlayer){
		return c[activePlayer];
	}

    char getIcon(int icon){
		return fstplyr[icon];
	}

    char* getLocation(int pin_number){
        return (location[pin_number]);
    }

    void setLocation(int pin_number,char* locate)
    {
        location[pin_number]=locate;
    }

    void setLocation(int pin_number){
        char p;
        switch(pin_number){
            case 0 : p='1';
                break;
            case 1 : p='2';
                break;
            case 2 : p='3';
                break;
            case 3 : p='4';
                break;
        }
        *location[pin_number]=p;
    }

    void setLocation(int pin_number,char p){
        *location[pin_number]=p;
    }

    int getStepCount(int pin_number){
        return (stepCount[pin_number]);
    }

    void setStepCount(int pin_number,int step){
        stepCount[pin_number] = step;
    }

    int getCount(int pin_number){
        return (Count[pin_number]);
    }

    void setCount(int pin_number,int step){
        Count[pin_number] = step;
    }

    bool checkInsideStatus(int pin_number){
        return insideStep[pin_number];
    }

    void checkInsideStatus(int pin_number,bool state){
        insideStep[pin_number] = state;
    }
};

class show{
    int color[4]={121,118,116,122};     // Individual Player Colors
    int player;     //  Number of players playing game
    int cage_number;

    void set4Players()
    {
        (p[0].getStepCount(0)==-1)?lodo[2][2]='1':lodo[2][2]='п';
        (p[0].getStepCount(1)==-1)?lodo[2][4]='2':lodo[2][4]='п';
        (p[0].getStepCount(2)==-1)?lodo[4][2]='3':lodo[4][2]='п';
        (p[0].getStepCount(3)==-1)?lodo[4][4]='4':lodo[4][4]='п';
        (p[1].getStepCount(0)==-1)?lodo[2][12]='1':lodo[2][12]='п';
        (p[1].getStepCount(1)==-1)?lodo[2][14]='2':lodo[2][14]='п';
        (p[1].getStepCount(2)==-1)?lodo[4][12]='3':lodo[4][12]='п';
        (p[1].getStepCount(3)==-1)?lodo[4][14]='4':lodo[4][14]='п';
        (p[2].getStepCount(0)==-1)?lodo[12][12]='1':lodo[12][12]='п';
        (p[2].getStepCount(1)==-1)?lodo[12][14]='2':lodo[12][14]='п';
        (p[2].getStepCount(2)==-1)?lodo[14][12]='3':lodo[14][12]='п';
        (p[2].getStepCount(3)==-1)?lodo[14][14]='4':lodo[14][14]='п';
        (p[3].getStepCount(0)==-1)?lodo[12][2]='1':lodo[12][2]='п';
        (p[3].getStepCount(1)==-1)?lodo[12][4]='2':lodo[12][4]='п';
        (p[3].getStepCount(2)==-1)?lodo[14][2]='3':lodo[14][2]='п';
        (p[3].getStepCount(3)==-1)?lodo[14][4]='4':lodo[14][4]='п';
    }

    void set2Players()
    {
        (p[0].getStepCount(0)==-1)?(cage_number==2)?lodo[2][2]='п':lodo[2][2]='1':lodo[2][2]='п';
        (p[0].getStepCount(1)==-1)?(cage_number==2)?lodo[2][4]='п':lodo[2][4]='2':lodo[2][4]='п';
        (p[0].getStepCount(2)==-1)?(cage_number==2)?lodo[4][2]='п':lodo[4][2]='3':lodo[4][2]='п';
        (p[0].getStepCount(3)==-1)?(cage_number==2)?lodo[4][4]='п':lodo[4][4]='4':lodo[4][4]='п';
        (p[1].getStepCount(0)==-1)?(cage_number==1)?lodo[2][12]='п':lodo[2][12]='1':lodo[2][12]='п';
        (p[1].getStepCount(1)==-1)?(cage_number==1)?lodo[2][14]='п':lodo[2][14]='2':lodo[2][14]='п';
        (p[1].getStepCount(2)==-1)?(cage_number==1)?lodo[4][12]='п':lodo[4][12]='3':lodo[4][12]='п';
        (p[1].getStepCount(3)==-1)?(cage_number==1)?lodo[2][14]='п':lodo[4][14]='4':lodo[4][14]='п';
        (p[2].getStepCount(0)==-1)?(cage_number==2)?lodo[12][12]='п':lodo[12][12]='1':lodo[12][12]='п';
        (p[2].getStepCount(1)==-1)?(cage_number==2)?lodo[12][14]='п':lodo[12][14]='2':lodo[12][14]='п';
        (p[2].getStepCount(2)==-1)?(cage_number==2)?lodo[14][12]='п':lodo[14][12]='3':lodo[14][12]='п';
        (p[2].getStepCount(3)==-1)?(cage_number==2)?lodo[14][14]='п':lodo[14][14]='4':lodo[14][14]='п';
        (p[3].getStepCount(0)==-1)?(cage_number==1)?lodo[12][2]='п':lodo[12][2]='1':lodo[12][2]='п';
        (p[3].getStepCount(1)==-1)?(cage_number==1)?lodo[12][4]='п':lodo[12][4]='2':lodo[12][4]='п';
        (p[3].getStepCount(2)==-1)?(cage_number==1)?lodo[14][2]='п':lodo[14][2]='3':lodo[14][2]='п';
        (p[3].getStepCount(3)==-1)?(cage_number==1)?lodo[14][4]='п':lodo[14][4]='4':lodo[14][4]='п';
    }

    public:

    char lodo[17][17];      //  Game Base Matrix
    char *ludo[56]={&lodo[7][2],&lodo[7][3],&lodo[7][4],&lodo[7][5],&lodo[7][6],&lodo[7][7],&lodo[6][7],&lodo[5][7],&lodo[4][7],&lodo[3][7],&lodo[2][7],&lodo[1][7],&lodo[1][8],&lodo[1][9],&lodo[2][9],&lodo[3][9],&lodo[4][9],&lodo[5][9],&lodo[6][9],&lodo[7][9],&lodo[7][10],&lodo[7][11],&lodo[7][12],&lodo[7][13],&lodo[7][14],&lodo[7][15],&lodo[8][15],&lodo[9][15],&lodo[9][14],&lodo[9][13],&lodo[9][12],&lodo[9][11],&lodo[9][10],&lodo[9][9],&lodo[10][9],&lodo[11][9],&lodo[12][9],&lodo[13][9],&lodo[14][9],&lodo[15][9],&lodo[15][8],&lodo[15][7],&lodo[14][7],&lodo[13][7],&lodo[12][7],&lodo[11][7],&lodo[10][7],&lodo[9][7],&lodo[9][6],&lodo[9][5],&lodo[9][4],&lodo[9][3],&lodo[9][2],&lodo[9][1],&lodo[8][1],&lodo[7][1]};
    char *insideLudo[4][7]={{&lodo[8][2],&lodo[8][3],&lodo[8][4],&lodo[8][5],&lodo[8][6],&lodo[8][7],&lodo[8][8]},{&lodo[2][8],&lodo[3][8],&lodo[4][8],&lodo[5][8],&lodo[6][8],&lodo[7][8],&lodo[8][8]},{&lodo[8][14],&lodo[8][13],&lodo[8][12],&lodo[8][11],&lodo[8][10],&lodo[8][9],&lodo[8][8]},{&lodo[14][8],&lodo[13][8],&lodo[12][8],&lodo[11][8],&lodo[10][8],&lodo[9][8],&lodo[8][8]}};
    plyr *p;        //  Pointer to array of type Plyr class.

    int numOfPlayers(){
        return player;
    }

    void numOfPlayers(int byDefault){
        player = byDefault;
    }

    int cageNumber(){
        return cage_number;
    }

    void logo()
    {
        system("cls");
        for(int j=0;j<15;j++){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240+j);
        cout<<"\n\n\n";
        cout<<"\t\t\t  лл        лл     лл    лллллм        млллм       \n";
        cout<<"\t\t\t  лл        лл     лл     лл  плм    млп   плм     \n";
        cout<<"\t\t\t  лл        лл     лл     лл   лл    лл     лл     \n";
        cout<<"\t\t\t  лл        плм   млп     лл  млп    плм   млп     \n";
        cout<<"\t\t\t  лллллл     плллллп     лллллп        плллп       \n";
        cout<<"\n\n\n";
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
    }

    int menu(bool newMenu)
    {
        int choice;
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
        cout<<"\n\n\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),241);
        cout<<"\t\t\t  лл        лл     лл    лллллм        млллм       \n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),244);
        cout<<"\t\t\t  лл        лл     лл     лл  плм    млп   плм     \n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),246);
        cout<<"\t\t\t  лл        лл     лл     лл   лл    лл     лл     \n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),252);
        cout<<"\t\t\t  лл        плм   млп     лл  млп    плм   млп     \n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),249);
        cout<<"\t\t\t  лллллл     плллллп     лллллп        плллп       \n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
        cout<<"\n\n\n";
        cout<<"========================================== WELCOME TO LUDO ================================================\n\n\n";
        cout<<"\t\t\t\t\t[1]=> New Game\n\n";
        if(newMenu)
            cout<<"\t\t\t\t\t     (1) Classic Game\n\n\t\t\t\t\t     (2) Dice Of Luck\n\n\n";
        cout<<"\t\t\t\t\t[2]=> Players\n\n";
        cout<<"\t\t\t\t\t[3]=> Exit\n\n\n";
        cout<<"===============================================================================================================\n\n";
        cout<<"\t\t\tEnter Your Choice:: ";
        cin>>choice;
        cout<<"\n\n";
        return choice;
    }

    int players()
    {
        int num_of_player;
        system("cls");
        cout<<"\n\n\n";
        cout<<"======================================== SELECT NUMBER OF PLAYERS =============================================\n\n\n";
        cout<<"\t\t\t\t\t>  2 Players\n\n";
        cout<<"\t\t\t\t\t>  4 Players\n\n\n";
        cout<<"===============================================================================================================\n\n";
        cout<<"\t\t\tEnter Your Choice:: ";
        cin>>num_of_player;
        if(num_of_player==2 || num_of_player==4){
            player=num_of_player;
        }
        else{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),244);
            cout<<"\n\t\t\t*Choose from given choices.";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
            cout<<"\n\n\n\t\t ";system("pause");
            //cin.ignore();cin.ignore();                 // just for display purpose (halt)
            players();
        }
        cout<<"\n\n";
        return player;
    }

    int selectCage()
    {
        int cage;
        gameSetUp(1);
        display();
        cout<<"\n\n\n";
        cout<<"=========================================== SELECT YOUR CAVES ================================================\n\n\n";
        cout<<"\t\t\t\t\t[1]=>  Cave 1 & Cave 3 \n\n";
        cout<<"\t\t\t\t\t[2]=>  Cave 2 & Cave 4 \n\n\n";
        cout<<"===============================================================================================================\n\n";
        cout<<"\t\t\tEnter Your Choice:: ";
        cin>>cage;
        if(cage!=1 && cage!=2){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),244);
            cout<<"\n\t\t\t*Choose from given choices.";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
            cout<<"\n\n\n\t\t ";system("pause");                  // just for display purpose (halt)
            selectCage();
        }
        cage_number = cage;
        cout<<"\n\n";
        return cage_number;
    }

    void gameSetUp(int flag)
    {
        for(int i=0;i<17;i++){
            for(int j=0;j<17;j++){
                if((i==0 || j==0 || i==16 || j==16) || ((i==2 || i==4 || i==12 || i==14) && (j==2 || j==4 || j==12 || j==14)) || ((i==7) && (j!=2 && j!= 8 && j!=13)) || ((i==9) && (j!=3 && j!= 8 && j!=14)) || ((i!=3 && i!=8 && i!=14) && (j==7)) || ((i!=2 && i!=8 && i!=13) && (j==9)) || ((i==8) && (j==1 || j==15)) || ((i==1 || i==15) && (j==8)))
                    lodo[i][j]='п';     //  LUDO Board Border + Common Pathway
                /*else if((i==6 && j==2) || (i==2 && j==10) || (i==14 && j==6) || (i==10 && j==14))
                    lodo[i][j]='H';     //  Marker for Player's Home Entrance
                else if((i==10 && j==3) || (i==3 && j==6) || (i==6 && j==13) || (i==13 && j==10))
                    lodo[i][j]='R';     //  Marker for Rest
                */
                else if((i==9 && j==3) || (i==3 && j==7) || (i==7 && j==13) || (i==13 && j==9))
                    lodo[i][j]='*';     //  Rest Places
                else if((i==7 && j==2) || (i==2 && j==9) || (i==9 && j==14) || (i==14 && j==7))
                    lodo[i][j]='п';     //  Player's Home Entrance Places
                else if((i==8 && (j==2 || j==3 || j==4 || j==5 || j==6 || j==7)) || ((i==2 || i==3 || i==4 || i==5 || i==6 || i==7) && j==8) || (i==8 && (j==14 || j==13 || j==12 || j==11 || j==10 || j==9)) || ((i==14 || i==13 || i==12 || i==11 || i==10 || i==9) && j==8))
                    lodo[i][j]='п';     //  Player's Personal Destination Pathway.
                else if(i==8 && j==8)
                    lodo[i][j]='п';     //  Destination Place
                else
                    lodo[i][j]=' ';
            }
        }
        if(flag == 1){  //To Assign Cage numbers
            lodo[3][3]='1';lodo[3][13]='2';lodo[13][13]='3';lodo[13][3]='4';
        }
    }

    void display()
    {
        if(player==4)
            set4Players();
        else
            set2Players();
        system("cls");
        cout<<"\n";
        if(p[0].getStepCount(0)==61 || p[0].getStepCount(1)==61 || p[0].getStepCount(2)==61 || p[0].getStepCount(3)==61 || p[1].getStepCount(0)==61 || p[1].getStepCount(1)==61 || p[1].getStepCount(2)==61 || p[1].getStepCount(3)==61 || p[2].getStepCount(0)==61 || p[2].getStepCount(1)==61 || p[2].getStepCount(2)==61 || p[2].getStepCount(3)==61 || p[3].getStepCount(0)==61 || p[3].getStepCount(1)==61 || p[3].getStepCount(2)==61 || p[3].getStepCount(3)==61){
            for(int i=0;i<4;i++){
                cout<<"\n\t\t ";p[i].getName();
                for(int j=0;j<4;j++){
                    if(p[i].getStepCount(j)==61){cout<<" ";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),p[i].getColor(i));
                        cout<<" "<<j+1;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
                    }
                }
                cout<<"\n";
            }
        }
        cout<<"\n\n";
        for(int i=0;i<17;i++){
                cout<<"\t\t\t";
            for(int j=0;j<17;j++){
                if((i==0 || j==0 || i==16 || j==16))
                {   //  Player's Home Entrance Places
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),117);
                    cout<<" "<<lodo[i][j];
                }
                else if(i==8 && j==8)
                {                                     // color's destination location.
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),117);
                    cout<<" "<<lodo[i][j];
                }
                else if(p[0].getLocation(0)==&lodo[i][j] || p[0].getLocation(1)==&lodo[i][j] || p[0].getLocation(2)==&lodo[i][j] || p[0].getLocation(3)==&lodo[i][j])
                {                                                                 //color's block location where player1 pins are present.
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),159);
                    cout<<" "<<lodo[i][j];
                }
                else if(p[1].getLocation(0)==&lodo[i][j] || p[1].getLocation(1)==&lodo[i][j] || p[1].getLocation(2)==&lodo[i][j] || p[1].getLocation(3)==&lodo[i][j])
                {                                                                 //color's block location where player2 pins are present.
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),111);
                    cout<<" "<<lodo[i][j];
                }
                else if(p[2].getLocation(0)==&lodo[i][j] || p[2].getLocation(1)==&lodo[i][j] || p[2].getLocation(2)==&lodo[i][j] || p[2].getLocation(3)==&lodo[i][j])
                {                                                                 //color's block location where player3 pins are present.
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),79);
                    cout<<" "<<lodo[i][j];
                }
                else if(p[3].getLocation(0)==&lodo[i][j] || p[3].getLocation(1)==&lodo[i][j] || p[3].getLocation(2)==&lodo[i][j] || p[3].getLocation(3)==&lodo[i][j])
                {                                                                  //color's block location where player4 pins are present.
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),47);
                    cout<<" "<<lodo[i][j];
                }
                else if((i==2 || i==4 || i==12 || i==14) && (j==2 || j==4 || j==12 || j==14))
                {                                     //if any pin of any Player is out of home then this common color is applied.
                    if((i==2||i==4)&&(j==2||j==4))
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),144);
                    else if((i==2||i==4)&&(j==12||j==14))
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),96);
                    else if((i==12||i==14)&&(j==12||j==14))
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),64);
                    else
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),32);
                    cout<<" "<<lodo[i][j];
                }
                else if((i==7 && j==2) || (i==2 && j==9) || (i==9 && j==14) || (i==14 && j==7))
                {                                     //color's Player Home Entrance Places.
                    cout<<" ";
                    if(i==7 && j==2)
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),249);
                    else if(i==2 && j==9)
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),246);
                    else if(i==9 && j==14)
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),244);
                    else if(i==14 && j==7)
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),250);
                    cout<<lodo[i][j];
                }
                else if((i==2 || i==3 || i==4 || i==5 || i==6 || i==7) && j==8)
                {                                     //color's Inner block location where player1 pins are present.
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color[1]);
                    cout<<" "<<lodo[i][j];
                }
                else if(i==8 && (j==2 || j==3 || j==4 || j==5 || j==6 || j==7))
                {                                     //color's Inner block location where player2 pins are present.
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color[0]);
                    cout<<" "<<lodo[i][j];
                }
                else if((i==14 || i==13 || i==12 || i==11 || i==10 || i==9) && j==8)
                {                                     //color's Inner block location where player3 pins are present.
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color[3]);
                    cout<<" "<<lodo[i][j];
                }
                else if(i==8 && (j==14 || j==13 || j==12 || j==11 || j==10 || j==9))
                {                                     //color's Inner block location where player4 pins are present.
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color[2]);
                    cout<<" "<<lodo[i][j];
                }
                else if((i==9 && j==3) || (i==3 && j==7) || (i==7 && j==13) || (i==13 && j==9))
                {                                     //color's Rest Places.
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),117);
                    cout<<" "<<lodo[i][j];
                }
                /*else if((i==6 && j==2) || (i==2 && j==10) || (i==14 && j==6) || (i==10 && j==14) || (i==10 && j==3) || (i==3 && j==6) || (i==6 && j==13) || (i==13 && j==10))
                {                                     // color's Marker for Rest + Marker for Player's Home Entrance.
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),245);
                    cout<<" "<<lodo[i][j];
                }
                */
                else                                  // color's common pathway locations which has no pins.
                    cout<<" "<<lodo[i][j];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
            }
            cout<<"\n";
        }
    }

};

class start : public show{
    bool bonusChance = false;
    int activePlayer = -1;
    int activePin;       //   Keeps track of Currently Active Player, it Changes in every chance
    char dice[5][5];      //    Only to display Dice
    int top;    // Top of Dice
    bool continueGame = true;       //   it will set to False when any one player's get first Rank in the game.
    bool pass = false;
    bool gatewayPass = true;
    bool first_time_only = true;
    bool tryLuck = false;
    int prediction = 0;
    bool notJustMode = false;

    public :

    int nextChance()
    {
        switch(numOfPlayers()){
        case 4:{if(activePlayer == -1)
                    return (activePlayer = 0);
                else
                    return ((activePlayer == 3)?activePlayer = 0:(activePlayer++));
            }
            break;
        case 2:{
                if(cageNumber() == 1){
                    if(activePlayer == -1)
                        return (activePlayer = 0);
                    else
                        return ((activePlayer == 2)?activePlayer = 0:(activePlayer+=2));
                }
                else{
                    if(activePlayer == -1)
                        return (activePlayer = 1);
                    else
                        return ((activePlayer == 3)?activePlayer = 1:(activePlayer+=2));
                }
            }
            break;
        }
    }

    void newGame(int choice)
    {
        (choice == 2)?notJustMode=true:notJustMode=false;
        int num_of_player = numOfPlayers();
        p = new plyr[No_Of_Objects];
        if(num_of_player == 2)
            selectCage();
        logo();
        gameSetUp(0);
        display();
        play();    //   play will be recursively called, as long as any one of the player wins the game and return false.
        cout<<"\n\n\n\t\t";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),71);
        cout<<" ***  Game Over  *** ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
        cout<<"\n\n\n\t\t ";system("pause");
    }

    void play()
    {     //recursion Concept
        //cout<<"\n\n\t\t\tbonusChance : "<<bonusChance<<" , countinueGame: "<<continueGame<<"\n";   //erase this step
        if(!bonusChance)
            nextChance();
        if(p[activePlayer].checkName() == " "){
            string pName;
            static int que;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),250);
            cout<<"\n\n\n\t\t\t*Blank Spaces in name's is not allowed.\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
            cout<<"\n\t\t\tEnter Player"<<(++que)<<" Name : ";
            cin>>pName;
            p[activePlayer].setName(pName);
            display();
        }
        if(bonusChance)
            cout<<"\n\n\t\t\t\t Bonus Turn : ";
        else
            cout<<"\n\n\t\t\t\t Turn : ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),p[activePlayer].getColor(activePlayer));
        p[activePlayer].getName();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
        if(!bonusChance && notJustMode){
            tryLuck = true;
            cout<<"\n\n\n\t\t Predict before rolling : ";//system("pause");
            cin>>prediction;
            if(prediction<1 || prediction>6)
                    prediction = 0;
        }
        else{
            cout<<"\n\n\n\t\t > To throw dice ";system("pause");
        }
        bonusChance = false;
        playChance();
        if(continueGame)
            play();
    }

    void playChance()
    {
        displayDice();

        if(tryLuck && notJustMode){
                if(prediction == top){
                    //bonusChance = true;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),253);
                    cout<<"\n\n\t\t Congratulation!!, Your prediction turned out to be right.\n\t\t NOTE : You may enter another staged token to its starting square, or will get an additional or \"bonus\" roll in this turn."<<endl;
                }
                else{
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),244);
                    cout<<"\n\n\t\t *Your prediction got wrong, no privilege earned."<<endl;
                }
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
        }

        if((top<6) && ((p[activePlayer].getStepCount(0)==-1 || p[activePlayer].getStepCount(0)+top>MAX_STEP) && (p[activePlayer].getStepCount(1)==-1 || p[activePlayer].getStepCount(1)+top>MAX_STEP) && (p[activePlayer].getStepCount(2)==-1 || p[activePlayer].getStepCount(2)+top>MAX_STEP) && (p[activePlayer].getStepCount(3)==-1 || p[activePlayer].getStepCount(3)+top>MAX_STEP)))
            gatewayPass = false;    //check
        //cout<<"\n\t\t\t\tTop : "<<top<<"\n";     //erase this step
        if(((prediction == top) && notJustMode) || (gatewayPass && (top == 6 || (top>=1 && top<=5 && (p[activePlayer].getLocation(0)!=nullptr || p[activePlayer].getLocation(1)!=nullptr || p[activePlayer].getLocation(2)!=nullptr || p[activePlayer].getLocation(3)!=nullptr)))))
        {
            selectPin();
            if(pass)
            {
                if(top == 6)   bonusChance = true;
                if(tryLuck && (prediction == top) && notJustMode){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),253);
                    if(p[activePlayer].getStepCount(activePin)== -1 && top!=6){
                        bonusChance = false;
                        cout<<"\n\n\t\t NOTE : You chose to enter Staged token and therefore no \"Bonus\" turn will be given.";
                        top = 6;
                    }
                    else{
                        bonusChance = true;
                        cout<<"\n\n\t\t NOTE : You have been privileged with a \"Bonus\" turn.";
                    }
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
                    cout<<"\n\n\n\t\t";system("pause");
                    //tryLuck = false;
                }
                if((p[activePlayer].getStepCount(activePin)+top)<=54)
                {
                    if(top == 6)
                    {
                        if(p[activePlayer].getLocation(activePin)!=nullptr)
                        {
                            placeState();
                            p[activePlayer].setCount(activePin, (p[activePlayer].getCount(activePin)+top)%56);
                            p[activePlayer].setStepCount(activePin, p[activePlayer].getStepCount(activePin)+top);
                        }
                        else
                        {
                            p[activePlayer].setCount(activePin, activePlayer*14);
                            p[activePlayer].setStepCount(activePin, 0);
                        }
                        p[activePlayer].setLocation(activePin, ludo[p[activePlayer].getCount(activePin)]);
                        p[activePlayer].setLocation(activePin);
                        checkPlace();
                    }
                    else if(p[activePlayer].getLocation(activePin)!=nullptr)
                    {
                        placeState();
                        p[activePlayer].setCount(activePin, (p[activePlayer].getCount(activePin)+top)%56);
                        p[activePlayer].setStepCount(activePin, p[activePlayer].getStepCount(activePin)+top);
                        p[activePlayer].setLocation(activePin, ludo[p[activePlayer].getCount(activePin)]);
                        p[activePlayer].setLocation(activePin);
                        checkPlace();
                    }
                }
                else
                {
                    if(!p[activePlayer].checkInsideStatus(activePin)){
                        placeState();
                        p[activePlayer].checkInsideStatus(activePin,true);
                        p[activePlayer].setCount(activePin, -1);
                    }
                    else
                        insidePlaceState();
                    p[activePlayer].setStepCount(activePin, p[activePlayer].getStepCount(activePin)+top);
                    p[activePlayer].setLocation(activePin, insideLudo[activePlayer][p[activePlayer].getStepCount(activePin)-55]);
                    if(p[activePlayer].getStepCount(activePin)!=MAX_STEP){
                        p[activePlayer].setLocation(activePin);
                    }
                    else
                    {
                        bonusChance = true;
                        display();
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),250);
                        cout<<"\n\t\t # # Awesome!!,";p[activePlayer].getName();cout<<"your token "<<activePin+1<<" has reached finishing square. # # "<<endl;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
                        cout<<"\n\n\n\t\t ";system("pause");

                        if(p[activePlayer].getLocation(0)==&lodo[8][8] && p[activePlayer].getLocation(1)==&lodo[8][8] && p[activePlayer].getLocation(2)==&lodo[8][8] && p[activePlayer].getLocation(3)==&lodo[8][8])
                        {
                            continueGame =false;
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),117);
                            cout<<"\n\n\t\t Congratulations";p[activePlayer].getName();cout<<" you wins the game."<<endl;
                            return;
                        }
                    }
                }
                //display();
                //cout<<"\nbonusChance : "<<bonusChance<<" , countinueGame: "<<continueGame<<"\n";
                //cout<<"\nactivePin : "<<activePin<<"\nStepCount : "<<p[activePlayer].getStepCount(activePin)<<"\n Count : "<<p[activePlayer].getCount(activePin);cout<<"\n\t\t ";system("pause"); //erase this step
            }
            gatewayPass = true;
        }
        else{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),244);
            if(!gatewayPass){
                gatewayPass = true;
                if(p[activePlayer].getStepCount(0)==-1 && p[activePlayer].getStepCount(1)==-1 && p[activePlayer].getStepCount(2)==-1 && p[activePlayer].getStepCount(3)==-1)
                    cout<<"\n\t\t *Sorry!!, You can open a new token only when 6 appears on the dice or if any privilege is granted in this turn."<<endl;
                else
                    cout<<"\n\t\t *This move is not possible for you."<<endl;
            }
            else{
                if((prediction != top) && notJustMode)
                    cout<<"\n\n\t\t *It was a wrong prediction, no privilege earned in this chance."<<endl;
                cout<<"\n\t\t *Sorry!!, You can open a new token only when 6 appears on the dice or if any privilege is granted in this turn."<<endl;
            }
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
            cout<<"\n\n\n\t\t ";system("pause");
        }
        display();
        if(tryLuck && notJustMode){
            prediction = 0;
            tryLuck = false;
        }
    }

    void placeState()   //Rebuilt
    {
       if(p[activePlayer].getCount(activePin)== 0 || p[activePlayer].getCount(activePin)== 9 || p[activePlayer].getCount(activePin)== 14 || p[activePlayer].getCount(activePin)== 23 || p[activePlayer].getCount(activePin)==28 || p[activePlayer].getCount(activePin)== 37 || p[activePlayer].getCount(activePin)== 42 || p[activePlayer].getCount(activePin)== 51){
            int f=0;
                for(int i=1;i<=4;i++){
                    for(int pi=1;pi<=4;pi++){
                        if(p[activePlayer].getCount(activePin)==p[(activePlayer+i)%4].getCount((activePin+pi)%4)){
                            if((((activePlayer+i)%4)==activePlayer) && (((activePin+pi)%4)==activePin)){
                                if(p[activePlayer].getCount(activePin)== 0 || p[activePlayer].getCount(activePin)== 14 || p[activePlayer].getCount(activePin)==28 || p[activePlayer].getCount(activePin)== 42)
                                    p[activePlayer].setLocation(activePin, 'п');
                                else
                                    p[activePlayer].setLocation(activePin, '*');
                            }
                            else
                                p[activePlayer].setLocation(activePin, p[(activePlayer+i)%4].getIcon((activePin+pi)%4));
                            f=1;
                            break;
                        }
                    }
                    if(f==1)
                        break;
                }
                if(f==0)
                    p[activePlayer].setLocation(activePin, '*');
        }
        else
            p[activePlayer].setLocation(activePin, 'п');
    }

    void insidePlaceState()
    {
        int flag = 0;
        for(int i=1;i<4;i++)    //status
            if(p[activePlayer].getStepCount(activePin)==p[activePlayer].getStepCount((activePin+i)%4)){
                p[activePlayer].setLocation(activePin, p[activePlayer].getIcon((activePin+i)%4));
                flag = 1;
                break;
            }
        if(flag == 0)
            p[activePlayer].setLocation(activePin, 'п');
    }

    void checkPlace()
    {
        for(int plr=0 ; plr<4;plr++){
            if(plr!=activePlayer){
                for(int i=0 ; i<4 ; i++){
                    if(p[activePlayer].getLocation(activePin)==p[plr].getLocation(i) && (p[activePlayer].getCount(activePin)!= 0 && p[activePlayer].getCount(activePin)!= 9 && p[activePlayer].getCount(activePin)!= 14 && p[activePlayer].getCount(activePin)!= 23 && p[activePlayer].getCount(activePin)!=28 && p[activePlayer].getCount(activePin)!= 37 && p[activePlayer].getCount(activePin)!= 42 && p[activePlayer].getCount(activePin)!= 51))
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),241);
                        cout<<"\n\t\t NOTE : Token "<<i+1<<" of";p[plr].getName();cout<<"has been killed by token "<<activePin+1<<" of";p[activePlayer].getName();cout<<"."<<endl;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
                        cout<<"\n\n\n\t\t ";system("pause");
                        p[plr].setLocation(i,nullptr);
                        p[plr].setStepCount(i,-1);
                        p[plr].setCount(i,-1);
                        display();
                        bonusChance = true;
                    }
                }
            }
        }
    }

    void selectPin()
    {           //if its Player's chance : selectPin() will return pin selected by player to move forward.
        int pin;
        int invalid=1;
        while(invalid){
            cout<<"\n\t\t Select a Token : ";
            cin>>pin;
            if(pin>=1 && pin<=4)
            {
                if(((top<=5 && p[activePlayer].getLocation(pin-1)!=nullptr) || top==6 || ((top == prediction) && notJustMode)) && ((p[activePlayer].getStepCount(pin-1)+top)<=MAX_STEP)){
                    activePin = pin-1;
                    pass = true;
                    invalid = 0;
                }
                else if((p[activePlayer].getStepCount(pin-1)==MAX_STEP || p[activePlayer].getLocation(pin-1)==&lodo[8][8]) && ((p[activePlayer].getLocation(pin%4)==nullptr || p[activePlayer].getLocation(pin%4)==&lodo[8][8]) && (p[activePlayer].getLocation((pin+1)%4)==nullptr || p[activePlayer].getLocation((pin+1)%4)==&lodo[8][8]) && (p[activePlayer].getLocation((pin+2)%4)==nullptr|| p[activePlayer].getLocation((pin+2)%4)==&lodo[8][8])))
                {
                    pass = false;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),244);
                    cout<<"\n\t\t *This move is not possible for you.";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
                    cout<<"\n\n\n\t\t ";system("pause");
                    invalid = 0;
                    //return;
                }
                else if((p[activePlayer].getStepCount(pin-1)+top > MAX_STEP) && ((p[activePlayer].getLocation(pin%4)==nullptr || p[activePlayer].getLocation(pin%4)==&lodo[8][8]) && (p[activePlayer].getLocation((pin+1)%4)==nullptr || p[activePlayer].getLocation((pin+1)%4)==&lodo[8][8]) && (p[activePlayer].getLocation((pin+2)%4)==nullptr|| p[activePlayer].getLocation((pin+2)%4)==&lodo[8][8])))
                {
                    pass = false;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),244);
                    cout<<"\n\t\t *This move is not possible for you.";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
                    cout<<"\n\n\n\t\t ";system("pause");
                    invalid = 0;
                    //return;
                }
                else if((p[activePlayer].getStepCount(pin-1)+top > MAX_STEP) && (p[activePlayer].getStepCount(pin%4)+top)>MAX_STEP && (p[activePlayer].getStepCount((pin+1)%4)+top)>MAX_STEP && (p[activePlayer].getStepCount((pin+2)%4)+top)>MAX_STEP)
                {
                    pass = false;
                    invalid = 0;
                    //return;
                }
                else{
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),244);
                    cout<<"\n\t\t *Any token out of home which is allowed to take "<<top<<" step can only be selected.";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
                    //cout<<"\n\n\n\t\t ";system("pause");
                }
            }
            else{
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),244);
                cout<<"\n\t\t Enter a valid Pin!!";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
                cout<<"\n\n\n\t\t ";system("pause");
            }
        }
    }

    void displayDice()
    {
        throwDice();
        cout<<"\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),245);
        for(int x=0;x<5;x++){
            cout<<"\t\t ";
            for(int y=0;y<5;y++){
                if((x==0 || x==4) || (y==0 || y==4))
                    dice[x][y]='..';
                cout<<" "<<dice[x][y];
            }
            cout<<"\n";
        }
        emptyDice();        // if separate class for dice is made then this function is not required.
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
    }

    int throwDice()
    {
        if(first_time_only){
            srand(time(NULL));
            first_time_only = false;
        }
        top = rand()%RAND_MAX;
        if(top>0 && top<7){
            switch(top){
                case 1:{
                    dice[2][2]='м';
                    }
                    break;
                case 2:{
                    dice[2][1]='м';dice[2][3]='м';
                    }
                    break;
                case 3:{
                    dice[1][3]='м';dice[2][2]='м';dice[3][1]='м';
                    }
                    break;
                case 4:{
                    dice[1][1]='м';dice[1][3]='м';dice[3][1]='м';dice[3][3]='м';
                    }
                    break;
                case 5:{
                    dice[1][1]='м';dice[1][3]='м';dice[3][1]='м';dice[3][3]='м';dice[2][2]='м';
                    }
                    break;
                case 6:{
                    dice[1][1]='м';dice[2][1]='м';dice[3][1]='м';dice[1][3]='м';dice[2][3]='м';dice[3][3]='м';
                    }
                    break;
            }
            return top;
        }
        throwDice();
    }

    void emptyDice(){
        for(int x=0;x<5;x++)
            for(int y=0;y<5;y++)
                dice[x][y]=' ';
    }

};

int main(){
    SMALL_RECT windowSize = {0,0,60,90};
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE),TRUE,&windowSize);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
    start *game = new start();
    //game->logo();
    //game->players();
    game->numOfPlayers(4);
    int choice;
    do{
        game->logo();
        choice = game->menu(false);
        switch(choice){
            case 1:{ choice = game->menu(true);
                     game->newGame(choice);
                     delete game;
                     choice = 5;
                   }
                break;
            case 2: game->players();
                break;
        }
        cout<<"\n\n\n";
    }while(choice<3);
    switch(choice)
    {
        case 3:{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),144);
            system("cls");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
            cout<<"===============================================================================================================\n\n\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),144);
            cout<<"\n\t\t\t\t\tThank You For Playing\t\t\t\t\t\t\n";
            cout<<"\n\t\t\t\t Created By Naman Jakhetiya \n\n\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
            cout<<"===============================================================================================================\n\n";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),144);
            cout<<"\n\n\n\t\t ";system("pause");
                break;
            }
        default: main();
    }
    return 0;
}
