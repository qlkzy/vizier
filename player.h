#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"

#define MAX_PLAYER_ID 5

typedef unsigned int Player;

void player_has_card(Player player, Card c);

void player_card_unknown(Player player, Card c);

void player_played_card(Player player, Card c);

Card player_estimated_card(Player player);

Player player_with_best_card(void);

#endif /* PLAYER_H */
