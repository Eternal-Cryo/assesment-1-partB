
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

//Bubble Sort
//
//Using the tutorials you will write a function that performs an ‘in - place’ bubble sort by passing an array of integers to it.Sort in ascending order(smallest to largest).You do not need to return any values from the function.
//You may NOT use any built - in sorting algorithms.
//Commit this to version control.
//Add an int main().Initialize this array and use your function to sort it.
//
//67, 13, 3, 89, 43, 2, 19, 71, 5, 61, 97, 7, 37, 31, 17, 11, 83, 53, 23, 29
//
//Write code that loops through PAIRS of values in the sorted array and asserts() that the first value of the pair is always less than the second value of the pair.This will confirm your bubble sort works.
//Ensure all asserts() pass when you build and run.
//Test and commit this to version control.
/////////////////////////////////////////////////////////////////////////////////////////

//Binary Search
//
//USE THE SAME BUBBLE SORT PROJECT(#7) FOR THIS TASK ONCE THE SORT IS WORKING
//You will implement a function that searches a sorted array for a given value.Pass the target value and the array to your function and return the index where the value was found if it exists in the array.If it is not in the array return -1.
//You must implement binary search for this exercise.Do NOT implement linear search.Do NOT use any built - in library functions.
//Call your function from int main() after the bubble sort asserts() using the sorted array.
//Add the following asserts() to your main function to check your binary search works.
//(Your sorted array should look like this 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 43, 53, 61, 67, 71, 83, 89, 97)
//11 = 4
//23 = 8
//97 = 19
//88 = -1
//Enure all asserts() pass when you build and run.
//Commit this to version control.
//Write a loop that asks the user for a value and then calls your function to search for that value in the sorted array.
//If your function finds the value, tell the user at which index it found it, otherwise tell them the value was not in the array.
//Test and commit this to version control.
//		

void bubbleSort(int array[], int arrayLength)
{
	int i = 0;
	//automaticly set to true
	bool swapped;
	// where the loop starts 
	do
	{
		//stays  at false if the array is sorted breaking the loop
		swapped = false;

		// runs for the length of the array -1 since index starts at 0
		//                                  the -i is to shorten the looping because each set of the loop 
		//                                    means the next biggest number reached the correct spot so it doesnt need to check that spot 
		for (int s = 0; s < arrayLength - 1 - i; s++)
		{
			//cout << i << endl;


			//if the number on the right is larger than the left 
			if (array[s] > array[s + 1])
			{


				// setting the temp as bubble array s
				int temp_num = array[s];
				//setting array s as array s +1
				array[s] = array[s + 1];
				//then setting s + 1 as the temps number which was array s original number
				array[s + 1] = temp_num;
				//to keep the loop going due to a number being swapped
				swapped = true;


			}


			////uncomenting this reads out the loop and shows every change made even iff nothing happened  
			/*for (int j = 0; j < array_length; j++)
			{
				cout << bubble_array[j] << " ";

			}
			cout << endl;*/

			//decreases the amount of loops that it goes through by 1 each time
		} i++;





		// uncomenting this one will read out the overall changes in each itteration 
		/*for (int i = 0; i < array_length; i++)
		{
			cout << bubble_array[i] << " ";

		}
		cout << endl;*/



		// to repeat the loop if something was swapped
	} while (swapped);

	return;
}

bool assertCheck(int array[], int arraylength)
{
	for (int i = 1 ; i < arraylength; i++)
	{	
		int a = array[i];
		int b = array[i - 1];
		assert(a > b);
	}


	return true;
}




// a function to call binary search with the variables provided 
int binary_search(int array[], int array_size, int user_number)
{
	//the lowest index int the array
	int low_point = 0;
	// highest index in the array
	int high_point = (array_size - 1);
	
	// rough middle of the array
	int mid_point = 0;



	// while its less than the high point 
	while (low_point <= high_point)
	{
		// the mid point moves with the changing of the variables and since its an int it automaticly rounds 
		mid_point = (low_point + high_point) / 2;


		//if the number is in the array is the one being searched for
		if (user_number == array[mid_point])
		{// return the index


			std::cout << mid_point << endl;
			std::cout << "the number " << user_number << " is in the array at index value " << mid_point << endl;
			return mid_point;

		}
		// if the search number is less than the number at the mid point
		else if (user_number > array[mid_point])
		{
			low_point = mid_point + 1;

		}
		// if the search number is more than the number at the mid point
		else if (user_number < array[mid_point])
		{

			high_point = mid_point - 1;

		}
		// after each set it halves the search area
	}

	//if it runs out of numbers to look through



	std::cout << "-1" << endl;
	std::cout << user_number << " the number isnt in the array"  << endl;
	return -1;


	




}












int main()
{
	//the array that is being used 
	int bubble_array[] = { 67, 13, 3, 89, 43, 2, 19, 71, 5, 61, 97, 7, 37, 31, 17, 11, 83, 53, 23, 29 };

	//the array length
	int	array_length = 20;
	//controlling the iterations of the loop
	int i = 0;
	//to repeat the loop and reduce the amount of times it runs 
	

	

	// reading out the original array before it is sorted
	std::cout << "pre sorted array " << endl;
	for (int i = 0; i < array_length; i++)
	{
		std::cout << bubble_array[i] << " ";
		

	}
	std::cout << endl;

	bubbleSort(bubble_array, 20);

// reading out the last changed array
	std::cout << " sorted array " << endl;

	for (int i = 0; i < array_length; i++)
	{
		std::cout << bubble_array[i] << " ";

	}
	std::cout << endl << endl;
	
	bool confirmed = 0;
	confirmed = assertCheck(bubble_array, 20);
	assert(confirmed == true);

	



	/////////

	// grabbing the char for the loop
	string user_input = " ";

	//grabbing the number being looked for
	int user_number = 0;
	


	assert(binary_search(bubble_array, 20, 11) == 4);
	assert(binary_search(bubble_array, 20, 23) == 8);
	assert(binary_search(bubble_array, 20, 97) == 19);
	assert(binary_search(bubble_array, 20, 88) == -1);

	 
	 




	//loop for giving multiple numbers 
	while (user_input != "exit")
	{
		//the code to grab the number
		std::cout << "give me a number to find in the array " << endl;
		cin >> user_number;



		//calling apon the function using the infomation from the player and the infomation that we have 
		 binary_search(bubble_array, 20, user_number);

		 

		// to repeate the loop
		 std::cout << "want to go again " << endl;
		cin >> user_input;


	}






	// end of code 
	std::cout << "----------- thanks for playing -----------" << endl;
	std::cout << "--------------end of code------------" << endl;

}

//bubble sort
// https://www.w3schools.com/dsa/dsa_algo_bubblesort.php
//https://www.geeksforgeeks.org/dsa/bubble-sort-algorithm/
//https://www.youtube.com/watch?v=62Ai0p1xUpE

//binarey search 
//https://www.geeksforgeeks.org/dsa/binary-search/ 
//https://www.youtube.com/watch?v=vohuRrwbTT4





//aswell as the infomation provided by aie