#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
    std::cin >> N;

    std::list<int> list;
    list.push_front(0);
    std::vector<std::list<int>::iterator> it(N);
    it[0] = list.begin();
    for (int i = 1; i < N; i++) {
        int k, p;
        std::cin >> k >> p;
        k--;
        if (p == 0) {
            it[i] = list.insert(it[k], i);
        } else {
            it[i] = list.insert(std::next(it[k]), i);
        }
    }

    int M;
    std::cin >> M;

    std::vector<bool> erased(N);

    while (M--) {
        int x;
        std::cin >> x;
        x--;
        if (!erased[x]) {
            list.erase(it[x]);
            erased[x] = true;
        }
    }

    for (int x : list) {
        std::cout << x + 1 << " ";
    }

	return 0;
}