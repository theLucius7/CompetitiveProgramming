#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

long long N, A, B;
char S[500010];
long long cntA, cntB;
long long ans;

int main() {
	scanf("%lld %lld %lld", &N, &A, &B);
	scanf("%s", S);


	for (int i = 0, l = 0, r = 0; i < N; i++) {
		while (l < N && cntA < A) {
			cntA += (S[l] == 'a');
			l++;
		}
		while (r < N && cntB < B) {
			cntB += (S[r] == 'b');
			r++;
		}

		if (cntA == A) {
			if (cntB < B) {
				ans += (r - l + 1 > 0 ? r - l + 1 : 0);
			} else {
				ans += (r - l > 0 ? r - l : 0);
			}	
		}

		cntA -= (S[i] == 'a');
		cntB -= (S[i] == 'b');
	}

	printf("%lld\n", ans);

	return 0;
}