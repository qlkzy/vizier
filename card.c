#include "card.h"

#include "util.h"

#include <string.h>

static const char *names[CARD_COUNT] = {
    "Invalid",
    "Soldier",
    "Clown",
    "Knight",
    "Priestess",
    "Wizard",
    "General",
    "Minister",
    "Princess"
};

static const int number_in_deck[CARD_COUNT] = {
    0,                          /* invalid */
    5,                          /* soldier */
    2,                          /* clown */
    2,                          /* knight */
    2,                          /* priestess */
    2,                          /* wizard */
    1,                          /* general */
    1,                          /* minister */
    1,                          /* princess */
};

Card card_intern(char *s)
{
    for (Card c = CARD_INVALID; c < CARD_COUNT; c++)
        if (istreq(names[c], s))
            return c;
    return CARD_INVALID;
}

const char *card_name(Card c)
{
    ASSERT_CARD_BOUNDS(c);
    return names[c];
}

int card_number_in_deck(Card c)
{
    ASSERT_CARD_BOUNDS(c);
    return number_in_deck[c];
}
