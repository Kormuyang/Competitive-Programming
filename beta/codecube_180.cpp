#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>

const ll INF = 1e18;
const int mxN = 5e4 + 1;

ll qs[mxN], dp[2][mxN], pmin[2][mxN];
int n, k, m;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> k >> m;
    for(int i = 1; i <= n; i++) {
        cin >> qs[i]; qs[i] += qs[i - 1]; pmin[0][i] = min(pmin[0][i - 1], -qs[i - 1]);
    }
    for(int i = 1; i <= k; i++) {
        int now = i & 1, prev = (i - 1) & 1;
        dp[now][0] = pmin[now][0] = INF;
        for(int j = 1; j <= n; j++) {
            dp[now][j] = min(dp[now][j - 1], j < m ? INF : pmin[prev][j - m + 1] + qs[j]);
            pmin[now][j] = min(pmin[now][j - 1], dp[now][max(j - 2, 0)] - qs[j - 1]);
        }
    }
    cout << (qs[n] - dp[k & 1][n]) << '\n';
    return 0;
}
