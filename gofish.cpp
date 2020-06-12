#include "gofish.h"

deck::deck(){
    head=nullptr;
    numbercards=0;
}
card deck::pop(){
    cardnode* ptr=head;
    card temp=head->data;
    head=head->next;
    delete ptr;
    return temp;
}
void deck::empty(){
    while(head!=nullptr){
        pop();
    }
}
hand::hand(){
    deck();
}
collected::collected(){
    deck();
}
deck::~deck(){
    empty();
}
hand::~hand(){
    empty();
}
collected::~collected(){
    empty();
}
void deck::push(card newdata){
    cardnode* newnode= new cardnode;
    newnode->data=newdata;
    newnode->next=head;
    head=newnode;
    ++numbercards;
    return;
}
bool deck::isEmpty(){
    if(head==nullptr){
        return true;
    }
        return false;
}
void deck::initializefromfile(){
    fstream output;
    card newdata;
    string temp;
    int i=0;
    output.open("cards.csv",std::fstream::in);
    while(!output.eof()&&i<52){
        getline(output,newdata.filename,',');
        getline(output,temp);
        istringstream(temp)>>newdata.face;
        push(newdata);
        ++i;
    }
}


void deck::swap(){
    int n1=0,n2=0;
    card temp;
    cardnode* location1=head;
    cardnode* location2=head;
    n1=rand()%numbercards+1;
    n2=rand()%numbercards+1;
    for(int i=1;i<n1;++i){
        location1=location1->next;
    }
    temp=location1->data;
    for(int i=1;i<n2;++i){
        location2=location2->next;
    }
    location1->data=location2->data;
    location2->data=temp;
    return;
}
void deck::shuffle(){
    for(int i=0;i<52;++i){
        swap();
    }
}
bool hand::check4ofakind(int face){
    cardnode* temp=head;
    int num=0;
    while(temp!=nullptr){
        if(face==temp->data.face)
            ++num;
        temp=temp->next;
    }
    if(num>=4){
        return true;
    }
    return false;
}
bool hand::searchface(int face){
    cardnode* temp=head;
    while(temp!=nullptr){
        if(face==temp->data.face){
            return true;
        }
        temp=temp->next;
    }
    return false;
}
card hand::remove(int face){
    cardnode*current=head;
    cardnode*previous=head;
    card storage;
    if(head->data.face==face){
        storage=head->data;
        head=head->next;
        delete current;
        return storage;
    }
    while(current!=nullptr){
        if(current->data.face==face){
            storage=current->data;
            previous->next=current->next;
            delete current;
            return storage;
        }
        previous=current;
        current=current->next;
    }
}

void deck::displaycards(){
    cardnode* ptr=head;
    while(head!=nullptr){
        cout<<ptr->data.filename<<endl;
        ptr=ptr->next;
    }
}
int deck::getnumcards(){
    return numbercards;
}
void playerturn(hand& activehand,hand& passivehand,collected& activecollection,deck& Deck,sf::RenderWindow &window){
    int cont=1;
    int hascard=0;
    sf::Vector2i mpos;
    card temp;
    while(cont==1){
        ///draw window, put in some text asking to choose a card
        //display window
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            mpos=sf::Mouse::getPosition();
            if(mpos.x>=0&&mpos.x<=(54*activehand.getnumcards()))
                if(mpos.y>=0&&mpos.y<=(85*activehand.getnumcards())){
                    //temp=returnbyint(mpos.x/54);
                    //hascard=passivehand.check4ofkind(temp.face)
                }
        }
    }
    if(hascard==0){
        //print and display gofish
        activehand.push(Deck.pop());
    }
    else{
        //removing cards from passive hand and adding to active hand
        while(passivehand.searchface(temp.face)){//checks if they still have card
            activehand.push(passivehand.remove(temp.face));//passive player gives active player the card
        }
       for(int i=1;i<14;++i){
           if(activehand.check4ofakind(i)){
               activecollection.push(activehand.remove(i));//if player has 4 of a kind for face i, add it to collection
                while(activehand.check4ofakind(i)){//while they still have cards of that facce, remove them
                activehand.remove(i);
                }
           }
        }
        
    }
}
bool checkwin(collected& p1, collected& p2){
    if((p1.getnumcards()+p2.getnumcards())<13){
        return false;
    }
    return true;
}