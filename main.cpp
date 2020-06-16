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
        //p1coll.push(Deck.pop());
        //p2coll.push(Deck.pop());
    } 
    sf::RenderWindow window(sf::VideoMode(1366,768),"Go Fish!");
    window.setFramerateLimit(60);
    sf::RectangleShape board(sf::Vector2f(1366.f,768.f));
    board.setTexture(&felt);
    board.setPosition(0,0);
    while(window.isOpen()){
        playerturn(p1,p2,p1coll,p2coll,Deck,window,1);
        if(checkwin(p1coll,p2coll));{
            //endgame
        }
        playerturn(p2,p1,p2coll,p2coll,Deck,window,2);
        if(checkwin(p1coll,p2coll));{
            //endgame
        }
    }
    window.close();
    return 0;
}