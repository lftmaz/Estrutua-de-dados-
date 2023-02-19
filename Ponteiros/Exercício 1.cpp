#include <stdio.h>

int main()
{
    int x, y, *p;
    y = 0;     // Y recebe 0,
    p = &y;    // Ponteiro aponta para o endereço de Y
    x = *p;    // Recebe o valor de Y, X = 0
    x = 4;     // X recebe 4
    (*p)++;    // Soma 1 no endereço do ponteiro Y = 1
    --x;       // Subtrai um de X, X = 3
    (*p) += x; // Soma o endereço do ponteiro + X, 1 + 3 = 4,X = 3 Y = 4  *p = 4
    printf("%d %d %p", x, y, p);
    return (0);
}