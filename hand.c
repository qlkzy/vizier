#include "hand.h"

#include "util.h"

#define HAND_MAX 8

static Card hand[HAND_MAX];

void hand_insert(Card c)
{
    for (Card *pc = hand; pc < SENTINEL(hand); pc++) {
        if (!*pc) {
            *pc = c;
            return;
        }
    }
    
    ERROR("Tried to insert card %d into hand, but it was full with %lu cards",
          c, NELEM(hand));
}

void hand_remove(Card c)
{
    for (Card *pc = hand; pc < SENTINEL(hand); pc++) {
        if (*pc == c) {
            *pc = CARD_INVALID;
            return;
        }
    }
    
    ERROR("Tried to remove card %d from hand, but it was not present", c); 
}

unsigned int hand_count(void)
{
    unsigned int i = 0;

    for (Card *pc = hand; pc < SENTINEL(hand); pc++)
        if (*pc) i++;

    return i;
}

Card hand_at(unsigned int i)
{
    for (Card *pc = hand; pc < SENTINEL(hand); pc++) {
        if (*pc) {
            if (--i == 0)
                return *pc;
        }
    }
    
    ERROR("Tried to access element %d of hand, "
          "which is out of range (max %u)", i , hand_count() - 1);
}

