#ifndef GOFISH_H
#define GOFISH_H
#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <fstream>
#include <unistd.h>
#include<SFML/Graphics.hpp> 
//#include <mouse.hpp>
using namespace std;

struct card{
    string filename;//corresponds to file
    int face;
};
struct cardnode{
    card data;
    cardnode* next;
};

class deck{
    protected:
        cardnode* head;
        int numbercards;
    public:
        void displaycards();
        /*************************************************************
        * Function: check4ofakind()
        * Date Created:7/12/2020
        * Date Last Modified: 7/12/2020
        * Returns: none
        * Description: writes the cards in a deck to the terminal
        * Preconditions: 
        * Postconditions:
        *************************************************************/
        deck();
        ~deck();
        void initializefromfile();
        /*************************************************************
        * Function: initializefromfile();
        * Date Created:7/10/2020
        * Date Last Modified: 7/10/2020
        * Returns: 
        * Description: reads in the deck from "cards.csv"
        * Preconditions:
        * Postconditions:
        *************************************************************/
        void draw(sf::RenderWindow& window);
        /*************************************************************
        * Function: display()
        * Date Created:7/10/2020
        * Date Last Modified: 7/10/2020
        * Returns: 
        * Description: a virtual display function, to allow different calls later
        * Preconditions:
        * Postconditions:
        *************************************************************/
        bool isEmpty();
        /*************************************************************
        * Function: isEmpty()
        * Date Created:7/10/2020
        * Date Last Modified: 7/10/2020
        * Returns: a boolean value
        * Description: checks if the deck is empty
        * Preconditions:
        * Postconditions:
        *************************************************************/
       void push(card);
        /*************************************************************
        * Function: push()
        * Date Created:7/10/2020
        * Date Last Modified: 7/10/2020
        * Returns: 
        * Description: pushes a card onto the stack
        * Preconditions:
        * Postconditions:
        *************************************************************/
       card pop();
        /*************************************************************
        * Function: pop()
        * Date Created:7/10/2020
        * Date Last Modified: 7/10/2020
        * Returns: 
        * Description: deletes and returns the card on top of the deck
        * Preconditions:
        * Postconditions:
        *************************************************************/
       void swap();
        /*************************************************************
        * Function: swap()
        * Date Created:7/10/2020
        * Date Last Modified: 7/10/2020
        * Returns: 
        * Description: swaps the location of two cards in the deck
        * Preconditions:
        * Postconditions:
        *************************************************************/
       void shuffle();
        /*************************************************************
        * Function: shuffle()
        * Date Created:7/10/2020
        * Date Last Modified: 7/10/2020
        * Returns: 
        * Description: calls swap 52 times to shuffle 
        * Preconditions:
        * Postconditions:
        *************************************************************/
       void empty();
        /*************************************************************
        * Function: empty()
        * Date Created:7/10/2020
        * Date Last Modified: 7/10/2020
        * Returns: 
        * Description: pops every card in the deck, used in ~deck();
        * Preconditions:
        * Postconditions:
        *************************************************************/
       int getnumcards();
        /*************************************************************
        * Function: getnumcards())
        * Date Created:7/12/2020
        * Date Last Modified: 7/12/2020
        * Returns: an integer
        * Description: returns the number of cards
        * Preconditions: 
        * Postconditions:
        *************************************************************/ 
       card returnbyint(int n);
        /*************************************************************
        * Function: returnbyint()
        * Date Created:7/12/2020
        * Date Last Modified: 7/12/2020
        * Returns: the nth card
        * Description: returns the nth card
        * Preconditions: 
        * Postconditions:
        *************************************************************/
};

class hand:public deck{
    public:
        hand();
        card remove(int face);
        /*************************************************************
        * Function: remove()
        * Date Created:7/10/2020
        * Date Last Modified: 7/10/2020
        * Returns: a card
        * Description: removes a card from the hand
        * Preconditions: searchsuit returns true
        * Postconditions:
        *************************************************************/
        bool searchface(int face);
        /*************************************************************
        * Function: searchsuit()
        * Date Created:7/10/2020
        * Date Last Modified: 7/10/2020
        * Returns: a boolean value
        * Description: searchs for a card with a specific face
        * Preconditions: 
        * Postconditions:
        *************************************************************/
        void draw(sf::RenderWindow& window,int player);
        void draw(cardnode* ptr,sf::RenderWindow& window,int player);
        /*************************************************************
        * Function: draw()
        * Date Created:7/12/2020
        * Date Last Modified: 7/12/2020
        * Returns: nothing
        * Description: draws cards in window
        * Preconditions: 
        * Postconditions:
        *************************************************************/
        void drawbacks(sf::RenderWindow& window,int player);
        /*************************************************************
        * Function: check4ofakind()
        * Date Created:7/12/2020
        * Date Last Modified: 7/12/2020
        * Returns: nothing
        * Description: draws the backs of cards
        * Preconditions: 
        * Postconditions:
        *************************************************************/
        int check4ofakind(int face);
        /*************************************************************
        * Function: check4ofakind()
        * Date Created:7/12/2020
        * Date Last Modified: 7/12/2020
        * Returns: a boolean value
        * Description: checks if a player has 4 of a kind
        * Preconditions: 
        * Postconditions:
        *************************************************************/
        ~hand();
        void display(){
            cardnode* ptr=head;
            while(ptr!=nullptr){
                cout<<ptr->data.filename<<endl;
                ptr=ptr->next;
            }
        }
        /*************************************************************
        * Function: display()
        * Date Created:7/12/2020
        * Date Last Modified: 7/12/2020
        * Returns: nothing
        * Description: displays cards in text box
        * Preconditions: 
        * Postconditions:
        *************************************************************/
};
class collected:public deck{
    public:
        collected();
     //   void display(Renderwindow& window);
        ~collected();
        void draw(sf::RenderWindow&window, int player, cardnode*ptr);
        void draw(sf::RenderWindow&window,int player);
        /*************************************************************
        * Function: draw()
        * Date Created:7/12/2020
        * Date Last Modified: 7/12/2020
        * Returns: 
        * Description: recursively draws the cards in a players collection
        * Preconditions: 
        * Postconditions:
        *************************************************************/
};

void playerturn(hand& activehand,hand& passivehand,collected& activecollection,collected& passivecollection, deck& Deck,sf::RenderWindow &window,int player);
        /*************************************************************
        * Function: playerturn()
        * Date Created:7/11/2020
        * Date Last Modified: 7/11/2020
        * Returns: nothing
        * Description: performs the turn of the active player
        * Preconditions: 
        * Postconditions:
        *************************************************************/

bool checkwin(collected& p1, collected& p2);
void rules(sf::RenderWindow& window);
        /*************************************************************
        * Function: rules()
        * Date Created:6/16/2020
        * Date Last Modified: 6/16/2020
        * Returns: nothing
        * Description: displays the rules
        * Preconditions: 
        * Postconditions:
        *************************************************************/

void mainmenu(sf::RenderWindow& window);
        /*************************************************************
        * Function: mainmenu()
        * Date Created:6/16/2020
        * Date Last Modified: 6/16/2020
        * Returns: nothing
        * Description: displays the mainmenu
        * Preconditions: 
        * Postconditions:
        *************************************************************/
#include "gofish.cpp"
#endif