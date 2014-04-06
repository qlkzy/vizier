#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <stdlib.h>

#define NELEM(x) (sizeof(x) / sizeof((x)[0]))
#define SENTINEL(x) (&(x)[NELEM(x)])

#define ERROR(...)                                                      \
    do {                                                                \
        fprintf(stderr, "%s:%d: error in %s: ", __FILE__, __LINE__, __FUNCTION__);   \
        fprintf(stderr, __VA_ARGS__);                                   \
        fprintf(stderr, "\n");                                          \
        abort();                                                        \
    } while (0)

#define UNUSED(x) ((void)(x))

#endif /* UTIL_H */
