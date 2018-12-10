#include "cards.h"

int main(void) {
  hand_ranking_t r1=0;//Straight Flush
  hand_ranking_t r2=3;//Flush
  hand_ranking_t r3=9;//Nothing

  ranking_to_string(r1);//Straight Flush
  ranking_to_string(r2);//Flush
  ranking_to_string(r3);//Nothing

  card_t c1;
  card_t c2;
  card_t c3;
  c1.value=15;//Invalid value
  c1.suit=1;//Valid suit
  c2.value=11;//Valid value
  c2.suit=6;//Invalid suit
  c3.value=4;//Valid value
  c3.suit=0;//Valid suit
  
  assert_card_valid(c1);//Error
  assert_card_valid(c2);//Error
  assert_card_valid(c3);//No error

  value_letter(c1);//Error
  value_letter(c2);//Error
  value_letter(c3);//J

  suit_letter(c1);//Error
  suit_letter(c2);//Error
  suit_letter(c3);//s

  print_card(c1);//Error
  print_card(c2);//Error
  print_card(c3);//Js

  c1=card_from_num(37);
  c2=card_from_num(52);
  c2=card_from_letters('k','d');
  c3=card_from_letters('h','s');
  c3=card_from_letters('0','e');
  c3=card_from_letters('0','c');
}
