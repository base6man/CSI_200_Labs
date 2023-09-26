/* CSCI 200: Lab 2B: Pointers: Addresses & Values
 *
 * Author: Keaton Mitchell
 *
 * Learned how to use pointers
 */

#include <iostream>
using namespace std;

int main(){
    int iNum = 4, iNum2 = 5;
    int* pINum1 = nullptr; 
    int* pINum2 = nullptr;

    pINum1 = &iNum;
    pINum2 = &iNum2;

    cout << &iNum << endl << pINum1 << endl;
    cout << &iNum2 << endl << pINum2 << endl;
    cout << *pINum1 << endl;
    cout << *pINum2 << endl;

    iNum = 6;
    cout << iNum << endl;
    cout << *pINum1 << endl;

    *pINum1 = 7;
    cout << iNum << endl;

    pINum2 = pINum1;
    cout << pINum2 << endl << *pINum2 << endl;
    *pINum2 = 8;
    cout << *pINum1 << endl << *pINum2 << endl << iNum << endl;
    cout << iNum2;

    double* pDNum = nullptr;
    //pDNum = &iNum; ERROR: cannot convert 'int*' to 'double*'
    //pDNum = pINum1; ERROR: cannot convert 'int*' to 'double*'
    double dNum = 14.25;
    pDNum = &dNum;
    cout << pDNum << endl << *pDNum << endl;
    *pINum1 = *pDNum;
    cout << dNum << endl << *pDNum;
 
    return 0;
}