#include <iostream>
#include <string>
using namespace std;


//You will write a function that performs a linear search through an integer array by passing the target value, and the array, as function arguments.The function will return the index where the target is found, otherwise it will return -1.
//Commit this to version control.
//
//Add an int main() function.Initialise this array
//
//67, 13, 3, 89, 43, 2, 19, 71, 5, 61, 97, 7, 37, 31, 17, 11, 83, 53, 23, 29
//
//Add four asserts to check your function works.
//3 should return 2
//7 should return 11
//67 should return 0
//88 should return -1
//Ensure all asserts() pass when you build and run.
//Test and commit this to version control.
//Write a loop that asks the user for a value and then calls your function to search for that value in the following array :
///////////////////////////////////////////////////////////////////////////////////////////////////


// a function that allows me search any array that is given
int search(int array[], int array_size, int search_value)
{

	//a loop to search through the array for each index value 
	for (int i = 0; i < array_size; i++)
	{
		//cout << array[i] << endl;
		//asking the index if the search value and and number at the index is the same 
		if (search_value == array[i])
		{
			//return the index value 
			return i;


		}

	}
	// if it isnt on the list it gives a -1 
	return -1;

};




int main()
{
	//storing the grabbed a word for the while loop
	string exit = "";

	//storing the grabbed a number from the player to search through the array for 
	int user_number = 0;

	//the array we are searching through 
	int search_array[] = { 67, 13, 3, 89, 43, 2, 19, 71, 5, 61, 97, 7, 37, 31, 17, 11, 83, 53, 23, 29 };


	//simple while loop to continue the search or to exit the program
	while (exit != "exit")
	{





		//asking and grabbing the number from the player: note it doesn't like letters or punctuation
		cout << "please enter a number to search the array" << endl;
		cin >> user_number;




		//finding the index//  imputting the variable for the search
		//   |						\/	then the user value
		//  \/                                   \/
		int result = search(search_array, 20, user_number);

		// reading out the index value or a -1 if not in the array
		cout << result << endl;

		// checking if its in the array 
		if (result >= 0) {
			// if it is then say the number                                 then the index it was found at
			//        \/													\/
			cout << user_number << " number was found at index number " << result << endl;
		}
		else
		{	//if its a negative print that it couldnt be found
			cout << user_number << " could not be found" << endl;

		}


		//doesnt care what is typed unless it is exit
		cout << "go again or exit" << endl;
		cin >> exit;
	}

	//end of code stuff
	cout << "thanks for playing!" << endl;
	cout << "---------- end of code ----------" << endl;
}


//infomation on linear search 
//https://www.geeksforgeeks.org/dsa/linear-search/
//https://www.youtube.com/watch?v=FYX_yG-9CxE&t=551s 
