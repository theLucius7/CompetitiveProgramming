#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector <string> s(n), t(n);
	for (int i = 0; i < n; i ++ ) {
		cin >> s[i] >> t[i];
	}

	for (int i = 0; i < n; i ++ ) {
		bool nice = false;
		for (auto x : {s[i], t[i]}) {
			bool ok = true;
			for (int j = 0; j < n; j ++ ) {
				if (i != j && (x == s[j] || x == t[j])) {
					ok = false;
					break;
				}
			}
			if (ok) {
				nice = true;
			}
		}
		if (!nice) {
			cout << "No" << "\n";
			return 0;
		}
	}

	cout << "Yes" << "\n";

	return 0;
}