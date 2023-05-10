#include <string>
using namespace std;
#ifndef PIECE
#define PIECE


class pieceCreate{//♙♘♗♖♕♔♚♛♜♝♞♟ 
private:
  string identifier;
  int val;
  int xpos;
  int ypos;
  bool alive;
  bool color;

public:

pieceCreate(){
  identifier="Square";
}

string getIdentifier(){
  return identifier;
}

int getVal(){
  return val;
}

int getXPos(){
  return xpos;
}

int getYPos(){
  return ypos;
}

int getAlive(){
  return alive;
}

int getColor(){
  return color;
}

void setIdentifier(string id){
  identifier=id;
}
void setXPos(int id){
    xpos=id;
}
void setYPos(int id){
    ypos=id;
}
void setVal(int id){
    val=id;
}
void setColor(bool id){
    color=id;
}
void setAlive(bool id){
    alive=id;
}


};
#endif