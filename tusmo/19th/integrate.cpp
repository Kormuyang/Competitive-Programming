#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int mxN = 5e1 + 2;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, 1}, {-1, -1}, {1, -1}, {1, 1}};

ll dp[4];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> dp[1];
    dp[1] %= MOD, dp[2] = (dp[1] * dp[1]) % MOD, dp[3] = (dp[2] * dp[1]) % MOD;
    cout << dp[3] << '\n';
    return 0;
}s
