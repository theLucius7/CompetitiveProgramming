#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

struct Node {
	int l, r;
}a[N];

int n;

bool cmp1 (Node a, Node b) {
	return a.l * a.r < b.l * b.r;
}

vector <int> div (vector <int> &A, int b) {
	vector <int> C;
	int r = 0;
	for (int i = A.size () - 1; i >= 0; i -- ) {
		r = r * 10 + A[i];
		C.push_back (r / b);
		r %= b;
	}

	reverse (C.begin (), C.end ());

	while (C.size () > 1 && C.back () == 0) {
		C.pop_back ();
	}

	return C;
}

bool cmp2 (vector <int> &A, vector <int> &B) {
	if (A.size () != B.size ()) {
		return A.size ();
	}

	for (int i = A.size () - 1; i >= 0; i -- ) {
		if (A[i] != B[i]) {
			return A[i] > B[i];
		}
	}

	return true;
}

vector <int> mul (vector <int> &A, int b) {
	vector <int> C;

	int t = 0;
	for (int i = 0; i < A.size () || t; i ++ ) {
		if (i < A.size ()) {
			t += A[i] * b;
		}
		C.push_back (t % 10);
		t /= 10;
	}

	while (C.size () > 1 && C.back () == 0) {
		C.pop_back ();
	}

	return C;

}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i <= n; i ++ ) {
		cin >> a[i].l >> a[i].r;
	}

	sort (a + 1, a + n + 1, cmp1);

	vector <int> S;
	int s = a[0].l;
	while (s) {
		S.push_back (s % 10);
		s /= 10;
	}

	vector <int> res;
	res.push_back (0);

	for (int i = 1; i <= n; i ++ ) {
		vector <int> C = div (S, a[i].r);
		if (cmp2 (C, res)) {
			res = C;
		}

		S = mul (S, a[i].l);
	}

	for (int i = res.size () - 1; i >= 0; i -- ) {
		cout << res[i];
	}
	cout << "\n";

	return 0;
}