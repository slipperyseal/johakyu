
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define RANGE_X 256
#define RANGE_Y 64

#define HALF_X (RANGE_X/2)
#define HALF_Y (RANGE_Y/2)

#define PI  3.14159265359

// generates the source code for a sine table which we can use in johakyu

int main(int argc, char **argv) {
    uint8_t table[RANGE_X/2];

    double rr = PI / 2.0;
    int t=0;
    for (double r=0.0; r<rr; r += (rr/HALF_X)) {
        uint8_t value = (int)(sin(r) * HALF_Y);
        //printf("%d, ",value);
        table[t++] = value;
    }
    printf("    ");

    int l=0;
    for (int x=0;x<HALF_X;x++) {
        printf("%d, ", HALF_Y - table[HALF_X-x-1]);
        if ((l++ & 0x0f) == 0x0f) {
            printf("\n    ");
        }
    }
    for (int x=0;x<HALF_X;x++) {
        printf("%d, ", HALF_Y + table[x]);
        if ((l++ & 0x0f) == 0x0f) {
            printf("\n    ");
        }
    }
    printf("\n");
}

