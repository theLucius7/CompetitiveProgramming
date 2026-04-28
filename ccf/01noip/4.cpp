#include <bits/stdc++.h>

using namespace std;

const int N = 410;

int n, m, s, e;
double d[N][N];

struct Vertex {
	int x, y;
	int c, w;
};

Vertex get_v4 (Vertex v1, Vertex v2, Vertex v3) {
	int d1 = (v2.x - v3.x) * (v2.x - v3.x) + (v2.y - v3.y) * (v2.y - v3.y);
	int d3 = (v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y);
	int d2 = (v3.x - v1.x) * (v3.x - v1.x) + (v3.y - v1.y) * (v3.y - v1.y);

	if (d1 == d2) {
		return {v1.x + v2.x - v3.x, v1.y + v2.y - v3.y, v3.c, v3.w};
	} else if (d2 == d3){
		return {v2.x + v3.x - v1.x, v2.y + v3.y - v1.y, v1.c, v1.w};
	} else {
		return {v1.x + v3.x - v2.x, v1.y + v3.y - v2.y, v2.c, v2.w};
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T -- ) {
		cin >> n >> m >> s >> e;

		vector <Vertex> vertexes;

		for (int i = 1; i <= n; i ++ ) {
			int x[5], y[5];
			for (int j = 0; j < 3; j ++ ) {
				cin >> x[j] >> y[j];
			}
			
			int w;
			cin >> w;

			Vertex v1 ({x[0], y[0], i, w}), v2 ({x[1], y[1], i, w}), v3 ({x[2], y[2], i, w}), v4 ({x[3], y[3], i, w});
			v4 = get_v4 (v1, v2, v3);

			vertexes.push_back (v1);
			vertexes.push_back (v2);
			vertexes.push_back (v3);
			vertexes.push_back (v4);
		}

		memset (d, 0x3f, sizeof d);

		for (int i = 0; i < vertexes.size (); i ++ ) {
			for (int j = 0; j < vertexes.size (); j ++ ) {
				if (i != j) {
					Vertex v1 = vertexes[i], v2 = vertexes[j];

					double distance = sqrt ((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y));
					double money;
					if (v1.c == v2.c) {
						money = distance * v1.w;
					} else {
						money = distance * m;
					}

					d[i][j] = d[j][i] = money;
				}
			}
		}

		for (int k = 0; k < vertexes.size (); k ++ ) {
			for (int i = 0; i < vertexes.size (); i ++ ) {
				for (int j = 0; j < vertexes.size (); j ++ ) {
					d[i][j] = min (d[i][j], d[i][k] + d[k][j]);
				}
			}
		}

		double res = 0x7f7f7f7f7f7f7f;
		for (int i = 0; i < vertexes.size (); i ++ ) {
			for (int j = 0; j < vertexes.size (); j ++ ) {
				Vertex v1 = vertexes[i], v2 = vertexes[j];
				if (v1.c == s && v2.c == e) {
					res = min (res, d[i][j]);
				}
			}
		}

		cout << fixed << setprecision (1) << res << "\n";
	}

	return 0;
}