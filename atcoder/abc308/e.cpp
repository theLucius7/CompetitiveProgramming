#include <iostream>
#include <vector>

int mex(int a, int b, int c) {
    if (a != 0 && b != 0 && c != 0) {
        return 0;
    } else if (a != 1 && b != 1 && c != 1) {
        return 1;
    } else {
        return 2;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<char> S(N);

    for (int i = 0; i < N; i++) {
        std::cin >> S[i];
    }

    long long sum_mex = 0;

    for (int i = 0; i < N - 2; i++) {
        int j = i + 1;
        int k = i + 2;

        while (k < N) {
            if (S[i] == 'M' && S[j] == 'E' && S[k] == 'X') {
                sum_mex += mex(S[i], S[j], S[k]);
            }

            k++;

            if (k == N && j + 1 < N) {
                j++;
                k = j + 1;
            }
        }
    }

    std::cout << sum_mex << "\n";

    return 0;
}
