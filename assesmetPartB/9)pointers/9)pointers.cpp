// 9)pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;





//You will write a function to swap the value of two integers.You will do this by passing pointers to those integers into the function and performing the swap through pointer manipulation.Your function will not return any values.
//Do NOT use std::swap.
//Commit this to version control.
//Add an int main().Initialise two integers to different values.Use your function to swap them in place.Add an assert()to confirm the values have been swapped.
//Ensure all asserts() pass when you build and run.
//Test and commit this to version control.
//
//
//

int main()
{
    string exit = "";
    int number01 = 0;
    int number02 = 0;
    int tempnumber = 0;


    int *pnumber01 = &number01;
    int *pnumber02 = &number02;
    int *ptempnumber = &tempnumber;



    
    cout << "pick a number and ill swap them using pointers " << endl;
    cin >> number01;
    cout << *pnumber01 << endl;

    cout << "now pick another number and ill swap them using pointers " << endl;
    cin >> number02;
    cout << *pnumber02 << endl;

    *ptempnumber = *pnumber01;
    *pnumber01 = *pnumber02;
    *pnumber02 = *ptempnumber;



    cout << " the first number is now " << *pnumber01 << endl;

    cout << " the second number is now " << *pnumber02 << endl;



    cout << "----------- end of code --------------" << endl;
}

