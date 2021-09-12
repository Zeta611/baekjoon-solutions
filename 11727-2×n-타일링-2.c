#include <stdio.h>
#define MODULUS 10007

int main(void)
{
    int n;
    scanf("%d", &n);
    int fi = 1;
    int fj = 1;
    while (n--) {
        const int tmp = fi;
        fi = (fi + 2 * fj) % MODULUS;
        fj = tmp;
    }
    printf("%d\n", fj);
}
