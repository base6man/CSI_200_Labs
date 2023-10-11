/**
 * @file main.cpp
 * @author Keaton Mitchell (keatonmitchell000@gmail.com)
 * @brief Decodes a secret message file and returns it into a decoded message file
 * @version 0.1
 * @date 2023-10-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <fstream>
using namespace std;

int main() {
    ifstream secretMessage("secretMessage.txt");
    ofstream deciferedMessage("deciferedMessage.txt");

    char inputChar, outputChar;
    while(secretMessage.get(inputChar)){
        if(inputChar == '\n') outputChar = '\n';
        else if (inputChar == '~') outputChar = ' ';
        else{ outputChar = (char)(inputChar + 1); }

        deciferedMessage << outputChar;
    }

    return 0;
}
