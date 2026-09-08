#include <bits/stdc++.h>

using namespace std;

struct node {
	bool ok = false;
	int a, b, number;
}students[1010];

bool cmp1 (node a, node b) {
	if (a.ok) {
		return false;
	}
	if (b.ok) {
		return true;
	}
	
	if (a.a == b.a) {
		return a.number < b.number;
	}
	return a.a > b.a;
}

bool cmp2 (node a, node b) {
	if (a.ok) {
		return false;
	}
	if (b.ok) {
		return true;
	}
	if (a.b == b.b) {
		return a.number < b.number;
	}
	return a.b > b.b;
}

bool cmp3 (node a, node b) {
	if (a.ok) {
		return false;
	}
	if (b.ok) {
		return true;
	}
	if (a.a + a.b == b.a + b.b) {
		return a.number < b.number;
	}
	return a.a + a.b > b.a + b.b;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	vector <int> ans;
	
	int n, x, y, z;
	cin >> n >> x >> y >> z;	
	
	for (int i = 1; i <= n; i ++ ) {
		int x;
		cin >> x;
		students[i].number = i, students[i].a = x;
	}
	
	for (int i = 1; i <= n; i ++ ) {
		int x;
		cin >> x;
		students[i].b = x;
	}
	
	sort (students + 1, students + 1 + n, cmp1);
	for (int i = 1; i <= x; i ++ ) {
		ans.push_back (students[i].number);
		students[i].ok = true;
	}
	
	sort (students + 1, students + 1 + n, cmp2);
	for (int i = 1; i <= y; i ++ ) {
		ans.push_back (students[i].number);
		students[i].ok = true;
	}
	
	sort (students + 1, students + 1 + n, cmp3);
	for (int i = 1; i <= z; i ++ ) {
		ans.push_back (students[i].number);
		students[i].ok = true;
	}
	
	sort (ans.begin (), ans.end ());
	
	for (auto i : ans) {
		cout << i << "\n";
	}
	
	return 0;	
}