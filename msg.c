#include "msg.h"

#include "card.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include "util.h"

#include <stdlib.h>

#define REQUIRE_ARGC(min)                       \
    require_argc(__FUNCTION__, __FILE__, __LINE__, argc, min);

static void require_argc(const char *function, const char *file,
                         int line, int argc, int min);

static int begun = 0;
static int our_turn = 0;
static Player our_number;

void msg_begin(int argc, char *argv[])
{
    UNUSED(argc);
    UNUSED(argv);
    begun = 1;
}

void msg_discard(int argc, char *argv[])
{
    REQUIRE_ARGC(2);

    Card c = card_intern(argv[1]);

    if (c == CARD_INVALID)
        ERROR("Invalid card name '%s'", argv[1]);

    deck_expend(c);
}

void msg_draw(int argc, char *argv[])
{
    REQUIRE_ARGC(2);

    Card c = card_intern(argv[1]);

    if (c == CARD_INVALID)
        ERROR("Invaild card name '%s'", argv[1]);

    hand_insert(c);

    if (begun && our_turn) {
        /* take turn */
        our_turn = 0;
    }
}

void msg_ident(int argc, char *argv[])
{
    REQUIRE_ARGC(2);
    our_number = atoi(argv[1]);
}

void msg_out(int argc, char *argv[])
{
    REQUIRE_ARGC(3);

    Player p = atoi(argv[1]);
    Card c = card_intern(argv[2]);

    player_has_card(p, CARD_INVALID);
    deck_expend(c);
}

void msg_played(int argc, char *argv[])
{
    REQUIRE_ARGC(3);

    Player p = atoi(argv[1]);
    Card c = card_intern(argv[2]);

    if (c == CARD_INVALID)
        ERROR("Invalid card name '%s'", argv[2]);

    deck_expend(c);


    /* don't keep track of card counts for our player */
    if (p == our_number)
        return;

    player_played_card(p, c);

    if (c == CARD_PRIESTESS)
        player_protected(p);
}

void msg_player(int argc, char *argv[])
{
    REQUIRE_ARGC(2);

    Player curr_number = atoi(argv[1]);

    our_turn = (curr_number == our_number);
}

void msg_protected(int argc, char *argv[])
{
    REQUIRE_ARGC(2);

    Player p = atoi(argv[1]);

    player_protected(p);
}

void msg_reveal(int argc, char *argv[])
{
    REQUIRE_ARGC(3);

    Player p = atoi(argv[1]);
    Card c = card_intern(argv[2]);

    player_has_card(p, c);
}

void msg_swap(int argc, char *argv[])
{
    REQUIRE_ARGC(2);

    Card c = card_intern(argv[1]);

    /* for now, just swap with the first card in our hand */
    hand_remove(hand_at(0));

    hand_insert(c);
}

static void require_argc(const char *function, const char *file,
                         int line, int argc, int min)
{
    if (argc < min) {
        fprintf(stderr,
                "%s:%d: error in %s: "
                "argc needs to be at least %d, but its value is %d\n",
                file, line, function, min, argc);
        abort();
    }
}
