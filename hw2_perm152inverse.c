/*
 Daniel Kuzmin
 Class code: 1618
 September 24 2019
 Brief Description:
 This file contains the code for part B of the second assignment.
 A program to decrypt an array of 64 bits given the algorithm from the assignment.
 from the assignment.
 Tested on Athena, compiled like so:
 clang -g -O0 -std=c99 -Werror -Wall -Wextra -Wconversion -fsanitize=address hw2_perm152inverse.c
*/

#include <stdio.h>
#include <string.h>
#include <stdint.h>

// This function takes a uint32_t and unsigned int i and rotates it right by i bits
static uint32_t rotr(uint32_t x, unsigned int i) {
    return (x >> i) | (x << (32-i));
}

// The de-mixing function
static void r_update(uint32_t *w, uint32_t *x, uint32_t *y, uint32_t *z) {
    *x = rotr(*x, 7); *x = *x ^ *y; *y = *y - *z;
    *z = rotr(*z, 8); *z = *z ^ *w; *w = *w - *x;
    *x = rotr(*x, 12); *x = *x ^ *y; *y = *y - *z;
    *z = rotr(*z, 16); *z = *z ^ *w; *w = *w - *x;
}

// Takes a pointer to an array in, copies it to a temp array, modifies it, then writes to out
void perm152inverse(unsigned char *in, unsigned char *out) {
    uint32_t a[16];
    memcpy(a, in, 64);

    r_update(&a[3], &a[4], &a[9], &a[14]);
    r_update(&a[2], &a[7], &a[8], &a[13]);
    r_update(&a[1], &a[6], &a[11], &a[12]);
    r_update(&a[0], &a[5], &a[10], &a[15]);
    r_update(&a[3], &a[7], &a[11], &a[15]);
    r_update(&a[2], &a[6], &a[10], &a[14]);
    r_update(&a[1], &a[5], &a[9], &a[13]);
    r_update(&a[0], &a[4], &a[8], &a[12]);
    memcpy(out, a, 64);

}