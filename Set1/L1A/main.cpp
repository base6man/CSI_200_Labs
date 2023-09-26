/* CSCI 200: Lab 1A: Setup VS Code
 *
 * Author: Keaton Mitchell
 *
 * Did some math operations
 */

// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include <cmath>

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Define any constants below this comment.

const double PI = 3.141592;


// Must have a function named "main", which is the starting point of a C++ program.
int main() {

  /******** INSERT YOUR CODE BELOW HERE ********/
  double voltage, resistance, radius;

  cout << "Enter the voltage: ";
  cin >> voltage;
  cout << "Enter the resistance: ";
  cin >> resistance;
  cout << "The current is: " << voltage / resistance << endl;

  cout << "Enter the radius: ";
  cin >> radius;
  double volume = 4/3 * PI * pow(radius, 3);
  cout << "The volume is: " << volume;

  /******** INSERT YOUR CODE ABOVE HERE ********/

  return 0; // signals the operating system that our program ended OK.
}