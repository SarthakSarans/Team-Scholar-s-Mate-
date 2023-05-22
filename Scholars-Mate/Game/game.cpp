#include "game.h"
#include <iostream>
#include <vector>

using namespace std;

#define CLEAR "\u001b[2J" 
//std::cout << "\u001b[2J"; CLEAR CONSOLE



char convertInt(int i){
if (i == 0){
  return 'a';
}
  else if (i == 1){
    return 'b';
  }
  else if (i == 2){
    return 'c';
  }

  else if (i == 3){
    return 'd';
  }
  else if (i == 4){
    return 'e';
  }
  else if (i == 5){
    return 'f';
  }
  else if (i == 6){
    return 'g';
  }
  else if (i == 7){
    return 'h';
  }
  else{
    return 0;
  }
}



int evaluatePiece(int positionX, int positionY, int id, bool color){
   int pawnVal = 10;
  int knightVal = 30;
  int bishopVal = 30;
  int rookVal = 50;
  int queenVal = 90;
  int kingVal = 900;
int pawn_table[8][8] = {
     0,  0,  0,  0,  0,  0,  0,  0,
    75, 75, 75, 75, 75, 75, 75, 75,
    25, 25, 29, 29, 29, 29, 25, 25,
     4,  8, 12, 21, 21, 12,  8,  4,
     0,  4,  8, 17, 17,  8,  4,  0,
     4, -4, -8,  4,  4, -8, -4,  4,
     4,  8,  8,-17,-17,  8,  8,  4,
     0,  0,  0,  0,  0,  0,  0,  0
};

  int black_pawn_table[8][8] = {
       0,  0,  0,  0,  0,  0,  0,  0,  
     4,  8,  8,-17,-17,  8,  8,  4,
     4, -4, -8,  4,  4, -8, -4,  4,
  0,  4,  8, 17, 17,  8,  4,  0,
     4,  8, 12, 21, 21, 12,  8,  4,
    25, 25, 29, 29, 29, 29, 25, 25,
    75, 75, 75, 75, 75, 75, 75, 75,
    0,  0,  0,  0,  0,  0,  0,  0,
};


  int knight_table[8][8] = {
  -50,-40,-30,-30,-30,-30,-40,-50,
-40,-20,  0,  0,  0,  0,-20,-40,
-30,  0, 10, 15, 15, 10,  0,-30,
-30,  5, 15, 20, 20, 15,  5,-30,
-30,  0, 15, 20, 20, 15,  0,-30,
-30,  5, 10, 15, 15, 10,  5,-30,
-40,-20,  0,  5,  5,  0,-20,-40,
-50,-40,-30,-30,-30,-30,-40,-50,
};

  int black_knight_table[8][8] = {
  -50,-40,-30,-30,-30,-30,-40,-50,
-40,-20,  0,  5,  5,  0,-20,-40,
-30,  5, 10, 15, 15, 10,  5,-30,
-30,  0, 15, 20, 20, 15,  0,-30, 
  -30,  5, 15, 20, 20, 15,  5,-30,
  -30,  0, 10, 15, 15, 10,  0,-30,
  -40,-20,  0,  0,  0,  0,-20,-40,
   -50,-40,-30,-30,-30,-30,-40,-50,
  };
  
    // bishop
int bishop_table[8][8] = {
-20,-10,-10,-10,-10,-10,-10,-20,
-10,  0,  0,  0,  0,  0,  0,-10,
-10,  0,  5, 10, 10,  5,  0,-10,
-10,  5,  5, 10, 10,  5,  5,-10,
-10,  0, 10, 10, 10, 10,  0,-10,
-10, 10, 10, 10, 10, 10, 10,-10,
-10,  5,  0,  0,  0,  0,  5,-10,
-20,-10,-10,-10,-10,-10,-10,-20,
};

  int black_bishop_table[8][8] = {
-20,-10,-10,-10,-10,-10,-10,-20,
-10,  5,  0,  0,  0,  0,  5,-10,
-10, 10, 10, 10, 10, 10, 10,-10, 
-10,  0, 10, 10, 10, 10,  0,-10,
-10,  5,  5, 10, 10,  5,  5,-10,
-10,  0,  5, 10, 10,  5,  0,-10,
-10,  0,  0,  0,  0,  0,  0,-10,
-20,-10,-10,-10,-10,-10,-10,-20
  
  };
  //rook
int rook_table[8][8] = {
  0,  0,  0,  0,  0,  0,  0,  0,
  5, 10, 10, 10, 10, 10, 10,  5,
 -5,  0,  0,  0,  0,  0,  0, -5,
 -5,  0,  0,  0,  0,  0,  0, -5,
 -5,  0,  0,  0,  0,  0,  0, -5,
 -5,  0,  0,  0,  0,  0,  0, -5,
 -5,  0,  0,  0,  0,  0,  0, -5,
  0,  0,  0,  5,  5,  0,  0,  0
};

  int black_rook_table[8][8] = {
  0,  0,  0,  5,  5,  0,  0,  0,
 -5,  0,  0,  0,  0,  0,  0, -5,
 -5,  0,  0,  0,  0,  0,  0, -5,
 -5,  0,  0,  0,  0,  0,  0, -5,
 -5,  0,  0,  0,  0,  0,  0, -5,
 -5,  0,  0,  0,  0,  0,  0, -5,
  5, 10, 10, 10, 10, 10, 10,  5,
  0,  0,  0,  0,  0,  0,  0,  0
  };

//queen
int queen_table[8][8] = {
  -20,-10,-10, -5, -5,-10,-10,-20,
-10,  0,  0,  0,  0,  0,  0,-10,
-10,  0,  5,  5,  5,  5,  0,-10,
 -5,  0,  5,  5,  5,  5,  0, -5,
  0,  0,  5,  5,  5,  5,  0, -5,
-10,  5,  5,  5,  5,  5,  0,-10,
-10,  0,  5,  0,  0,  0,  0,-10,
-20,-10,-10, -5, -5,-10,-10,-20
};

  int black_queen_table[8][8] = {
-20,-10,-10, -5, -5,-10,-10,-20,
  -10,  0,  5,  0,  0,  0,  0,-10,
  -10,  5,  5,  5,  5,  5,  0,-10,
  0,  0,  5,  5,  5,  5,  0, -5,
 -5,  0,  5,  5,  5,  5,  0, -5
-10,  0,  5,  5,  5,  5,  0,-10,
-10,  0,  0,  0,  0,  0,  0,-10,
    -20,-10,-10, -5, -5,-10,-10,-20
  };

int king_middle_table[8][8] = {
-30,-40,-40,-50,-50,-40,-40,-30,
-30,-40,-40,-50,-50,-40,-40,-30,
-30,-40,-40,-50,-50,-40,-40,-30,
-30,-40,-40,-50,-50,-40,-40,-30,
-20,-30,-30,-40,-40,-30,-30,-20,
-10,-20,-20,-20,-20,-20,-20,-10,
 20, 20,  0,  0,  0,  0, 20, 20,
 20, 30, 10,  0,  0, 10, 30, 20
};

  
  
  // king end game
int king_end_table[8][8] = {
  -50,-40,-30,-20,-20,-30,-40,-50,
-30,-20,-10,  0,  0,-10,-20,-30,
-30,-10, 20, 30, 30, 20,-10,-30,
-30,-10, 30, 40, 40, 30,-10,-30,
-30,-10, 30, 40, 40, 30,-10,-30,
-30,-10, 20, 30, 30, 20,-10,-30,
-30,-30,  0,  0,  0,  0,-30,-30,
-50,-30,-30,-30,-30,-30,-30,-50
};

  int black_king_end_table[8][8] = {

-50,-30,-30,-30,-30,-30,-30,-50,
-30,-30,  0,  0,  0,  0,-30,-30,
-30,-10, 20, 30, 30, 20,-10,-30,
-30,-10, 30, 40, 40, 30,-10,-30,
-30,-10, 30, 40, 40, 30,-10,-30,
-30,-10, 20, 30, 30, 20,-10,-30,
-30,-20,-10,  0,  0,-10,-20,-30,
   -50,-40,-30,-20,-20,-30,-40,-50
  };
  int black_king_middle_table[8][8] = {
 20, 30, 10,  0,  0, 10, 30, 20,
20, 20,  0,  0,  0,  0, 20, 20,
-10,-20,-20,-20,-20,-20,-20,-10,
-20,-30,-30,-40,-40,-30,-30,-20,
-30,-40,-40,-50,-50,-40,-40,-30,
-30,-40,-40,-50,-50,-40,-40,-30,
  -30,-40,-40,-50,-50,-40,-40,-30,
    -30,-40,-40,-50,-50,-40,-40,-30
  };
  int finalValue;
  
  if (id == 1 && color == 1)
  {
    finalValue = pawn_table[positionX][positionY] * pawnVal;
  }
  else if (id == 1 && color == 0) 
  {
        finalValue = black_pawn_table[positionX][positionY] * pawnVal;
  }

  else if (id == 3 & color == 1){
     finalValue = knight_table[positionX][positionY] * knightVal;
  }

  else if (id == 3 && color == 0){
    finalValue = black_knight_table[positionX][positionY] * knightVal;
  }

  else if (id == 5 && color == 1){
    finalValue = rook_table[positionX][positionY] * rookVal;
  }
  else if (id == 5 && color == 0){
    finalValue = black_rook_table[positionX][positionY] * rookVal;
  }

  else if (id == 9 && color == 1){
    finalValue = queen_table[positionX][positionY] * queenVal;
  }
  else if (id == 9 && color == 0){
    finalValue = black_queen_table[positionX][positionY] * queenVal;
  }

  else if (id == 10 && color == 0){
   if (true){
     finalValue = king_end_table[positionX][positionY] * kingVal;
   }
    else{
      finalValue = king_middle_table[positionX][positionY] * kingVal;
    }
  }

  else{
if (true){
     finalValue = black_king_end_table[positionX][positionY] * kingVal;
   }
    else{
      finalValue = black_king_middle_table[positionX][positionY] * kingVal;
    }
  }

  return finalValue;
/**
rook = 5
knight = 3
queen = 9
king = 10
**/    

  
}

int evaluateBoard(board* c) {
  int white_value;
  int black_value;
  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      if (c->getPiece(i, j).getColor() == 0) {
        if (c->getPiece(i, j).getVal() < 0 || c->getPiece(i, j).getVal() > 10) {
          continue;
        }
        white_value += evaluatePiece(c->getPiece(i, j).getXPos(), c->getPiece(i, j).getYPos(), c->getPiece(i, j).getVal(), c->getPiece(i, j).getColor());
  
      }
      else {
        if (c->getPiece(i, j).getVal() < 0 || c->getPiece(i, j).getVal() > 10) {
          continue;
        }
           black_value+= evaluatePiece(c->getPiece(i, j).getXPos(), c->getPiece(i, j).getYPos(), c->getPiece(i, j).getVal(), c->getPiece(i, j).getColor());

       
      }
    }
  }

  int value = white_value - black_value;
  return value;
}

  bool canMove(pieceCreate p,int oldx, int oldy, int newx, int newy){
  int id = p.getVal();
   if(oldx<8 || oldy<'i'){ //if move is on the chessboard 
     
     if(id==1){//for pawn
    if(oldx==2){ //for white pawn
      if(newx==(oldx+1) || newx==(oldx+2)){
        return true;
      }
    }
    else if (id==7){ //for black pawn
      if(newx==(oldx-1) || newx==(oldx-2)){
        return true;
      }
    }
  } //pawn

     else if(id==4){
       if(newx==newy && newx!=oldx){
         return true;
       }
     } //bishop

     else if(id==5){
       if(oldx!=newx && oldy==newy){
         return true;
       }
       else if (oldx==newx && oldy!=newy){
         return true;
       }
      //rook
   }
     else if(id==10){
       
     }
    
  
   return false; //move isn't on chessboard or didn't pass parameters above
//    else if(id==3){
    
//   }
//   
//   else if(id==5){
    
//   }
//   else if(id==9){
    
//   }
//   else if(id==10){
    
//   }
 }
 }

vector<board> evaluatePosition(board* chessboard) {
  vector<board> *boards;
  int count = 0;
board* temp;
  char newyPos;
  char oldyPos;
  temp = chessboard;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (chessboard->getPiece(i, j).getVal()<=11) {
        for (int y = 0; y< 8-chessboard->getPiece(i, j).getYPos(); y++){
          for (int x = 0; x<8-chessboard->getPiece(i, j).getXPos(); x++){
         if (chessboard->canMove(chessboard->getPiece(i, j), chessboard->getPiece(i, j).getXPos(), chessboard->getPiece(i, j).getYPos(), x, y)){
           oldyPos = convertInt(chessboard->getPiece(i, j).getYPos());
           newyPos = convertInt(y);
              temp->move(chessboard->getPiece(i, j).getXPos(), chessboard->getPiece(i, j).getYPos(), x, y);
         
              boards->push_back(*temp);
           
            temp = chessboard;
              count++;
            }
          
          }
        }
      }
    } 
  }
  return *boards;
}


// void finalMove(){
//   int curMin = 2147483647;
//   int finalIndex;
// for (int i = 0; i < boards.size(); i++){
//   if (evaluateBoard(boards[i]) < curMin){
//     curMin = evaluateBoard(boards[i]);
//     finalIndex = i;
//   } //fixed it imma code a get method cuz idk what's happening with that 
//   //loveee ty
//   //do u know why canMove doesn't work again
//   //good question
//   //ALEX I FIXED IT BUT IT'S HELLA SUS  
  
// }
//  chessboard = boards[finalIndex];
// }


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
//     int maxPos = 0;
//     int max = 0;
//     int searchRow = 3;
//     for (int i = 2; i < 4; i++) {
//       for (int j = 0; j < 8; j++) {
        
//         cout << evaluatePiece(i, j, 1, 1) << endl;
//       }
//     }
    
//     for (int i = 0; i < 8; i++) {
//       if (evaluatePiece(searchRow, i, 1, 1 ) > max) {
//         max = evaluatePiece(searchRow, i, 1, 1 );
     
//         maxPos++;
//       }
//     }

//     cout << endl << max << endl;
//     cout << endl << maxPos << endl;

// char arr[8] = {'z','e','d','d','b','g','c','f'};
// int arr2[8] = {999,7,7,5,7,7,7,7};
// char arr3[8] = {'z','e','d','e','b','g','c','f'};
// int arr4[8] = {999, 5,5,4,5,5,5,5};
    

//    char cch = 'a' + rand()%7;
//     b->move(arr2[gameCounter],arr[gameCounter],arr4[gameCounter], arr3[gameCounter]);
   
    b->displayPieceBoard();
  }
 
  std::cout<<"Game Over!";
}