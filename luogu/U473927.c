#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int N;

void hanoi(int n, int from, int to, int tran) {
	if (n == 1) {
		char c = from + 'A', z = to + 'A';
		printf("%c -> %c\n", c, z);
		return;
	}

	hanoi(n - 1, from, tran, to);

	char c = from + 'A', z = to + 'A';
	printf("%c -> %c\n", c, z);

	hanoi(n - 1, tran, to, from);
}

int main() {
	scanf("%d", &N);
	hanoi(N, 0, 2, 1);

	return 0;
}