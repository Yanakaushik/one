#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    int playerMoney = 1000; // Starting virtual money
    int bet;

    cout << "The Casino Number Guessing Game!" << endl;
    cout << "You have Rs." << playerMoney << ". Good luck!" << endl;

    while (playerMoney > 0) {
        int secretNumber = rand() % 100 + 1;
        int guess;

        cout << "Enter your bet (you have Rs." << playerMoney << "): ";
        cin >> bet;

        if (bet <= 0 || bet > playerMoney) {
            cout << "Invalid bet amount. Please bet a valid amount." << endl;
            continue;
        }

        cout << "Guess a number between 1 and 100: ";
        cin >> guess;

        if (guess < secretNumber) {
            cout << "Too low! You lose Rs." << bet << "." << endl;
            playerMoney -= bet;
        } else if (guess > secretNumber) {
            cout << "Too high! You lose Rs." << bet << "." << endl;
            playerMoney -= bet;
        } else {
            cout << "Congratulations! You guessed the number " << secretNumber << " and win Rs." << bet << "!" << endl;
            playerMoney += bet;
        }

        cout << "The secret number was: " << secretNumber << endl;

        if (playerMoney > 0) {
            char playAgain;
            cout << "Do you want to play again? (y/n): ";
            cin >> playAgain;

            if (playAgain != 'y' && playAgain != 'Y') {
                cout << "Thank you for playing. You finish with Rs." << playerMoney << "." << endl;
                break;
            }
        } else {
            cout << "You've run out of money. Thanks for playing!" << endl;
            break;
        }
    }

    return 0;
}