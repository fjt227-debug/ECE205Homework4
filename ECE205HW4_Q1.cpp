#include <iostream>
using namespace std;

//Function prototypes
void input(int myArray[], int size);
void output(int histogram[], int size);
void calculate_histogram(int myArray[], int histogram[], int size);

int main() {
	//Declare array size and histogram size
	const int size = 20;
	const int histsize = 10;
	int myArray[size];
	int histogram[histsize] = { 0 }; //Initialize all bins to 0
	int size_n; //Get size from the user
	cout << "Please enter the size of the array " << endl;
	cin >> size_n;

	input(myArray, size_n); //Fill array with user size
	calculate_histogram(myArray, histogram, size_n); //Calculate histogram bins from array
	output(histogram, histsize); //Display histogram results

	return 0;
}
//Fills myArray with size integers enterted by the user
void input(int myArray[], int size)
{
	//fill in user array with scores
	cout << "PLease enter " << size << " non negative integers" << endl;
		for (int i = 0; i < size; i++)
			cin >> myArray[i]; //Stores each value into array
}
//Counts how many values fall into each bin of size 10
void calculate_histogram(int myArray[], int histogram[], int size)
{
	for (int i = 0; i < size; i++)
		histogram[myArray[i] / 10]++; //Dividing by 10 gives the bin index
}
//Pints each bin and the number of values that fall into it
void output(int histogram[], int histSize)
{
	for (int i = 0; i < histSize; i++)
	{
		//Print bin number range and count
		cout << "Bin " << i + 1 << ": " << i * 10 << "-" << (i * 10 + 9) << ": " << histogram[i] << endl;
	}
}
