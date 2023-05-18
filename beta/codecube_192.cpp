#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int INF = 1e9;
const int MOD = 1e6 + 7;
const int mxN = 5e3 + 1;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int a[mxN], b[mxN], dp[2][mxN], mn[mxN];
int n, m, k, ans;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i], dp[0][i] = mn[i] = i;
    for(int i = 1; i <= n; i++) {
        int now = i & 1, prev = (i - 1) & 1; dp[now][0] = 1;
        for(int j = 1; j <= m; j++) {
            dp[now][j] = min({dp[prev][j - 1] + (a[i] != b[j]), dp[now][j - 1] + 1, mn[j] + 1});
            mn[j] = min(mn[j], dp[now][j]);
            if(dp[now][j] <= k) ans = max(ans, j);
        }
    }
    cout << ans << '\n';
    return 0;
}
