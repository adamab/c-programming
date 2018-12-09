#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(c.value >= 2 & c.value <= 14);
  assert(c.suit >= 0 & c.suit <= 3);

}

const char * ranking_to_string(hand_ranking_t r) {
  switc(r){
  case STRAIGHT_FLUSH:
    return "STRAIGHT FLUSH";
  case FOUR_OF_A_KIND:
    return "FOUR OF A KIND";
  case FULL_HOUSE:
    return "FULL HOUSE";
  case FLUSH:
    return "FLUSH";
  case STRAIGHT:
    return "STRAIGHT";
  case THREE_OF_A_KIND:
    return "THREE OF A KIND";
  case TWO_PAIR:
    return "TWO PAIR";
  case PAIR:
    return "PAIR";
  case NOTHING:
    return "NOTHING";
  
return "";
}

char value_letter(card_t c) {
  return 'x';
}


char suit_letter(card_t c) {
  return 'x';
  
}

void print_card(card_t c) {

}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  return temp;
}
