#include "msg.h"

#include "card.h"
#include "deck.h"
#include "hand.h"
#include "util.h"

#include <stdlib.h>

#define REQUIRE_ARGC(min)                       \
    require_argc(__FUNCTION__, __FILE__, __LINE__, argc, min);

static void require_argc(const char *function, const char *file,
                         int line, int argc, int min);

static int our_turn = 0;
static int our_number;

int msg_begin(int argc, char *argv[])
{
    UNUSED(argc);
    UNUSED(argv);
    return 0;
}

int msg_discard(int argc, char *argv[])
{
    REQUIRE_ARGC(2);

    Card c = card_intern(argv[1]);
    
    if (c == CARD_INVALID)
        ERROR("Invalid card name '%s'", argv[1]);
    
    deck_expend(c);

    return 0;
}

int msg_draw(int argc, char *argv[])
{
    REQUIRE_ARGC(2);

    Card c = card_intern(argv[1]);

    if (c == CARD_INVALID)
        ERROR("Invaild card name '%s'", argv[1]);

    hand_insert(c);

    if (our_turn) {
        /* take turn */
        our_turn = 0;
    }

    return 0;
}

int msg_ident(int argc, char *argv[])
{
    REQUIRE_ARGC(2);
    our_number = atoi(argv[1]);
    return 0;
}

int msg_out(int argc, char *argv[])
{
    UNUSED(argc);
    UNUSED(argv);
    return 0;
}

int msg_played(int argc, char *argv[])
{
    REQUIRE_ARGC(3);

    Card c = card_intern(argv[2]);

    if (c == CARD_INVALID)
        ERROR("Invalid card name '%s'", argv[2]);

    deck_expend(c);

    return 0;
}

int msg_player(int argc, char *argv[])
{
    REQUIRE_ARGC(2);

    int curr_number = atoi(argv[1]);

    if (curr_number == our_number)
        our_turn = 1;

    return 0;
}

int msg_protected(int argc, char *argv[])
{
    UNUSED(argc);
    UNUSED(argv);
    return 0;
}

int msg_reveal(int argc, char *argv[])
{
    UNUSED(argc);
    UNUSED(argv);
    return 0;
}

int msg_swap(int argc, char *argv[])
{
    UNUSED(argc);
    UNUSED(argv);
    return 0;
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
