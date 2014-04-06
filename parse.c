#include "parse.h"

#include "util.h"

#include <string.h>

int parse(char *argv_out[], int n_argv, char *buf, int n_buf)
{
    const char *delim = " \n\t";
    int argc = 0;

    fgets(buf, n_buf, stdin);

    argv_out[argc++] = strtok(buf, delim);

    /* argc was optimistically incremented above; if the line was
     * empty, that was wrong, so jump out */
    if (argv_out[0] == NULL)
        return 0;

    while ((argv_out[argc++] = strtok(NULL, delim)) != NULL)
        if (argc == n_argv)
            ERROR("Command contained too many arguments (%d)\n", argc);

    /* the above loop will count the final NULL in argc, so we need to
     * walk it back */
    argc--;

    return argc;
}
