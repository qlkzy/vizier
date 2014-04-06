#include "player.h"

#include "deck.h"
#include "util.h"

static Card player_cards[MAX_PLAYER_ID];
static int protected[MAX_PLAYER_ID];


#define ASSERT_PLAYER_BOUNDS(player)                                    \
    do {                                                                \
        ASSERT(player > 0,                                              \
               "Player '%s' must be positive but was %d",               \
               #player, (player));                                      \
        ASSERT(player < NELEM(player_cards),                            \
               "Player '%s' must be less than %lu but was %d",          \
               #player, NELEM(player_cards), (player));                 \
    } while (0)

void player_has_card(Player player, Card c)
{
    ASSERT_PLAYER_BOUNDS(player);
    ASSERT_CARD_BOUNDS(c);
    player_cards[player] = c;
}

void player_card_unknown(Player player, Card c)
{
    ASSERT_PLAYER_BOUNDS(player);
    ASSERT_CARD_BOUNDS(c);
    player_cards[player] = deck_average_remaining();
}

void player_played_card(Player player, Card c)
{
    ASSERT_PLAYER_BOUNDS(player);
    ASSERT_CARD_BOUNDS(c);
    /* assume that the held card was as good as the played card */
    player_cards[player] = c;
}

Card player_estimated_card(Player player)
{
    ASSERT_PLAYER_BOUNDS(player);
    return player_cards[player];
}

void player_protected(Player player)
{
    ASSERT_PLAYER_BOUNDS(player);
    protected[player] = 1;
}

int player_is_protected(Player player)
{
    ASSERT_PLAYER_BOUNDS(player);
    return protected[player];
}

Player player_with_best_card(void)
{
    Card best = CARD_INVALID;
    Player best_player;
    for (Player p = 0; p < NELEM(player_cards); p++) {
        if (player_estimated_card(p) > best) {
            best = player_estimated_card(p);
            best_player = p;
        }
    }
    return best_player;
}

Player player_with_best_card_unprotected(void)
{
    Card best = CARD_INVALID;
    Player best_player;
    for (Player p = 0; p < NELEM(player_cards); p++) {
        if (!player_is_protected(p) && player_estimated_card(p) > best) {
            best = player_estimated_card(p);
            best_player = p;
        }
    }
    return best_player;
}
