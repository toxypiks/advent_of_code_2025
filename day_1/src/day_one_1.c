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

    int start_value = 50;
    int counter = 0;
    for (int i = 0; i < hmlen(rotations); ++i) {
        //printf("key: %d, value: %c\n", rotations[i].key, rotations[i].value);
        if(rotations[i].value == 'R') {
            start_value += rotations[i].key;
            if(start_value > 99) {
                start_value = (start_value%99)-1;
            }
            if(start_value == 0) {
                counter += 1;
            }
            printf("value: %d\n", start_value);
        }
        if(rotations[i].value == 'L') {
            start_value -= rotations[i].key;
            if(start_value < 0) {
                start_value = ((start_value % 99) + 99)+1;
            }
            if(start_value == 0) {
                counter += 1;
            }
            printf("value: %d\n", start_value);
        }
    }
    printf("zeros: %d\n", counter);
}
