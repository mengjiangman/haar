/**
 * Integral image calculation.
 *
 * @blackball
 */

#ifndef INTEGRAL_H
#define INTEGRAL_H

/**
 * image integral 
 * @src src image data, should be grayscale
 * @w number of pixel in a row
 * @ws number of bytes in a row
 * @h number of row
 * @dst used to store integral image data, size must = (w, h)
 * return 0 for success, else -1
 */
int integral(const unsigned char *src, int w, int ws, int h, unsigned int *dst);

#endif 
