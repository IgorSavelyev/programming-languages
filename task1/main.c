#include <stdio.h>
#include <stdlib.h>

#define size_t ulong

int main(int argc, const char *argv[])
{
    typedef unsigned long ulong;

    size_t table_dim;
    scanf("%lu", &table_dim);

    ulong **table = (ulong **) malloc(sizeof(ulong *) * table_dim);

    for (size_t i = 0; i < table_dim; i++) {
        table[i] = (ulong *) malloc(sizeof(ulong) * table_dim);
    }

    for (size_t i = 0; i < table_dim; i++) {
        for (size_t j = 0; j < table_dim; j++) {
            table[i][j] = (i + 1) * (j + 1);
        }
    }

    size_t x1, x2, y1, y2;
    do {
        scanf("%lu%lu%lu%lu", &x1, &y1, &x2, &y2);

        if (x1) {
            for (size_t i = x1 - 1; i < x2; i++) {
                for (size_t j = y1 - 1; j < y2; j++) {
                    printf("%lu ", table[i][j]);
                }
                printf("\n");
            }
        }
    } while (x1 != 0);

    for (size_t i = 0; i < table_dim; i++) {
        free(table[i]);
    }

    free(table);

    return 0;
}
