#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int X, Y;
	scanf("%d %d", &X, &Y);

	int cnt = 0;
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 6; j++) {
			if ((i + j) >= X || abs(i - j) >= Y) {
				cnt++;
			}
		}
	}

	long double ans = 1.0 * cnt / 36;

	printf("%.12Lf\n", ans);

	return 0;
}