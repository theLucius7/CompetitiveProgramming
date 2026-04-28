#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 inf = 1E18 + 10;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::set<i64> s;
    s.insert(0);

	auto get = [&](i64 p) {
        auto it = s.find(p);
        i64 ans = inf;
        if (it != s.begin()) {
            ans = std::min(ans, p - *std::prev(it));
        }
        
        auto itn = std::next(it);
        if (itn != s.end()) {
            ans = std::min(ans, *itn - p);
        }
        return ans;
    };


    i64 sum = 0;
    for (int i = 0; i < N; i++) {
    	i64 x;
    	std::cin >> x;

    	if (s.size() == 1) {
    		s.insert(x);
    		sum = 2 * x;
    	} else {
    		auto itR = s.lower_bound(x);
        	bool okR = (itR != s.end()), okL = (itR != s.begin());
	        i64 R = 0, L = 0;

	        i64 ll = 0, rr = 0;
	        if (itR != s.end()) {
	            R = *itR;
	            rr = get(R);
	        }
	        if (okL) {
	            L = *std::prev(itR);
	            ll = get(L);
	        }

	        s.insert(x);

	        i64 nl = 0, nr = 0, xx = get(x);
	        if (okL) {
	        	nl = get(L);
	        }
	        if (okR) {
	        	nr = get(R);
		    }

	        sum = sum - ll - rr + nl + nr + xx;
    	}
    	std::cout << sum << "\n";
    	
    }


    return 0;
}
