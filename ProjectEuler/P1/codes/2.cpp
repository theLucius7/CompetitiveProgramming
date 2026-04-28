#include <bits/stdc++.h>

using i64 = long long;

int n = 999;

int SumDivisibleBy (int x) {
	int p = n / x;
	return x * p * (p + 1) / 2;
}

void solve () {
	std::cout << SumDivisibleBy (3) + SumDivisibleBy (5) - SumDivisibleBy (15) << "\n";
}

int main () {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve ();

	return 0;
}