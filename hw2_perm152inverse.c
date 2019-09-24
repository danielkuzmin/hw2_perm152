#include <stdio.h>
#include <string.h>
#include <stdint.h>

static uint32_t rotr(uint32_t x, unsigned int i) {
    return (x >> i) | (x << (32-i));
}

static void r_update(uint32_t *w, uint32_t *x, uint32_t *y, uint32_t *z) {
//    *w = *w + *x; *z = *z ^ *w; *z = rotl(*z, 16);
//    *y = *y + *z; *x = *x ^ *y; *x = rotl(*x, 12);
//    *w = *w + *x; *z = *z ^ *w; *z = rotl(*z, 8);
//    *y = *y + *z; *x = *x ^ *y; *x = rotl(*x, 7);

    *x = rotr(*x, 7); *x = *x ^ *y; *y = *y - *z;
    *z = rotr(*z, 8); *z = *z ^ *w; *w = *w - *x;
    *x = rotr(*x, 12); *x = *x ^ *y; *y = *y - *z;
    *z = rotr(*z, 16); *z = *z ^ *w; *w = *w - *x;
}

void perm152inverse(unsigned char *in, unsigned char *out) {
    printf("perminversecalled\n");
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

    printf("---REVERSE---\n");

    for (int i = 0; i < 64; i++)
    {
        printf("%x \n", out[i]);
    }
}