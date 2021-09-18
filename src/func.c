#include "func.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void max_len_amount_lines(FILE* f, int* amount, int* maxlen)
{
    if (!f) {
        printf("File 'input.txt' is not found\n");
        exit(1);
    }
    char ch;
    int counter_lines = 0;
    int max = -1;
    int i = 0;
    while (1) {
        ch = fgetc(f);
        if ((ch == '\n') || (ch == EOF)) {
            if (max < i)
                max = i;
            i = 0;
            if (ch == EOF)
                break;
            counter_lines++;
        } else
            i++;
    }
    *amount = counter_lines;
    *maxlen = max;
    fseek(f, 0, SEEK_SET);
}

void check_shape(FILE* f, int maxlen)
{
    if (!f) {
        printf("File 'input.txt' is not found\n");
        exit(1);
    }
    char string[maxlen];
    char str[maxlen];
    int i;
    while (fgets(string, maxlen + 2, f) != NULL) {
        memset(str, 0, maxlen);
        for (i = 0; i < maxlen; i++) {
            if (string[i] == '(')
                break;
            else {
                str[i] = string[i];
            }
        }
        if (strcmp(str, "Circle") != 0) {
            printf("Error: unknown shape '%s'\n", str);
            exit(1);
        }
    }
    fseek(f, 0, SEEK_SET);
}

void parser(int maxlen, int amount, FILE* f, Circles* c)
{
    // Counter for filling struct
    int i = 1;
    // Counter args
    int schet_err = 0;
    // Counter for array of structs
    int j = 0;
    char* end = 0;
    double y = 0;
    char sep[15] = "Circle(),\n  ";
    char string[maxlen];
    char* istr;
    while (fgets(string, maxlen + 2, f) != NULL) {
        i = 1;
        istr = strtok(string, sep);
        while (istr != NULL) {
            y = strtod(istr, &end);
            if (strlen(end) != 0) {
                printf("Error: invalid input format\n");
                exit(1);
            }
            if (i == 3) {
                if (y == 0) {
                    printf("Error: circle cannot have radius <= 0\n");
                    exit(1);
                }
                c[j].r = y;
                j++;
            } else if (i == 2)
                c[j].y = y;
            else
                c[j].x = y;
            istr = strtok(NULL, sep);
            i++;
            schet_err++;
        }
    }
    // Comparing the number of entered args and max number of args
    if (schet_err != amount * 3) {
        printf("Error: invalid input format\n");
        exit(1);
    }
}

void PrintCircle(int amount, Circles* c)
{
    int i;
    for (i = 0; i < amount; i++) {
        printf("%d. Circle(%g %g, %g)\n", i + 1, c[i].x, c[i].y, c[i].r);
        printf("\tPerimeter = %g\n\tArea = %g\n",
               2 * 3.1415 * c[i].r,
               3.1415 * c[i].r * c[i].r);
        intersects(amount, i, c);
    }
}

void intersects(int amount, int i, Circles* c)
{
    int j;
    printf("\tIntersects:\n");
    for (j = 0; j < amount; j++) {
        if (i != j) {
            if ((abs(sqrt(pow(c[i].x - c[j].x, 2) + pow(c[i].y - c[j].y, 2))))
                <= (c[i].r + c[j].r)) {
                printf("\t  %d. circle\n", j + 1);
            }
        }
    }
}

int quest() 
{
    //you find it) 
    //follow the link to youtube
    //https://youtu.be/yNad1J1IpLc
    return 0;
}
