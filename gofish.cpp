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
int hand::check4ofakind(int face){
    cardnode* temp=head;
    int num=0;
    while(temp!=nullptr){
        if(face==temp->data.face)
            ++num;
        temp=temp->next;
    }
    if(num>=4){
        return 1;
    }
    return 0;
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
//
void deck::draw(sf::RenderWindow& window){
    sf::Texture back;
    back.loadFromFile("gray_back.png");
    sf::Sprite deckback(back);
    deckback.setPosition(100,342);
    deckback.setScale(0.078148f,0.080492f);
    window.draw(deckback);
    
}
void hand::draw(cardnode* ptr,sf::RenderWindow& window){
    static int i =1;
    if(ptr==nullptr||i>numbercards){
        i=1;
        return;
    }
    sf::Texture t;
    t.loadFromFile(ptr->data.filename);
    sf::Sprite carddisplay(t);
    carddisplay.setTexture(t);
    carddisplay.setScale(0.078148f,0.080492f);
    carddisplay.setPosition((i*54),(0));
    window.draw(carddisplay);
    ++i;
    ptr = ptr->next;
    draw(ptr,window);
}
void hand::draw(sf::RenderWindow& window){
    cardnode* temp = head;
    if(temp==nullptr){
        return;
    }
    sf::Texture t;
    t.loadFromFile(temp->data.filename);
    sf::Sprite carddisplay(t);
    carddisplay.setTexture(t);
    carddisplay.setScale(0.078148f,0.080492f);
    carddisplay.setPosition((0),(0));
    window.draw(carddisplay);
    temp = temp->next;
    draw(temp,window);
}
void hand::drawbacks(sf::RenderWindow& window){
    for(int i = 0; i<numbercards; i++){
    if(numbercards == 0){
        return;
    }
    sf::Texture t;
    t.loadFromFile("gray_back.png");
    sf::Sprite carddisplay(t);
    carddisplay.setScale(0.078148f,0.080492f);
    carddisplay.setPosition((1366-(1+i)*54),(683));
    window.draw(carddisplay);
    }
    

}

card deck::returnbyint(int n){
    int i=0;
    cardnode* ptr=head;
    while(i<n&&i<numbercards){
    ptr=ptr->next;
     ++i;   
    }
    return ptr->data;
}
//
void playerturn(hand& activehand,hand& passivehand,collected& activecollection,deck& Deck,sf::RenderWindow &window,int player){
    int cont=1;
    int hascard=0;
    sf::Vector2i mpos;
    sf::Text text;
    sf::Font font;
    sf::Texture felt;
    felt.loadFromFile("felttable.png");
    sf::RectangleShape board(sf::Vector2f(1366.f,768.f));
    board.setTexture(&felt);
    board.setPosition(0,0);
    sf::Event userinput;
    font.loadFromFile("Amatic-Bold.ttf");
    text.setFont(font);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Regular);
    text.setPosition(400,340);
    cout<<"Active Player\n";
    activehand.display();
    cout<<"Passive Player\n";
    passivehand.display();
    card temp;
    while(window.isOpen()){
        ///draw window, put in some text asking to choose a card
        if(cont==0){
            break;
        }
        window.draw(board);
        Deck.draw(window);
        activehand.draw(window);
        if(player==1){
            text.setString("Player 1's turn, choose a card...");
        }
        else
        {
            text.setString("Player 2's turn, choose a card...");
        }
        window.draw(text);
        passivehand.drawbacks(window);
        window.display();
        //display window
        while(window.pollEvent(userinput)){
            if(userinput.type==sf::Event::MouseButtonPressed){
                if(userinput.mouseButton.button==sf::Mouse::Left){
                    if(userinput.mouseButton.x>=0&&userinput.mouseButton.x<=(54*activehand.getnumcards())){
                        if(userinput.mouseButton.y>=0&&userinput.mouseButton.y<=(85)){
                            temp=activehand.returnbyint(mpos.x/54);
                            hascard=passivehand.searchface(temp.face);
                            cont=0;
                            //window.close();
                        }
                    }
                }
            }
        }
            //below is code to pick up inputs that we tried previously
            /*if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                mpos=sf::Mouse::getPosition();
                if(mpos.x>=0&&mpos.x<=(54)){
                    if(mpos.y>=0&&mpos.y<=(85*activehand.getnumcards())){
                        temp=activehand.returnbyint(mpos.x/54);
                        hascard=passivehand.searchface(temp.face);
                        window.close();
                    }
                }
            }*/
    }
    if(hascard==0){
        //print and display gofish
        window.clear();
        window.display();
        window.draw(board);
        text.setString("Go Fish!");//draw objects
        window.draw(text);
        Deck.draw(window);
        activehand.draw(window);
        passivehand.drawbacks(window);
        window.display();//display
        pause();//pause
        activehand.push(Deck.pop());//add card to hand
        text.setString("Go Fish!");//draw&display&pause
        window.draw(text);
        Deck.draw(window);
        activehand.draw(window);
        passivehand.drawbacks(window);
        window.display();
        pause();
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