#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int INF = 1e9;
const int MOD = 1e6 + 7;
const int mxN = 2e5 + 1;
const int mxB = 1e2 + 1;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int a[mxN], dp[2][mxB], mn[2][mxB];
int n, k, ans = INF;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cin >> k;
    for(int i = 1; i <= 100; i++) dp[1][i] = (i >= a[1] ? (i - a[1]) * (i - a[1]) : INF);
    for(int i = 2; i <= n; i++) {
        int now = i & 1, prev = (i - 1) & 1;
        for(int j = 1; j <= 100; j++) {
            dp[now][j] = INF; mn[0][j] = dp[prev][j] - k * j; mn[1][j] = dp[prev][j] + k * j;
        }
        for(int j = 2; j <= 100; j++) mn[0][j] = min(mn[0][j], mn[0][j - 1]);
        for(int j = 100; j >= 2; j--) mn[1][j - 1] = min(mn[1][j - 1], mn[1][j]);
        for(int j = a[i]; j <= 100; j++) dp[now][j] = min(mn[0][j] + j * k, mn[1][j] - j * k) + (j - a[i]) * (j - a[i]);
    }
    for(int i = a[n]; i <= 100; i++) ans = min(ans, dp[n & 1][i]);
    cout << ans << '\n';
    return 0;
}
