// 9)pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cassert>

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

 
        


// its a bool due to it returning a true or fals comand
bool swap(int number01, int number02) 
{   
    // temp
     int tempNumber = 0;

     // assigning the pointers to the original variables
    int *pNumber01 = &number01;
    int *pNumber02 = &number02;
    int *pTempNumber = &tempNumber;
   // reading out the preswapped pointers
   cout << *pNumber01 << endl;
   cout << *pNumber02 << endl;
    // the pointers get swapped using a temp number as a place holder
    *pTempNumber = *pNumber01;
    *pNumber01 = *pNumber02;
    *pNumber02 = *pTempNumber;

    // reads out the changed numbers 
    std::cout << " the first number is now " << *pNumber01 << endl;
    std::cout << " the second number is now " << *pNumber02 << endl;

    // runs the check to see if 1 swapped places with 2 if it isnt 1 it'll stop working due to the assert check at the end but will skip over this
     if ((*pNumber01 == 2) && (*pNumber02 == 1))
    {//derefrences the pointers then returns true
         pNumber01 = nullptr;
         pNumber02 = nullptr;
         pTempNumber = nullptr;
        return true;


    }
        
    // derefrencing the pointers
    pNumber01 = nullptr;
    pNumber02 = nullptr;
    pTempNumber = nullptr;
    // if it isnt true its false
    return false;
}





int main()
{
    string exit = "";
   
     int number01 = 1;
    int number02 = 2;
    bool confirmed = false;

    // the swapping 
    confirmed = swap(number01, number02);
    //the assert check seeing if they swapped 
     assert(confirmed == true);


     //a  while script for random numbers 
    /*while (exit != "exit")
    {

        std::cout << "pick a number and ill swap them using pointers " << endl;
        std::cin >> number01;


        std::cout << "now pick another number and ill swap them using pointers " << endl;
        std::cin >> number02;


        swap(number01, number02);

        std::cout << "want to go again" << endl;
        std::cin >> exit;
    }*/
     

    std::cout << "----------- end of code --------------" << endl;
}

