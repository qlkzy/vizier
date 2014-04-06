#include "deck.h"

#include "util.h"

static int expended[CARD_COUNT];

int deck_remaining(Card c)
{
    ASSERT_CARD_BOUNDS(c);
    return card_number_in_deck(c) - expended[c];
}

void deck_expend(Card c)
{
    ASSERT_CARD_BOUNDS(c);
    expended[c]++;
}

Card deck_average_remaining(void)
{
    int ncards;
    int total;
    for (Card c = CARD_INVALID; c < CARD_COUNT; c++) {
        ncards += deck_remaining(c);
        total += c * deck_remaining(c);
    }
    return ncards/total;
}

Card deck_best_remaining(void)
{
    for (Card c = CARD_PRINCESS; c > CARD_INVALID; c--) {
        if (deck_remaining(c) > 0)
            return c;
    }
    return CARD_INVALID;
}
