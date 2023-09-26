/* CSCI 200: Lab 2B: Pointers: Addresses & Values
 *
 * Author: Keaton Mitchell
 *
 * Uses pointers to return multiple function values and splits functions across multiple files
 */

#include <iostream>
#include "coordinate_conversion.h"
using namespace std;


int main(){
    string userInput;

    cout << "This program converts cartesian to polar and polar to cartesian!" << endl;
    
    while(userInput != "Y" && userInput != "y" && userInput != "N" && userInput != "n"){

        cout << "Do you want to convert cartesian to polar? (Y/N)";
        cin >> userInput;
    }
    if(userInput == "Y" || userInput == "y"){
        float xCoordinate, yCoordinate, radius, angle;

        cout << "X coordinate: ";
        cin >> xCoordinate;
        cout << "Y coordinate: ";
        cin >> yCoordinate;

        cartesian_to_polar(xCoordinate, yCoordinate, &radius, &angle);
        cout << "The radius is " << radius << ", and the angle is " << angle << "." << endl;
    }
    else{

        float xCoordinate, yCoordinate, radius, angle;

        cout << "Radius: ";
        cin >> radius;
        cout << "Angle: ";
        cin >> angle;

        polar_to_cartesian(radius, angle, &xCoordinate, &yCoordinate);
        cout << "The x coordinate is " << xCoordinate << ", and the y coordinate is " << yCoordinate << "." << endl;
    }



    return 0;
}