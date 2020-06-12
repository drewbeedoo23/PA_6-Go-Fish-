#include "gofish.h"

int main(){
    deck Deck;
    hand p1, p2;
    string input;
    int hold=0;
    collected p1coll, p2coll;
    sf::Texture felt, back;
    srand(time(nullptr));
    back.setRepeated(false);
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
    sf::Sprite deckback(back);
    board.setTexture(&felt);
    deckback.setPosition(100,342);
    deckback.setScale(0.078148f,0.080492f);
    board.setPosition(0,0);
    window.draw(board);
    window.draw(deckback);
    p1.initializetexture();
    p1.display(window);
    //set loaction of deck
    //set loaction of collections
    window.display();
    cin.ignore().get(); 
    //while(window.isOpen()){
        //window.draw(board);
        //playerturn(activehand,passivehand,activecollection,window,1);
        //intermediate checks
        //playerturn()
    //}
    window.close();
    return 0;
}