#ifndef DECK_H
#define DECK_H

#include "card.h"

int deck_remaining(Card c);
void deck_expend(Card c);

Card deck_average_remaining(void);

Card deck_best_remaining(void);

#endif /* DECK_H */
