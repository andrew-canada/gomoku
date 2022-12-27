#include <iostream>
#include "connectFour.h"

using namespace std;

int main()
{
    Board board;
    string name1, name2;
    Piece p1;

    cout << "player 1, enter your name: ";
    cin >> name1;
    cout << "choose your piece (X or O): ";
    // scanf("%d", &p1);
    p1 = X;
    Player player1(name1, p1, board);

    cout << "player 2, enter your name: ";
    cin >> name2;
    cin >> name2;

    Player player2(name2, board);
    if (p1 == X)
    {
        player2.pickPiece(O);
    }
    else
    {
        player2.pickPiece(X);
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << "_"
                 << "|";
        }
        cout << "_" << '\n';
    }

    printf(board.getPieces());
    board.printMoveHistory();
}