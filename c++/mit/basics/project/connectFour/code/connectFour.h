#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

enum Piece
{
    X = 'X',
    O = 'O'
};

class Board
{
private:
    map<int, string> moveLog;
    char pieces[6][7] = {X, O};
    int moveNumber = 0;

public:
    char *getPieces()
    {
        return *pieces;
    }
    void recordMove(string name, int x, int y)
    {
        moveLog[++moveNumber] = name + ": " + to_string(x) + ", " + to_string(y);
    }
    void printMoveHistory()
    {
        for_each(moveLog.begin(), moveLog.end(), [](pair<int, string> currentMove)
                 { cout << currentMove.first << " " << currentMove.second << '\n'; });
    }
};

class Player
{
private:
    string name;
    Piece piece;
    Board gameBoard;

public:
    Player(string name, Piece piece, Board gameBoard)
    {
        this->name = name;
        this->piece = piece;
        this->gameBoard = gameBoard;
    }
    Player(string name, Piece piece)
    {
        this->name = name;
        this->piece = piece;
    }
    Player(string name, Board gameBoard)
    {
        this->name = name;
        this->gameBoard = gameBoard;
    }
    void setName(const string &inputName)
    {
        name = inputName;
    }
    string getName()
    {
        return name;
    }
    void pickPiece(const Piece &p)
    {
        piece = p;
    }
    void setBoard(Board &board)
    {
        gameBoard = board;
    }
    void movePiece(const int x, const int y)
    {
        gameBoard.getPieces()[7 * x + y] = piece;
    }
    Piece getPiece()
    {
        return piece;
    }
};
