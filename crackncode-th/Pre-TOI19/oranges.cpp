#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define db double
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

map<db, vector<db>> res;
map<db, int> dp;
int n;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        db a, b, c, d; cin >> a >> b >> c >> d;
        db l = a / b, r = c / d;
        if(l > r) swap(l, r); res[r].emplace_back(l);
    }
    dp[-1] = 0;
    for(auto [i, v] : res) {
        dp[i] = prev(dp.lower_bound(i))->second;
        for(auto j : v) dp[i] = max(dp[i], prev(dp.lower_bound(j))->second + 1);
    }
    cout << n - dp.rbegin()->second << '\n';
    return 0;
}
