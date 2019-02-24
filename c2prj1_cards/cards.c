#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert (c.value >= 2 && c.value <= VALUE_ACE);
  assert (c.suit <= 3 && c.suit >= 0);
}

const char * ranking_to_string(hand_ranking_t r) {
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
  case NOTHING:
    return "NOTHING";
  default:
    return "Unknow value";
      }
}

char value_letter(card_t c) {
  if (c.value >= 2 && c.value <= 9){
    return c.value + '0';
  }
  else if (c.value == 10){
    return '0';
  }
  else if (c.value == 11){
    return 'J';
  }
  else if (c.value == 12){
    return 'Q';
  }
  else if (c.value == 13){
    return 'K';
  }
  else if (c.value == 14){
    return 'A';
  }
  else {
    printf("Invalid card value");
    exit(EXIT_FAILURE);
  }
} 

char suit_letter(card_t c) {
  switch (c.suit){
  case SPADES:
    return 's';
  case HEARTS:
    return 'h';
  case DIAMONDS:
    return 'd';
  case CLUBS:
    return 'c';
  default:
    return 'e';
  }
}

void print_card(card_t c) {
  printf("%c%c",value_letter(c),suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  unsigned try = value_let - '0';
  if (try >= 2 && try <= 9){
    temp.value = try;
  }
  else if (value_let == '0'){
    temp.value = 10;
  }
  else if (value_let == 'J'){
    temp.value = 11;
  }
  else if (value_let == 'Q'){
    temp.value = 12;
  }
  else if (value_let == 'K'){
    temp.value = 13;
  }
  else if (value_let == 'A'){
    temp.value = 14;
  }
  else {
    printf("Input error");
    exit(EXIT_FAILURE);
      }

  if (suit_let == 's'){
    temp.suit = SPADES;
  }
  else if (suit_let == 'h'){
    temp.suit = HEARTS;
  }
  else if (suit_let == 'd'){
    temp.suit = DIAMONDS;
  }
  else if (suit_let == 'c'){
    temp.suit = CLUBS;
  }
  else{
    printf("Input error");
    exit(EXIT_FAILURE);
      }
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  if (c > 51){
    printf("Input error, input a number between 0-51 inclusive");
    exit(EXIT_FAILURE);
  }
  else{
    temp.suit = c/13;
    temp.value = 2+c%13;
  } 
  return temp;
}
