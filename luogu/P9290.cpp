#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
    	std::cin >> a[i];
    }

    std::vector<int> qMax, qMin;
    std::vector<int> rMax(n, n), rMin(n, n);
    for (int i = n - 1; i >= 0; i--) {
    	while (!qMax.empty() && a[i] > a[qMax.back()]) {
    		qMax.pop_back();
    	}
    	if (!qMax.empty()) {
    		rMax[i] = qMax.back();
    	}
    	qMax.push_back(i);

    	while (!qMin.empty() && a[i] <= a[qMin.back()]) {
    		qMin.pop_back();
    	}
    	if (!qMin.empty()) {
    		rMin[i] = qMin.back();
    	}
    	qMin.push_back(i);
    }

    int cnt = 0;
    for (int x = 0; x < n; ) {
    	int nx = x;
    	while (rMax[nx] != n && rMax[nx] < rMin[x]) {
    		nx = rMax[nx];
    	}
    	x = nx + 1;
    	cnt++;
    }
    std::cout << cnt << "\n";


	return 0;
}