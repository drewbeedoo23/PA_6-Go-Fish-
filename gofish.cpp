#include "gofish.h"

deck::deck(){
    head=nullptr;
    numbercards=0;
}
card deck::pop(){
    cardnode* ptr=head;
    card temp=head->data;
    head=head->next;
    --numbercards;
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
    if(num==4){
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
        --numbercards;
        delete current;
        return storage;
    }
    while(current!=nullptr){
        if(current->data.face==face){
            storage=current->data;
            previous->next=current->next;
            cout<<"card removed\n";
            --numbercards;
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
void hand::draw(cardnode* ptr,sf::RenderWindow& window, int player){
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
    if(player==1)
        carddisplay.setPosition((i*54),(0));
    else
        carddisplay.setPosition((1366-(1+i)*54),(683));
    window.draw(carddisplay);
    ++i;
    ptr = ptr->next;
    draw(ptr,window,player);
}
void hand::draw(sf::RenderWindow& window,int player){
    cardnode* temp = head;
    if(temp==nullptr){
        return;
    }
    sf::Texture t;
    t.loadFromFile(temp->data.filename);
    sf::Sprite carddisplay(t);
    carddisplay.setTexture(t);
    carddisplay.setScale(0.078148f,0.080492f);
    if(player==1)
        carddisplay.setPosition((0),(0));
    else
        carddisplay.setPosition((1312),(683));
    window.draw(carddisplay);
    temp = temp->next;
    draw(temp,window,player);
}

void collected::draw(sf::RenderWindow&window, int player, cardnode*ptr){
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
    if(player==1){//activeplayer
    carddisplay.setPosition((54+i*54),(190));
    }
    else{
    carddisplay.setPosition((1258-i*54),(513));
    }
    window.draw(carddisplay);
    ++i;
    ptr = ptr->next;
    draw(window, player, ptr);

}
void collected::draw(sf::RenderWindow&window,int player){
    cardnode* temp = head;
    if(temp==nullptr){
        return;
    }
    sf::Texture t;
    t.loadFromFile(temp->data.filename);
    sf::Sprite carddisplay(t);
    carddisplay.setTexture(t);
    carddisplay.setScale(0.078148f,0.080492f);
    if(player==1){//activeplayer
    carddisplay.setPosition((54),(190));
    }
    else{
    carddisplay.setPosition((1258),(513));
    }
    window.draw(carddisplay);
    temp = temp->next;
    draw(window, player, temp);

}
void hand::drawbacks(sf::RenderWindow& window, int player){
    for(int i = 0; i<numbercards; i++){
    if(numbercards == 0){
        return;
    }
    sf::Texture t;
    t.loadFromFile("gray_back.png");
    sf::Sprite carddisplay(t);
    carddisplay.setScale(0.078148f,0.080492f);
    if(player==1)
    carddisplay.setPosition((1366-(1+i)*54),(683));
    else
    carddisplay.setPosition((0+(i)*54),(0));
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
void playerturn(hand& activehand,hand& passivehand,collected& activecollection,collected& passivecollection, deck& Deck,sf::RenderWindow &window,int player){
    int cont=1;
    int n =0;
    bool hascard=false;
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
        activehand.draw(window,player);
        if(player==1){
            text.setString("Player 1's turn, choose a card...");
        }
        else
        {
            text.setString("Player 2's turn, choose a card...");
        }
        window.draw(text);
        passivehand.drawbacks(window,player);
        activecollection.draw(window,player);
        passivecollection.draw(window,player-1);
        window.display();
        //display window
        while(window.pollEvent(userinput)){
            if(userinput.type==sf::Event::MouseButtonPressed){
                if(player==1){
                    if(userinput.mouseButton.button==sf::Mouse::Left){
                        if(userinput.mouseButton.x>=0&&userinput.mouseButton.x<=(54*activehand.getnumcards())){
                            if(userinput.mouseButton.y>=0&&userinput.mouseButton.y<=(85)){
                                n=userinput.mouseButton.x/54;
                                temp=activehand.returnbyint(n);
                                hascard=passivehand.searchface(temp.face);
                                cout<<endl<<n<<"  "<<temp.filename<<endl;
                                cont=0;
                                //window.close();
                            }
                        }
                    }
                }
                else{
                    if(userinput.mouseButton.button==sf::Mouse::Left){
                        if(userinput.mouseButton.x<=1366&&userinput.mouseButton.x>=(1366-54*activehand.getnumcards())){
                            if(userinput.mouseButton.y<=768&&userinput.mouseButton.y>=(683)){
                                n=(1366-userinput.mouseButton.x)/54;
                                temp=activehand.returnbyint(n);
                                hascard=passivehand.searchface(temp.face);
                                cout<<endl<<n<<"  "<<temp.filename<<endl;
                                cont=0;
                                //window.close();
                            }
                        }
                    }

                }
            }
        }
    }
    if(!hascard){
        //print and display gofish
        window.clear();
       if(!Deck.isEmpty()){
        text.setString("Go Fish! Press Enter to continue:");
        activehand.push(Deck.pop());
        }//add card to hand
        else{
        text.setString("Go Fish! The Deck is empty! Press Enter to continue:");
        }//draw&display&pause
        window.draw(board);
        window.draw(text);
        Deck.draw(window);
        passivehand.drawbacks(window,player);
        activehand.draw(window,player);
        activecollection.draw(window,player);
        passivecollection.draw(window,player-1);
        window.display();
    }
    else{
        //removing cards from passive hand and adding to active hand
        while(passivehand.searchface(temp.face)){//checks if they still have card
            activehand.push(passivehand.remove(temp.face));//passive player gives active player the card
        }
        text.setString("The other player had some! Press Enter to continue:");
        window.draw(board);
        window.draw(text);
        Deck.draw(window);
        passivehand.drawbacks(window,player);
        activehand.draw(window,player);
        activecollection.draw(window,player);
        passivecollection.draw(window,player-1);
        window.display();
        
    }
       for(int i=1;i<14;++i){
           if(activehand.check4ofakind(i)){
               cout<<"4ofkind dectected\n";
               activecollection.push(activehand.remove(i));//if player has 4 of a kind for face i, add it to collection
                while(activehand.searchface(i)){//while they still have cards of that facce, remove them
                activehand.remove(i);
                }
           }
        }
    cont=1;
    while(window.isOpen()){
        if(cont==0){
            break;
        }
        window.draw(board);
        window.draw(text);
        Deck.draw(window);
        passivehand.drawbacks(window,player);
        activehand.draw(window,player);
        activecollection.draw(window,player);
        passivecollection.draw(window,player-1);
        window.display();
        while(window.pollEvent(userinput)){
            if(userinput.type==sf::Event::KeyPressed){
                cout<<"Key Pressed\n";
                if(userinput.key.code==sf::Keyboard::Return){
                    cont=0;
                    cout<<"Enter Pressed\n";
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
void rules(sf::RenderWindow& window){
    sf::Texture ocean;
    ocean.loadFromFile("ocean.jpg");
    sf::RectangleShape board(sf::Vector2f(1366.f,768.f));
    board.setTexture(&ocean);
    board.setPosition(0,0);
    int cont=0;
    sf::Text text;
    sf::Event userinput;
    sf::Font font;
    font.loadFromFile("Amatic-Bold.ttf");
    text.setFont(font);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Regular);
    text.setPosition(250,240);
    text.setString("Each player takes turn guessing if the other player has a card they have.\n"
                    "To do this, the active player clicks on a card in their hand\n"
                    "If they do, they get that card. Otherwise they draw. At the end of each\n"
                    "turn any four of a kinds are placed on the table. The player to get the most\n"
                    "four of a kinds when the deck runs out, wins. Press Enter to return to main menu.");
    while(window.isOpen()){
        if(cont==1){
            break;
        }
        window.draw(board);
        window.draw(text);
        window.display();
            while(window.pollEvent(userinput)){
                if(userinput.type==sf::Event::KeyPressed){
                    if(userinput.key.code==sf::Keyboard::Return){
                        return;
                    }

                }
                    
            }

    }
}

void mainmenu(sf::RenderWindow& window){
    sf::Texture ocean;
    ocean.loadFromFile("ocean.jpg");
    sf::RectangleShape board(sf::Vector2f(1366.f,768.f));
    board.setTexture(&ocean);
    board.setPosition(0,0);
    int cont=1;
    sf::Text text;
    sf::Event userinput;
    sf::Font font;
    font.loadFromFile("Amatic-Bold.ttf");
    text.setFont(font);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Regular);
    text.setPosition(400,340);
    text.setString("1. Play\n2.Rules\n3.Exit");
    while(window.isOpen()){
        if(cont==0){
            break;
        }
        window.draw(board);
        window.draw(text);
        window.display();
            while(window.pollEvent(userinput)){
                if(userinput.type==sf::Event::KeyPressed){
                    switch(userinput.key.code){
                        case sf::Keyboard::Num1:
                            cont=0;
                            break;
                        case sf::Keyboard::Numpad1:
                            cont=0;
                            break;
                        case sf::Keyboard::Num2:
                            rules(window);
                            mainmenu(window);
                            break;
                        case sf::Keyboard::Numpad2:
                            rules(window);
                            mainmenu(window);
                            break;
                        case sf::Keyboard::Num3:
                            window.close();
                            break;
                        case sf::Keyboard::Numpad3:
                            window.close();
                            break;
                        
                    }
                }

        }
    }



}