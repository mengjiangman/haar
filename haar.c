/**
 * Haar-like implementation in C
 *
 * @blackball 
 */

#include "debug.h"
#include "haar.h"
#include <stdlib.h>

struct Haars *
Haars_New() {
        struct Haars *h = (struct Haars *)malloc(sizeof(*h));

        ASSERT(h == NULL, "Create Haars failed!");

        h->size = 0;

        return h;
}

void
Haars_Free(struct Haars **h) {
        if (h) {
                free( *h );
                *h = NULL;
        }
}


int
Haars_Append(struct Haars *h, const struct HaarPattern *p) {
        if (!(h->size < HAAR_PATTERN_NUM_MAX)) {
                return -1;
        }
        
        /* copy p to hp */
        h->patterns[h->size] = *p;

        h->size++;

        return 0;
}

int
Haars_Len(const struct Haars *h, int rw, int rh) {
        int len = 0;
        
        /*
        for each patten:
            len += <len of pattern: rw, rh>
        */
        for (int i = 0; i < h->size; ++h) {
                for (int j = 0; j < h->patterns[i].nscale; ++j) {
                        len += (vstep, hstep, w, h);
                }
        }
        
        return len;        
}

#include "patterns.c"

int
Haars_Extract(const struct Haars *h, int *vec, int len,
              const int *iimg, int rx, int ry, int rw, int rh) {
        /* @TODO safe check */
        int len = 0;
        int *pvec = vec;
        
        for (int i = 0; i < h->size; ++i) {
                const struct HaarPattern *hp = h->patterns[i];
                for (int j = 0; j < hp->nscale; ++j) {
                        _patternfunc *pfunc = _patternfuncs[ hp->haar ];
                        if ( pfunc != NULL ) {
                                len = pfunc(iimg, rx, ry, rw, rh, pvec, hp->sizes[j].w, hp->sizes[j].h, hp->sizes[j].vstep, hp->sizes[j].hstep);
                                ASSERT(len == -1, "error happened when extract haar pattern!");
                                pvec += len;
                        }
                }
        }
}
