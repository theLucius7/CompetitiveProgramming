Looking at this problem, I need to recover string s from the array p where p[j] = x means s[x..j] is the lexicographically minimum suffix of s[1..j].

Let me think about the properties of p:

For each j, s[p[j]..j] is the minimum suffix of s[1..j].

Key observations:
1. p[1] = 1 always (only one suffix).
2. For j > 1, p[j] is either p[j-1] or j (the new character itself starts a new minimum suffix).

Wait, let me think more carefully. The minimum suffix of s[1..j] is either:
- The minimum suffix of s[1..j-1] extended... no, that's not right either.

Actually, let me think about when p[j] changes. The minimum suffix of s[1..j] is the lex smallest among s[1..j], s[2..j], ..., s[j..j].

If p[j] = p[j-1], that means s[p[j-1]..j] is still the minimum suffix. This means s[p[j-1]..j] ≤ s[k..j] for all k.

If p[j] ≠ p[j-1], then p[j] must be j (since the new minimum suffix starts at j, meaning s[j] alone or s[j..j] is smallest, which means s[j] < s[p[j-1]]).

Wait, p[j] could be anything from 1 to j. Let me reconsider.

Actually the minimum suffix can start anywhere. But there's a constraint: if p[j] = x, then s[x..j] must be ≤ s[x..j-1] extended... 

Let me think differently. If p[j] = p[j-1] = x, then s[x..j] ≤ all other suffixes ending at j. Also s[x..j-1] was min suffix of s[1..j-1]. The relationship: s[x..j] vs s[x..j-1]: s[x..j] = s[x..j-1] + s[j], so s[x..j] starts with s[x..j-1].

If p[j] ≠ p[j-1], what can p[j] be? It seems p[j] must equal j (new single character is minimum), OR it could be some other position.

Actually I recall that for Lyndon-related structures, p[j] is either p[j-1] or j. Let me verify with examples.

Example: "1 2 3" gives output "1 1 1". p[1]=1, p[2]=1, p[3]=1. So minimum suffix always starts at 1. That means s[1..j] is always minimum, so s[1] ≤ s[2] ≤ ... which gives "1 1 1". ✓

Example: "1 2 1" gives "-1". p[2]=2 means s[2..2] < s[1..2], so s[2] < s[1]. But p[3]=1 means s[1..3] < s[2..3] and s[1..3] < s[3..3]. s[1..3] < s[2..3] means s[1] < s[2] or (s[1]=s[2] and s[2..3]<s[3..3]). But s[2]<s[1], contradiction. So -1. ✓

So p[j] must be either p[j-1] or j. If p[j] is neither, output -1.

If p[j] = j: s[j] < s[p[j-1]] (new char is strictly smaller).
If p[j] = p[j-1]: s[p[j-1]..j] ≤ s[j..j], meaning s[p[j-1]] ≤ s[j]. Also need s[p[j-1]..j] is still minimum.

For p[j] = p[j-1] = x: we need s[x..j] ≤ s[k..j] for all k. The critical constraint is s[j] ≥ s[x + (j - x) mod period]... this gets complex.

Actually the key insight: if p[j]=p[j-1]=x, then s[j] = s[x + (j-x) mod (something)]. To minimize lexicographically, assign s[j] = s[x + ((j-x) mod (j-x))]... Let me think: s[x..j] must be ≤ s[x+1..j], which means s[x..j-1] ≤ s[x+1..j-1] (already known) and comparing last chars or the suffix itself repeats.

After more analysis, when p[j]=p[j-1]=x: s[j] should equal s[x + ((j-x) % (j-x))] = s[x] when we want minimum. Actually s[j] = s[x + (j-1-x+1) % (j-x)] = s[x + (j-x) % (j-x)] = s[x]. To minimize, set s[j] = s[x] if valid, else increment.

#include <bits/stdc++.h>
using i64 = long long;
void solve(){int n;std::cin>>n;std::vector<int>p(n+1);for(int i=1;i<=n;i++)std::cin>>p[i];std::vector<int>s(n+1,0);bool ok=true;for(int j=1;j<=n;j++){if(p[j]==j){if(j==1){s[j]=1;}else{int x=p[j-1];if(s[j-1+1-1]>0)s[j]=s[x]-1;// s[j] < s[x]
s[j]=s[x]-1;if(s[j]<1){// need to go back and increment... complex
ok=false;break;}}}else if(j>1&&p[j]==p[j-1]){int x=p[j];int len=j-x;s[j]=s[x+(j-1-x)%len+1-1+1];// s[j] = s[x + (j-1-x)%len]
int idx=x+(j-1-x)%len;s[j]=s[idx];}else if(j==1&&p[j]==1){s[j]=1;}else{ok=false;break;}}if(!ok){std::cout<<-1<<"\n";return;}for(int i=1;i<=n;i++)std::cout<<s[i]<<" \n"[i==n];}
int main(){std::ios::sync_with_stdio(false);std::cin.tie(nullptr);int t;std::cin>>t;while(t--)solve();}

Let me redo this more carefully.

#include <bits/stdc++.h>
using i64 = long long;
void solve() {
    int n; std::cin >> n;
    std::vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) std::cin >> p[i];
    std::vector<int> s(n + 1, 0);
    // p[1] must be 1
    if (p[1] != 1) { std::cout << -1 << "\n"; return; }
    s[1] = 1;
    bool ok = true;
    for (int j = 2; j <= n; j++) {
        if (p[j] == j) {
            // s[j] < s[p[j-1]]
            int prev = s[p[j-1]];
            if (prev <= 1) { ok = false; break; }
            s[j] = prev - 1;
        } else if (p[j] == p[j-1]) {
            int x = p[j];
            int len = j - 1 - x + 1; // length of s[x..j-1]
            // s[j] = s[x + (j-1-x+1) % len] ... 
            // The suffix s[x..j] should still be minimum
            // s[x..j] <= s[x+1..j]: since s[x..j-1] <= s[x+1..j-1] (from prev step)
            // we need s[j] >= s[x + (j-1-x+1) % (j-1-x+1)]
            // To minimize s[j], set s[j] = s[x + len % len] = s[x]
            // But also s[x..j] <= s[j..j] means s[x] <= s[j]
            // So s[j] >= s[x], minimize means s[j] = s[x]
            // But we also need s[x..j] <= s[k..j] for all k
            // The binding constraint from s[x..j] <= s[x+1..j]:
            // Since s[x..j-1] < s[x+1..j-1] or s[x..j-1]=s[x+1..j-1]
            // If s[x..j-1] < s[x+1..j-1]: automatically s[x..j] < s[x+1..j]
            // If s[x..j-1] = s[x+1..j-1]: need s[j] <= s[j] (always true)
            // Hmm but we need to check all suffixes...
            // Actually the key recurrence: s[j] = s[x + (j-x) % (j-x)]... 
            // len of period = j-1-x+1 = j-x... wait x=p[j], len = j-1-x+1
            int period = j - 1 - x + 1; // = j - x
            // s[j] should equal s[x + (j-1-x+1) % period]... 
            // index: x + period % period = x + 0 = x
            // So s[j] = s[x]? Let me verify with example.
            // "1 1 1": p=[1,1,1], s[1]=1, p[2]=p[1]=1, period=1, s[2]=s[1]=1? But answer is "1 2 2"
            // Hmm that's wrong. Let me reconsider.
            s[j] = s[x]; // placeholder
        } else {
            ok = false; break;
        }
    }
    if (!ok) { std::cout << -1 << "\n"; return; }
    for (int i = 1; i <= n; i++) std::cout << s[i] << " \n"[i == n];
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t; std::cin >> t;
    while (t--) solve();
}

I need to think more carefully. Let me re-examine the examples.

Example 1: p = [1,1,1], answer = "1 2 2"
- j=1: p[1]=1, s[1]=1
- j=2: p[2]=1=p[1]=1, so same minimum suffix start. s[1..2] is min suffix of s[1..2]. Need s[1..2] ≤ s[2..2], so s[1] ≤ s[2]. To minimize s[2], set s[2] = s[1] = 1? But answer is 2.

Wait, if s[2]=1=s[1], then s[1..2]="1 1" and s[2..2]="1". Then min suffix of s[1..2] is s[2..2]="1", so p[2]=2, not 1. Contradiction!

So when p[j]=p[j-1]=x, we need s[x..j] to be strictly less than s[j..j] (or at least ≤, but if equal then p[j] would be j not x... actually if equal, the minimum suffix could be either, but we want p[j]=x).

Hmm, actually the problem says "minimum suffix" - if there are ties, which one is chosen? The problem says p[j]=x means s[x..j] IS the minimum suffix. If multiple suffixes are equal minimum, then p[j] is the leftmost? Or any?

Actually for the minimum suffix to have p[j]=x (not j), we need s[x..j] < s[j..j], i.e., s[x] < s[j], OR s[x]=s[j] and s[x+1..j] < s[j+1..j] (but s[j+1..j] is empty, so s[x..j] > s[j..j] if s[x]=s[j] and len>1... wait no).

Comparing s[x..j] vs s[j..j]: s[j..j] has length 1. s[x..j] has length j-x+1 ≥ 2 (since x < j). Lex comparison: compare first chars: s[x] vs s[j]. If s[x] < s[j]: s[x..j] < s[j..j]. If s[x] > s[j]: s[x..j] > s[j..j]. If s[x] = s[j]: s[j..j] is a prefix of s[x..j]... wait no. s[j..j]="c" and s[x..j]="...c". Lex: compare char by char. First char of s[x..j] is s[x], first char of s[j..j] is s[j]. If s[x]=s[j], then we compare second chars: s[x+1] vs (s[j..j] has no second char, so s[j..j] is a prefix of s[x..j] if s[x]=s[j])... In standard lex order, shorter string that is a prefix is smaller. So s[j..j] < s[x..j] if s[x]=s[j]. 

So for p[j]=x (x<j), we need s[x..j] < s[j..j], which requires s[x] < s[j].

And for p[j]=p[j-1]=x, we need s[x..j] to be the minimum suffix of s[1..j]. The new suffix added is s[j..j]. We need s[x..j] ≤ s[j..j], i.e., s[x] ≤ s[j]. But if s[x]=s[j], then s[j..j] < s[x..j] (as shown above), so p[j] would be j, not x. So we need s[x] < s[j].

Wait but also we need s[x..j] ≤ all other suffixes s[k..j] for k=1..j-1. Since s[x..j-1] was the min suffix of s[1..j-1], we know s[x..j-1] ≤ s[k..j-1] for all k. Does this imply s[x..j] ≤ s[k..j]?

Not necessarily. We need to be more careful.

Let me think about this differently. The minimum suffix of s[1..j] among s[1..j], s[2..j], ..., s[j..j].

Key insight: if p[j] = p[j-1] = x, then s[x..j] is min suffix of s[1..j]. The previous min suffix was s[x..j-1] for s[1..j-1].

For s[x..j] to remain minimum when we append s[j]:
- s[x..j] ≤ s[k..j] for all k from 1 to j.

The suffixes s[k..j] for k=1..j-1 are just s[k..j-1] with s[j] appended. 

Claim: if s[x..j-1] < s[k..j-1] (strictly), then s[x..j] < s[k..j] (since the first difference is before position j).

Claim: if s[x..j-1] = s[k..j-1], then s[x..j] = s[k..j], so they're equal.

But wait, s[x..j-1] has length j-1-x+1 = j-x, and s[k..j-1] has length j-k. They can only be equal if j-x = j-k, i.e., x=k. So for k≠x, s[x..j-1] ≠ s[k..j-1] in length unless... actually lex comparison of strings of different lengths: "abc" < "abd" but also "ab" < "abc" (prefix is smaller). 

Hmm, so s[x..j-1] ≤ s[k..j-1] means either s[x..j-1] is a proper prefix of s[k..j-1], or they differ at some position where s[x] wins.

Case 1: s[x..j-1] is a proper prefix of s[k..j-1] (so j-x < j-k, i.e., x > k, and s[k..k+j-x-1] = s[x..j-1]). Then s[x..j] vs s[k..j]: compare char by char. First j-x chars: s[x..j-1] vs s[k..k+j-x-1] = s[x..j-1], equal. Then s[j] vs s[k+j-x]. So s[x..j] ≤ s[k..j] iff s[j] ≤ s[k+j-x].

Case 2: s[x..j-1] < s[k..j-1] with a strict difference at some position i < min(j-x, j-k). Then s[x..j] < s[k..j] automatically.

Case 3: s[k..j-1] is a proper prefix of s[x..j-1] (so x < k). Then s[k..j-1] < s[x..j-1], contradicting s[x..j-1] ≤ s[k..j-1].

So the only non-trivial case is Case 1: when s[x..j-1] is a proper prefix of s[k..j-1], i.e., s[k..k+j-x-1] = s[x..j-1] and k < x.

In this case, we need s[j] ≤ s[k+j-x].

Note that k+j-x = k + (j-x). Since s[k..k+j-x-1] = s[x..j-1], we have s[k+i] = s[x+i] for i=0..j-x-1. In particular, s[k+j-x] = s[x + (j-x) - (k - (x - (j-x)))]... hmm this is getting complicated.

Actually, let me think about when s[x..j-1] is a proper prefix of s[k..j-1] with k < x. This means s[k..k+j-x-1] = s[x..j-1]. 

Note that s[x..j-1] was the minimum suffix of s[1..j-1], and s[k..j-1] is another suffix. Since s[x..j-1] is a prefix of s[k..j-1] and k < x, we have s[k..j-1] starts with s[x..j-1]. 

Also, s[k..j-1] ≥ s[x..j-1] (since x is the min suffix start). Since s[x..j-1] is a prefix of s[k..j-1], s[k..j-1] ≥ s[x..j-1] is automatically satisfied (prefix is smaller in lex).

Now, s[k+j-x] is the character right after the matching prefix in s[k..j-1]. We need s[j] ≤ s[k+j-x].

But s[k+j-x] is a character in s[1..j-1] (since k+j-x ≤ j-1 iff k ≤ x-1, which is true since k < x). 

Hmm, this is getting complex. Let me look at this from a different angle.

I recall that the minimum suffix (Booth's algorithm related) has a nice property: p[j] is either p[j-1] or j. Let me verify:

Can p[j] be something other than p[j-1] or j?

Suppose p[j] = y where y ≠ p[j-1] and y ≠ j. Then s[y..j] is the minimum suffix of s[1..j]. In particular, s[y..j] < s[p[j-1]..j]. 

But s[y..j-1] is a suffix of s[1..j-1], and s[p[j-1]..j-1] is the minimum suffix of s[1..j-1]. So s[p[j-1]..j-1] ≤ s[y..j-1].

Case A: s[p[j-1]..j-1] < s[y..j-1]. Then s[p[j-1]..j] < s[y..j], contradicting s[y..j] being minimum.

Case B: s[p[j-1]..j-1] = s[y..j-1]. Then s[p[j-1]..j] vs s[y..j] depends only on s[j] vs s[j], which are equal. So s[p[j-1]..j] = s[y..j]. But then both are minimum, and p[j] could be either. But the problem specifies a unique p[j], so if both are equal, which one is p[j]?

Hmm, actually the problem says "if s[x..j] is the minimum suffix of s[1..j], then p[j] = x". If multiple suffixes achieve the minimum, the problem might define p[j] as the leftmost (smallest x). Let me re-read.

"if s[x…j] is the minimum suffix of s[1…j], then we define p_j = x"

This implies uniqueness. So the minimum suffix is unique, meaning there's a unique starting position. So p[j] is well-defined.

From Case B above: if s[p[j-1]..j-1] = s[y..j-1] and y ≠ p[j-1], then s[p[j-1]..j] = s[y..j], which means the minimum is not unique. Contradiction with the problem's definition.

So actually, if the minimum suffix is unique, then p[j] can only be p[j-1] or j (from the analysis: if p[j] ≠ p[j-1] and p[j] ≠ j, we get a contradiction).

Wait, I didn't fully cover all cases. Let me redo:

If p[j] = y ≠ p[j-1] and y ≠ j:
- s[y..j] is the unique minimum suffix of s[1..j].
- s[p[j-1]..j-1] is the minimum suffix of s[1..j-1], so s[p[j-1]..j-1] ≤ s[y..j-1].
- Since s[y..j] < s[p[j-1]..j]: 
  - If s[y..j-1] < s[p[j-1]..j-1]: impossible since p[j-1] is min.
  - If s[y..j-1] = s[p[j-1]..j-1]: then s[y..j] = s[p[j-1]..j] (same last char s[j]), so they're equal, contradicting uniqueness.
  - If s[y..j-1] > s[p[j-1]..j-1]: then s[y..j] > s[p[j-1]..j] (first difference before position j), contradicting s[y..j] < s[p[j-1]..j].

So indeed p[j] ∈ {p[j-1], j}. 

Now, if p[j] = j: s[j..j] is the unique minimum suffix. So s[j] < s[k] for all k that are starts of suffixes... wait, s[j..j] < s[p[j-1]..j]. Since s[p[j-1]..j] starts with s[p[j-1]], and s[j..j] = s[j], we need s[j] < s[p[j-1]]. Also s[j..j] must be < all other suffixes s[k..j] for k=1..j-1. Since s[p[j-1]..j] was the min of s[k..j-1] extended, and s[j] < s[p[j-1]], we have s[j] < s[p[j-1]] ≤ s[k] for all k... wait not necessarily.

Hmm, s[j..j] < s[k..j] for all k < j means s[j] < s[k] for all k < j? No! s[j..j] vs s[k..j]: first char is s[j] vs s[k]. If s[j] < s[k], then s[j..j] < s[k..j]. If s[j] > s[k], then s[j..j] > s[k..j]. If s[j] = s[k], then s[j..j] < s[k..j] (since s[j..j] is shorter and is a prefix of s[k..j] only if s[k]=s[j], s[k+1]=s[j+1]... but s[j..j] has length 1 and s[k..j] has length j-k+1 ≥ 2, so s[j..j] is a prefix of s[k..j] iff s[k]=s[j], and in that case s[j..j] < s[k..j]).

So s[j..j] < s[k..j] iff s[j] ≤ s[k]. And s[j..j] is the unique minimum iff s[j] < s[k] for all k < j (strictly less, since if s[j]=s[k] then s[j..j] < s[k..j] but also s[j..j] might equal some other suffix... wait s[j..j] < s[k..j] when s[j]=s[k] since s[j..j] is a proper prefix).

Actually wait: if s[j] = s[k] for some k < j, then s[j..j] < s[k..j] (since s[j..j] is a prefix of s[k..j] and shorter). So s[j..j] is still the minimum. But is it unique? s[j..j] < s[k..j] strictly, so yes unique.

So p[j] = j iff s[j] ≤ s[k] for all k < j, i.e., s[j] = min(s[1..j]).

And p[j] = p[j-1] iff s[p[j-1]..j] is the unique minimum, which requires s[p[j-1]] < s[j] (from the analysis: s[p[j-1]..j] < s[j..j] requires s[p[j-1]] < s[j] or s[p[j-1]] = s[j] but then s[j..j] < s[p[j-1]..j]... wait).

s[p[j-1]..j] vs s[j..j]: first char s[p[j-1]] vs s[j]. 
- If s[p[j-1]] < s[j]: s[p[j-1]..j] < s[j..j], so p[j] = p[j-1] (assuming s[p[j-1]..j] is still min among all).
- If s[p[j-1]] > s[j]: s[p[j-1]..j] > s[j..j], so p[j] = j.
- If s[p[j-1]] = s[j]: s[j..j] < s[p[j-1]..j] (since s[j..j] is shorter prefix), so p[j] = j.

So: p[j] = j iff s[j] ≤ s[p[j-1]], and p[j] = p[j-1] iff s[j] > s[p[j-1]].

Wait but I also need to verify that when p[j] = p[j-1], s[p[j-1]..j] is indeed the minimum among ALL suffixes, not just compared to s[j..j].

From the earlier analysis: if s[p[j-1]..j-1] < s[k..j-1] (strictly) for all k ≠ p[j-1], then s[p[j-1]..j] < s[k..j] for all k ≠ p[j-1] (since the first difference is before position j). And we just showed s[p[j-1]..j] < s[j..j] when s[p[j-1]] < s[j].

But what if s[p[j-1]..j-1] = s[k..j-1] for some k? We showed that can't happen if the minimum is unique (which it is by the problem's definition).

So the rule is simply:
- p[j] = j iff s[j] ≤ s[p[j-1]]
- p[j] = p[j-1] iff s[j] > s[p[j-1]]

Now, given p, we need to find s:
- If p[j] = j: s[j] ≤ s[p[j-1]] (and s[j] is as small as possible, so s[j] = 1, but we also need p[j] = j to be consistent, meaning s[j] ≤ s[p[j-1]]).

Wait, but we also need p[j] ≠ p[j-1] when p[j] = j (i.e., j ≠ p[j-1], which is true since j > p[j-1] for j > 1... unless p[j-1] = j which is impossible since p[j-1] ≤ j-1).

Actually wait, I need to be more careful. The condition p[j] = j means s[j] ≤ s[p[j-1]]. The condition p[j] = p[j-1] means s[j] > s[p[j-1]].

But what if p[j] is neither j nor p[j-1]? Then it's invalid, output -1.

Also, what if p[j] = j = p[j-1]? That would mean j = p[j-1], but p[j-1] ≤ j-1 < j, so this can't happen.

So the algorithm:
1. Check p[1] = 1, else -1.
2. For j = 2..n:
   - If p[j] = j: need s[j] ≤ s[p[j-1]]. To minimize s[j], set s[j] = 1 (if 1 ≤ s[p[j-1]], which is always true since s[p[j-1]] ≥ 1). But wait, we need s[j] ≤ s[p[j-1]], and to minimize lexicographically, we want s[j] as small as possible, so s[j] = 1.
   
   But hold on: if p[j] = j and p[j+1] = p[j] = j (i.e., p[j+1] = j), then s[j+1] > s[j]. If s[j] = 1, then s[j+1] ≥ 2. That's fine.
   
   But if p[j] = j and p[j+1] = j+1, then s[j+1] ≤ s[j] = 1, so s[j+1] = 1. Fine.
   
   Actually, setting s[j] = 1 whenever p[j] = j seems correct for minimizing.
   
   Wait, but we need s[j] ≤ s[p[j-1]]. If s[p[j-1]] = 1, then s[j] ≤ 1, so s[j] = 1. Fine.
   
   - If p[j] = p[j-1]: need s[j] > s[p[j-1]]. To minimize s[j], set s[j] = s[p[j-1]] + 1.
   
   - Else: output -1.

Wait, but is this correct? Let me verify with examples.

Example 1: p = [1,1,1]
- s[1] = 1
- j=2: p[2]=1=p[1]=1, so p[j]=p[j-1]. s[2] = s[p[1]] + 1 = s[1] + 1 = 2.
- j=3: p[3]=1=p[2]=1, so p[j]=p[j-1]. s[3] = s[p[2]] + 1 = s[1] + 1 = 2.
- Result: 1 2 2. ✓

Example 2: p = [1,1,2]
- s[1] = 1
- j=2: p[2]=1=p[1]=1, p[j]=p[j-1]. s[2] = s[1]+1 = 2.
- j=3: p[3]=2. p[j-1]=p[2]=1. p[j]=2 ≠ 1 = p[j-1], and p[j]=2 ≠ 3=j. So invalid. Output -1. ✓

Example 3: p = [1,1,3]
- s[1] = 1
- j=2: p[2]=1=p[1], p[j]=p[j-1]. s[2] = s[1]+1 = 2.
- j=3: p[3]=3=j. s[3] ≤ s[p[2]] = s[1] = 1. So s[3] = 1.
- Result: 1 2 1. ✓

Example 4: p = [1,2,1]
- s[1] = 1
- j=2: p[2]=2=j. s[2] ≤ s[p[1]] = s[1] = 1. s[2] = 1.
- j=3: p[3]=1. p[j-1]=p[2]=2. p[j]=1 ≠ 2=p[j-1], and p[j]=1 ≠ 3=j. Invalid. Output -1. ✓

Example 5: p = [1,2,2]
- s[1] = 1
- j=2: p[2]=2=j. s[2] ≤ s[p[1]] = s[1] = 1. s[2] = 1.
- j=3: p[3]=2=p[2]=2. p[j]=p[j-1]. s[3] = s[p[2]] + 1 = s[2] + 1 = 2.
- Result: 1 1 2. ✓

Example 6: p = [1,2,3]
- s[1] = 1
- j=2: p[2]=2=j. s[2] ≤ s[p[1]] = s[1] = 1. s[2] = 1.
- j=3: p[3]=3=j. s[3] ≤ s[p[2]] = s[2] = 1. s[3] = 1.
- Result: 1 1 1. ✓

All examples match! The algorithm is:
- p[1] must be 1, s[1] = 1.
- For j ≥ 2:
  - If p[j] = j: s[j] = 1 (minimize, and it's ≤ s[p[j-1]] ≥ 1).
  - If p[j] = p[j-1]: s[j] = s[p[j-1]] + 1.
  - Else: -1.

Wait, but I need to double-check: when p[j] = j, we set s[j] = 1. But we need s[j] ≤ s[p[j-1]]. Since s[p[j-1]] ≥ 1 always, s[j] = 1 is always valid. ✓

And when p[j] = p[j-1], we set s[j] = s[p[j-1]] + 1. This is the minimum value > s[p[j-1]]. ✓

But wait, I also need to verify that the constructed s actually gives the correct p. Let me think about whether there could be additional constraints I'm missing.

The key claim was: p[j] = j iff s[j] ≤ s[p[j-1]], and p[j] = p[j-1] iff s[j] > s[p[j-1]].

But I derived this assuming the minimum suffix of s[1..j-1] is unique. Is that guaranteed by our construction?

In our construction, when p[j] = p[j-1], s[j] > s[p[j-1]], so s[p[j-1]..j] starts with s[p[j-1]] which is strictly less than s[j]. The minimum suffix of s[1..j] is s[p[j-1]..j] since it starts with s[p[j-1]] < s[j] ≤ s[k] for all k... wait, is s[p[j-1]] ≤ s[k] for all k?

Hmm, not necessarily. Let me think again.

Actually, I think the claim needs more careful justification. Let me think about whether the minimum suffix of s[1..j] is indeed determined solely by comparing s[j] with s[p[j-1]].

Claim: The minimum suffix of s[1..j] is either s[p[j-1]..j] or s[j..j].

Proof: For any k < j, s[k..j] vs s[p[j-1]..j]:
- If s[k..j-1] > s[p[j-1]..j-1]: then s[k..j] > s[p[j-1]..j].
- If s[k..j-1] = s[p[j-1]..j-1]: impossible if min suffix of s[1..j-1] is unique (which we need to verify).
- If s[k..j-1] < s[p[j-1]..j-1]: impossible since p[j-1] is the min suffix start.

So for k < j and k ≠ p[j-1], s[k..j] > s[p[j-1]..j] (assuming uniqueness of min suffix of s[1..j-1]).

So the minimum of s[1..j] is min(s[p[j-1]..j], s[j..j]).

Now, is the minimum suffix of s[1..j-1] unique in our construction? 

By induction: assume min suffix of s[1..j-1] is unique (s[p[j-1]..j-1]). Then min of s[1..j] is min(s[p[j-1]..j], s[j..j]).

s[p[j-1]..j] vs s[j..j]: first char s[p[j-1]] vs s[j].
- If s[p[j-1]] < s[j]: s[p[j-1]..j] < s[j..j], so min is s[p[j-1]..j], unique. p[j] = p[j-1]. ✓
- If s[p[j-1]] > s[j]: s[p[j-1]..j] > s[j..j], so min is s[j..j], unique. p[j] = j. ✓
- If s[p[j-1]] = s[j]: s[j..j] < s[p[j-1]..j] (shorter prefix), so min is s[j..j], unique. p[j] = j. ✓

So in all cases, the minimum is unique, and p[j] is determined by whether s[j] ≤ s[p[j-1]] (then p[j]=j) or s[j] > s[p[j-1]] (then p[j]=p[j-1]).

This confirms the algorithm. Now let me also verify uniqueness of min suffix of s[1..j] for the induction:

Base: j=1, only one suffix, unique. ✓
Step: shown above, always unique. ✓

Great, the algorithm is correct. Now let me code it up properly.

#include <bits/stdc++.h>
using i64 = long long;
void solve() {
    int n; std::cin >> n;
    std::vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) std::cin >> p[i];
    if (p[1] != 1) {
        std::cout << -1 << "\n";
        return;
    }
    std::vector<int> s(n + 1);
    s[1] = 1;
    bool ok = true;
    for (int j = 2; j <= n; j++) {
        if (p[j] == j) {
            s[j] = 1;
        } else if (p[j] == p[j-1]) {
            s[j] = s[p[j]] + 1;
        } else {
            ok = false;
            break;
        }
    }
    if (!ok) {
        std::cout << -1 << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        std::cout << s[i];
        if (i < n) std::cout << ' ';
    }
    std::cout << "\n";
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t; std::cin >> t;
    while (t--) solve();
}
Wait, when p[j] = p[j-1], s[j] = s[p[j]] + 1 = s[p[j-1]] + 1. That's correct.

Let me trace through all examples once more quickly... already verified above. Looks good.

One edge case: what if p[j] = j and j = 1? Handled (p[1] = 1 check).

Another edge case: n = 1, p[1] = 1. s[1] = 1. Output: "1". ✓

I think the solution is correct. Let me write the final clean version.

#include <bits/stdc++.h>
using i64 = long long;
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) std::cin >> p[i];
    if (p[1] != 1) {
        std::cout << -1 << "\n";
        return;
    }
    std::vector<int> s(n + 1);
    s[1] = 1;
    bool ok = true;
    for (int j = 2; j <= n; j++) {
        if (p[j] == j) {
            s[j] = 1;
        } else if (p[j] == p[j - 1]) {
            s[j] = s[p[j]] + 1;
        } else {
            ok = false;
            break;
        }
    }
    if (!ok) {
        std::cout << -1 << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        std::cout << s[i] << " \n"[i == n];
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
