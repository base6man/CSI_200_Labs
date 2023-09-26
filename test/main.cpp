/* CSCI 200: test: for my benefit only
 *
 * Author: Keaton Mitchell
 *
 * testing funny stuff
 */

// input/output 
#include <iostream>

// standard library and time
#include <cstdlib>
#include <ctime>

// my functions
#include "functions.h"

#ifndef FUNCTIONS_H
#define ADD_FUNCTIONS_H
/**
 * @brief multiplies 2 ints
 * @param x first operand
 * @param y second operand
 * @return product of x and y
*/
int multiply(int x, int y);
#endif

using namespace std;

int main() {
    // seed the RNG - random number generator
    srand(time(0));
    rand();

    
    #ifdef DEBUG
    cout << "Debugging!" << endl;
    #endif
    
    cout << multiply(3, 6) << endl;

    return 0;
}