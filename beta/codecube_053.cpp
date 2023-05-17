#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int INF = 1e9;
const int MOD = 1e6 + 7;
const int mxN = 3e1 + 1;
const int mxH = 1e2 + 1;

int dp[2][mxH][mxH][2 * mxN];
int n, a, b, m;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int q; cin >> q;
    while(q--) {
        cin >> n >> a >> b >> m;
        for(int i = 0; i <= 1; i++) for(int j = 0; j <= a; j++) for(int k = 0; k <= b; k++) for(int l = 0; l <= 60; l++) dp[i][j][k][l] = -INF;
        dp[0][a][b][30] = 0;
        for(int i = 1, x, y, v; i <= n; i++) {
            cin >> x >> y >> v;
            int now = i & 1, prev = (i - 1) & 1;
            for(int j = 0; j <= a; j++) for(int k = 0; k <= b; k++) for(int l = 0; l <= 60; l++) dp[now][j][k][l] = -INF;
            for(int j = 0; j <= a; j++) for(int k = 0; k <= b; k++) for(int l = 0; l <= 60; l++) {
                dp[now][j][k][l] = max(dp[now][j][k][l], dp[prev][j][k][l]);
                if(j >= x + 1 and l + 1 >= 0 and l + 1 <= 60) {
                    dp[now][j - x][k][l + 1] = max(dp[now][j - x][k][l + 1], dp[prev][j][k][l] + v);
                }
                if(k >= y + 1 and l - 1 >= 0 and l - 1 <= 60) {
                    dp[now][j][k - y][l - 1] = max(dp[now][j][k - y][l - 1], dp[prev][j][k][l] + v);
                }
            }
        }
        int ans = -INF;
        for(int i = 0; i <= a; i++) for(int j = 0; j <= b; j++) for(int k = max(1, 30 - m); k <= 30 + m; k++) {
            ans = max(ans, dp[n & 1][i][j][k]);
        }
        cout << (m == 0 ? 0 : ans) << '\n';
    }
    return 0;
}
