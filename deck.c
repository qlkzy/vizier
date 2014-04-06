#include "deck.h"

#include "util.h"

static int expended[CARD_COUNT];

int deck_remaining(Card c)
{
    if (c >= CARD_COUNT)
        ERROR("Tried to find the number of invalid card %d remaining", c);

    return card_number_in_deck(c) - expended[c];
}

void deck_expend(Card c)
{
    if (c >= CARD_COUNT)
        ERROR("Tried to find the number of invalid card %d remaining", c);

    expended[c]++;
}
