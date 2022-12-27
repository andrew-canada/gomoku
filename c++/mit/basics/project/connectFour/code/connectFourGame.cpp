#include <iostream>
#include <cctype>
#include "connectFour.h"

using namespace std;

void initBoard(char board[][8]);
bool isWin(char board[][8], int x, int y);
void printBoard(char board[][8]);

int main()
{
    int totalMoves = 0;
    int xCoord, yCoord;
    string name1, name2;
    Piece p1;
    char piece;
    char endOrContinue;

    char board[7][8];
    initBoard(board);

    cout << "player 1, enter your name: ";
    cin >> name1;
    cout << "choose your piece (X or O): ";
    cin >> piece;
    p1 = (piece == X) ? X : O;
    Player player1(name1, p1);

    cout << "player 2, enter your name: ";
    cin >> name2;
    Piece p2 = (p1 == X) ? O : X;
    Player player2(name2, p2);

    do
    {
        totalMoves += 1;
        printBoard(board);
        if (totalMoves % 2 != 0)
        {
            cout << player1.getName() << ", enter your move (x y): ";
            cin >> xCoord >> yCoord;
            board[xCoord][yCoord] = player1.getPiece();
        }
        else
        {
            cout << player2.getName() << ", enter your move (x y): ";
            cin >> xCoord >> yCoord;
            board[xCoord][yCoord] = player2.getPiece();
        }

        if (isWin(board, xCoord, yCoord) || totalMoves == 42)
        {
            printBoard(board);

            if (totalMoves > 10)
            {
                cout << "Game over, tied game! \n New Game? (Y/N): ";
            }
            else if (totalMoves % 2 != 0)
            {
                cout << player1.getName() << " Won! \n New Game? (Y/N): ";
            }
            else
            {
                cout << player2.getName() << " Won! \n New Game? (Y/N): ";
            }
            cin >> endOrContinue;
            initBoard(board);
        }
    } while (toupper(endOrContinue) != 'N');
}

void initBoard(char board[][8])
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (i == 0 && j != 0)
            {
                board[i][j] = char(49 + j - 1);
            }
            else if (j == 0 && i != 0)
            {
                board[i][j] = char(49 + i - 1);
            }
            else
            {
                board[i][j] = ' ';
            }
        }
    }
}

void printBoard(char board[][8])
{
    system("clear");
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
}

bool isWin(char board[][8], int x, int y)
{
    int numAdj = 0;
    bool isEnterDirection1 = true;
    bool isEnterDirection2 = true;

    // horizontal
    for (int i = 1; i <= 3; i++)
    {
        // 1 left
        if (board[x][y - i] == board[x][y] && isEnterDirection1 == true)
        {
            numAdj += 1;
        }
        else
        {
            isEnterDirection1 = false;
        }
        // 1 right
        if (board[x][y + i] == board[x][y] && isEnterDirection2 == true)
        {
            numAdj += 1;
        }
        else
        {
            isEnterDirection2 = false;
        }
    }
    if (numAdj >= 3)
    {
        return true;
    }

    numAdj = 0;
    isEnterDirection1 = true;
    isEnterDirection2 = true;
    // vertical
    for (int i = 1; i <= 3; i++)
    {
        // 1 left
        if (board[x - i][y] == board[x][y] && isEnterDirection1 == true)
        {
            numAdj += 1;
        }
        else
        {
            isEnterDirection1 = false;
        }
        // 1 right
        if (board[x + i][y] == board[x][y] && isEnterDirection2 == true)
        {
            numAdj += 1;
        }
        else
        {
            isEnterDirection2 = false;
        }
    }
    if (numAdj >= 3)
    {
        return true;
    }

    numAdj = 0;
    isEnterDirection1 = true;
    isEnterDirection2 = true;
    // diagonal increasing
    for (int i = 1; i <= 3; i++)
    {
        // 1 lowerleft
        if (board[x - i][y - i] == board[x][y] && isEnterDirection1 == true && x > 1 && y > 1)
        {
            numAdj += 1;
        }
        else
        {
            isEnterDirection1 = false;
        }
        // 1 upperright
        if (board[x + i][y + i] == board[x][y] && isEnterDirection2 == true && x < 7 && y < 7)
        {
            numAdj += 1;
        }
        else
        {
            isEnterDirection2 = false;
        }
    }
    if (numAdj >= 3)
    {
        return true;
    }

    numAdj = 0;
    isEnterDirection1 = true;
    isEnterDirection2 = true;
    // diagonal decreasing
    for (int i = 1; i <= 3; i++)
    {
        // 1 upperleft
        if (board[x - i][y + i] == board[x][y] && isEnterDirection1 == true && x > 1 && y < 7)
        {
            numAdj += 1;
        }
        else
        {
            isEnterDirection1 = false;
        }
        // 1 lowerright
        if (board[x + i][y - i] == board[x][y] && isEnterDirection2 == true && x < 7 && y < 1)
        {
            numAdj += 1;
        }
        else
        {
            isEnterDirection2 = false;
        }
    }
    return (numAdj >= 3) ? true : false;
}
