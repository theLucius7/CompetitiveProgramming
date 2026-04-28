#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E8;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::map<int, bool> map;
	
	int cnt = 0;
	for( ; !map[N]; ) {
		map[N] = true;
		cnt++;
		int nN = 0;
		while (N) {
			nN += (N % 10) * (N % 10);
			N /= 10;
		}
		if (nN == 1) {
			std::cout << "Yes\n";
			return 0;
		}
		N = nN;
	}
	std::cout << "No\n";

	return 0;
}