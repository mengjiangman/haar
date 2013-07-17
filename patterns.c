/**
 * Implementation of haar pattern extractor.
 *
 * @blackball 
 */


#define _PF_ARGS \
        const int *iimg, int x, int y, int w, int h, int *hvec, int pw, int ph, int vs, int hs

typedef int (* _patternfunc)( _PF_ARGS );

static _patternfunc _patternfuncs[HAAR_PATTERN_NUM_MAX] = {
        _haar_lr_wb, // 0
        _haar_tb_bw,
        _haar_lmr_wbw,
        _haar_tlrblr_wbbw,
        NULL,
        NULL,
        NULL,
        NULL,
};

static inline int
_haar_lr_wb( _PF_ARGS ) {

        return 0;
}

static inline int
_haar_tb_bw( _PF_ARGS ) {

        return 0;
}

static inline int
_haar_lmr_wbw( _PF_ARGS ) {

        return 0;
}

static inline int
_haar_tlrblr_wbbw( _PF_ARGS ) {

        return 0;
}


#undef _PF_ARGS

        
