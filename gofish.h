#ifndef GOFISH_H
#define GOFISH_H
#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <fstream>
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
        deck();
        ~deck();
        void initializetexture();
        void initializesprite();
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
        //void display();
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
        void display(sf::RenderWindow& window);
        /*************************************************************
        * Function: display()
        * Date Created:7/12/2020
        * Date Last Modified: 7/12/2020
        * Returns: nothing
        * Description: displays each card in the hand
        * Preconditions: 
        * Postconditions:
        *************************************************************/
        bool check4ofakind(int face);
        ~hand();
};
class collected:public deck{
    public:
        collected();
     //   void display(Renderwindow& window);
        ~collected();
};

void playerturn(hand& activehand,hand& passivehand,collected& activecollection,sf::RenderWindow &window);
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
#include "gofish.cpp"
#endif