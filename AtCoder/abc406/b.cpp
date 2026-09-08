#include <stdio.h>
#include <stdlib.h>

int A[110];

int main() {
	int N, K;
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	int base = 1;
	for (int i = 0; i < K; i++) {
		base *= 10;
	}

	int cur = 1;
	for (int i = 0; i < N; i++) {
		cur *= A[i];
		if (cur > base) {
			cur = 1;
		}
	}

	printf("%d\n", cur);
	return 0;
}