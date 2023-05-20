#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int mxN = 2e3 + 2;
const int mxM = 3e3 + 2;

int l[mxN], r[mxN], dp1[mxN][mxM], dp2[mxN][mxM], dp3[mxN][mxM], dp4[mxN][mxM];
int n, m, s, ans;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> s;
    for(int i = 1; i <= n; i++) cin >> l[i];
    for(int i = 1; i <= n; i++) cin >> r[i];
    for(int i = 1; i <= n; i++) for(int j = 0; j <= m; j++) {
        dp1[i][j] = max(dp1[i - 1][j], j + min(0, r[i]) < 0 ? 0 : dp1[i - 1][j + min(0, r[i])] + l[i]);
    }
    for(int i = n; i >= 1; i--) for(int j = 0; j <= m; j++) {
        dp2[i][j] = max(dp2[i + 1][j], j + min(0, r[i]) < 0 ? 0 : dp2[i + 1][j + min(0, r[i]) + l[i]]);
    }
    for(int i = 1; i <= n; i++) for(int j = 0; j <= m; j++) {
        dp3[i][j] = max(dp3[i - 1][j], j + min(0, l[i]) < 0 ? 0 : dp3[i - 1][j + min(0, l[i])] + r[i]);
    }
    for(int i = n; i >= 1; i--) for(int j = 0; j <= m; j++) {
        dp4[i][j] = max(dp4[i + 1][j], j + min(0, l[i]) < 0 ? 0 : dp4[i + 1][j + min(0, l[i]) + r[i]]);
    }
    ans = dp1[n][m] + dp3[n][m];
    if(s) {
        for(int i =  0; i <= n; i++) {
            int res1 = 0, res2 = 0;
            for(int j = 0; j <= m; j++) {
                res1 = max(res1, dp1[i][j] + dp4[i + 1][m - j]);
                res2 = max(res2, dp3[i][j] + dp2[i + 1][m - j]);
            }
            ans = max(ans, res1 + res2);
        }
    }
    cout << ans << '\n';
    return 0;
}
