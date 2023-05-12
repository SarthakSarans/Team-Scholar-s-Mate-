import pygame
import sys
from pygame.locals import *
import time


COLOR1 = ((244, 194, 194))
COLOR2 = ((245, 245, 230))
BLACK = ((0,0,0))
pygame.init()
WHITE = (255,255,255)
# set up the window
size = (640, 640)
screen = pygame.display.set_mode(size)
pygame.display.set_caption("Chess Game")
pieces = []
global selected 
selected = False
# set up the board
board = pygame.Surface((640, 640))
board.fill(COLOR1)
    
# draw the board
def drawBoard():
    selected = False
    for x in range(0, 8, 2):
        for y in range(0, 8, 2):
            pygame.draw.rect(board, COLOR2, (x*80, y*80, 80, 80))
            pygame.draw.rect(board, COLOR2, ((x+1)*80, (y+1)*80, 80, 80))

# add the board to the screen
drawBoard()
screen.blit(board, (0, 0))

pygame.display.flip()

class Piece:
    def __init__(self, color, x, y, piece_type):
        self.color = color
        self.x = x
        self.y = y
        self.type = piece_type
        self.selected = False
        self.countMoves = 0

    def draw(self, letter,surface):
        PIECE = "assets/ChessAlpha2.ttf"
        mediumFont = pygame.font.Font(PIECE, 95)
        buttonRect = pygame.Rect(8,8,8,8)
        buttonText = mediumFont.render(letter, True, BLACK)
        buttonTextRect = buttonText.get_rect()
        buttonTextRect.center = buttonRect.center
        pygame.draw.rect(screen, WHITE, buttonRect)
        if self.type == "pawn":
            screen.blit(buttonText, (self.x*80+17,self.y*80))
        elif self.type == "rook":
            screen.blit(buttonText, (self.x*80+15,self.y*80))
        elif self.type == "king" or self.type == "queen":
            screen.blit(buttonText, (self.x*80+7,self.y*80))

        else:
            screen.blit(buttonText, (self.x*80+10,self.y*80))

    def getType(self):
        return self.type
    def getColor(self):
        return self.color
    def drawMoves(self):
        
        if(self.selected):
            drawBoard()
            screen.blit(board, (0, 0))
            drawPieces(pieces)
            self.selected = False
            

        else:
            drawBoard()
            screen.blit(board, (0, 0))
            drawPieces(pieces)
 
            pygame.draw.rect(screen, (244, 194, 80), (self.x*80, self.y*80, 80, 80))
            drawPieces(pieces)
            selected = True
            self.selected = True
     
        
        pygame.display.flip()
    
        
def drawPieces(pieces):
    for piece in pieces:
        if piece.getColor() == "white":
            if piece.getType() == "pawn":
                piece.draw("i",board)
            if piece.getType() == "rook":
                piece.draw("l",board)
            if piece.getType() == "bishop":
                piece.draw("j",board)
            if piece.getType() == "knight":
                piece.draw("k",board)
            if piece.getType() == "king":
                piece.draw("n",board)
            if piece.getType() == "queen":
                piece.draw("m",board)

        else:
            if piece.getType() == "pawn":
                piece.draw("I",board)
            if piece.getType() == "rook":
                piece.draw("L",board)
            if piece.getType() == "bishop":
                piece.draw("J",board)
            if piece.getType() == "knight":
                piece.draw("K",board)
            if piece.getType() == "king":
                piece.draw("N",board)
            if piece.getType() == "queen":
                piece.draw("M",board)
# set up the pieces

for i in range(8):
    pieces.append(Piece("black", i, 1, "pawn"))
    pieces.append(Piece("white", i, 6, "pawn"))

for i in range(1):
    pieces.append(Piece("black", 0, 0, "rook"))
    pieces.append(Piece("black", 2, 0, "bishop"))
    pieces.append(Piece("black", 1, 0, "knight"))
    pieces.append(Piece("white", 0, 7, "rook"))
    pieces.append(Piece("white", 2, 7, "bishop"))
    pieces.append(Piece("white", 1, 7, "knight"))

    pieces.append(Piece("black", 7, 0, "rook"))
    pieces.append(Piece("black", 5, 0, "bishop"))
    pieces.append(Piece("black", 6, 0, "knight"))
    pieces.append(Piece("white", 7, 7, "rook"))
    pieces.append(Piece("white", 5, 7, "bishop"))
    pieces.append(Piece("white", 6, 7, "knight"))
    pieces.append(Piece("black", 4, 0, "king"))
    pieces.append(Piece("black", 3, 0, "queen"))
    pieces.append(Piece("white", 4, 7, "king"))
    pieces.append(Piece("white", 3, 7, "queen"))

drawPieces(pieces)
# draw the pieces
pygame.display.flip()

dummyPiece = Piece(None,None,None,None)
lastSelected = dummyPiece

# main loop
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()


        if event.type == pygame.MOUSEBUTTONDOWN and selected:
            pos = pygame.mouse.get_pos()
            # convert the position to board coordinates
            x = (pos[0]) // 80
            y = (pos[1]) // 80

            invalidMove = False
            selectedPiece = dummyPiece

            
            for piece in pieces:
                if piece.x == x and piece.y == y and piece.color == lastSelected.color:
                    # if moving to where a piece is currently, stops it from moving
                    selected = False;
                    drawBoard()
                    screen.blit(board, (0, 0))
                    drawPieces(pieces)
                    invalidMove = True
                    piece.selected = False
                    lastSelected = piece
                    break
            if invalidMove:
                continue
            for piece in pieces:
                #deletes piece if same location as moved
                if piece.x == x and piece.y == y :
                    pieces.remove(piece)
                # moves if it is a valid location

                if (piece.selected == True):
                    piece.x = x 
                    piece.y = y 
                    print(piece.type)
                    piece.drawMoves()
                    lastSelected = piece
                    selected = False
                    piece.selected = False
                    piece.countMoves += 1
                    #time.sleep(0.4)
                    break
                
                piece.selected = False
                
            pygame.display.flip()
            time.sleep(0.2)

            
            
        elif event.type == pygame.MOUSEBUTTONDOWN and not selected:
            # get the position of the click
            pos = pygame.mouse.get_pos()
            # convert the position to board coordinates
            x = (pos[0]) // 80
            y = (pos[1]) // 80
            
            
            # find the piece at the clicked position
            for piece in pieces:
                if piece.x == x and piece.y == y:
                    # move the piece
                    pos = pygame.mouse.get_pos()
                    
                    piece.x = x
                    piece.y = y
                    print(piece.type)
                    piece.drawMoves()
                    lastSelected = piece
                    selected = True
                    pygame.display.flip()
                    time.sleep(0.2)
                    piece.countMoves += 1
                    break
        pygame.display.flip()


                    


                    



      

    



