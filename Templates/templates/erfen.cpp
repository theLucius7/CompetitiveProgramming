using i64 = long long;
using real = long double;

constexpr real eps = 1E-7;

auto get = [&](const auto &f) {
    real lo = -1E4, hi = 1E4;
    while (hi - lo > 3 * eps) {
        real x1 = (lo + hi - eps) / 2;
        real x2 = (lo + hi + eps) / 2;
        if (f(x1) > f(x2)) {
            lo = x1;
        } else {
            hi = x2;
        }
    }
    return f((lo + hi) / 2);
};

std::cout << get([&](real px) {
    return get([&](real py) {
        // write
    });
}) << "\n";



auto check = [&](double t) {
    // write
};

double lo = 0;
double hi = 1E12;
while (hi - lo > std::max(1.0, lo) * eps) {
    double x = (lo + hi) >> 1;
    if (check(x)) {
        hi = x;
    } else {
        lo = x;
    }
}



/**   二分算法（整数域）： 前驱
 *    2023-09-18: https://qoj.ac/submission/182628
**/
int lo = 1, hi = 1E9;
while (lo < hi) {
    int m = (lo + hi + 1) >> 1;
    if (check(m)) {
        lo = m;
    } else {
        hi = m - 1;
    }
}
std::cout << lo << "\n";

/**   二分算法（整数域）：后继
 *    2023-09-18: https://qoj.ac/submission/182752
**/
int lo = 1, hi = n;
while (lo < hi) {
    int m = (lo + hi) >> 1;
    if (check(m)) {
        hi = m;
    } else {
        lo = m + 1;
    }
}
std::cout << lo << "\n";
