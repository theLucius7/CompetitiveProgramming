#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T -- ) {
		int n;
		cin >> n;

		string s;
		cin >> s;

		LL cnt = 0;
		for (int i = 1; i < s.size (); i ++ ) {
			if (s[i - 1] == ')' && s[i] == '(') {
				cnt ++ ;
			}
		}

		cout << n - cnt << "\n";
	}

	return 0;
}