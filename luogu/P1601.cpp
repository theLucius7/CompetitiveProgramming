#include <bits/stdc++.h>

const std::vector<int> to_vec(const std::string &s) {
	std::vector<int> res;
	for (auto x : s) {
		res.push_back(x - '0');
	}

	return res;
}

const std::vector<int> operator+(const std::vector<int> &A, const std::vector<int> &B) {
	std::vector<int> res;
	int carry = 0, backA = A.size() - 1, backB = B.size() - 1;

	while (backA >= 0 || backB >= 0 || carry) {
		if (backA >= 0) {
			carry += A[backA];
			backA--;
		}
		if (backB >= 0) {
			carry += B[backB];
			backB--;
		}
		res.insert(res.begin(), carry % 10);
		carry /= 10;
	}

	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string a, b;
	std::cin >> a >> b;

	std::vector<int> res = to_vec(a) + to_vec(b);
	for (int x : res) {
		std::cout << x;
	}
	std::cout << "\n";

	return 0;
}