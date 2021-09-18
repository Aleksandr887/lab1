#ifndef FUNC_H
#define FUNC_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    double x;
    double y;
    double r;
} Circles;

void max_len_amount_lines(FILE* f, int* amount, int* maxlen);
void check_shape(FILE* f, int maxlen);
void parser(int maxlen, int amount, FILE* f, Circles* c);
void PrintCircle(int amount, Circles* c);
void intersects(int amount, int i, Circles* c);
int quest();

#endif
