#include "util.h"

#include <ctype.h>

int istreq(const char *s1, const char *s2)
{
    while (*s1 && *s2 && (tolower(*s1) == tolower(*s2)))
        s1++, s2++;

    if (*s1 || *s2)
        return 0;

    return 1;
}
