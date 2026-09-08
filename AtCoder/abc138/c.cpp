#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector <int> w(n);
    for (int i = 0; i < n; i ++ ) {
        cin >> w[i];
    }

    sort (w.begin (), w.end ());

    stack <double> stk;
    for (int i = n - 1; i >= 0; i -- ) {
        stk.push(w[i]);
    }

    while (stk.size () > 1) {
        double a = stk.top ();
        stk.pop ();
        double b = stk.top ();
        stk.pop ();
        
        double c = (a + b) / 2;
        stk.push (c);
    }

    cout << stk.top () << "\n";


    return 0;
}