#include "play.h"

#include "deck.h"
#include "hand.h"
#include "player.h"

void play(void)
{
    Card to_discard = hand_at(0);
    const char *character = card_name(to_discard);


    switch (to_discard) {
    case CARD_INVALID:
        ERROR("trying to discard invalid card");
        break;
    case CARD_CLOWN:
    case CARD_GENERAL:
    case CARD_WIZARD: {
        Player target = player_with_best_card_unprotected();
        printf("play %s %d\n", character, target);
        break;
    }
    case CARD_KNIGHT: {
        Player target = player_with_worst_card_unprotected();
        printf("play %s %d\n", character, target);
        break;
    }
    case CARD_SOLDIER: {
        Card target_card = deck_best_remaining();
        Player target_player = player_with_best_card_unprotected();
        printf("play %s %d %s\n",
                character, target_player, card_name(target_card));
        break;
    }
    default:
        printf("play %s\n", character);
        break;
    }

    fflush(stdout);
}
