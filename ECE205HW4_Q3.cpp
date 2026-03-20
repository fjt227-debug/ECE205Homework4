#include <iostream>
using namespace std;

//Functions
void initializeSeatMap(char seatMap[][4], int rows);
void displaySeatMap(char seatMap[][4], int rows);
void assignSeat(char seatMap[][4], int rows, int& seatstaken, bool& plane_full);

int main() 
{
	//Step-1:intialize seart map that is two dimensional as a character
	int userRow; //1-10
	char userSeat; //A,B,C,D
	char seatMap[10][4]; //A,B,C,D ---col // row --1-10
	char response;
	bool plane_full = false;
	int seatstaken = 0;

	//Step-1:intialize seart map that is two dimensional as a character
	initializeSeatMap(seatMap, 10);

	//Step-2: Ask the user to give the seat input intill seats are 40, the plane is full or the user wants to give another response
	do
	{
		//Display current seat map
		displaySeatMap(seatMap, 10);
		//Assign a seat based on user input
		assignSeat(seatMap, 10, seatstaken, plane_full);
		//Check if plane is full (10 rows x 4 seats = 40)
		if (seatstaken == 40)
		{
			cout << "The plane is full" << endl;
			plane_full = true;
		}
		//Ask if user wants to continue
		if (!plane_full)
		{
			cout << "Would you like to add another seat? (y/n): ";
			cin >> response;
		}
	} while ((response == 'y' || response == 'Y') && !plane_full);
	// Display final seat map
	return 0;
}

void initializeSeatMap(char seatMap[][4], int rows) //Initializes every seat in the map to A, B, C, or D
{
	for (int i = 0; i < 10; i++)
	{
		seatMap[i][0] = 'A'; //Column 0 = Seat A
		seatMap[i][1] = 'B'; //Column 1 = Seat B
		seatMap[i][2] = 'C'; //Column 2 = Seat C
		seatMap[i][3] = 'D'; //Column 3 = Seat D
	}
}

void displaySeatMap(char seatMap[][4], int rows) //Display the current states of the seat map row by row
{
	cout << "Seat Map : " << endl;
	for (int i = 0; i < rows; i++)
	{
		cout << i + 1 << '\t'; //print row number
		for (int j = 0; j < 4; j++)
		{
			cout << seatMap[i][j] << ' '; //Prints each seat in the row
		}
		cout << endl;
	}
}

void assignSeat(char seatMap[][4], int rows, int& seatstaken, bool& plane_full) //Asks user for a seat and marks it as taken
{
	int userRow;
	char userSeat;

	do
	{
		cout << "Enter row (1-10) and seat (A-D): ";
		cin >> userRow >> userSeat;
		//Coverts lowercase to uppercase by subtracting 32
		if (userSeat >= 'a' && userSeat <= 'd')
			userSeat = userSeat - 32;
		//Checks if row or seat is out of range
		if (userRow < 1 || userRow > 10 || userSeat < 'A' || userSeat > 'D')
			cout << "Invalid input" << endl;
		//Checks if seat is already taken
		else if (seatMap[userRow - 1][userSeat - 65] == 'X')
			cout << "This seat is already taken" << endl;
	} while (userRow < 1 || userRow>10 || userSeat < 'A' || userSeat > 'D' || seatMap[userRow - 1][userSeat - 65] == 'X');
		//Mark that the seat is taken with the letter X
		seatMap[userRow - 1][userSeat - 65] = 'X';
		seatstaken++; 
		cout << "Seat " << userRow << userSeat << " has been assigned" << endl;
}

