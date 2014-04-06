#ifndef CARD_H
#define CARD_H

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
