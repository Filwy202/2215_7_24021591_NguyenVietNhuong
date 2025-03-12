#include <iostream>
#include <cstdlib>
#include <ctime>
#include "guessit.h"

using namespace std;


/***
    Args:
        
    Returns:
        number (int) : random number in range 1-100
***/
int generateRandomNumber() {
    // TODO: Return the random number in range 1 to 100
  return rand() % 100 + 1;
}

int getPlayerGuess() {
    // TODO: Ask the player guest and return the player's number
int guess;
    cout << "Enter your guess (1-100): ";
    cin >> guess;
    return guess;

}

string getAnswer(int number, int randomNumber) {
    /*** 
        TODO: check number with randomNumber and return the result.
              If number is higher than randomNumber, the answer is "Your number is higher."
              If number is lower than randomNumber, the answer is "Your number is lower."
              If number is equal randomNumber, the answer is "Congratulation! You win."
    ***/
   if (number > randomNumber) {
        return "Your number is higher.";
    } else if (number < randomNumber) {
        return "Your number is lower.";
    } else {
        return "Congratulations! You win.";
    }

}

bool checkSuccess(string answer) {
    // TODO: return the result after checking that player guessed right or wrong
    
    return answer == "Congratulations! You win.";
}

bool checkContinuePlaying(char isContinued) {
    // TODO: return result after checking player continue playing or not
    return (isContinued == 'y' || isContinued == 'Y');

}

char getPlayerOpinion() {
    // TODO: Ask the player about continue playing and return the player's choice
    char isContinued;
    
    cout << "Do you want to play again? (y/n): ";
    cin >> isContinued;
    
    return isContinued;
}


void playGuessIt() {
    int randomNumber = generateRandomNumber();
    int number;
    string answer;
    
    do {
        number = getPlayerGuess();
        answer = getAnswer(number, randomNumber);
        cout << answer << endl;
    } while (!checkSuccess(answer));
}

int run() {
    srand(time(0));
    char isContinued;
    do {
        playGuessIt();
        isContinued = getPlayerOpinion();
    } while (checkContinuePlaying(isContinued));
    return 0;
}
