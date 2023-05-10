#include "board.h"
#include <vector>
#include <iostream>
using namespace std;




        // let's loop through array to populate board
board::board(){
  for(int i = 0;i<8;i++){
    vector<square> row;
    for(int j=0;j<8;j++){
      square sq;
      sq.color=((i+j)%2);
      row.push_back(sq);
    }
    chessboard.push_back(row);
  }
}
void board::displayBoard(){
  for (int i = 0; i < chessboard.size(); i++)
  {
    for (int j = 0; j < chessboard[i].size(); j++)
    {
      cout << chessboard[i][j].color;
    }
    cout << endl;
  }
}

void board::setpieces(){
  // Setting up black pieces on the 1st and 2nd row
  for (int col = 0; col < 8; col++) {
    pieceCreate p;
    p.setColor(0);
    p.setXPos(1);
    p.setYPos(col);
    p.setVal(1);
    p.setIdentifier("♙");
    chessboard[1][col].p = p;
    switch(col) {
      case 0:
      case 7:
        p.setVal(5);
        p.setIdentifier("♖");
        break;
      case 1:
      case 6:
        p.setVal(3);
        p.setIdentifier("♘");
        break;
      case 2:
      case 5:
        p.setVal(4);
         p.setIdentifier("♗");
        break;
      case 3:
        p.setVal(9);
         p.setIdentifier("♕");
        break;
      case 4:
        p.setVal(10);
         p.setIdentifier("♔");
        break;
    }
    chessboard[0][col].p = p;
  }
  // Setting up white pieces on the 6th and 7th row
  for (int col = 0; col < 8; col++) {
    pieceCreate p;
    p.setColor(1);
    p.setXPos(6);
    p.setYPos(col);
    p.setVal(1);
    p.setIdentifier("♟");
    chessboard[6][col].p = p;
    switch(col) {//♙♘♗♖♕♔♚♛♜♝♞♟ 
      case 0:
      case 7:
        p.setVal(5);
         p.setIdentifier("♜");
        break;
      case 1:
      case 6:
        p.setVal(3);
         p.setIdentifier("♞");
        break;
      case 2:
      case 5:
        p.setVal(4);
         p.setIdentifier("♝");
        break;
      case 3:
        p.setVal(9);
         p.setIdentifier("♛");
        break;
      case 4:
        p.setVal(10);
         p.setIdentifier("♚");
        break;
    }
    chessboard[7][col].p = p;
  }
}
// piece board::getPiece(){
  void board::displayPieceBoard(){
   for(char ch='a'; ch<='h'; ch++){cout<<ch<<" ";}
    cout<<endl<<endl;
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
       if (chessboard[i][j].p.getVal() >100 ) {
        cout << "□ ";
      } else {
         cout<<chessboard[i][j].p.getIdentifier()<<" ";
      }
    }
    cout <<"  " <<8-i<<"\n";
  }
}
// }
// bool board::canMove(pieceCreate p){
  
// }
void board::move(int oldx, char oldy, int newx, char newy) {
  int val;
  int val2;
  switch (oldy){
    case 'a':
      val=0;
      break;
    case 'b':
      val=1;
      break;
    case 'c':
      val=2;
      break;
    case 'd':
      val=3;
      break;
    case 'e':
      val=4;
      break;
    case 'f':
      val=5;
      break;
    case 'g':
      val=6;
      break;
    case 'h':
      val=7;
      break;
    
  }
    switch (newy){
    case 'a':
      val2=0;
      break;
    case 'b':
      val2=1;
      break;
    case 'c':
      val2=2;
      break;
    case 'd':
      val2=3;
      break;
    case 'e':
      val2=4;
      break;
    case 'f':
      val2=5;
      break;
    case 'g':
      val2=6;
      break;
    case 'h':
      val2=7;
      break;
    
  }
  pieceCreate temp = chessboard[8-oldx][val].p;
  //add if else later if a piece moves onto another piece and different color then it is added to dead piece vector
  chessboard[8-oldx][val].p.setVal(0);
  chessboard[8-oldx][val].p.setIdentifier("□");
  chessboard[8-newx][val2].p = temp;
  // chessboard[8-newx][val2].p.setXPos(newx);
  // chessboard[8-newx][val2].p.setYPos(val2);
}


// bool board::canMove(pieceCreate p,int oldx, char oldy, int newx, char newy){
//   int id = p.getVal();
//   if(id==1){
//     if(oldx==2||7){
//       if(newx==(oldx+1) || newx==(oldx+2))
//     }
//   }
//   else if(id==3){
    
//   }
//   else if (id==4){
    
//   }
//   else if(id==5){
    
//   }
//   else if(id==9){
    
//   }
//   else if(id==10){
    
//   }
// }

//♙♘♗♖♕♔♚♛♜♝♞♟ 