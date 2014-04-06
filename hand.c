#include "hand.h"

#include "util.h"

static int card_counts[CARD_COUNT];

void hand_insert(Card c)
{
    ASSERT_CARD_BOUNDS(c);
    card_counts[c]++;
}

void hand_remove(Card c)
{
    ASSERT_CARD_BOUNDS(c);

    card_counts[c]--;

    if (card_counts[c] < 0)
        ERROR("Negative number of card %d (%s) in hand", c, card_name(c));
}

unsigned int hand_count(void)
{
    unsigned int i = 0;

    for (Card c = CARD_INVALID; c < NELEM(card_counts); c++)
        i += card_counts[c];

    return i;
}

Card hand_at(int i)
{
    for (Card c = CARD_INVALID; c < NELEM(card_counts); c++) {
        i -= card_counts[c];
        if (i < 0) return c;
    }
    
    ERROR("Tried to access element %d of hand, "
          "which is out of range (max %u)", i , hand_count() - 1);
}

