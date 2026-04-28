#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int MAXX = 200000;
static long long fact[MAXX+5], invFact[MAXX+5];

// Fast modular exponentiation
long long modExp(long long base, long long exp) {
    long long result = 1 % MOD;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

// Precompute factorials and inverse factorials up to maxX
void initFactorials(int maxN) {
    fact[0] = 1;
    for(int i = 1; i <= maxN; ++i) {
        fact[i] = fact[i-1] * i % MOD;
    }
    invFact[maxN] = modExp(fact[maxN], MOD-2);  // Fermat's little theorem for modular inverse
    for(int i = maxN; i > 0; --i) {
        invFact[i-1] = invFact[i] * i % MOD;
    }
}

// Combination function nCk under modulo
inline long long nCk(int n, int k) {
    if(k < 0 || k > n) return 0;
    return fact[n] * invFact[k] % MOD * invFact[n-k] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    initFactorials(MAXX);
    int t;
    if(!(cin >> t)) {
        return 0;
    }

    // Memoization: results[f_n][x] for given n and x
    // Using map to only store computed ranges for each n
    unordered_map<int, vector<int>> computedF;   // computedF[n] will hold results from minX(n) up to some max
    unordered_map<int, int> minX_for_n;          // store threshold x_min for each n
    
    while(t--) {
        int n, x;
        cin >> n >> x;
        if(n == 1) {
            // For n=1, any single element set {k} is valid
            cout << x % MOD << "\n";
            continue;
        }
        // Compute threshold x_min for this n if not already
        if(minX_for_n.find(n) == minX_for_n.end()) {
            // x_min = ceil((n^2 + n - 2)/2)
            long long num = 1LL * n * n + n - 2;
            long long x_min = (num % 2 == 0 ? num/2 : num/2 + 1);
            minX_for_n[n] = (int)min(x_min, (long long)MAXX);  // clamp to MAXX
            // Initialize vector up to current query x (size might adjust later)
            computedF[n] = vector<int>(minX_for_n[n] + 1);
            // All values below threshold yield 0
            computedF[n].assign(minX_for_n[n], 0);
            if(minX_for_n[n] <= MAXX) {
                computedF[n].push_back(1); // at threshold, exactly one set
            }
        }
        int x_min = minX_for_n[n];
        if(x < x_min) {
            cout << 0 << "\n";
            continue;
        }
        // Ensure our computed vector covers up to x
        if(x > (int)computedF[n].size() - 1) {
            computedF[n].resize(x+1);
        }
        int lastComputed = computedF[n].size() - 1;
        // Actually, lastComputed might be larger than content if we pre-resized above. 
        // Let's find the actual highest value we have computed.
        lastComputed = 0;
        while(lastComputed < (int)computedF[n].size() && computedF[n][lastComputed] != 0) {
            lastComputed++;
        }
        lastComputed = max(lastComputed - 1, x_min);
        // Compute f(n) values from lastComputed+1 up to x
        long long prevCount = computedF[n][lastComputed];  // f(n) at lastComputed
        for(int M = lastComputed + 1; M <= x; ++M) {
            // Base from previous count
            long long newCount = prevCount;
            // Calculate additional sets introduced by max = M
            // We use the sum condition to determine valid omissions from top block
            // Top block (largest n-1 numbers < M): [M-(n-1), ..., M-1]
            long long topBlockSum = 0;
            for(int val = M - (n-1); val < M; ++val) {
                topBlockSum += val;
            }
            // Sum threshold for other elements:
            long long threshold = 1LL * (n-2) * M + (n-1);
            // We will try different omission patterns j = 0, 1, 2, ... and count valid ones
            int validPatterns = 0;
            // To avoid iterating n-1 times (which can be large), we stop when condition fails the first time 
            // since further omissions (losing larger numbers) will only reduce sum more.
            // We consider omitting *smallest* j elements as the scenario that gives the **highest** sum for that j (best case).
            // If that fails, any other j-omission fails as well.
            long long currentSum = topBlockSum;
            for(int j = 0; j < n; ++j) {
                // others sum with j smallest omitted = remove [M-(n-1), ..., M-(n-j)] and add [M-n, ..., M-n-j+1]
                if(j == 0) {
                    // j=0: others sum = topBlockSum (no change)
                } else {
                    // remove M-(n-j) (j-th smallest in block) and add M-n-(j-1) (j-th largest below block)
                    long long removed = M - (n - j);            // M - (n - j) is the j-th smallest in block
                    long long added = M - n - (j - 1);         // M - n - (j-1) is the j-th largest outside
                    currentSum += added - removed;
                }
                if(currentSum >= threshold) {
                    validPatterns++;
                } else {
                    break; // further j will only reduce sum more, so stop
                }
            }
            // Subtract 1 because j=0 (no omission) corresponds to the contiguous block which was counted already in previous count
            // All other patterns (j >= 1) are new.
            int newSets = max(validPatterns - 1, 0);
            // Add new sets count to previous count
            newCount = (newCount + newSets) % MOD;
            computedF[n][M] = (int)newCount;
            prevCount = newCount;
        }
        cout << computedF[n][x] % MOD << "\n";
    }

    return 0;
}
