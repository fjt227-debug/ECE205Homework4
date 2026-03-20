#include <iostream>
using namespace std;

void printBoard(char board[3][3]);
bool checkWin(char board[3][3], char player);

int main()
{
    //Declare variables
    int position;
    char currentplayer = 'X';
    int row;
    int col;
    bool gameOver = false;
    int moves = 0;
    //STEP 1: print the board
    char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
    //Step 2: take the input, calculate position, check the validility
    while (!gameOver)
    {
        //Print the board
        printBoard(board);

        //Input
        cout << "Player " << currentplayer << ", enter position 1 through 9: ";
        cin >> position;

        //Check if position has a valid range
        if (position < 1 || position > 9)
        {
            cout << "Invald position" << endl;
            continue;
        }

        //Convert position to row and column
        row = (position - 1) / 3;
        col = (position - 1) % 3;
        
        //Check if poisition is already taken
        if (board[row][col] == 'X' || board[row][col] == 'O')
        {
            cout << "Position already taken" << endl;
            continue;
        }

        //Step 3: Update the board
        board[row][col] = currentplayer;
        moves++;

        //Step 4: Check the win-draw-game over
        if (checkWin(board, currentplayer))
        {
            printBoard(board);
            cout << "Player " << currentplayer << " wins" << endl;
            gameOver = true;
        }
        //Check for draw
        else if (moves == 9)
        {
            printBoard(board);
            cout << "Draw" << endl;
            gameOver = true;
        }
        else
        {
            //switch players 
            currentplayer = (currentplayer == 'X') ? 'O' : 'X';
        }
   
    }
    return 0;
}

void printBoard(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << '\t';
        }
        cout << endl;
    }
}

bool checkWin(char board[3][3], char player)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true; //Check rows
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true; //Check columns
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true; //Check diagonal
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true; //Check anti-diagonal 
    return false;
}
