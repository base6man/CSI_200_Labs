
#include <cmath>
#include "coordinate_conversion.h"

using namespace std;

/**
 * @brief converts 2 polar coordinates into their cartesian counterparts
 * @param RADIUS The point's distance from the origin
 * @param ANGLE The point's angle from the positive x axis
 * @param xCoordinate The address of the variable where the x coordinate will be stored
 * @param yCoordinate The address of the variable where the y coordinate will be stored
*/
void polar_to_cartesian(const float RADIUS, const float ANGLE, float* xCoordinate, float* yCoordinate){
    *xCoordinate = RADIUS*cos(ANGLE);
    *yCoordinate = RADIUS*sin(ANGLE);
}

/**
 * @brief converts 2 cartesian coordinates into their polar counterparts
 * @param X_COORDINATE The point's distance from the x-axis
 * @param Y_COORDINATE The point's distance from the y-axis
 * @param radius The address of the variable where the radius will be stored
 * @param angle The address of the variable where the angle will be stored
*/
void cartesian_to_polar(const float X_COORDINATE, const float Y_COORDINATE, float* radius, float* angle){
    *radius = sqrt(pow(X_COORDINATE, 2) + pow(Y_COORDINATE, 2));
    *angle = atan2(X_COORDINATE, Y_COORDINATE);
}
