#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int mxN = 1e3 + 1;

int j[mxN], k[mxN];
pi dp[mxN][mxN];
int n, m;

pi calc(pi a, int b) {
    if(a.second + b > m) return {a.first + 1, b};
    return {a.first, a.second + b};
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> m >> n;
    for(int i = 1; i <= n; i++) cin >> j[i], dp[i][0] = calc(dp[i - 1][0], j[i]);
    for(int i = 1; i <= n; i++) cin >> k[i], dp[0][i] = calc(dp[0][i - 1], k[i]);
    for(int i = 1; i <= n; i++) for(int l = 1; l <= n; l++) {
        dp[i][l] = min(calc(dp[i - 1][l], j[i]), calc(dp[i][l - 1], k[l]));
    }
    cout << dp[n][n].first + 1 << '\n' << dp[n][n].second << '\n';
    return 0;
}
