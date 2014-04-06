#include "dispatch.h"

#include "msg.h"
#include "util.h"

#include <string.h>

typedef struct {
    const char *name;
    int (*fn)(int,char*[]);
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

int dispatch(int argc, char *argv[])
{
    /* ignore blank commands */
    if (argc == 0 || argv[0] == NULL)
        return 0;

    for (Namefun *nfp = handlers; nfp < SENTINEL(handlers); nfp++) {
        if (!strcmp(argv[0], nfp->name))
            return (nfp->fn)(argc, argv);
    }
    
    ERROR("Unknown command '%s'", argv[0]);
}
