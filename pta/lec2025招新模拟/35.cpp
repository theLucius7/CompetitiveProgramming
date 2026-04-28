#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    char now = s[0];
    int u = 0, cnt = 0;
    std::string t;
    for (int i = 0; i <= s.size(); i++) {
    	if (i < s.size() && s[i] == 'a') {
    		cnt++;
    		continue;
    	}

    	if (i < s.size() && s[i] == now) {
    		u++;
    	} else {
    		if (now != 'a') {
    			t += now;
    		}
    		if (u > 1) {
    			cnt++;
    		}

    		u = 1;
    		if (i < s.size()) {
    			now = s[i];
    		}
    	}
    }

    std::cout << t << std::string(cnt, 'a') << "\n";


    return 0;
}