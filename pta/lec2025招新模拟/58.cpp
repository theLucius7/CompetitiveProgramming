#include <bits/stdc++.h>

using i64 = long long;

struct Person {
    std::string na, bi, ph;
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<Person> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i].na >> p[i].bi >> p[i].ph;
    }  

    std::sort(p.begin(), p.end(), [](Person &a, Person &b) {
        return a.bi < b.bi;
    });

    for (int i = 0; i < n; i++) {
        std::cout << p[i].na << " " << p[i].bi << " " << p[i].ph << "\n";
    }

    return 0;
}