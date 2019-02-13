#include <iostream>
#include <cstdlib>

using namespace std;

/* Prototypes */
void shuffle(int cards[]);
void printCard(int id);
int cardValue(int id);
void printHand(int hand[], int numCards);
int getBestScore(int hand[], int numCards);



/**
 * Global arrays to be used as look-up tables, if desired.
 *
 */
const char suit[4] = {'H','S','D','C'};
const char* type[13] = 
  {"2","3","4","5","6","7",
   "8","9","10","J","Q","K","A"};
const int value[13] = {2,3,4,5,6,7,8,9,10,10,10,10,11};

/**
 * Should permute the deck of cards, effectively shuffling it.
 * You must use the Fisher-Yates / Durstenfeld shuffle algorithm
 *  
 */
void shuffle(int cards[])
{
  /******** You complete ****************/
  int N = 52;
  
    for(int i = N-1; i >= 1; i--){
      int j = rand() % (i + 1);  //(i.e. use a modulus operation on the random number)
      int temp = cards[i];
      cards[i] = cards[j];
      cards[j] = temp;
  }
}
/**
 * Prints the card in a "pretty" format:   "type-suit"
 *  Examples:  K-C  (King of clubs), 2-H (2 of hearts)
 *  Valid Types are: 2,3,4,5,6,7,8,9,10,J,Q,K,A
 *  Valid Suits are: H, D, C, S
 */

void printCard(int id)
{
  //maybe put this in main

cout << type [id % 13] << "-"<< suit [id / 13];  // Type comes first then suit!

}


/**
 * Returns the numeric value of the card.
 *  
 *  
 */
int cardValue(int id)
{
  
   return value [id% 13];     // only one line of code

}

/**
 * Should print out each card in the hand separated by a space and
 * then print a newline at the end.  
 * Should use printCard() to print out each card.
 */
void printHand(int hand[], int numCards)
{
 for (int i= 0; i < numCards; i ++){
  printCard(hand[i]);
  cout << " ";
   } // how many cards within a hand? 

}


/**
 * Should return the total score of the provided hand.  
 * 
 *  
 */
int getBestScore(int hand[], int numCards)
{

      // call the shuffle function here or in for loop?
int total_score=0;

int aces = 0;
for (int i = 0; i < numCards; i ++) {// for loop for player

int current_cardv;
  current_cardv = cardValue(hand[i]);
  total_score += current_cardv;
  if (cardValue(hand[i]) == 11){
    aces++;
  }
   // loop through the cards, get value of each card and add that to score of the hand 
   //use THAT to check if that is an ACE! 
      // adding to printHand
  } // go through cards to check if there is an ace 

while (aces > 0 && total_score > 21 ){
  total_score -= 10; 
  aces--;
}

return total_score;
//total -= ((total-22)/10+1)*10? 


}

/**
 * Main program logic for the game of 21
 */
int main(int argc, char* argv[])
{

//shuffle (int cards);

 


  if(argc < 2){
    cout << "Error - Please provide the seed value." << endl;
    return 1;
  }
  int seed = atoi(argv[1]);
  srand(seed);

  int cards[52];
  int dhand[9];
  int phand[9];

  /******** You complete ****************/
char response;
response = 'y';
while (response == 'y'){
  for (int i = 0; i < 52; i++){
    cards[i] = i;
  } 

  shuffle(cards);

int size_deck = 0;
int dealer_size = 0;
int player_size = 0;
 
phand[ player_size++] = cards[size_deck++];
dhand[ dealer_size++ ] = cards[size_deck++];

phand[ player_size++] = cards[size_deck++];
dhand[ dealer_size++ ] = cards[size_deck++];

cout << "Dealer: ? ";
for (int i= 1; i < dealer_size; i ++){
  printCard(dhand[i]);
  cout << " ";
   }
cout << endl;

cout << "Player: ";
printHand(phand,player_size);
cout << endl;
while ( getBestScore(phand, player_size) < 21) {

cout << "Type 'h' to hit and 's' to stay: " << endl;
char ans;
cin >> ans;
if (ans == 'h'){
  phand[ player_size++] = cards[size_deck++];
  cout << "Player: ";
printHand(phand,player_size);
cout << endl;
}
else if( ans == 's'){
 // while (getBestScore(dhand, dealer_size) < 17){
 //  dhand[ dealer_size++ ] = cards[size_deck++];
 // }
  break;
}
}



if( getBestScore(phand,player_size) <= 21){
  while (getBestScore(dhand, dealer_size) < 17){
   dhand[ dealer_size++ ] = cards[size_deck++];
  }
}
if (getBestScore(phand, player_size) > 21){
  cout << "Player busts" << endl << "Lose" << " "<< getBestScore(phand, player_size) << " " << getBestScore(dhand, dealer_size) << endl;
}
else if (getBestScore(dhand, dealer_size) > 21) {
  cout << "Dealer busts" << endl << "Win" << " "<< getBestScore(phand, player_size) << " " << getBestScore(dhand, dealer_size) << endl;
}
else if (getBestScore(phand, player_size) > getBestScore(dhand, dealer_size) ) {
  cout << "Win" <<" " << getBestScore(phand, player_size) << " " << getBestScore(dhand, dealer_size) << endl;
}
else if (getBestScore(phand, player_size) < getBestScore(dhand, dealer_size ) ){
  cout << "Lose" << " " << getBestScore(phand, player_size) << " " << getBestScore(dhand, dealer_size) << endl;
}
else{
  cout << "Tie" << " " << getBestScore(phand, player_size) << " " << getBestScore(dhand, dealer_size) << endl;
}


cout << "do you want to play again?"; //game has ended 
cin >> response;
}

  return 0;

}