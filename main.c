#include "util.h"
#include "parse.h"
#include "dispatch.h"

static char linebuf[512];
static char *args[16];

int main()
{
    for (;;) {
        int argc = parse(args, NELEM(args), linebuf, NELEM(linebuf));
        dispatch(argc, args);
    }
    return 0;
}

