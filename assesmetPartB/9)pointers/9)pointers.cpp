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
    int tempNumber = 0;


    int *pNumber01 = &number01;
    int *pNumber02 = &number02;
    int *pTempNumber = &tempNumber;



    
    cout << "pick a number and ill swap them using pointers " << endl;
    cin >> number01;
    cout << *pNumber01 << endl;

    cout << "now pick another number and ill swap them using pointers " << endl;
    cin >> number02;
    cout << *pNumber02 << endl;

    *pTempNumber = *pNumber01;
    *pNumber01 = *pNumber02;
    *pNumber02 = *pTempNumber;



    cout << " the first number is now " << *pNumber01 << endl;

    cout << " the second number is now " << *pNumber02 << endl;



    cout << "----------- end of code --------------" << endl;
}

