#include "gofish.h"

int main(){
    deck Deck;
    hand p1, p2;
    sf::Text text;
    sf::Event userinput;
    sf::Font font;
    int cont=1;
    font.loadFromFile("Amatic-Bold.ttf");
    text.setFont(font);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Regular);
    text.setPosition(400,340);
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
       // p1coll.push(Deck.pop());
        //p2coll.push(Deck.pop());
    } 
    sf::RenderWindow window(sf::VideoMode(1366,768),"Go Fish!");
    window.setFramerateLimit(60);
    sf::RectangleShape board(sf::Vector2f(1366.f,768.f));
    board.setTexture(&felt);
    board.setPosition(0,0);
    mainmenu(window);
    while(window.isOpen()){
        playerturn(p1,p2,p1coll,p2coll,Deck,window,1);
        if(checkwin(p1coll,p2coll)){
            if(p1coll.getnumcards()>p2coll.getnumcards()){
                text.setString("Player 1 wins! Press Escape to exit:");
            }
            else{
                text.setString("Player 2 wins! Press Escape to exit:");

            }
            while(window.isOpen()){
                if(cont==0){
                    break;
                }
                window.draw(board);
                window.draw(text);
                Deck.draw(window);
                p1.draw(window,1);
                p1coll.draw(window,1);
                p2coll.draw(window,2);
                p2.drawbacks(window,1);
                window.display();
                while(window.pollEvent(userinput)){
                    if(userinput.type==sf::Event::KeyPressed){
                        cout<<"Key Pressed\n";
                        if(userinput.key.code==sf::Keyboard::Escape){
                            cont=0;
                            cout<<"Enter Pressed\n";
                        }
                    }
                }

            }
            //endgame
            window.close();
            break;
        }
        playerturn(p2,p1,p2coll,p1coll,Deck,window,2);
        if(checkwin(p1coll,p2coll)){
            if(p1coll.getnumcards()>p2coll.getnumcards()){
                text.setString("Player 1 wins! Press Escape to exit:");

            }
            else{
                text.setString("Player 2 wins! Press Escape to exit:");

            }
            while(window.isOpen()){
                if(cont==0){
                    break;
                }
                window.draw(board);
                window.draw(text);
                Deck.draw(window);
                p2.draw(window,2);
                p2coll.draw(window,2);
                p1.drawbacks(window,1);
                p1coll.draw(window,1);
                window.display();
                while(window.pollEvent(userinput)){
                    if(userinput.type==sf::Event::KeyPressed){
                        cout<<"Key Pressed\n";
                        if(userinput.key.code==sf::Keyboard::Escape){
                            cont=0;
                            cout<<"Enter Pressed\n";
                        }
                    }
                }

            }
            //endgame
            window.close();
            break;
        }
    }
    window.close();
    return 0;
}