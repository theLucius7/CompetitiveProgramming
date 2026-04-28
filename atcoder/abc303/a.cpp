#include <bits/stdc++.h>

int main () {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::string S, T;
	std::cin >> S >> T;

	for (int i = 0; i < N;i++) {
		if (S[i] == '0') S[i] = 'o';
		if (S[i] == '1') S[i] = 'l';
		if (T[i] == '0') T[i] = 'o';
		if (T[i] == '1') T[i] = 'l';
	}

	if (S == T) {
		std::cout << "Yes\n";
	} else {
		std::cout << "No\n";
	}

	return 0;
}