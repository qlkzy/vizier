#ifndef HAND_H
#define HAND_H

#include "card.h"

void hand_insert(Card c);
void hand_remove(Card c);
unsigned int hand_count(void);
Card hand_at(int i);

#endif /* HAND_H */
