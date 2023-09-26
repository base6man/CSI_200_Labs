/* CSCI 200: Assignment 1: A1 - Rock Paper Scissor Throw Down!
 *
 * Author: Keaton Mitchell
 * Resources used: My classmate Nathan, who gave me the idea for the name "crossblades" as a stand-in for sizzors
 *
 * XXXXXXXX (MORE_COMPLETE_DESCRIPTION_HERE)
 */
// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.

// standard library and time
#include <cstdlib>
#include <ctime>

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Define any constants below this comment.

// Must have a function named "main", which is the starting point of a C++ program.
int main() {
  // seed the RNG - random number generator
  srand(time(0));
  rand();

  bool isStillPlaying = true;
  while(isStillPlaying){

    string playerChoice;
    int playerChoiceNumber;
    string playerChoiceString;

    // In this game, crossblades is equivalent to sizzors
    // This idea was given to me by my friend Nathan, and helps give everything unique initials
    cout << "Welcome one and all to a round of Rock, Paper, Crossblades, Lizard, Spock! (Enter R, P, C, L, or S)" << endl;
    cout << "Player one: ";
    cin >> playerChoice;
    cout << "Player chooses ";

    if(playerChoice == "c" || playerChoice == "C"){
      playerChoiceNumber = 0;
      playerChoiceString = "Crossblades";
    }
    if(playerChoice == "p" || playerChoice == "P"){
      playerChoiceNumber = 1;
      playerChoiceString = "Paper";
    }
    if(playerChoice == "r" || playerChoice == "R"){
      playerChoiceNumber = 2;
      playerChoiceString = "Rock";
    }
    if(playerChoice == "l" || playerChoice == "L"){
      playerChoiceNumber = 3;
      playerChoiceString = "Lizard";
    }
    if(playerChoice == "s" || playerChoice == "S"){
      playerChoiceNumber = 4;
      playerChoiceString = "Spock";
    }
    cout << playerChoiceString << endl;

    cout << "Computer chooses ";

    float randomNumber = (float) rand() / RAND_MAX;
    int computerChoiceNumber = randomNumber * 5;
    string computerChoiceString;

    switch(computerChoiceNumber){
      case 0:
        computerChoiceString = "Crossblades";
        break;
      case 1:
        computerChoiceString = "Paper";
        break;
      case 2:
        computerChoiceString = "Rock";
        break;
      case 3:
        computerChoiceString = "Lizard";
        break;
      case 4:
        computerChoiceString = "Spock";
        break;
      default:
        cout << "Something broke!" << endl;
        break;
    }
    cout << computerChoiceString << endl;

    if(playerChoiceNumber < computerChoiceNumber){
      playerChoiceNumber += 5;
    }
    if((playerChoiceNumber - computerChoiceNumber) % 5 == 0){
      cout << "Tie!" << endl;
    }
    else if((playerChoiceNumber - computerChoiceNumber) % 5 == 2 || (playerChoiceNumber - computerChoiceNumber) % 5 == 4){
      cout << playerChoiceString << " beats " << computerChoiceString << endl;
      cout << "Player wins!" << endl;
    }
    else{
      cout << computerChoiceString << " beats " << playerChoiceString << endl;
      cout << "Computer wins!" << endl;
    }

    string isStillPlayingString = "";
    cout << "Play again? (Y/N): ";
    cin >> isStillPlayingString;
    if(isStillPlayingString == "Y" || isStillPlayingString == "y"){
      isStillPlaying = true;
    }
    else{
      isStillPlaying = false;
    }
  }


  return 0; // signals the operating system that our program ended OK.
}