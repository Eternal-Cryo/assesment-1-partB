
#include <iostream>
#include <string>
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





int main()
{
	//the array that is being used 
	int bubble_array[] = { 67, 13, 3, 89, 43, 2, 19, 71, 5, 61, 97, 7, 37, 31, 17, 11, 83, 53, 23, 29 };

	//the array length
	int	array_length = 20;
	//controlling the iterations of the loop
	int i = 0;
	//to repeat the loop and reduce the amount of times it runs 
	//automaticly set to true
	bool swapped;



	// reading out the original array before it is sorted
	cout << "pre sorted array " << endl;
	for (int i = 0; i < array_length; i++)
	{
		cout << bubble_array[i] << " ";

	}
	cout << endl;




	// where the loop starts 
	do
	{
		//stays  at false if the array is sorted breaking the loop
		swapped = false;

		// runs for the length of the array -1 since index starts at 0
		//                                  the -i is to shorten the looping because each set of the loop 
		//                                    means the next biggest number reached the correct spot so it doesnt need to check that spot 
		for (int s = 0; s < array_length - 1 - i; s++)
		{
			//cout << i << endl;


			//if the number on the right is larger than the left 
			if (bubble_array[s] > bubble_array[s + 1])
			{


				// setting the temp as bubble array s
				int temp_num = bubble_array[s];
				//setting array s as array s +1
				bubble_array[s] = bubble_array[s + 1];
				//then setting s + 1 as the temps number which was array s original number
				bubble_array[s + 1] = temp_num;
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



	// reading out the last changed array
	cout << " sorted array " << endl;

	for (int i = 0; i < array_length; i++)
	{
			cout << bubble_array[i] << " ";

	}
	cout << endl;












}

