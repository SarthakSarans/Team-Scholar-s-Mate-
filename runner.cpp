#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <string.h>
using namespace std;
    class Piece {
        

    public:

        std::string color;
        int x;
        int y;
        int pieceType;
        bool selected;
        int countMove


        Piece(const std::string col, int xpos, int ypos, const std::int piece_type){
            color = (col); 
            x =(xpos); 
            y= (ypos); 
            pieceType = (piece_type); 
             selected = false; 
             countMoves = 0;
        }
    }
        }

        void draw(sf::Text& letter, sf::RenderWindow& surface) {
            sf::Font PIECE;
            PIECE.loadFromFile("assets/ChessAlpha2.ttf");
            letter.setFont(PIECE);
            letter.setCharacterSize(95);
            letter.setStyle(sf::Text::Bold);
            letter.setFillColor(BLACK);

            if (type == "pawn") {
                letter.setPosition(sf::Vector2f(x * 80 + 17, y * 80));
            }
            else if (type == "rook") {
                letter.setPosition(sf::Vector2f(x * 80 + 15, y * 80));
            }
            else if (type == "king" || type == "queen") {
                letter.setPosition(sf::Vector2f(x * 80 + 7, y * 80));
            }
            else {
                letter.setPosition(sf::Vector2f(x * 80 + 10, y * 80));
            }

            sf::RectangleShape buttonRect(sf::Vector2f(8, 8));
            buttonRect.setPosition(8, 8);
            buttonRect.setFillColor(sf::Color::White);
            surface.draw(buttonRect);
            surface.draw(letter);
        }

        std::string getType() const {
            return type;
        }

        std::string getColor() const {
            return color;
        }

        void drawMoves(sf::RenderWindow& window, sf::RectangleShape& board, std::vector<std::unique_ptr<Piece>>& pieces) {
            if (selected) {
                board.setFillColor(COLOR1);
                window.draw(board);
                for (auto& piece : pieces) {
                    sf::Text letter;
                    if (piece->getColor() == "white") {
                        if (piece->getType() == "pawn") {
                            letter.setString("i");
                        }
                       


int main()
{
    sf::Color COLOR1(244, 194, 194);
    sf::Color COLOR2(245, 245, 230);
    sf::Color BLACK(0, 0, 0);
    sf::RenderWindow window(sf::VideoMode(640, 640), "Chess Game");
    window.setFramerateLimit(60);
    std::vector<std::unique_ptr<Piece>> pieces;
    bool selected = false;

    // set up the board
    sf::RectangleShape board(sf::Vector2f(640, 640));
    board.setFillColor(COLOR1);

    // draw the board
    for (int x = 0; x < 8; x += 2) {
        for (int y = 0; y < 8; y += 2) {
            sf::RectangleShape square(sf::Vector2f(80, 80));
            square.setFillColor(COLOR2);
            square.setPosition(sf::Vector2f(x * 80, y * 80));
            board.draw(square);

            sf::RectangleShape square2(sf::Vector2f(80, 80));
            square2.setFillColor(COLOR2);
            square2.setPosition(sf::Vector2f((x + 1) * 80, (y + 1) * 80));
            board.draw(square2);
        }
    }

    // add the board to the screen
    window.draw(board);
