#include "gofish.h"

int main(){
    deck Deck;
    hand p1, p2;
    string input;
    collected p1coll, p2coll;
    sf::Texture felt, back;
    felt.loadFromFile("felttable.png");
    back.loadFromFile("gray_back.png");
    Deck.initializefromfile();
    Deck.shuffle();
    for(int i=0;i<7;++i){
        p1.push(Deck.pop());
        p2.push(Deck.pop());
    }
    sf::RenderWindow window(sf::VideoMode(1366,768),"Go Fish!");
        sf::RectangleShape board(sf::Vector2f(1366.f,768.f));
        sf::RectangleShape deckback(sf::Vector2f(54.f,85.f));
        board.setTexture(&felt);
    deckback.setPosition(100,342);
    board.setPosition(0,0);
    window.draw(board);
    window.draw(deckback);
    //set loaction of deck
    //set loaction of collections
    window.display();
    cin.ignore().get(); 
    //while(window.isOpen()){
        //window.draw(board);
        //playerturn(activehand,passivehand,activecollection);
    //}
    window.close();
    return 0;
}