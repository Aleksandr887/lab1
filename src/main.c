#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int amount, maxlen;
    FILE* f = fopen("bin/input.txt", "r");
    if (!f) {
        printf("File 'input.txt' is not found\n");
        exit(1);
    }
    max_len_amount_lines(f, &amount, &maxlen);
    check_shape(f, maxlen);
    Circles c[amount];
    parser(maxlen, amount, f, c);
    PrintCircle(amount, c);
    fclose(f);
    return 0;
}
