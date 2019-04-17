#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  //Assert the value is between 2 and 14
  //  assert((c.value >= 2) & (c.value <= 14));
  //Assert the suit value is between 0 and 3
  assert((c.suit >= 0) & (c.suit <= 3));

}

const char * ranking_to_string(hand_ranking_t r) {
  //Use switch case to return the char for hand ranking
  switch (r){
  case STRAIGHT_FLUSH:
    return "STRAIGHT_FLUSH";
  case FOUR_OF_A_KIND:
    return "FOUR_OF_A_KIND";
  case FULL_HOUSE:
    return "FULL_HOUSE";
  case FLUSH:
    return "FLUSH";
  case STRAIGHT:
    return "STRAIGHT";
  case THREE_OF_A_KIND:
    return "THREE_OF_A_KIND";
  case TWO_PAIR:
    return "TWO_PAIR";
  case PAIR:
    return "PAIR";
  default:
    return "NOTHING";
  }
}

char value_letter(card_t c) {
  //Check for a valid card
  assert_card_valid(c);
  //Instantiate temp variable
  //Determine if it is one of the single characters to use decimal char
  if (c.value < 10) {
    return (char) ('0' + c.value);
  } else {
    //If it is not a single digit, then use switch case to return the proper char
    switch(c.value){
    case 10:
      return (char) '0';
    case 11:
      return (char) 'J';
    case 12:
      return (char) 'Q';
    case 13:
      return (char) 'K' ;
    case 14:
      return (char) 'A';
    default:
      return 'x';
    }
  }
}


char suit_letter(card_t c) {
  //Check for a valid card
  assert_card_valid(c);
  //Use switch case to return the char for the suit
  switch (c.suit){
  case SPADES:
    return (char) 's';
  case HEARTS:
    return (char) 'h';
  case DIAMONDS:
    return (char) 'd';
  case CLUBS:
    return (char) 'c';
  default:
    return 'x';
  }
}

void print_card(card_t c) {
  //Store value in temp variable
  char value_temp = value_letter(c);
  //Store suit in temp variable
  char suit_temp = suit_letter(c);
  //Print card using appropriate values
  printf("%c%c", value_temp, suit_temp);
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  //Use switch case to set the proper suit value
  switch (suit_let){
  case 's':
    temp.suit=0;
    break;
  case 'h':
    temp.suit=1;
    break;
  case 'd':
    temp.suit=2;
    break;
  case 'c':
    temp.suit=3;
    break;
  default:
    temp.suit=5;
    break;
  }
  //Use switch case to set the proper value
  switch(value_let){
  case (int) '2':
    temp.value=2;
    break;
  case (int) '3':
    temp.value=3;
    break;
  case (int) '4':
    temp.value=4;
    break;
  case (int) '5':
    temp.value=5;
    break;
  case (int) '6':
    temp.value=6;
    break;
  case (int) '7':
    temp.value=7;
    break;
  case (int) '8':
    temp.value=8;
    break;
  case (int) '9':
    temp.value=9;
    break;
  case (int) '0':
    temp.value=10;
    break;
  case (int) 'J':
    temp.value=11;
    break;
  case (int) 'Q':
    temp.value=12;
    break;
  case (int) 'K':
    temp.value=13;
    break;
  case (int) 'A':
    temp.value=14;
    break;
  default:
    temp.value=15;
    break;
  }
  //Check for valid card
  assert_card_valid(temp);
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  //set suit value as number mod 4
  temp.suit = c%4;
  //Set value as number mod 13 plus 2
  temp.value = ((c%13) + 2);
  return temp;
}
