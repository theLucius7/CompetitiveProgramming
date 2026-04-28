#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 10, M = 2e6 + 10;

int n, m;
vector <int> adj1[N], adj2[N];
bool vis1[N], vis2[N];
int dist[N];
int s, e;

void dfs (int u) {
	vis2[u] = true;

	for (int j : adj2[u]) {
		if (!vis2[j]) {
			dfs (j);
		}
	}
}

bool check (int u) {
	for (int j : adj1[u]) {
		if (!vis2[j]) {
			return false;
		}
	}

	return true;
}

int bfs (int u) {
	queue <int> q;
	q.push (u);

	vis1[u] = true;

	while (q.size ()) {
		int t = q.front ();
		q.pop ();

		if (t == e) {
			return dist[t];
		}

		for (int j : adj1[t]) {
			if (!vis1[j] && check (j)) {
				q.push (j);
				vis1[j] = true;
				dist[j] = dist[t] + 1;
			}
		}
	}

	return -1;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < m; i ++ ) {
		int a, b;
		cin >> a >> b;

		adj1[a].push_back (b);
		adj2[b].push_back (a);
	}

	cin >> s >> e;

	dfs (e);

	cout << bfs (s) << "\n";

	return 0;
}