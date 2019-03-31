#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
void print_hand(deck_t * hand){
  //Loop thorugh the length of the hand  
  for(int i = 0; i < hand->n_cards; i++){  
    //Print the card at index i
    print_card(***hand.cards+i);
  }
}

int deck_contains(deck_t * d, card_t c) {
  //Loop through the length of the deck
  for(int i = 0; i < d->n_cards; i++){
    //Check if the card is equal to the check for card
    if(***d.cards+i == c) return 1;
  }
  return 0;
}

void shuffle(deck_t * d){
  //Save the cards addresses in a new array of cards
  card_t * cards[d->n_cards] = *d.cards;
  //Loop through the length of the cards and assign them to a random position in the deck
  for(int i = 0; i < d->n_cards; i++){
    //Assign card addresses to a random position in the original deck
    *d->cards[rand()%52] = cards[i];
  }
}

void assert_full_deck(deck_t * d) {
  //Loop through the 52 cards
  for(int i = 0; i < 52; i++){
    //Create each card for index i
    card_t card = card_from_num(i);
    //Check whether the deck does not contain the card
    if(deck_contains(d, card == 0){
	printf("ERROR: Card %s is not in the deck.", card);
      exit(EXIT_FAILURE);
    }
}
