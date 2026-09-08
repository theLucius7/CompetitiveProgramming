#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

constexpr int N = 1010;

bool st[N];
int primes[N], cnt;

void get_primes (int n) {
	for (int i = 2; i <= n; i ++ ) {
		if (!st[i]) {
			primes[cnt ++ ] = i;
		}
		for (int j = 0; primes[j] <= n / i; j ++ ) {
			st[primes[j] * i] = true;
			if (i % primes[j] == 0) {
				break;
			}
		} 
	} 
}

void solve () {
	int n, m;
	cin >> n >> m;
	
	get_primes (n);
	
	for (int i = 0; i < cnt; i ++ ) {
		for (int j = 0; j + 1 < i; j ++ ) {
			if (primes[i] == primes[j] + primes[j + 1] + 1) {
				m -- ;
			}
		}
	} 
		
	if (m <= 0) {
		cout << "YES\n";
	} else {
		cout << "NO\n";	
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solve (); 
	
	return 0;
}