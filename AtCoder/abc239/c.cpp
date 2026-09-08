#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef pair <int, int> PII;

vector <PII> moves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	for (auto d1 : moves) {
		for (auto d2 : moves) {
			if (x1 + d1.x == x2 + d2.x && y1 + d1.y == y2 + d2.y) {
				cout << "Yes" << "\n";
				return 0;
			}
		}
	}

	cout << "No" << "\n";

	return 0;
}