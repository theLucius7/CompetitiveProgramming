#include <bits/stdc++.h>

typedef long long ll;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	ll A, B;
	std::cin >> A >> B;

	std::cout << (A + B - 1) / B << "\n";

	return 0;
}