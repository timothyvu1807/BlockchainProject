// #ifndef CARD_H
// #define CARD_H

// #include <iostream>
// #include <stdlib.h>
// #include <time.h>
// using namespace std;

// // void run();

// class Card{
//       private:
//               char suit;
//       public:
//              int value;
//              Card();
//              void run();
//              void setCard();
//              void getCard();      
//              int getValue();
//              int getSuit();
//       };

// class Deck{
//       private:
//               Card cards[52];
//               int numDrawn;
//       public:
//              Deck();
//              void shuffle();
//              void draw();
//              bool cardInDeck(Card card, int index);
//       };

// Card::Card(){
//      srand(time(NULL));
//      value = rand() % 13;
//      suit = rand() % 4 + 1;           
// }

// void Card::setCard(){
//      value = rand() % 13;
//      suit = rand() % 4 + 1;            
// }

// void Card::getCard(){
//     int temp = value;
//      cout << " ----" << endl << "|    |" << endl << "| ";

//      if (value == 0) cout << 'A' << "  |" << endl << "|    |" << endl << " ----" << endl;
//      else if  (value ==9)
//      {
//        cout << value+1;
//        cout << " |" << endl << "|    |" << endl << " ----" << endl;
//      }
//      else if (value == 10) cout << 'J' << "  |" << endl << "|    |" << endl << " ----" <<endl;
//      else if (value == 11) cout << 'Q' << "  |" << endl << "|    |" << endl << " ----" <<endl;
//      else if (value == 12) cout << 'K' << "  |" << endl << "|    |" << endl << " ----" <<endl;
//      else cout<<value+1 << "  |" << endl << "|    |" << endl << " ----" <<endl;

//      if (suit == 1) cout<<(char)3;
//      else if (suit == 2) cout<<(char)4;
//      else if (suit == 3) cout<<(char)5;
//      else cout<<(char)6;
// }

// int Card::getSuit(){
//     return suit;
// }

// int Card::getValue(){
//     return value+1;
// }

// bool Deck::cardInDeck(Card card, int index){
//      bool match;
//      for(int i=0;i<=index;i++){
//              if((card.getValue() == cards[i].getValue()) && (card.getSuit() == cards[i].getSuit())){
//                   match = true;
//                   break;
//                   }
//              else match = false;
//      }
//      return match;
// }

// Deck::Deck(){
//      Card card;
//      bool match = false;
//      for (int i=0;i<47;i++){
//          do{
//             card.setCard();
//             match = cardInDeck(card, i);
//             }while(match == true);
//          match = false;
//          cards[i] = card;
//      }
//      numDrawn = 0;
// }

// void Deck::shuffle(){
//      Card card;
//      bool match = false;
//      for (int i=0;i<52;i++){
//          do{
//             card.setCard();
//             match = cardInDeck(card, i);
//             }while(match == true);
//          match = false;
//          cards[i] = card;
//      }
//      numDrawn = 0;        
// }

// void Deck::draw(){
//      cards[numDrawn].getCard();
//      numDrawn++;
// }

// void Card::run(){
//      Deck cards;
//      char choice;
//      int cardsDrawn = 0;
//      cout<<"Enter 's' to shuffle the deck, 'H' to Hit, or 'x' to exit:  ";
//      do{
//      cin>>choice;
//      switch(choice){
//                     case 'X':
//                     case 'x':break;
//                     case 'S':
//                     case 's':cards.shuffle();
//                              cout<<"Deck shuffled."<<endl;
//                              cardsDrawn = 0;
//                              break;
//                     case 'H':
//                     case 'h':if (cardsDrawn == 52){
//                                  cout<<"Out of cards. Deck reshuffled."<<endl;
//                                  cards.shuffle();
//                                  cardsDrawn = 0;
//                                  break;
//                              }
//                              else{
//                                  Card test;
//                                  int counter =0;
//                                   cards.draw();
//                                 //   int Hand[10];
//                                 //  if( value  == 10|| value  == 11|| value  == 12)
//                                 //  {
//                                 //      Hand[counter] = 10;
//                                 //  }else{
//                                 //      Hand[counter] = value;
//                                 //  }
//                                 //  int sum =0;
//                                 //  counter++;
//                                 //  for(int i =0; i<counter; i++)
//                                 //  {
//                                 //      sum = sum + Hand[counter];
//                                 //      cout << sum << endl;
//                                 //  }
//                                   cardsDrawn++;
//                                   break;
//                              }
//                     default: cout<<"Invalid entry.\a Enter a valid option('s','d','x'):  ";
//                     }
//      }while((choice != 'x') && (choice != 'X'));
// }

// #endif