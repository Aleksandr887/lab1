#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Number of args for shapes
const int CircleArgs = 3;

typedef struct {
    double x;
    double y;
    double r;
} Circles;

void max_len_amount_lines(int* amount, int* maxlen)
{
    FILE* f = fopen("input.txt", "r");
    if (!f) {
        printf("File 'input.txt' is not found\n");
        exit(1);
    }
    char ch;
    int counter_lines = 1;
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
    fclose(f);
}

void check_shape(int maxlen)
{
    FILE* f = fopen("input.txt", "r");
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
    fclose(f);
}

int main()
{
    int amount, maxlen;
    max_len_amount_lines(&amount, &maxlen);
    check_shape(maxlen);
    FILE* f = fopen("input.txt", "r");
    if (!f) {
        printf("File 'input.txt' is not found\n");
        exit(1);
    }
    Circles c[amount];
    // Counter for feeling struct
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
                c[j].x = y;
                j++;
            } else if (i == 2)
                c[j].y = y;
            else {
                if (y == 0) {
                    printf("Error: circle cannot have radius <= 0\n");
                    exit(1);
                }
                c[j].r = y;
            }
            istr = strtok(NULL, sep);
            i++;
            schet_err++;
        }
    }
    // Comparing the number of entered args and max number of args
    if (schet_err < amount * CircleArgs) {
        printf("Error: invalid input format\n");
        exit(1);
    }
    // Data output
    for (i = 0; i < amount; i++) {
        printf("%d. Circle(%g %g, %g)\n", i + 1, c[i].x, c[i].y, c[i].r);
    }
    fclose(f);
    return 0;
}
