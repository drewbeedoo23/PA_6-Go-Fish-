#ifndef GOFISH_H
#define GOFISH_H
#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <fstream>
#include<SFML/Graphics.hpp> 
using namespace std;

struct card{
    string filename;//corresponds to file
    int face;
};

class deck{
    protected:
        struct cardnode{
            card data;
            cardnode* next;
        };
        cardnode* head;
        int numbercards;
    public:
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
        virtual void display();
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
       
};

class hand:public deck{
    public:
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
        void display();
        bool check4ofakind(int face);
};
class collected:public deck{
    public:
        void display();
};





#endif