#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    int Q;
    std::cin >> Q;

    std::vector<int> t(Q), x(Q);
    std::vector<char> c(Q);
    int flag = 0, last = -1;
    for (int i = 0; i < Q; i++) {
        std::cin >> t[i] >> x[i] >> c[i];
        x[i]--;

        if (t[i] == 2) {
            flag = 1;//low
            last = i;
        } else if (t[i] == 3) {
            flag = -1;//up
            last = i;
        }
    }

    for (int i = 0; i < Q; i++) {
        if (i == last) {
            if (flag == 1) {
                for (int j = 0; j < N; j++) {
                    S[j] = std::tolower(S[j]);
                }
            } else if (flag == -1) {
                for (int j = 0; j < N; j++) {
                    S[j] = std::toupper(S[j]);
                }
            }
        }

        if (t[i] == 1) {
            S[x[i]] = c[i];
        }
    }
    std::cout << S << "\n";

    return 0;
}
