#include "gofish.h"

int main(){
    deck Deck;
    hand p1, p2;
    collected p1coll, p2coll;
    sf::Texture felt;
    felt.loadFromFile("felttable.png");
    Deck.initializefromfile();
    Deck.shuffle();
    for(int i=0;i<7;++i){
        p1.push(Deck.pop());
        p2.push(Deck.pop());
    }
    sf::RenderWindow window(sf::VideoMode(1920,1080),"Go Fish!");
        sf::RectangleShape board(sf::Vector2f(1920.f,1080.f));
        board.setTexture(&felt);
    while(window.isOpen()){
        window.draw(board);
        //playerturn(activehand,passivehand,activecollection);
    }

}