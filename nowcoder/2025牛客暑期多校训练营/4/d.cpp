#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t N;
    cin >> N;

    // 预处理 Fibonacci 数列直到大于 N
    vector<int64_t> fib = {0, 1}; // fib[1] = 1 is F(1)
    while (fib.back() < N) {
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
    }

    int n = -1;
    for (int i = 1; i < fib.size(); ++i) {
        if (fib[i] == N) {
            n = i;
            break;
        }
    }

    if (n == -1) {
        // 如果不是 Fibonacci 数，可以使用其他构造方式（见后续补充）
        cout << "No solution found.\n";
        return 0;
    }

    // 输出矩阵大小
    cout << n << '\n';

    // 构造 Fibonacci 矩阵
    for (int i = 0; i < n; ++i) {
        vector<int> row(n, 0);
        if (i == 0) {
            row[0] = 1;
        } else {
            row[i] = 1;
            row[i - 1] = 1;
        }
        for (int j = 0; j < n; ++j) {
            cout << row[j] << " \n"[j == n - 1];
        }
    }

    return 0;
}
