#include <stdbool.h>
#include <stdio.h>
#include <string.h>

char codes[][5] = {".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",
                   "....", "..",   ".---", "-.-",  ".-..", "--",   "-.",
                   "---",  ".--.", "--.-", ".-.",  "...",  "-",    "..-",
                   "...-", ".--",  "-..-", "-.--", "--.."};

char buf[5];
char find()
{
    for (char c = 'A'; c <= 'Z'; ++c) {
        if (!strcmp(codes[c - 'A'], buf)) {
            return c;
        }
    }
    return '\0';
}

int main(void)
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        printf("Case %d: ", i);
        for (int j = 0; j < 5; ++j) {
            scanf("%s", buf);
            putchar(find());
        }
        putchar('\n');
    }
}
