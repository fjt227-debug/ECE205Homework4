#include <iostream>
using namespace std;
//Function prototypes
void inputScores(double scores[], int size);
double inputDifficulty();
double findMax(double scores[], int size);
double findMin(double scores[], int size);
double calculateScore(double scores[], int size, double difficulty);
void outputScore(double finalScore);

int main() {
	const int size = 7; //Declare constant for number of judges and array to hold scores
	double scores[size];
	double difficulty;
	double finalScore;

	inputScores(scores, size); //Get judges scores from user
	difficulty = inputDifficulty(); //Get degree of difficulty from user
	finalScore = calculateScore(scores, size, difficulty); //Calculate and display final score
	outputScore(finalScore);
	return 0;
}

//Filles scores array with valid nubmers between 0 and 10
void inputScores(double scores[], int size)
{
	for (int i = 0; i < size; i++)
	{
		//do while loop forces input to be within valid range
		do
		{
			cout << "Judge "  << i + 1 << " score" << " (0-10): ";
			cin >> scores[i];
			if (scores[i] < 0 || scores[i] > 10)
				cout << "Invalid score" << endl;
		} while (scores[i] < 0 || scores[i] > 10);
	}
}
//Gets valid degree of difficulty between 1.2 and 3.8
double inputDifficulty()
{
	double difficulty;
	//do while loop forces input to be within valid range
	do
	{
		cout << "Enter degree of difficulty (1.2-3.8): ";
		cin >> difficulty;
		if (difficulty < 1.2 || difficulty > 3.8)
			cout << "Invalid difficulty" << endl;
	} while (difficulty < 1.2 || difficulty > 3.8);

	return difficulty;
}

//Returns the highest score in the array
double findMax(double scores[], int size)
{
	double max = scores[0];
	for (int i = 1; i < size; i++)
	{
		if (scores[i] > max)
			max = scores[i];
	}
	return max;
}

//Returns the lowest score in the array
double findMin(double scores[], int size)
{
	double min = scores[0];
	for (int i = 1; i < size; i++)
	{
		if (scores[i] < min)
			min = scores[i];
	}
	return min;
}

//Drops highest and lowest, sums, multiplies by difficulty and 0.6
double calculateScore(double scores[], int size, double difficulty)
{
	double max = findMax(scores, size);
	double min = findMin(scores, size);
	double sum = 0;
	//Sum all scores then subtract the highest and lowest
	for (int i = 0; i < size; i++)
		sum += scores[i];
	sum = sum - max - min;
	//Multiply by difficulty and 0.6 to get final score
	return sum * difficulty * 0.6;
}

//Displays the final diver score
void outputScore(double finalScore)
{
	cout << "Diver's final score: " << finalScore << endl;
}
