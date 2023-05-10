#include <vector>
#include "../Piece/pieceCreate.h"
using namespace std;

#ifndef BOARD
#define BOARD


class board{
private:
struct square{
int color; //0 = black and 1 = white
pieceCreate p;
};
vector<vector<square>> chessboard;
vector<pieceCreate> alive;
vector<pieceCreate> dead;
public:
board();
void displayBoard();
void move(int a, char b, int c, char d);
void setpieces();
void displayPieceBoard();
bool canMove(pieceCreate p,int oldx, char oldy, int newx, char newy);


};

#endif