#include <stdio.h>

#define STB_DS_IMPLEMENTATION
#include "stb_ds.h"

struct {
    int key;
    char value;
} *rotations;

int main(void)
{
    printf("Hello from main\n");

    hmput(rotations, 68, 'L');
    hmput(rotations, 30, 'L');
    hmput(rotations, 48, 'R');
    hmput(rotations, 5, 'L');
    hmput(rotations, 60, 'R');
    hmput(rotations, 55, 'L');
    hmput(rotations, 1, 'L');
    hmput(rotations, 99, 'L');
    hmput(rotations, 14, 'R');
    hmput(rotations, 82, 'L');

    for (int i = 0; i < hmlen(rotations); ++i)
    {
        printf("key: %d, value: %c\n", rotations[i].key, rotations[i].value);
    }
}
