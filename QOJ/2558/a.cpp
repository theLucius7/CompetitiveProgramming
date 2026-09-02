#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i ++ ) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int mx = 0, mn = 0;
    for (int i = 0; i < n; i ++ ) {
        if (mx >= a[i]) {
            mx ++ ;
        } else {
            mx -- ;
        }
    }
    for (int i = n - 1; i >= 0; i -- ) {
        if (mn < a[i]) {
            mn -- ;
        } else {
            mn ++ ;
        }
    }
    cout << mx << " " << mn << endl;


	return 0;
}