/* CSCI 200: Lab 1B: Random Classification
 *
 * Author: Keaton Mitchell
 *
 * CLI and Makefiles
 * Random Numbers
 * Makefiles
 */

// input/output 
#include <iostream>

// standard library and time
#include <cstdlib>
#include <ctime>


using namespace std;

int main() {
    // seed the RNG - random number generator
    srand(time(0));
    rand();

    bool repeat = true;
    string repeatString;
    while(repeat){
        //
        // Random Numbers
        //
        float randomNumber, randomNumberInRange;
        int quartile;
        string quartileName;
        float max, min;

        // Get intput for the range of values for random numbers
        cout << "Enter the minimum value: ";
        cin >> min;
        cout << "Enter the maximum value: ";
        cin >> max;

        



        // Generate random numbers
        randomNumber = (float) rand() / RAND_MAX;
        randomNumberInRange = randomNumber * (max - min) + min;
        quartile = randomNumber * 4;
        if(quartile == 0) quartileName = "first";
        if(quartile == 1) quartileName = "second";
        if(quartile == 2) quartileName = "third";
        if(quartile == 3) quartileName = "fourth";
        
        // Generate random numbers within a range
        cout << "A random value is: " << randomNumberInRange << endl;
        cout << "This is in the " << quartileName << " quartile." << endl;

        while(repeatString != "Y" && repeatString != "N"){
            cout << "Do you want another random value? (Y/N) ";
            cin >> repeatString;
        }

        if(repeatString == "N") repeat = false;
        repeatString = "";
    }

    return 0;
}
