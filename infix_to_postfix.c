#include <stdio.h>
#include <ctype.h>

char s[100];
int top = -1;

int p(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main() {
    char in[100], out[100], c;
    int i, j = 0;

    printf("Enter infix: ");
    scanf("%s", in);

    for (i = 0; in[i]; i++) {
        c = in[i];

        if (isalnum(c))
            out[j++] = c;
        else if (c == '(')
            s[++top] = c;
        else if (c == ')') {
            while (s[top] != '(')
                out[j++] = s[top--];
            top--;
        } else {
            while (top >= 0 && p(s[top]) >= p(c))
                out[j++] = s[top--];
            s[++top] = c;
        }
    }

    while (top >= 0)
        out[j++] = s[top--];

    out[j] = '\0';

    printf("Postfix: %s", out);
    return 0;
}

