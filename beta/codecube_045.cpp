#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int mxN = 1e5 + 1;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int qs[mxN], dp[2][mxN];
int n, k, p;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> k >> p;
    for(int i = 1; i <= n; i++) cin >> qs[i], qs[i] += qs[i - 1];
    for(int i = 1; i <= k; i++) {
        int now = i & 1, prev = (i - 1) & 1;
        for(int j = 1; j <= n; j++) {
            dp[now][j] = max(dp[now][j - 1], dp[prev][max(0, j - p)] + qs[j] - qs[max(0, j - p)]);
        }
    }
    cout << dp[k & 1][n] << '\n';
    return 0;
}
