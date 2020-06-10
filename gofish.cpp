#include "gofish.h"

deck::deck(){
    head=nullptr;
    numbercards=0;
}
deck::~deck(){
    empty();
}
void deck::push(card newdata){
    cardnode* newnode= new cardnode;
    newnode->data=newdata;
    newnode->next=nullptr;
    if(head==nullptr){
        head=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
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
    output.open("cards.csv",std::fstream::in);
    while(!output.eof()){
        getline(output,newdata.name,',');
        getline(output,temp);
        istringstream(temp)>>newdata.suit;
        push(newdata);
    }
}

card deck::pop(){
    card temp=head->data;
    head=head->next;
    return temp;
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
void deck::empty(){
    while(head!=nullptr){
        pop();
    }
}
