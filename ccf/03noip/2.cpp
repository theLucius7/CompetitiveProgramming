#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long i64;
typedef pair <int, string> pis;

const int N = 21, M = 110;

int n, m, S; 
string names[N];
pis sentences[M];
int st[N];

string weekdays[7] = {
	"Today is Monday.",
    "Today is Tuesday.",
    "Today is Wednesday.",
    "Today is Thursday.",
    "Today is Friday.",
    "Today is Saturday.",
    "Today is Sunday."
};

int get_id (string s) {
	for (int i = 0; i < n; i ++ ) {
		if (names[i] == s) {
			return i;
		}
	}
	return -1;
}

int judge (int day, int badman, int now, string s) {
	if (s == "I am guilty.") {
		return now == badman;
	} else if (s == "I am not guilty.") {
		return now != badman;
	}
	
	for (int i = 0; i < n; i ++ ) {
		if (names[i] + " is guilty." == s) {
			return i == badman;
		}
	}
	for (int i = 0; i < n; i ++ ) {
		if (names[i] + " is not guilty." == s) {
			return i != badman;
		}
	}
	
	for (int i = 0; i < 7; i ++ ) {
		if (weekdays[i] == s) {
			return day == i;
		}
	}
	
	return -1;
}

bool check (int day, int badman) {
	memset (st, -1, sizeof st);
	
	for (int i = 0; i < S; i ++ ) {
		pis sen = sentences[i];
		
		int t = judge (day, badman, sen.x, sen.y);
		int p = sen.x;
		
		if (t == 1) {
			if (st[p] == 0) {
				return false;
			}
			st[p] = 1;
		} else if (t == 0) {
			if (st[p] == 1) {
				return false;
			}
			st[p] = 0;
		}
	}
	
	int fakers = 0, others = 0;
	for (int i = 0; i < n; i ++ ) {
		if (st[i] == 0) {
			fakers ++ ;
		} else if (st[i] == -1) {
			others ++ ;
		}
	}
	
	return fakers <= m && m <= fakers + others;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m >> S;
	
	for (int i = 0; i < n; i ++ ){
		cin >> names[i];
	}
	
	for (int i = 0; i < S; i ++ ) {
		string a, b;
		
		cin >> a;
		a.erase (a.end () - 1);
		
		getline (cin, b);
		b.erase (b.begin ());
		b.erase (b.end () - 1);
		
		sentences[i] = {get_id (a), b};
	}
	
	int cnt, p = -1;
	
	for (int i = 0; i < 7; i ++ ) {
		cnt = 0;
		for (int j = 0; j < n; j ++ ) {
			if (check (i, j)) {
				cnt ++;
				p = j;
			} 
		} 
		
		if (cnt > 1) {
			cout << "Cannot Determine\n";
			return 0;
		}
	}
	
	if (p != -1) {
		cout << names[p] << "\n";
	} else {
		cout << "Impossible\n";
	}
	
	return 0;
} 
