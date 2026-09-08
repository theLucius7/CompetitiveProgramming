#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

constexpr int N = 13;

string m[N] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void solve () {
	string s;
	cin >> s;

	int n;
	for (int i = 1; i <= 12; i ++ ) {
		if (s == m[i]) {
			n = i;
		}
	}

	int k;
	cin >> k;

	cout << m[(n + k - 1) % 12 + 1] << "\n";
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	solve ();

	return 0;
}