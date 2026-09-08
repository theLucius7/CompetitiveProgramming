#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int primes[N], cnt;
bool st[N];

void init (int n) {
	for (int i = 2; i <= n; i ++ ) {
		if (!st[i]) primes[cnt ++ ] = i;
		for (int j = 0; i * primes[j] <= n; j ++ ) {
			st[primes[j] * i] = true;
			if (i % primes[j] == 0) break;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	init (n + 1);
	
	if (n <= 2) cout << "1" << "\n";
	else cout << "2" << "\n";
	
	for (int i = 2; i <= n + 1; i ++ ) {
		if (!st[i]) cout << "1" << " ";
		else cout << "2" << " ";
	}
	
	cout << "\n";
	
	return 0;
}