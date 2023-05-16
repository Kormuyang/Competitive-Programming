#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const ll INF = 1e18;
const int MOD = 1e6 + 7;
const int mxN = 5e2 + 1;
const int mxM = 5e4 + 1;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int a[mxN], dp[2][mxM];
int n, m;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        int now = i & 1, prev = (i - 1) & 1;
        for(int j = 0; j <= m; j++) {
            dp[now][j] = (dp[prev][j] + (j >= a[i] ? dp[prev][j - a[i]] : 0)) % MOD;
        }
    }
    cout << dp[n & 1][m] << '\n';
    return 0;
}
