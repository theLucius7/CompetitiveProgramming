#include <stdio.h>
#include <stdlib.h>

int A[110];
char c[100];

int main() {

	fgets(c, 100, stdin);

	printf("%d\n", sizeof(c));

	for (int i = 0; i < 20; i++) {
		printf("%c", c[i]);
	}

	return 0;
}