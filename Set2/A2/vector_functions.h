/**
 * @brief Prompts the user to enter an angle and updates the corresponding parameter. Be sure to specify to the user what units they are working with.
 * @param A float pointer corresponding to the angle
*/
void angle_input(float* angle);

/**
 * @brief Converts an angle with the positive X-axis to the resultant vector on the unit circle
 * @param A float corresponding to the angle from the positive X-axis
 * @param A float pointer corresponding to the resultant vector's x coordinate
 * @param A float pointer corresponding to the resultant vector's y coordinate
*/
void angle_to_vector(float angle, float* x, float* y);

/**
 * @brief Prompts the user to enter the (x, y) coordinate and updates the corresponding parameters.
 * @param A float pointer corresponding to the point's y coordinate
 * @param A float pointer corresponding to the point's x coordinate
*/
void point_input(float* x, float* y);

/**
 * @brief Prompts the user to enter the <x, y> coordinate and updates the corresponding parameters.
 * @param A float pointer corresponding to the vector's y coordinate
 * @param A float pointer corresponding to the vector's x coordinate
*/
void vector_input(float* x, float* y);

/**
 * @brief Normalizes the input vector setting the corresponding pointer parameters to the output normalized vector
 * @param A float corresponding to the input vector's x coordinate
 * @param A float corresponding to the input vector's y coordinate
 * @param A float pointer corresponding to the output normalized vector's x coordinate
 * @param A float pointer corresponding to the output normalized vector's y coordinate
*/
void vector_normalize(float xInput, float yInput, float* xOutput, float* yOutput);

/**
 * @brief Determines the angle the vector forms with the positive X-axis based on where it intersects the unit circle. Angle is computed by taking the arctan of y over x. Be sure to handle edge cases correctly.
 * @param A float corresponding to the vector's x coordinate
 * @param A float corresponding to the vector's y coordinate
 * @return A float corresponding to the angle the vector forms with the positive X-axis
*/
float vector_to_angle(float x, float y);

/**
 * @brief Performs the rotation by multiplying complex numbers. Form a complex number using the point (px, py) coordinate: px + pyi. Form a second complex number using the vector <vx, vy> coordinate: vx + vyi. Multiply these two complex numbers to compute the resultant point.
 * @param A float corresponding to the input point's x coordinate
 * @param A float corresponding to the input point's y coordinate
 * @param A float corresponding to the input vector's x coordinate
 * @param A float corresponding to the input vector's y coordinate
 * @param A float pointer corresponding to the output rotated point's x coordinate
 * @param A float pointer corresponding to the output rotated point's y coordinate
 * @return float 
 */
void rotate_point_by_vector(float xPoint, float yPoint, float xVector, float yVector, float* xOutput, float* yOutput);