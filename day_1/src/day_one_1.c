#include <stdio.h>

#define STB_DS_IMPLEMENTATION
#include "stb_ds.h"

typedef struct {
    char dir;
    int value;
} Entry;

int read_input(Entry **entries)
{
    FILE *f = fopen("../input.txt", "r");
    if(!f) {
        perror("Could not open file");
        return 1;
    }

    char dir;
    int value;

    while(fscanf(f, " %c%d", &dir, &value) == 2) {
        Entry e = {dir, value};
        arrput(*entries, e);
    }

    fclose(f);
    return 0;
}

int main(void)
{
    Entry *entries = NULL;

    read_input(&entries);

    int start_value = 50;
    int counter = 0;
    for (int i = 0; i < hmlen(entries); ++i) {
        if(entries[i].dir == 'R') {
            start_value += entries[i].value;
            if(start_value > 99) {
                start_value = (start_value % 99)-1;
            }
            if(start_value == 0) {
                counter += 1;
            }
            printf("value: %d\n", start_value);
        }
        if(entries[i].dir == 'L') {
            start_value -= entries[i].value;
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
