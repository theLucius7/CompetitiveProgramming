#include <bits/stdc++.h>

using i128 = __int128;

std::ostream &operator<<(std::ostream &os, i128 n) {
    if (n == 0) {
        return os << 0;
    }
    std::string s;
    while (n > 0) {
        s += char('0' + n % 10);
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}

i128 mul(i128 a, i128 b, i128 p) {
    i128 c = a * b - i128(1.0L * a * b / p) * p;
    c %= p;
    if (c < 0) {
        c += p;
    }
    return c;
}

i128 power(i128 a, i128 b, i128 p) {
	if (a == 0 ) {
		return 1;
	}
	// 
    i128 res = 1;
    for (; b; b /= 2, a = mul(a, a, p)) {
        if (b % 2) {
            res = mul(res, a, p);
        }
    }
    return res;
}

int main() {

	for (int i = 0; i <= 11; i++) {
		if ((i ^ 6) % 7 == 1) {
			std::cout << i << "\n";
		}
	}

	// std::cout << (7 ^ 6) % 7 << "\n";
	
	// std::cout << power(7, 6, 7) << "\n";
}