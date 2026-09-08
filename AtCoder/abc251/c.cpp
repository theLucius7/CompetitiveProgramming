#include <bits/stdc++.h>

using namespace std;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector <string> s(n);
	vector <int> t(n);
	for (int i = 0; i < n; i ++ ) {
		cin >> s[i] >> t[i];
	}

	int res = 0;
	set <string> st;
	for (int i = 0; i < n; i ++ ) {
		if (st.count (s[i]) == 0) {
			if (t[i] > t[res]) {
				res = i;
			}
			st.insert (s[i]);
		}
	}

	cout << res + 1 << "\n";
	return 0;
}