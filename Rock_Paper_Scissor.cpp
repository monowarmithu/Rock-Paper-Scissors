#include <iostream>
#include <stdlib.h>
#include<string>
#include <ctime>
#include<conio.h>
using namespace std;

class A
{
public:
    int number;

protected:
    int i, player, computer, player_win = 0, computer_win = 0, draw = 0;

public:
    void get()
    {
        cout << "How many time you play : ";
        cin >> number;
    }
};

class B : public A
{
public:
    void put()
    {
        for (i = 1; i <= number; ++i)
        {
        first:
            cout <<endl << "Enter : 1 for rock\n        2 for scissor\n        3 for paper \n=> ";
            cin >> player;
            cout << endl;
            if (player >= 1 && player <= 3)
            {
                if (player == 1)
                {
                    cout << "You choose \"Rock\"\n";
                }
                else if (player == 2)
                {
                    cout << "You choose \"scissor\"\n";
                }
                else
                {
                    cout << "You choose \"paper\"\n";
                }

                computer = (rand() % 3 + 1);

// computer choose
                if (computer == 1)
                {
                    cout << "Computer choose \"Rock\"\n";
                }
                else if (computer == 2)
                {
                    cout << "Computer choose \"scissor\"\n";
                }
                else
                {
                    cout << "Computer choose \"paper\"\n";
                }

// match
                if (player == computer)
                {
                    cout << "Match tie !\n";
                    draw++;
                }
                else if (player == 1)
                {
                    if (computer == 2)
                    {
                        cout << "Rock smashes scissors! You win! \n";
                        player_win++;
                    }
                    if (computer == 3)
                    {
                        cout << "Paper covers rock! You lose. \n";
                        computer_win++;
                    }
                }
                else if (player == 2)
                {
                    if (computer == 3)
                    {
                        cout << "Scissors cuts paper! You win! \n";
                        player_win++;
                    }
                    if (computer == 1)
                    {
                        cout << "Rock smashes scissors! You lose. \n";
                        computer_win++;
                    }
                }
                else if (player == 3)
                {
                    if (computer == 1)
                    {
                        cout << " Paper covers rock! You win!\n";
                        player_win++;
                    }
                    if (computer == 2)
                    {
                        cout << " Scissors cuts paper! You lose.\n";
                        computer_win++;
                    }
                }
            }
            else
            {
                cout << "wrong number";
                goto first;
            }
        }
    }
};

class C : public B
{
public:
    void getput()
    {
        cout << "\n";
        cout << "You win = " << player_win << "\n";
        cout << "Computer win = " << computer_win << "\n";
        cout << "Draw = " << draw;
    }
};


int main()
{
    srand(time(0));

    string name;
    cout<<"===========================================\n\n         Rock  Paper  Scissor game                 \n===========================================";
    cout<<endl<<"Enter Your Name : ";
    cin>>name;
    cout<<endl <<"Hello "<<name<<" !\n";

    C obj;
    obj.get();
    obj.put();
    obj.getput();

    cout<<endl<<"\nThanks for Playing ! press enter to exit.";
    getch();
}