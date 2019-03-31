#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"


int check_list(int * list, int length, int newInt){
  for(int i = 0; i < length; i ++){
    if(list[i] == newInt) return 1;
  }
  return 0;
}

void print_hand(deck_t * hand){
  //Loop thorugh the length of the hand  
  for(int i = 0; i < hand->n_cards; i++){  
    //Print the card at index i
    print_card(*(*hand).cards[i]);
  }
}

int deck_contains(deck_t * d, card_t c) {
  //Loop through the length of the deck
  for(int i = 0; i < (*d).n_cards; i++){
    card_t card = *(*d).cards[i];
    //Check if the card is equal to the check for card
    if(value_letter(card) == value_letter(c) && suit_letter(card) == suit_letter(c)) return 1;
  }
  return 0;
}

void shuffle(deck_t * d){
  //Save the cards addresses in a new array of cards
  //Create the array
  card_t * cards[(*d).n_cards];
  int positions[(*d).n_cards];
  int position = 0;
  int len = 0;
  //Loop through the cards
  for(int i = 0; i < (*d).n_cards; i++){
    //Assign the cards to the array
    cards[i] = (*d).cards[i];
  }
  //Loop through the length of the cards and assign them to a random position in the deck
  for(int j = 0; j < (*d).n_cards; j++){
    position = rand()%52;
    while(check_list(positions, len, position) == 1){
      position = rand()%52;
    }
    len +=1;
    positions[j] = position;
    //Assign card addresses to a random position in the original deck
    (*d).cards[position] = cards[j];
  }
}

void assert_full_deck(deck_t * d) {
  //Loop through the 52 cards
  for(int i = 0; i < 52; i++){
    //Create each card for index i
    card_t card = card_from_num(i);
    //Check whether the deck does not contain the card
    if(deck_contains(d, card) == 0){
      char suit = suit_letter(card);
      char val = value_letter(card);
      printf("ERROR: Card %c%c is not in the deck.", val, suit);
      exit(EXIT_FAILURE);
    }
  }
}
