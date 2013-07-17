/**
 * Haar-like feature implementation.
 *
 * @blackball
 */

#ifndef HAAR_H
#define HAAR_H

/*
  A Haar feature <-> 
 */

enum {
        HAAR_LR_WB       = 0,
        HAAR_TB_BW       = 1,
        HAAR_LMR_WBW     = 2,
        HAAR_TLRBLR_WBBW = 3,
};

#define HAAR_SIZE_NUM_MAX    16
#define HAAR_PATTERN_NUM_MAX 8

struct HaarPattern {
        int haar;

        int nscale; /* how many scales of this pattern */
        struct {
                int w,h;
                int hstep; 
                int vstep; /* sliding step for haar window, vertically */
        } sizes[HAAR_SIZE_NUM_MAX];
};

struct Haars {
        /* haar feature patterns */
        /* min size and max size of every pattern */
        int size;
        struct HaarPattern paterns[HAAR_PATTERN_NUM_MAX];
};

struct Haars * Haars_New();

void Haars_Free(struct Haars **h);

int Haars_Append(struct Haars *h, const struct HaarPattern *p);

/**
 * get the length of haar feature vector.
 *
 * @h haars configuration structure
 * @rw the specified rectangle width
 * @rh the specified rectangle width
 * return the length or -1 for error
 */
int Haars_Len(const struct Haars *h, int rw, int rh);


int Haars_Extract(const struct Haars *h, int *vec, int len,
                  const int *iimg, int rx, int ry, int rw, int rh);

#endif 
