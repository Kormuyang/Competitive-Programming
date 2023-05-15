#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int mxN = 1e3 + 1;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int dp[mxN][mxN];
int n, m;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) dp[i][0] = 1;
    for(int j = 1; j <= m; j++) dp[1][j] = 1;
    for(int i = 2; i <= n; i++) for(int j = 1; j <= m; j++) {
        dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1] + 1) % MOD;
    }
    cout << dp[n][m] << '\n';
    return 0;
}
