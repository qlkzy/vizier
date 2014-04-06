#ifndef CARD_H
#define CARD_H

#include "util.h"

#define ASSERT_CARD_BOUNDS(card)                                        \
    do {                                                                \
        ASSERT((card) < CARD_COUNT,                                     \
               "Card '%s' must be less than %d but was %d",             \
               #card, CARD_COUNT, (card));                              \
    } while (0)


typedef enum {
    CARD_INVALID,
    CARD_SOLDIER,
    CARD_CLOWN,
    CARD_KNIGHT,
    CARD_PRIESTESS,
    CARD_WIZARD,
    CARD_GENERAL,
    CARD_MINISTER,
    CARD_PRINCESS,
    CARD_COUNT
} Card;

Card card_intern(char *s);
const char *card_name(Card c);
int card_number_in_deck(Card c);

#endif /* CARD_H */
