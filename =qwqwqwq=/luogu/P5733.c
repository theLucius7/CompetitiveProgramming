#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

char c[110];

int main() {
    scanf("%s", c);

    for (int i = 0; i < strlen(c); i++) {
        if (islower(c[i])) {
            printf("%c", toupper(c[i]));
        } else {
            printf("%c", c[i]);
        }
    }
    
}
