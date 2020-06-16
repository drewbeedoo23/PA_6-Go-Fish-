#include "gofish.h"

int main(){
    deck Deck;
    hand p1, p2;
    string input;
    int hold=0;
    collected p1coll, p2coll;
    sf::Texture felt;
    srand(time(nullptr));
    felt.loadFromFile("felttable.png");
    Deck.initializefromfile();
    Deck.shuffle();
    for(int i=0;i<7;++i){
        p1.push(Deck.pop());
        p2.push(Deck.pop());
    } 
    sf::RenderWindow window(sf::VideoMode(1366,768),"Go Fish!");
    sf::RectangleShape board(sf::Vector2f(1366.f,768.f));
    board.setTexture(&felt);
    board.setPosition(0,0);
    while(window.isOpen()){
        window.draw(board);
        playerturn(p1,p2,p1coll,Deck,window,1);
        //playerturn(activehand,passivehand,activecollection,window,1);
        //intermediate checks
        //playerturn()
    }
    window.close();
    return 0;
}