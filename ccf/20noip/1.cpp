#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, M = 2 * N;

int n, m;
int h[N], e[M], ne[M], idx;
int din[N], dout[N];;
__int128 f[N], g[N];

inline void print(__int128 x) {
    if (x > 9)
        print(x / 10);

    putchar(x % 10 + '0');
}

void add (int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

__int128 gcd (__int128 a, __int128 b) {
	return b == 0 ? a : gcd (b, a % b);
}

__int128 lcm (__int128 a, __int128 b) {
	return a / gcd (a, b) * b;
}

void simplify (int u) {
	__int128 gcd_u = gcd (f[u], g[u]);
	f[u] /= gcd_u, g[u] /= gcd_u;
}

void topsort () {
	queue <int> q;
	for (int i = 1; i <= n; i ++ ) {
		if (din[i] == 0) {
			f[i] = 1, g[i] = 1;	
			q.push (i);
		}
	}

	while (q.size ()) {
		int t = q.front ();
		q.pop ();

		for (int i = h[t]; ~i; i = ne[i]) {
			int j = e[i];

			if (!f[j]) {
				f[j] = f[t];
				g[j] = g[t] * dout[t];
				simplify (j);
			} else {
				__int128 dx = f[t];
				__int128 dy = g[t] * dout[t];

				__int128 lcm_g = lcm (dy, g[j]);

				dx *= lcm_g / dy;
				dy = lcm_g;

				f[j] *= lcm_g / g[j];
				f[j] += dx;

				g[j] = lcm_g;
				
				simplify (j);
			}

			if ( -- din[j] == 0) {
				q.push (j);
			}
		}
	}
}

int main () {
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);

	cin >> n >> m;

	memset (h, -1, sizeof h);

	for (int i = 1; i <= n; i ++ ) {
		int d;
		cin >> d;

		dout[i] = d;
		for (int j = 0; j < d; j ++ ) {
			int v;
			cin >> v;
			
			add (i, v);
			din[v] ++ ;
		}
	}

	topsort ();

	for (int i = 1; i <= n; i ++ ) {
		if (dout[i] == 0) {
            print(f[i]);
            cout << " ";
            print(g[i]);
            cout << "\n";
	    }
    }

	return 0;
}