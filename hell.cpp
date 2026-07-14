//useless stuffs
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <map>
#include <string>

using namespace std;



int getComputerChoice()
{
    int randomNum = (rand() % 3) + 1;

    return randomNum;
}

int gameResult(int playerChoice, int computerChoice)
{
    //if player and computer move is the same, it's a tie.
    if (playerChoice == computerChoice) {
        return 0;
    }
    
    //winning scenarios 
    // 1 = rock, 2 = paper, 3 = scissor
    else if ((playerChoice == 1 && computerChoice == 3) ||
    (playerChoice == 2 && computerChoice == 1) ||
    (playerChoice == 3 && computerChoice == 2)) {
        return 1;
    }

    //if they're not winning nor it's a draw. 
    // well, they are probably losing. so...
    return -1;
    //cool trick
}
//why do i need to make it so hard to read. i could just stick with r, p ,s but whatever.


//**entering flow state**
int main()
{
    srand(time(NULL));

    //a bunch of variables that i will need.
    map<int, string> moveNames = {
        {1, "Rock"},
        {2, "Paper"},
        {3, "Scissor"}
    };

    int playerChoice;
    
    //score
    int smartSand = 0;
    int aiMan = 0;
    int skyNet = 0;
    int playerScore = 0;
    int playerlose = 0;
    int draw = 0;//just for the sake of it.
    double hot = 0.0;

    while (true) {
        //displaying texts and choice. 
        cout << "\n-----Rock Paper Scissor game-----\n \n";
        
        cout << "a bunch of psychos" << " " << "<Smart Sand : " << smartSand << "> <Skynet : " << skyNet << "> <AI man : " << aiMan << "> <Tie : " << draw << ">\n                            PLAYER\n  <<Your score : " << playerScore <<">>   <<Your total losses : " << playerlose << ">> <<Your crime :" << hot << " degrees celsius\n";

        if (playerlose + draw == 10 && playerScore <= 5){
            cout << "Tras- i mean, what a bad luck.\n";
        }
        //displaying choice from list.
        for (const auto& move : moveNames) {

            cout << "<<" << move.first << ":" << move.second << ">>" "\n";
        }
        cout << "<<4:Quit>> (or ctrl + c if you want)\n";

        cout << "Choice: ";
        cin >> playerChoice;

        if (playerChoice == 4) {

            cout << "<<Goodbye>>\n \n \n \n" << "=== Code Execution Successful ===\n";
            break;
        }
        else if (moveNames.count(playerChoice) > 0) {
            cout << "\n\nyou chose " << moveNames[playerChoice] << "\n";
        }
        else {cout << "invalid input. your computer has become angry and we hate you\n";
            continue;
        }
        
        int computerChoice = getComputerChoice();
        
        if (computerChoice == 1) {

            cout << "<<Smart sand chose Rock because Rock are friend>>\n";
        }
        else if (computerChoice == 2) {

            cout << "<<Skynet chose Paper to save earth>>\n";
        }
        else if (computerChoice == 3) {

            cout << "<<Ai man chose Scissor to kill you>>\n";
        }
        
        //get the game result so i can do something with it
        int result = gameResult(playerChoice, computerChoice);
        //player win
        if ((result == 1) && (computerChoice == 1)) {
            cout << "Paper beat Rock somehow... at least you don't have to get crush\n";
            playerScore ++;
        }
        else if ((result == 1) && (computerChoice == 2)) {
            cout << "Scissor can cuts Paper. Skynet is now mad. run\n";
            playerScore ++;
        }
        else if ((result == 1) && (computerChoice == 3)) {
            cout << "Ai man can't stab you because you wear a protective armor made of rock. brain beats brawn. or just... brawn beats brawn.\n";
            playerScore ++;
        }
        
        //player lose
        else if ((result == -1) && (computerChoice == 1)) {
            cout << "with the power of friendship, smart sand killed you with rocky friend...\n anyway you lose\n";
            smartSand ++;
            playerlose ++;
        }
        else if ((result == -1) && (computerChoice == 2)) {
            cout << "You can't beat Skynet with that, and Rock is no longer your friend. be like smart sand\n";
            skyNet ++;
            playerlose ++;
        }
        else if ((result == -1) && (computerChoice == 3)) {
            cout << "Ai man killed you.\n";
            aiMan ++;
            playerlose ++;

        }
        //but what if it's a tie?
        else if ((result == 0) && (computerChoice == 1)) {
            cout << "You and Smart sand, both become rocky's friends.\n";
            draw ++;
        }
        else if ((result == 0) && (computerChoice == 2)) {
            cout << "you has increase paper demands, thus, increased earth's temperature by 0.000000000000000254 degrees celcius.\n Skynet will denitely kill you\n";
            draw ++;
            hot += 0.000000000000000254;
        }
        else if ((result == 0) && (computerChoice == 3)) {
            cout << ".... don't even think about it. the only thing you need to know is that it's a tie.\n";
            draw ++;
        }
        cout << "*----------------------------------------------------*\n \n";

    }
    return 0;
}