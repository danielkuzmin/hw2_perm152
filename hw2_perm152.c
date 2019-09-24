#include <stdio.h>
#include <string.h>
#include <stdint.h>

static uint32_t rotl(uint32_t x, unsigned int i) {
    return (x << i) | (x >> (32-i));
}

static void update(uint32_t *w, uint32_t *x, uint32_t *y, uint32_t *z) {
    printf("update started %d %d %d %d\n" , *w, *x, *y, *z );
    *w = *w + *x; *z = *z ^ *w; *z = rotl(*z, 16);
    *y = *y + *z; *x = *x ^ *y; *x = rotl(*x, 12);
    *w = *w + *x; *z = *z ^ *w; *z = rotl(*z, 8);
    *y = *y + *z; *x = *x ^ *y; *x = rotl(*x, 7);
    printf("update completed %d %d %d %d\n" , *w, *x, *y, *z );
}

void perm152(unsigned char *in, unsigned char *out) {
    printf("perm152 incoming values \n");
    for(int i = 0; i < 16; i++) {
        printf("%d\n", in[i]);
    }
    printf("end of perm152 incoming values \n");

    uint32_t a[16];

    memcpy(a, in, 16);
    printf("input values after memcpy\n");
    for(int i = 0; i < 16; i++) {
        printf("%d\n", a[i]);
    }
    printf("end of input values after memcpy\n\n");
    update(&a[0], &a[4], &a[8], &a[12]);
    update(&a[1], &a[5], &a[9], &a[13]);
    update(&a[2], &a[6], &a[10], &a[14]);
    update(&a[3], &a[7], &a[11], &a[15]);
    update(&a[0], &a[5], &a[10], &a[15]);
    update(&a[1], &a[6], &a[11], &a[12]);
    update(&a[2], &a[7], &a[8], &a[13]);
    update(&a[3], &a[4], &a[9], &a[14]);
    memcpy (out, a, 64);

    for (int i = 0; i < 16; i++) {
        printf("%d \n", a[i]);
    }

    printf("---Printing out array---\n");

    for (int i = 0; i < 16; i++) {
        printf("%d \n", out[i]);
    }
}