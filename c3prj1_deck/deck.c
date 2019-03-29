#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
void print_hand(deck_t * hand){
  for (int i = 0; i < hand->n_cards; i++) {
    print_card(*(hand->cards[i]));
    putchar(' ');
  }
}

int deck_contains(deck_t * d, card_t c) {
  for (int i = 0; i < d->n_cards; i++) {
    if ((d->cards[i]->value == c.value) && ((d->cards[i])->suit == c.suit)) {
      return 1;
    }
  }
  return 0;
}

void shuffle(deck_t * d){
  for (int i = 0; i < d->n_cards; i++) {
    int rand_i = i + rand()%(d->n_cards-i);
    card_t * temp = d->cards[i];
    d->cards[i] = d->cards[rand_i];
    d->cards[rand_i] = temp;
  }
}

void assert_full_deck(deck_t * d) {
  assert(d->n_cards == 52);
  printf("deck has 52 cards. \n");
  
  for (unsigned i = 0; i < d->n_cards; i++){
    assert(deck_contains(d, card_from_num(i)) == 1);
  }
  printf("Decks has 52 different cards!");
}
