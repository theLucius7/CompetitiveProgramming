#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<double> dur(n);
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        int h = std::stoi(s.substr(0, 2));
        int m = std::stoi(s.substr(3, 2));
        int sec = std::stoi(s.substr(6, 2));
        dur[i] = h + m / 60.0 + sec / 3600.0;
    }
    
    int a, b, c, d;
    double t;
    std::cin >> a >> b >> c >> d >> t;
    
    // Sort durations
    std::sort(dur.begin(), dur.end());
    
    // We need to pick a videos at 0.75x, b at 1.25x, c at 1.5x, d at 2.0x
    // To minimize total time, assign fastest speeds to longest videos
    // speeds: 0.75x -> time = dur/0.75, 1.25x -> dur/1.25, 1.5x -> dur/1.5, 2.0x -> dur/2.0
    // To minimize total watch time, assign highest speed (2.0x) to longest videos
    // So sort durations ascending, assign speeds from slowest to fastest
    // speeds sorted ascending: 0.75, 1.25, 1.5, 2.0
    // counts: a, b, c, d
    // assign 0.75x to smallest a videos, 1.25x to next b, 1.5x to next c, 2.0x to largest d
    
    // But we need to pick exactly a+b+c+d videos from n videos
    // We want to minimize total time, so we should pick the shortest videos overall
    // and assign fastest speeds to longest among chosen
    
    // Total videos to watch: a+b+c+d
    int total = a + b + c + d;
    
    if (total > n) {
        // shouldn't happen per constraints
        std::cout << "No\n0.00\n";
        return;
    }
    
    // Pick the smallest 'total' videos
    // Then assign: 0.75x to smallest a, 1.25x to next b, 1.5x to next c, 2.0x to largest d
    // This minimizes total time
    
    double totalTime = 0.0;
    // dur is sorted ascending, pick first 'total'
    // assign speeds: first a get 0.75x (slowest), next b get 1.25x, next c get 1.5x, last d get 2.0x
    for (int i = 0; i < a; i++) totalTime += dur[i] / 0.75;
    for (int i = a; i < a + b; i++) totalTime += dur[i] / 1.25;
    for (int i = a + b; i < a + b + c; i++) totalTime += dur[i] / 1.5;
    for (int i = a + b + c; i < total; i++) totalTime += dur[i] / 2.0;
    
    if (totalTime <= t + 1e-9) {
        std::cout << "Yes\n";
        double rem = t - totalTime;
        std::cout << std::fixed << std::setprecision(2) << rem << "\n";
    } else {
        std::cout << "No\n";
        double over = totalTime - t;
        std::cout << std::fixed << std::setprecision(2) << over << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    solve();
    
    return 0;
}
