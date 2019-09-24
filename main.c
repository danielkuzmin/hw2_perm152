#include <stdio.h>
#include <stdint.h>
#include "hw2_perm152.c"
#include "hw2_perm152inverse.c"

int main() {
    unsigned char a[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};;// = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
/*    a[0] = 0x03020100;
    a[1] = 0x07060504;
    a[2] = 0x0b0a0908;
    a[3] = 0x0f0e0d0c;
    a[4] = 0x13121110;
    a[5] = 0x17161514;
    a[6] = 0x1b1a1918;
    a[7] = 0x1f1e1d1c;

    a[8] = 0x23222120;
    a[9] = 0x27262524;
    a[10] = 0x2b2a2928;
    a[11] = 0x2f2e2d2c;
    a[12] = 0x33323130;
    a[13] = 0x37363534;
    a[14] = 0x3b3a3938;
    a[15] = 0x3f3e3d3c;
*/

    uint32_t b[64];
    printf("input values\n");
    for(int i = 0; i < 16; i++) {
        printf("%d\n", a[i]);
    }
    printf("end of input values\n\n");

    perm152((unsigned char *) a, (unsigned char *) b);
    unsigned char c[64];
    perm152inverse((unsigned char *)b, c);

    return 0;
}