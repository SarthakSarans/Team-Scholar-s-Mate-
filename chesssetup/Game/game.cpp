#include "game.h"
#include <iostream>
using namespace std;

#define CLEAR "\u001b[2J" 
//std::cout << "\u001b[2J"; CLEAR CONSOLE
game::game(){
  int gameCounter=0;
   board *b = new board();
     b->setpieces();

      b->displayPieceBoard();
  while(flag==false){
    gameCounter++;
    cout<<"\n It is move: "<<gameCounter;
    cout<<"\nWhite, chose your new and old coordinates!";
    int x,z;
    char w,y;
    cin>>w>>x>>y>>z;
    b->move(x, w, z, y);
    std::cout<< CLEAR;
     b->displayPieceBoard();
     cout<<"\nBlack, chose your new and old coordinates!";
     cin>>w>>x>>y>>z;
    b->move(x, w, z, y);
      b->displayPieceBoard();
  }
  std::cout<<"Game Over!";
}