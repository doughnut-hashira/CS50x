#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <algorithm>

using std::cout, std::cin;

char playersChoice();
char computersChoice();
void showChoice(char choice);
void ChooseWinner(char player,char computer);

int tries = 1;
int winCount;
int lossCount;
std::vector<int> vec = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

int main(void)
{
    srand(time(0));
    do
    {
        cout << "+----------------------------+" << "\n";
        cout << "|-----rock-paper-scissors----|" << "\n";
        cout << "+----------------------------+" << "\n";
        cout << ">>'r' for rock" << "\n";
        cout << ">>'p' for paper" << "\n";
        cout << ">>'s' for scissors" << "\n";
        cout << ">>'q' for quit" << "\n";
        winCount = 0;
        lossCount = 0;

        for (int i = 0; i < tries;)
        {
            char player = playersChoice();
            char computer = computersChoice();

            cout << "Players Choice: ";
            showChoice(player);
            if(player == 'q')
            {
                return 1;
            }
            else if (player != 'r' && player != 'p' && player != 's')
            {
                continue;
            }

            cout << "Computers Choice: ";
            showChoice(computer);
            ChooseWinner(player, computer);
            i++;
            if (winCount == round(tries / 2) && tries > 1)
            {
                cout << "Final winner is 'Player' \n";
                break;
            }
            else if (winCount == round(tries / 2) && tries > 1 )
            {
                cout << "Final winner is 'Computer' \n";
                break;
            }
        }
        tries = 1;
    }while(true);
}

char playersChoice()
{
    char player;
    cout << "Choice: ";
    cin >> player;
    return player;
}

char computersChoice()
{
    int draw = rand() % 3;
    if (draw == 0)
    {
        return 'r';
    }
    else if (draw == 1)
    {
        return 'p';
    }
    else
    {
        return 's';
    }
}

void showChoice(char choice)
{
    if (choice >= '0' && choice <= '9')
    {
        tries = choice - '0';
        cout << tries << " Rounds \n";
        return;
    }

    switch(choice)
    {
        case 'r':
            cout << "rock" << "\n";
            break;
        case 'p':
            cout << "paper" << "\n";
            break;
        case 's':
            cout << "scissors" << "\n";
            break;
        case 'q':
            cout << "quit" << "\n";
            break;
        default:
        cout << "INVALID" << "\n";
    }
}

void ChooseWinner(char player,char computer)
{
    if (player == computer) {
        cout << "It's a draw!\n";
    }
    else if ((player == 'r' && computer == 's') ||
               (player == 'p' && computer == 'r') ||
               (player == 's' && computer == 'p'))
    {
        cout << "Player wins!\n";
        winCount++;
    }
    else
    {
        cout << "Computer wins!\n";
        lossCount++;
    }

}
