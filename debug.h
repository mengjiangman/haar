/**
 * Simple debug utils for haar
 *
 * @blackball 
 */

#ifndef HAAR_DEBUG_H
#define HAAR_DEBUG_H

#if defined(NDEBUG)

#  define ASSERT(expr, msg)

#else

#  include <stdio.h>
#  include <stdlib.h>

static inline void
_assert(int b, const char *msg, const char *file, int line) {
        if (b) {
                fprintf(stderr, "%s at %d: %s\n", msg, file, line);
                exit( EXIT_FAILURE );
        }
}

#  define ASSERT(expr, msg) _assert( ((expr) ? 1 : 0), msg, __FILE__, __LINE)

#endif 

#endif 
