/* CSCI 200: Fix Loop and Function Errors
 *
 * Author: Keaton Mitchell
 *
 * Description:
 *    This program illustrates a variety of common loop and function 
 *    errors.  Fix the errors in each section.
 * 
 * Copyright 2023 Dr. Jeffrey Paone
 * 
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#include <cstdlib>      // for rand(), srand()
#include <ctime>        // for time()
#include <iostream>     // for cout, cin, endl etc.
using namespace std;

/**
 * @brief adds five to the given parameter
 * @param x integer to be added to
 * @returns parameter plus five
 */
int add_five( int x ) {
    // isn't returning anything; should be returning x
    // added return x
    x += 5;
    return x;
}

/**
 * @brief generates a single random integer number within the expected range
 * @param MIN lower inclusive bound of range
 * @param MAX upper inclusive bound of range
 * @returns random integer within the range [MIN, MAX]
 */
int generate_random_integer(const int MIN, const int MAX) {
    // currently returning a regular random number
    // added code to put it between MIN and MAX
    int myRandomNumber = (double)rand() / RAND_MAX * (MAX - MIN + 1) + MIN;
    return myRandomNumber;
}

/**
 * @brief generates a single random floating point number within the expected range
 * @param MIN lower inclusive bound of range
 * @param MAX upper inclusive bound of range
 * @return random float within the range [MIN, MAX]
 */
float generate_random_float(const float MIN, const float MAX) {
    // also doing a regular random number
    // added a line to put it between MIN and MAX
    float myRandomNumber = (double)rand() / RAND_MAX * (MAX - MIN) + MIN;
    return myRandomNumber;
}

/**
 * @brief sums three integer values
 * @param x first value to be added
 * @param y second value to be added
 * @param z third value to be added
 * @returns the sum of all three parameters
 */
int sum( int x, int y, int z ) {
    // not using y and z, simply tripling x
    // made it return x + y
    return x + y + z;
}

/**
 * @brief multiples two floats together
 * @param a first value to multiply
 * @param b second value to multipl
 * @returns the product of the two float parameters
 */
float multiply( float a, float b ){
    // this was a function header with no function definition
    // made a definition
    return a * b;
}

/**
 * @brief runs test summing numbers in the range [1, N]
 */
void loop_test_1() {
    // FIX = made the end of the for loop <= instead of <
    // TESTS: n = 5
    // Should return 15

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Looping 1 " << endl;
    cout << "******************" << endl;

    int n;  
    cout << "Enter a number greater than 1 to sum up to: ";
    cin >> n;

    int sum;
    for(int i = 1; i <= n; ++i) {
         sum += i;
    }
    cout << "The sum of the numbers from 1 to " << n << " (inclusive) is: " << sum << endl;
}

/**
 * @brief runs test summing set of prices entered by the user
 */
void loop_test_2() {
    // FIX = moved "totalPrice = 0" outside of the for loop
    // TESTS: numItems = 3; prices = 4, 7, 8
    // Should return 19

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Looping 2 " << endl;
    cout << "******************" << endl;

    int numItems;
    cout << "How many items do you have? ";
    cin >> numItems;
    cout << endl;

    int counter = 1;
    float totalPrice, price;
    totalPrice = 0;
    while (counter <= numItems) {
        cout << "Enter the price of item " << counter << ": ";
        cin >> price;
        totalPrice += price;
        counter++;
    }
    cout << "The total price is: " << totalPrice << endl;
}

/**
 * @brief runs test summing numbers in the range [1, N]
 */
void loop_test_3() {
    // FIX = added counter++ to within the do-while loop
    //       used n to check whether to end the loop instead of sum
    // TESTS: n = 5
    // Should return 15

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Looping 3 " << endl;
    cout << "******************" << endl;

    int n;
    cout << "What number do you wish me to sum to?" << endl;
    cin >> n;

    int sum = 0, counter = 1;
    do {
        sum += counter;
        cout << "Sum so far: " << sum << endl;
        counter++;
    } while (counter <= n);

    cout << endl << "Section III Recap" << endl;

    cout << "I calculated the sum of numbers from 1 to " << n << " (inclusive) as " << sum << endl;
}

/**
 * @brief runs test summing i^2 in the range [1, N]
 */
void loop_test_4() {
    // FIX made i decreasing in the for loop
    // TESTS: n = 3
    // Should return 14

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Looping 4 " << endl;
    cout << "******************" << endl;

    cout << "I will now calculate the sum of squares from 1 to N (inclusive)" << endl;
    
    int n;
    cout << "Enter N: ";
    cin >> n;

    int sum = 0;
    for (int i = n; i > 0; i--) {
        sum += i*i;
    }

    cout << "The sum of squares from 1 to " << n << " is: " << sum << endl;
}

/**
 * @brief runs test summing i^3 in the range [1, N]
 */
void loop_test_5() {
    // FIX = moved counter++ to within the while loop, and used counter <= n as the loop break check
    // TESTS: n = 3
    // Should return 36

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Looping 5 " << endl;
    cout << "******************" << endl;

    cout << "I will now calculate the sum of cubes from 1 to N (inclusive)" << endl;

    int n;
    cout << "Enter N: ";
    cin >> n;

    int sum = 0, counter = 1;
    while (counter <= n) {
        sum += (counter * counter * counter);
        counter++;
    }

    cout << "The sum of cubes from 1 to " << n << " is: " << sum << endl;
}

/**
 * @brief runs test using function to add five to an entered value
 */
void function_test_1() {
    // FIX = made add_five return a value
    // TESTS: numTrees = 3
    // Should return 8

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Function 1" << endl;
    cout << "******************" << endl;

    int numTrees;
    cout << "How many trees do you currently have? ";
    cin >> numTrees;
    cout << "There are initially " << numTrees << " trees." << endl;
    numTrees = add_five( numTrees );
    cout << "We planted five trees, there are now " << numTrees << " trees." << endl;
}

/**
 * @brief prints a smiley face
*/
void printSmileyFace(){
    cout << ":)";
}

/**
 * @brief runs test to call a function that outputs a smiley face to the standard out
 * 
 */
void function_test_2() {
    // FIX = the printSmileyFace function does not exist. Added the function.
    // TESTS: No input for this function
    // Should return :)

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Function 2" << endl;
    cout << "******************" << endl;

    printSmileyFace();
}

/**
 * @brief runs test to generate five random integers within a provided range
 */
void function_test_3() {
    // FIX = made generate_random_integer return an integer within the bounds, as opposed to within any bounds
    //       also moved srand() to the beginning of the main function
    // TESTS: min = 5, max = 5
    // Should return 5   5   5   5   5
    //        min = 1, max = 10
    // Should return 5 numbers where 1 <= number <= 10

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Function 3" << endl;
    cout << "******************" << endl;

    int min, max;
    cout << "Enter the minimum integer range value: ";
    cin >> min;
    cout << "Enter the maximum integer range value: ";
    cin >> max;

    cout << "Five different random numbers are: " << endl;
    for( int i = 0; i < 5; i++ ) {
        cout << "\t" << generate_random_integer(min, max) << endl;
    }
}

/**
 * @brief runs test to use function to sum three values
 */
void function_test_4() {
    // FIX = fixed sum() to actually sum the numbers, instead of tripling x
    //       also fixed the arguments for the call of sum() to include num3
    // TESTS: num1 = 0, num2 = 0, num3 = 0
    // Should return 0
    //        num1 = 1, num2 = 2, num3 = 3
    // Should return 6

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Function 4" << endl;
    cout << "******************" << endl;

    int num1, num2, num3;
    cout << "Enter three integer numbers: ";
    cin >> num1 >> num2 >> num3;
    cout << "The sum of all three is " << sum( num1, num2, num3 ) << endl;
}

/**
 * @brief runs test to generate five random floats within a provided range
 */
void function_test_5() {
    // FIX = made generate_random_float() return a float within the bounds, as opposed to within any bounds
    //       also changed generate_random_float to generate_random_float(), and added the appropriate arguments
    // TESTS: min = 1.0, max = 1.0
    // Should return    1   1   1   1   1
    //        min = 1.1, max = 4.7
    // Should return 5 numbers where 1.1 <= number <= 4.7

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Function 5" << endl;
    cout << "******************" << endl;

    float min, max;
    cout << "Enter the minimum float range value: ";
    cin >> min;
    cout << "Enter the maximum float range value: ";
    cin >> max;
    cout << "Five different random floats are: " << endl;
    for( int i = 0; i < 5; i++ ) {
        cout << "\t" << generate_random_float(min, max) << endl;
    }
}

/**
 * @brief runs test to use function to multiply two provided numbers
 */
void function_test_6() {
    // FIX = created the function definition for multiply()
    // TESTS: leftHandSide = 2.5, rightHandSide = 0.2
    // Should return 0.5

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Function 6" << endl;
    cout << "******************" << endl;

    float leftHandSide, rightHandSide;
    cout << "Enter two floats: ";
    cin >> leftHandSide >> rightHandSide;
    cout << "Their product is: " << multiply( leftHandSide, rightHandSide ) << endl;
}

int main() {
    srand( time(0) );
    rand();
    cout << "Welcome To Looping Function World!" << endl;
    
    loop_test_1();        // run looping test 1
    loop_test_2();        // run looping test 2
    loop_test_3();        // run looping test 3
    loop_test_4();        // run looping test 4
    loop_test_5();        // run looping test 5

    function_test_1();    // run function test 1
    function_test_2();    // run function test 2
    function_test_3();    // run function test 3
    function_test_4();    // run function test 4
    function_test_5();    // run function test 5
    function_test_6();    // run function test 6

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Done" << endl;
    cout << "******************" << endl;

    cout << endl << "Congrats!  You fixed them all (hopefully correctly!)" << endl << endl << "Goodbye" << endl << endl;

    return 0;
}

