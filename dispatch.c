#include "dispatch.h"

#include "msg.h"
#include "util.h"

#include <string.h>

typedef struct {
    const char *name;
    void (*fn)(int,char*[]);
} Namefun;

static Namefun handlers[] = {
    {"begin",     msg_begin},
    {"discard",   msg_discard},
    {"draw",      msg_draw},
    {"ident",     msg_ident},
    {"out",       msg_out},
    {"played",    msg_played},
    {"player",    msg_player},
    {"protected", msg_protected},
    {"reveal",    msg_reveal},
    {"swap",      msg_swap},
};

void dispatch(int argc, char *argv[])
{
    /* ignore blank commands */
    if (argc == 0 || argv[0] == NULL)
        return;

    for (Namefun *nfp = handlers; nfp < SENTINEL(handlers); nfp++) {
        if (istreq(argv[0], nfp->name)) {
            (nfp->fn)(argc, argv);
            return;
        }
    }

    ERROR("Unknown command '%s'", argv[0]);
}
