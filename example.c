/**
 * unit test of Haar exractor
 */
#include "debug.h"
#include "haar.h"
#include "integral.h"

static void
test(const unsigned char *data, int w, int ws, int h) {
        /* @TODO safe check */

        int errc = 0;
        
        int *iimg = (int *)malloc(sizeof(int) * w * h);

        ASSERT(iimg == NULL, "can not create integral image!");
        
        errc = integral(data, w, ws, h, iiimg);

        ASSERT(errc != 0, "error happened in integral()!");

        struct Haars *haars = Haars_New();

        /* add one haar pattern into haars */
        struct HaarPattern pattern;

        pattern.haar = HAAR_LR_WB;
        pattern.nscale = 8;
        
        for (int i = 0; i < 8; ++i) {
                pattern.sizes[i].w = 8 * (i + 1);
                pattern.sizes[i].h = 8 * (i + 1);
                pattern.sizes[i].hstep = 4 * (i + 1);
                pattern.sizes[i].vstep = 4 * (i + 1);
        }

        errc = Haars_Append(haars, &pattern);

        ASSERT(errc != 0, "append new pattern failed!\n");

        /* perform haar extraction */

        int len = Haars_Len(haars, w, h);

        int *hvec = (int *)malloc(sizeof(*hvec) * len);

        ASSERT( hvec == NULL, "create haar feature vector failed!");

        errc = Haars_Extract(h, hvec, len, iimg, 0, 0, w, h);

        ASSERT(errc != 0, "extract haar feature failed!");

        free(iimg);
        free(hvec);
        Haars_Free(&haars);

        return ;
}

int main(int argc, char *argv[]) {
        
        return 0;
}
