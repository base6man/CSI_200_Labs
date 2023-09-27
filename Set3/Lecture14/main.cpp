#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    ifstream myInput("data.txt");
    ofstream myOutput("newData.txt");
    
    // If I want to keep my current output file, I can use this line:
    // ofstream myOutput("newData.txt", ios::app);

    if(myInput.fail()){
        cerr << "Error opening input file" << endl;
        return -1;
    }

    if(!myOutput.is_open()){
        cerr << "Error opening output file" << endl;
        return -1;
    }

    myOutput << "lots of data here" << endl;

    float num, sum = 0, count = 0;
    while(!myInput.eof()){
        myInput >> num;
        sum += num;
        myOutput << "Sum so far: " << sum << endl;
        count++;
    }
    
    myOutput << "Total sum: " << sum << endl;
    cout << "Total sum: " << sum << endl;
    cout << fixed << setprecision(2) << "Average term: " << (double)sum / count << endl;

    // fixed sets to standard decimal notation
    // setprecision sets the number of decimal places
    // both apply to all couts going forward

    int x, y;
    while(true){

        cout << "x and y =? ";
        cin >> x >> y;
        if( !cin.fail() ) break;

        cerr << "error encountered from read" << endl;
        cin.clear();

        char badChar;
        do{ badChar = cin.get(); } while( badChar != '\n');
        cout << "Please enter 2 integers" << endl;
    }
    return 0;
}
