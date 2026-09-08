#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL n, a, b, c;
LL x;
LL da, db, dc;

LL gcd(LL a, LL b)
{
    return b ? gcd(b, a % b) : a;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	
	cin >> n >> a >> b;
	c = gcd (a, b);
	c = a * b / c;

	x = (1 + n) * n / 2;

	LL ca = n / a, cb = n / b, cc = n / c;
	da = (1 + ca) * ca / 2;
	db = (1 + cb) * cb / 2;
	dc = (1 + cc) * cc / 2;

	x = x - (da * a) - (db * b) + (dc * c);

	cout << x << "\n";

	return 0;
}