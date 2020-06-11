#include "gofish.h"

deck::deck(){
    head=nullptr;
    numbercards=0;
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
    collected();
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
        getline(output,newdata.filename,',');
        getline(output,temp);
        istringstream(temp)>>newdata.face;
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