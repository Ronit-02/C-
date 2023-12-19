#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<bits/stdc++.h>
#include<ctype.h>
using namespace std;

class casino
{
private:
    char player_name[20];
    int initial_amount;
    double bet_amount;
    int bet_choice1;
    int bet_choice2;
    int numberOnWheel;
    int bet_number[4];
public:
    void entry();
        ///Functions for roulette///
    void roulette();
    void rou_rules();
    void rou_option();
    void rou_outsideBet();
    void rou_insideBet();
    void rou_betDetails();
    void rou_betAgain();
    int rou_spinningWheel();
    double rou_winCondition(int);
};
void casino::entry()
{
    cout<<"Enter the player name: ";
    gets(player_name);
    player_name[0] = toupper(player_name[0]);
    startingOfGame:
    start:
    cout<<"\nEnter the initial deposit(500 min. amount): ";
    cin>>initial_amount;
    if( initial_amount < 500 )
    {
        cout<<"\nNot enough amount to play with";
        goto start;
    }
}
void casino::rou_option()
{
    gameplay:
    system("CLS");
    cout<<"\t\t Types of bet: ";
    cout<<"\n\t1. Outside Bet";
    cout<<"\n\t2. Inside Bet";
    cout<<"\n\tEnter the type of bet you want to play (1 or 2): ";
    cin>>bet_choice1;
    if( bet_choice1 == 1)
    {
        rou_outsideBet();
    }
    else if( bet_choice1 == 2)
    {
        rou_insideBet();
    }
    else
    {
        cout<<"\n\tWrong choice";
        cout<<"\n\tEnter again";
        system("PAUSE");
        goto gameplay;
    }
}
void casino::rou_betDetails()
{
    startingOfBet1:
    cout<<"\nEnter the amount you want to bet for: ";
    cin>>bet_amount;
    if( bet_amount > initial_amount )
    {
        cout<<"\nYou don't have enough money to bet ";
        cout<<"\nTry again ";
        goto startingOfBet1;
    }
}
double casino::rou_winCondition(int numberOfBets)
{
    startingOfWinCondition:
    cout<<"\nEnter "<<numberOfBets<<" number you want to bet on: ";
    for( int i=1; i<=numberOfBets; i++ )
    {
        cin>>bet_number[i];
        if( bet_number[i] > 36 || bet_number[i] < 0 )
        {
            cout<<"Invalid  number";
            cout<<"\nEnter again";
            goto startingOfWinCondition;
        }
    }
    numberOnWheel = rou_spinningWheel();
    cout<<numberOnWheel;
    double bet_totalAmount=0;
    int winner=0;
    for( int win=1; win<=numberOfBets; win++)
    {
        if( bet_number[win] == numberOnWheel )
        {
            bet_totalAmount += 2 * bet_amount;
            winner = 1;
        }
    }
    if( winner == 1)
    {
            cout<<"You won "<<bet_totalAmount;
            initial_amount += bet_totalAmount;
    }
    else
    {
        cout<<"\nBetter luck next time";
        initial_amount -= bet_amount;
    }
    return bet_totalAmount;
}
void casino::rou_betAgain()
{
    cout<<"\nTotal amount left: "<<initial_amount;
    char choice;
    if( initial_amount == 0 )
    {
        cout<<"\nYour money has exhausted";
        cout<<"\nYou can't play more bets";
    }
    else
    {
        cout<<"\nDo you want to play again with the left amount: ";
        cout<<"\nEnter your choice (y or n): ";
        cin>>choice;
        choice = toupper(choice);
        if( choice == 'Y')
            rou_option();
        system("CLS");
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t    The total amount you take is "<<initial_amount;
        cout<<"\n\t\t\t\t   Thank You for playing"<<"\n\n\n\n\n";
    }
}
void casino::rou_outsideBet()
{
    cout<<"\n\tTypes of Outside Bet";
    cout<<"\n\t1. Even or Odd \n\t2. Dozen or Column ";
    cout<<"\n\tEnter your bet (1 or 2): ";
    cin>>bet_choice2;
    outsideBetStr:
    int bet_outsideChoice1;
    int bet_outsideChoice2;
    int bet_totalAmount =0 ;
    switch( bet_choice2 )
    {
        case 1: cout<<"\nPress 1 for Even or 2 for Odd";
                cin>>bet_outsideChoice1;
                if( bet_outsideChoice1 == 1)
                {
                    cout<<"\nYou chose to bet on Even number";
                    rou_betDetails();
                    numberOnWheel = rou_spinningWheel();
                    cout<<numberOnWheel;
                    if( numberOnWheel % 2 == 0 )
                    {
                        bet_totalAmount += 2* bet_amount;
                        cout<<"\nYou won: ";
                        cout<<"\nTotal bet price won: "<<bet_totalAmount;
                        initial_amount += bet_totalAmount;
                    }
                    else
                    {
                        cout<<"Better luck next time";
                        initial_amount -= bet_amount;
                    }

                }
                else if( bet_outsideChoice1 == 2)
                {
                    cout<<"\nYou chose to bet on Odd number";
                    rou_betDetails();
                    numberOnWheel = rou_spinningWheel();
                    cout<<numberOnWheel;
                    if( numberOnWheel % 2 != 0 )
                    {
                        bet_totalAmount += 2* bet_amount;
                        cout<<"\nYou won: ";
                        cout<<"\nTotal bet price won: "<<bet_totalAmount;
                        initial_amount += bet_totalAmount;
                    }
                    else
                    {
                        cout<<"Better luck next time";
                        initial_amount -= bet_amount;
                    }

                }
                break;
        case 2: cout<<"\nPress 1 for Dozen or 2 for Column";
                cin>>bet_outsideChoice1;
                if( bet_outsideChoice1 == 1)
                {
                    cout<<"\nYou chose to bet on Dozen numbers";
                    cout<<"\n\tWhich dozen numbers you want to bet on \n\t1. First dozen (1-12) \n\t2. Second dozen (13-24) \n\t3. Third dozen (25-36) ";
                    cout<<"\n\tEnter your choice (1 , 2 or 3): ";
                    cin>>bet_outsideChoice2;
                    rou_betDetails();
                    numberOnWheel = rou_spinningWheel();
                    cout<<numberOnWheel;
                    if( bet_outsideChoice2 == 1 && numberOnWheel >=1 && numberOnWheel <=12 )
                    {
                        bet_totalAmount += 2* bet_amount;
                        cout<<"\nYou won: ";
                        cout<<"\nTotal bet price won: "<<bet_totalAmount;
                        initial_amount += bet_totalAmount;
                    }
                    else if( bet_outsideChoice2 == 2 && numberOnWheel >=13 && numberOnWheel <=24 )
                    {
                        bet_totalAmount += 2* bet_amount;
                        cout<<"\nYou won: ";
                        cout<<"\nTotal bet price won: "<<bet_totalAmount;
                        initial_amount += bet_totalAmount;
                    }
                    else if( bet_outsideChoice2 == 3 && numberOnWheel >=25 && numberOnWheel <=36 )
                    {
                        bet_totalAmount += 2* bet_amount;
                        cout<<"\nYou won: ";
                        cout<<"\nTotal bet price won: "<<bet_totalAmount;
                        initial_amount += bet_totalAmount;
                    }
                    else
                    {
                        cout<<"Better luck next time";
                        initial_amount -= bet_amount;
                    }

                }
                else if( bet_outsideChoice1 == 2)
                {
                    cout<<"\nYou chose to bet on Column";
                    cout<<"\n\tWhich column you want to bet on \n\t1. First column \n\t2. Second column \n\t3. Third column";
                    cout<<"\n\tEnter your choice (1 , 2 or 3): ";
                    cin>>bet_choice2;
                    rou_betDetails();
                    numberOnWheel = rou_spinningWheel();
                    cout<<numberOnWheel;
                    if( numberOnWheel % 2 != 0)   ///Will use file handling here
                    {
                        bet_totalAmount += 2* bet_amount;
                        cout<<"\nYou won: ";
                        cout<<"\nTotal bet price won: "<<bet_totalAmount;
                        initial_amount += bet_totalAmount;
                    }
                    else
                    {
                        cout<<"Better luck next time";
                        initial_amount -= bet_totalAmount;
                    }
                }
                break;
        default:cout<<"Wrong choice";
                cout<<"Enter your choice again: ";
                goto outsideBetStr;
    }
    rou_betAgain();
}
void casino::rou_insideBet()
{
    cout<<"\n\tTypes of Inside Bet";
    cout<<"\n\t1. One or Straight \n\t2. Two or Split \n\t3. Trio or Three \n\t4. Square or Four \n\t5. Five \n\t6. Six ";
    cout<<"\n\tEnter your bet (1 , 2 , 3 or 4) ";
    insideBetStr:
    cin>>bet_choice2;
    int numberOfBets;
    switch( bet_choice2 )
    {
        case 1: cout<<"\nYou chose a straight bet: ";
                numberOfBets = 1;
                rou_betDetails();
                cout<<"\nTotal bet price won: "<<rou_winCondition(numberOfBets);
                break;
        case 2: cout<<"\nYou chose a split bet: ";
                numberOfBets = 2;
                rou_betDetails();
                cout<<"\nTotal bet price won: "<<rou_winCondition(numberOfBets);
                break;
        case 3: cout<<"\nYou chose a Trio bet: ";
                numberOfBets = 3;
                rou_betDetails();
                cout<<"\nTotal bet price won: "<<rou_winCondition(numberOfBets);
                break;
        case 4: cout<<"\nYou chose a Square bet: ";
                numberOfBets = 4;
                rou_betDetails();
                cout<<"\nTotal bet price won: "<<rou_winCondition(numberOfBets);
                break;
        case 5: cout<<"\nYou chose a five bet: ";
                numberOfBets = 5;
                rou_betDetails();
                cout<<"\nTotal bet price won: "<<rou_winCondition(numberOfBets);
                break;
        case 6: cout<<"\nYou chose a six bet: ";
                numberOfBets = 6;
                rou_betDetails();
                cout<<"\nTotal bet price won: "<<rou_winCondition(numberOfBets);
                break;
        default:cout<<"Wrong choice";
                cout<<"Enter your choice again: ";
                goto insideBetStr;
    }
    rou_betAgain();
}
int casino::rou_spinningWheel()
{
    cout<<"Spinning";
    for(int ctr=0;ctr<10;ctr++)
    {
        cout<<".";
        Sleep(500);
    }
    srand(time(0));
    return((rand() % 36) + 1);   ///to return a random number from 1-36
}
void casino::rou_rules()
{
    system("CLS");
    cout<<"\n\n\n\t\t\t\t        About the game ";
    cout<<"\n\n\tRoulette is a simple yet fascinating game of chance that is extremely popular around the world.";
    cout<<"\n\tI doubt there is a person on this Earth that has n\’t heard of it and does n\’t have the slightest idea";
    cout<<"\n\tof how to play yet if you\’re planning on playing for money I would recommend that you explore the";
    cout<<"\n\trules of the game because in some cases that might actually give you better chances for a win.";
    cout<<"\n\n\n\t\t\t\t        Rules of the game ";
    cout<<"\n\n\tIn roulette, you can bet on a single number or on different groups of numbers. There are many betting";
    cout<<"\n\tcombinations all of which bring you different odds for winning and different payouts.";
    cout<<"\n\tAll in all, the more numbers you bet on, the bigger are your chances for a win and,";
    cout<<"\n\ttherefore, the lower are the payouts that the game offers.";
    cout<<"\n\tOther than that, all bets are divided in two main categories: inside and outside bets.";
    cout<<"\n\t\t\'Outside Bets\' - the bets that you place on the other sectors are called outside bets.";
    cout<<"\n\t\t\'Inside Bets\' - the bets that you place on the numbers themselves are called inside bets"<<"\n\n\t";
    system("\t\tPAUSE");
}
void casino::roulette()
{
    entry();       ///Here the player enters his/her name and initial amount to bet on
    rou_rules();  ///Rules regarding the game
    rou_option(); ///Controls the whole game
}
int main()
{
    casino first_player;
    first_player.roulette();
    return(0);
}

