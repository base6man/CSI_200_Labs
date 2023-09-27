#include <iostream>
#include "vector_functions.h"
using namespace std;

int main(){
    float xCoordinate, yCoordinate;
    float xVector, yVector, angle;
    int menuChoice = -1;

    while(menuChoice != 0){
        cout << "Menu:" << endl;
        cout << "       1) Enter point (x, y) coordinate" << endl;
        cout << "       2) Rotate point by angle" << endl;
        cout << "       3) Rotate point by vector" << endl;
        cout << "       0) Quit" << endl;

        cin >> menuChoice;
        if(menuChoice != 1 && menuChoice != 2 && menuChoice != 3 && menuChoice != 0) {
            cout << "Invalid selection, enter a valid option" << endl;
            continue;
        }

        cout << "Choice: " << menuChoice << endl;
        
        if(menuChoice == 1){
            point_input(&xCoordinate, &yCoordinate);
            continue;
        }
        if(menuChoice == 2){
            float xOutput, yOutput;

            angle_input(&angle);
            angle_to_vector(angle, &xVector, &yVector);
            rotate_point_by_vector(xCoordinate, yCoordinate, xVector, yVector, &xOutput, &yOutput);
            
            cout << "The point (" << xCoordinate << ", " << yCoordinate << ") ";
            cout << "rotated by " << angle << " degrees ";
            cout << "is now at (" << xOutput << ", " << yOutput << ")" << endl;

            xCoordinate = xOutput;
            yCoordinate = yOutput;
            continue;
        }
        if(menuChoice == 3){
            float xOutput, yOutput;
            float normalXVector, normalYVector;

            vector_input(&xVector, &yVector);
            vector_normalize(xVector, yVector, &normalXVector, &normalYVector);
            rotate_point_by_vector(xCoordinate, yCoordinate, normalXVector, normalYVector, &xOutput, &yOutput);

            angle = vector_to_angle(xVector, yVector);

            cout << "The point (" << xCoordinate << ", " << yCoordinate << ") ";
            cout << "rotated by the vector <" << xVector << ", " << yVector << "> (" << angle << " degrees) ";
            cout << "is now at (" << xOutput << ", " << yOutput << ")" << endl;

            xCoordinate = xOutput;
            yCoordinate = yOutput;
            continue;
        }
    }
    cout << "Goodbye!";
    return 0;
}