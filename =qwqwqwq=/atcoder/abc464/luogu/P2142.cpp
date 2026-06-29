#include <bits/stdc++.h>

const std::vector<int> to_vec(const std::string &s) {
	std::vector<int> res;
	for (auto x : s) {
		res.push_back(x - '0');
	}
	return res;
}

const bool operator<(const std::vector<int> &A, const std::vector<int> &B) {
	if (A.size() != B.size()) {
		return A.size() < B.size();
	}

	for (int i = 0; i < A.size(); i++) {
		if (A[i] != B[i]) {
			return A[i] < B[i];
		}
	}

	return false;
}

const bool operator>(const std::vector<int> &A, const std::vector<int> &B) {
    return B < A;
}

const std::vector<int> operator-(const std::vector<int> &A, const std::vector<int> &B) {
	std::vector<int> res;
	int borrow = 0;
	for (int i = 0; i < A.size(); i++) {
		int digitA = A[A.size() - 1 - i], digitB = (i < B.size()) ? B[B.size() - 1 - i] : 0;
		int diff = digitA - digitB - borrow;
		if (diff < 0) {
			diff += 10;
			borrow = 1;
		} else {
			borrow = 0;
		}
		res.insert(res.begin(), diff);
	}
	while (res.size() > 1 && res[0] == 0) {
		res.erase(res.begin());
	}
	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string a, b;
	std::cin >> a >> b;

	std::vector<int> res;
	if (to_vec(a) < to_vec(b)) {
		std::cout << "-";
		res = to_vec(b) - to_vec(a);
	} else {
		res = to_vec(a) - to_vec(b);
	}

	for (int x : res) {
		std::cout << x;
	}
	std::cout << "\n";

	return 0;
}