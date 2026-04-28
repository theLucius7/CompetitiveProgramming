#include <bits/stdc++.h>

using namespace std;

int n, m;
string a;
vector <int> res;

bool cmp (vector <int> A, vector <int> B) {
	if (A.size () != B.size ()) {
		return A.size () > B.size ();
	}

	for (int i = A.size () - 1; i >= 0; i -- ) {
		if (A[i] != B[i]) {
			return A[i] > B[i];
		}
	}
	return true;
}

vector <int> mul (vector <int> A, vector <int> B) {
	vector <int> C (A.size () + B.size () + 1);

	for (int i = 0; i < A.size (); i ++ ) {
		for (int j = 0; j < B.size ();j ++ ) {
			C[i + j] += A[i] * B[j];

			if (C[i + j] >= 10) {
				C[i + j + 1] += C[i + j] / 10;
				C[i + j] %= 10;
			}
		}
	}

	while (C.size () > 1 && C.back () == 0) {
		C.pop_back ();
	}

	return C;
}

void shuchu (vector <int> a) {
	for (int i = a.size () - 1; i >= 0; i -- ) {
		cout << a[i];
	}
	cout << "\n";
}

void dfs (int u, int last, vector <int> A) {
	if (u == m) {
		vector <int> B;
		for (int i = n - 1; i > last; i -- ) {
			B.push_back (a[i] - '0');
		}
		// shuchu (A);
		// shuchu (B);

		A = mul (A, B);
		// shuchu (A);

		if (cmp (A, res)) {
			res = A;
			// shuchu (B);
			return;
		}
	}

	for (int i = last + 1; i < n - 1; i ++ ) {
		vector <int> B;
		for (int j = i; j > last; j -- ) {
			B.push_back (a[j] - '0');
		}
		vector <int> C = mul (A, B);
		dfs (u + 1, i, C);
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	cin >> a;

	vector <int> A;
	A.push_back (1);

	res.push_back (0);
	dfs (0, -1, A);

	for (int i = res.size () - 1; i >= 0; i -- ) {
		cout << res[i];
	}
	cout << "\n";

	return 0;
}